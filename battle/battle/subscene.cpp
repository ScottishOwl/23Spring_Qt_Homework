
#include "subscene.h"
#include <QIcon>

Subscene::Subscene(QWidget *parent)
    : QWidget{parent}
{
    //按钮和窗口信息初始化
    setWindowTitle("游戏结束!");
    resize(SUB_WIDTH , SUB_HEIGHT);
    b_con.setParent(this);
    b_fin.setParent(this);
    b_con.setText("重新开始");
    b_fin.setText("关闭游戏");
    b_con.move( SUB_WIDTH * 3 / 16, SUB_HEIGHT / 8 * 3);
    b_fin.move( SUB_WIDTH * 9 / 16, SUB_HEIGHT / 8 * 3);

    //加载图标
    setWindowIcon(QIcon(GAME_LABEL));
}

void Subscene::closeEvent ( QCloseEvent * )
{
    emit Close_signal();
}
