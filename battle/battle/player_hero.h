#ifndef PLAYER_HERO_H
#define PLAYER_HERO_H
#include <QPixmap>
#include <QRect>

class Player_Hero
{
public:
    Player_Hero();

   //发射子弹
    void shoot();

    //设置玩家位置
    void setPosition(int x,int y);

    //更改玩家形象
    void Change();

public:
    //玩家资源 对象
    QPixmap m_player,m_player2,m_player3;

    //玩家坐标
    int m_x,m_y,temp_x,temp_y;

    //记录是否更新动作
    int m_picrate;

    //记录目前动作
    int m_model;

    //玩家的矩形边框
    QRect m_Rect;
};

#endif // PLAYER_HERO_H
