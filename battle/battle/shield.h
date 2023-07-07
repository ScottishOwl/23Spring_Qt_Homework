#ifndef SHIELD_H
#define SHIELD_H
#include <QPixmap>
#include <ctime>

class Shield
{
public:
    Shield();

    //更新坐标与形象
    void updatePosition();

    //资源初始化
    void Init();
public:
    //远程道具对象
    QPixmap m_shield,m_shield2;

    //位置
    int m_x,m_y;

    //远程道具矩形边框（碰撞检测）
    QRect m_Rect;

    //状态
    bool m_Free;

    //速度
    int m_Speed;

    //记录是否更新动作
    int m_picrate;

    //记录目前动作为1还是2
    int m_model;

    //模型随机数
    int m_rand;
};

#endif // Shield_H
