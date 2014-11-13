#ifndef LUAWINDOW_H
#define LUAWINDOW_H

#include <QMainWindow>

namespace Ui {
class LuaWindow;
}

class LuaWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LuaWindow(QWidget *parent = 0);
    ~LuaWindow();

private:
    Ui::LuaWindow *ui;
};

#endif // LUAWINDOW_H
