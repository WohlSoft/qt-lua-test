#include "luawindow.h"
#include "ui_luawindow.h"
#include <qfiledialog.h>
#include <QMessageBox>


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
    luabind::open(this->luaStt);
    luabind::module(this->luaStt) [
        luabind::def("MsgBox", MsgBox)
      ];

    if(!luaL_loadfile(this->luaStt, ui->luaCodepath->text().toLocal8Bit().data()))
    {
        luaError();
    }
    updateButtonState();
}

void LuaWindow::on_RunLuaFile_clicked()
{
    if(!isActiveState())
        return;
    luaL_dostring(
        this->luaStt,
        "run()\n"
      );
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
