#include "luawindow.h"
#include "ui_luawindow.h"
#include <qfiledialog.h>
#include <QMessageBox>


using namespace OOLUA;
void MsgBox(const char* text)
{
    QMessageBox::information(NULL, "A message from Lua", text);
}
OOLUA_CFUNC(MsgBox, MsgBox_l);



LuaWindow::LuaWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LuaWindow)
{
    ui->setupUi(this);
}

LuaWindow::~LuaWindow()
{
    delete luavm;
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
    luavm = new OOLUA::Script();
    OOLUA::set_global(luavm->state(), "MsgBox", MsgBox_l);
    if(!OOLUA::run_file(luavm->state(), ui->luaCodepath->text().toStdString())){
        luaError();
    }

    updateButtonState();
}

void LuaWindow::on_RunLuaFile_clicked()
{
    if(!isActiveState())
        return;

    if(!luavm->call("run")){
        luaError();
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
    QMessageBox::warning(this, "Error", QString(OOLUA::get_last_error(luavm->state()).c_str()));
    delete luavm;
    luavm = NULL;
}
