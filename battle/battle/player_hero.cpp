#include "player_hero.h"
#include "config.h"
Player_Hero::Player_Hero()
{
    //玩家准备切换图片
    m_picrate = 0;
    m_model = 1;

    //初始化加载玩家图片资源
    m_player.load(HERO_PATH);
    m_player2.load((HERO_PATH2));
    m_player3.load((HERO_PATH3));

    //初始化玩家坐标
    m_x = (GAME_WIDTH - m_player.width()) * 0.5;
    m_y = GAME_HEIGHT - m_player.height();

    //初始化矩形边框
    m_Rect.setWidth(m_player.width());
    m_Rect.setHeight(m_player.height());
    m_Rect.moveTo(m_x,m_y);
}

void Player_Hero::setPosition(int x, int y)
{
    m_x = x;
    m_y = y;
    m_Rect.moveTo(x,y);
}

//玩家动作切换
void Player_Hero::Change()
{
    m_picrate++;
    if(m_picrate == PIC_RATE)
    {
        m_picrate = 0;
        if(m_model == 1) m_model = 2;
        else if(m_model == 2) m_model = 3;
        else if(m_model == 3) m_model = 1;
    }
}
