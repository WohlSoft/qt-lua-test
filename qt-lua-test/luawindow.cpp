#include "luawindow.h"
#include "ui_luawindow.h"
#include <qfiledialog.h>
#include <QMessageBox>

LuaWindow::LuaWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LuaWindow)
{
    ui->setupUi(this);
}

LuaWindow::~LuaWindow()
{
    delete ui;
}

int LuaWindow::MsgBox(lua_State *L)
{
    int numOfArg = lua_gettop(L);
    if(!numOfArg)
        return 0;
    if(lua_type(L, 1) != LUA_TSTRING)
        return 0;

    QString msg = lua_tostring(L,1);
    QMessageBox::information(NULL, "A message from Lua", msg);
    return 0;
}

void LuaWindow::on_browseButton_clicked()
{
    QString sel = QFileDialog::getOpenFileName(this, "Select lua file for test", QString(), QString("Lua file (*.lua);;All files (*.*)"));
    if(sel.isEmpty())
        return;

    ui->luaCodepath->setText(sel);
}

void LuaWindow::on_LoadLuaFile_clicked()
{
    L = luaL_newstate();

    lua_pushcfunction(L, luaopen_base);
    lua_call(L,0,0);
    lua_pushcfunction(L, luaopen_math);
    lua_call(L,0,0);
    lua_pushcfunction(L, luaopen_string);
    lua_call(L,0,0);
    lua_pushcfunction(L, luaopen_table);
    lua_call(L,0,0);
    lua_pushcfunction(L, luaopen_debug);
    lua_call(L,0,0);
    lua_pushcfunction(L, luaopen_package);
    lua_call(L,0,0);

    lua_register(L, "MsgBox", LuaWindow::MsgBox);

    if (luaL_loadfile(L, ui->luaCodepath->text().toStdString().c_str()) || lua_pcall(L, 0, 0, 0)) {
        luaError(&L);
        goto finalizeLua;
    }

finalizeLua:;
    updateButtonState();
}

void LuaWindow::on_RunLuaFile_clicked()
{
    if(!isActiveState())
        return;

    lua_getglobal(L, "run");
    if(!lua_isfunction(L,-1))
    {
        lua_pop(L,1);
        return;
    }
    if (lua_pcall(L, 0, 0, 0) != 0) {
        luaError(&L);
        updateButtonState();
        return;
    }

}

void LuaWindow::updateButtonState()
{
    if(isActiveState())
        ui->RunLuaFile->setEnabled(true);
}

void LuaWindow::luaError(lua_State **L)
{
    QString errTxt = "error: ";
    errTxt.append(lua_tostring(*L, -1));
    QMessageBox::warning(this, "Error", errTxt);
    lua_close(*L);
    *L = NULL;
}
