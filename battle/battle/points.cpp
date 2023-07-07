#include "points.h"
#include "config.h"

Points::Points()
{
    //护盾准备切换图片
    m_picrate = 0;
    m_model = 1;

    //护盾位置
    m_x = 0;
    m_y = 0;

    //护盾状态
    m_Free = 1;

    //护盾初始化速度
    m_Speed = POINTS_SPEED;

}

void Points::updatePosition()
{
    //空闲状态护盾不用更新
    if (m_Free == 1) return;

    //更改位置
    m_y += m_Speed;
    m_Rect.moveTo(m_x, m_y);

    //更改图片
    m_picrate++;
    if (m_picrate == PIC_RATE)
    {
        m_picrate = 0;
        if (m_model == 1) m_model = 2;
        else if (m_model == 2) m_model = 1;
    }

    if (m_y >= GAME_HEIGHT + POINTS_SPEED)
    {
        m_Free = 1;
    }
}

void Points::Init()
{
    m_rand = rand() % 6;

    //护盾资源加载
    switch (m_rand)
    {
    case 0:
        m_points.load(POINTS1_PATH);
        m_points2.load(POINTS1_PATH2);
        break;

    case 1:
        m_points.load(POINTS1_PATH);
        m_points2.load(POINTS1_PATH2);
        break;
    }
    //护盾矩形框（碰撞检测）
    m_Rect.setWidth(m_points.width());
    m_Rect.setHeight(m_points.height());
    m_Rect.moveTo(m_x, m_y);
}
