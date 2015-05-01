#include "luawindow.h"
#include "ui_luawindow.h"
#include <qfiledialog.h>
#include <QMessageBox>

#include <luabind/detail/call_function.hpp>
extern "C" {
    #include <lua/lualib.h>
}
void MsgBox(const char* text)
{
    QMessageBox::information(NULL, "A message from Lua", text);
}


LuaWindow::LuaWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LuaWindow)
{
    ui->setupUi(this);
}

LuaWindow::~LuaWindow()
{
    lua_close(luaStt);
    delete ui;
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
    this->luaStt = luaL_newstate();
    luaL_openlibs(this->luaStt);
    luabind::open(this->luaStt);
    luabind::module(this->luaStt) [
        luabind::def("MsgBox", MsgBox)
      ];

    int lapierrcode = luaL_loadfile(this->luaStt, ui->luaCodepath->text().toLocal8Bit().data())  || lua_pcall(this->luaStt, 0, LUA_MULTRET, 0);
    if(!(lapierrcode == 0)){
        luaError();
    }
    updateButtonState();
}

void LuaWindow::on_RunLuaFile_clicked()
{
    if(!isActiveState())
        return;

    try{
        luabind::call_function<void>(this->luaStt, "run");
    }catch(luabind::error& e){
        luabind::object error_msg(luabind::from_stack(e.state(), -1));
        QMessageBox::information(this, "Error", luabind::object_cast<const char*>(error_msg));
    }



    updateButtonState();
}

void LuaWindow::updateButtonState()
{
    if(isActiveState())
        ui->RunLuaFile->setEnabled(true);
}

void LuaWindow::luaError()
{
    QMessageBox::warning(this, "Error", QString(lua_error(luaStt)));
    lua_close(luaStt);
}
