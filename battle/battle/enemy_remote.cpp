#include "enemy_remote.h"
#include "config.h"

Enemy_Remote::Enemy_Remote()
{
    //敌人准备切换图片
    m_picrate = 0;
    m_model = 1;

    m_recorder = 0;

    //远程敌人位置
    m_x = 0;
    m_y = 0;

    //远程敌人状态
    m_Free = 1;

    //敌人初始化速度
    m_Speed = REMOTE_SPEED;

    //初始化子弹间隔
    bullet_interval = BULLET_INTERVAL;

}

void Enemy_Remote::Shoot()
{
    //累加时间间隔记录变量
    m_recorder++;

    //如果记录的数字未达到发射间隔,直接return
    if(m_recorder < bullet_interval ) return;

    m_recorder=0;

    //发射子弹
    for(int i = 0 ;i < BULLET_NUM ;i++)
    {
        if(m_bullets[i].m_Free)
        {
            //空闲状态改为假
            m_bullets[i].m_Free = 0;
            //设置子弹位置
            m_bullets[i].m_x = m_x +30;
            m_bullets[i].m_y = m_y +55;
            break;
        }
    }
}

void Enemy_Remote::updatePosition()
{
    //空闲状态敌人不用更新
    if(m_Free == 1) return;

    //更改位置
    m_y += m_Speed;
    m_Rect.moveTo(m_x,m_y);

    //更改图片
    m_picrate++;
    if(m_picrate == PIC_RATE)
    {
        m_picrate = 0;
        if(m_model == 1) m_model = 2;
        else if(m_model == 2) m_model = 1;
    }

    //发射子弹
    this->Shoot();

    //计算所有非空闲子弹的当前坐标
    for(int i = 0 ;i < BULLET_NUM;i++)
    {
        //如果非空闲，计算发射位置
        if(m_bullets[i].m_Free == 0)
        {
            m_bullets[i].updatePosition();
        }
    }
    if( m_y >= GAME_HEIGHT + REMOTE_SPEED)
    {
        m_Free = 1;
    }
}

void Enemy_Remote::Init()
{
    m_rand=(rand() + m_model)% 7;

    //远程敌人资源加载
    switch(m_rand)
    {
    case 0:
        m_enemy.load(REMOTE1_PATH);
        m_enemy2.load(REMOTE1_PATH2);
        break;

    case 1:
        m_enemy.load(REMOTE2_PATH);
        m_enemy2.load(REMOTE2_PATH2);
        break;

    case 2:
        m_enemy.load(REMOTE3_PATH);
        m_enemy2.load(REMOTE3_PATH2);
        break;

    case 3:
        m_enemy.load(REMOTE4_PATH);
        m_enemy2.load(REMOTE4_PATH2);
        break;

    case 4:
        m_enemy.load(REMOTE5_PATH);
        m_enemy2.load(REMOTE5_PATH2);
        break;

    case 5:
        m_enemy.load(REMOTE6_PATH);
        m_enemy2.load(REMOTE6_PATH2);
        break;

    case 6:
        m_enemy.load(REMOTE7_PATH);
        m_enemy2.load(REMOTE7_PATH2);
        break;
    }

    //远程敌人矩形框（碰撞检测）
    m_Rect.setWidth(m_enemy.width());
    m_Rect.setHeight(m_enemy.height());
    m_Rect.moveTo(m_x,m_y);
}
