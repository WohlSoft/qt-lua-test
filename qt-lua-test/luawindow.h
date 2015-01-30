#ifndef LUAWINDOW_H
#define LUAWINDOW_H

#include <QMainWindow>

#include "oolua/include/oolua.h"

namespace Ui {
class LuaWindow;
}

class LuaWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LuaWindow(QWidget *parent = 0);
    ~LuaWindow();

private slots:
    void on_browseButton_clicked();

    void on_LoadLuaFile_clicked();

    void on_RunLuaFile_clicked();

private:
    OOLUA::Script* luavm;
    bool isActiveState()
    {
        return luavm != NULL;
    }
    void updateButtonState();
    void luaError();

    Ui::LuaWindow *ui;
};

#endif // LUAWINDOW_H
