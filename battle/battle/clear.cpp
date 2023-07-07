#include "clear.h"
#include "config.h"

Clear::Clear()
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
    m_Speed = CLEAR_SPEED;

}

void Clear::updatePosition()
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

    if (m_y >= GAME_HEIGHT + CLEAR_SPEED)
    {
        m_Free = 1;
    }
}

void Clear::Init()
{
    m_rand = rand() % 2;

    //������Դ����
    switch (m_rand)
    {
    case 0:
        m_clear.load(CLEAR1_PATH);
        m_clear2.load(CLEAR1_PATH2);
        break;

    case 1:
        m_clear.load(CLEAR1_PATH);
        m_clear2.load(CLEAR1_PATH2);
        break;
    }
    //���ܾ��ο�����ײ���⣩
    m_Rect.setWidth(m_clear.width());
    m_Rect.setHeight(m_clear.height());
    m_Rect.moveTo(m_x, m_y);
}
