#include "shield.h"
#include "config.h"

Shield::Shield()
{
    //����׼���л�ͼƬ
    m_picrate = 0;
    m_model = 1;

    //����λ��
    m_x = 0;
    m_y = 0;

    //����״̬
    m_Free = 1;

    //���ܳ�ʼ���ٶ�
    m_Speed = SHIELD_SPEED;

}

void Shield::updatePosition()
{
    //����״̬���ܲ��ø���
    if (m_Free == 1) return;

    //����λ��
    m_y += m_Speed;
    m_Rect.moveTo(m_x, m_y);

    //����ͼƬ
    m_picrate++;
    if (m_picrate == PIC_RATE)
    {
        m_picrate = 0;
        if (m_model == 1) m_model = 2;
        else if (m_model == 2) m_model = 1;
    }

    if (m_y >= GAME_HEIGHT + SHIELD_SPEED)
    {
        m_Free = 1;
    }
}

void Shield::Init()
{
    m_rand = rand() % 2;

    //������Դ����
    switch (m_rand)
    {
    case 0:
        m_shield.load(SHIELD1_PATH);
        m_shield2.load(SHIELD1_PATH2);
        break;

    case 1:
        m_shield.load(SHIELD1_PATH);
        m_shield2.load(SHIELD1_PATH2);
        break;
    }
    /*
    case 2:
        m_shield.load(SHIELD3_PATH);
        m_shield2.load(SHIELD3_PATH2);
        break;

    case 3:
        m_shield.load(SHIELD4_PATH);
        m_shield2.load(SHIELD4_PATH2);
        break;

    case 4:
        m_shield.load(SHIELD5_PATH);
        m_shield2.load(SHIELD5_PATH2);
        break;

    case 5:
        m_shield.load(SHIELD6_PATH);
        m_shield2.load(SHIELD6_PATH2);
        break;

    case 6:
        m_shield.load(SHIELD7_PATH);
        m_shield2.load(SHIELD7_PATH2);
        break;
    */
    //���ܾ��ο�����ײ���⣩
    m_Rect.setWidth(m_shield.width());
    m_Rect.setHeight(m_shield.height());
    m_Rect.moveTo(m_x, m_y);
}
