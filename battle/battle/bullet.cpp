#include "bullet.h"

Bullet::Bullet()
{
    //加载子弹资源
    m_Bullet.load(BULLET_PATH);

    //子弹坐标
    m_x = 0;
    m_y = 0;

    //子弹状态
    m_Free = 1;

    //子弹边框
    m_Rect.setHeight(m_Bullet.height());
    m_Rect.setWidth(m_Bullet.width());
    m_Rect.moveTo(m_x,m_y);

    //子弹速度初始化
    m_Speed = BULLET_SPEED;
}

void Bullet::updatePosition()
{
    //未发射状态子弹不用管坐标
    if(m_Free == 1 ) return;

    //敌人子弹向下
    m_y += m_Speed;
    m_Rect.moveTo(m_x,m_y);

    //如果子弹超出屏幕：重新转化为空闲状态
    if(m_y >= GAME_HEIGHT )
    {
        m_Free = 1;
        return;
    }

}
