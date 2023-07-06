#ifndef ENEMY_REMOTE_H
#define ENEMY_REMOTE_H
#include <QPixmap>
#include <ctime>
#include "Bullet.h"

class Enemy_Remote
{
public:
    Enemy_Remote();

    //发射子弹
    void Shoot();

    //更新坐标与形象
    void updatePosition();

    //资源初始化
    void Init();
public:
    //远程敌人对象
    QPixmap m_enemy,m_enemy2;

    //位置
    int m_x,m_y;

    //远程敌人矩形边框（碰撞检测）
    QRect m_Rect;

    //状态
    bool m_Free;

    //速度
    int m_Speed;

    //弹匣
    Bullet m_bullets[BULLET_NUM];

    //子弹间隔
    int m_recorder;
    int bullet_interval;

    //记录是否更新动作
    int m_picrate;

    //记录目前动作为1还是2
    int m_model;

    //模型随机数
    int m_rand;
};

#endif // ENEMY_REMOTE_H
