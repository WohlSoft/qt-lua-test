#ifndef LUAWINDOW_H
#define LUAWINDOW_H

#include <QMainWindow>
#include "lua/lua.hpp"

namespace Ui {
class LuaWindow;
}

class LuaWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LuaWindow(QWidget *parent = 0);
    ~LuaWindow();
    static int MsgBox(lua_State *L);

private slots:
    void on_browseButton_clicked();

    void on_LoadLuaFile_clicked();

    void on_RunLuaFile_clicked();

private:
    lua_State* L;
    bool isActiveState()
    {
        return L != NULL;
    }
    void updateButtonState();
    void luaError(lua_State **L);

    Ui::LuaWindow *ui;
};

#endif // LUAWINDOW_H
