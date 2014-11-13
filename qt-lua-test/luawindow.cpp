#include "luawindow.h"
#include "ui_luawindow.h"

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
