#ifndef LUAWINDOW_H
#define LUAWINDOW_H

#include <QMainWindow>
extern "C" {
#include <lua.h>
}
#include <luabind/luabind.hpp>
#include <luabind/function.hpp>
#include <luabind/class.hpp>
#include <luabind/detail/call_function.hpp>

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
    lua_State *luaStt;
    bool isActiveState()
    {
        return luaStt != NULL;
    }
    void updateButtonState();
    void luaError();

    Ui::LuaWindow *ui;
};

#endif // LUAWINDOW_H
