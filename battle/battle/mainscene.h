#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include <QPushButton>
#include <QTimer>
#include <QLabel>
#include <QFont>
#include <QString>
#include <QPalette>
#include <QtMultimedia/QSoundEffect>
#include "Map.h"
#include "player_hero.h"
#include "enemy_remote.h"
#include "config.h"
#include "subscene.h"
#include "shield.h"
#include "points.h"
#include "clear.h"

class Mainscene : public QWidget
{
    Q_OBJECT

public:
    Mainscene(QWidget *parent = nullptr);
    ~Mainscene();

    //初始化场景
    void InitScene();

    //启动游戏
    void playGame();

    //更新所有游戏中元素的坐标
    void updatePosition();

    //绘制到屏幕中
    void paintEvent(QPaintEvent *);

    //键盘移动事件
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);

    //容器用于存放按下的按键 定时器检测键盘响应
    QList<int> keys;
    QTimer *keyRespondTimer;
    void keyslot();

    //地图对象
    Map m_map;

    //玩家对象
    Player_Hero m_hero;

    //定时器更新地图
    QTimer m_Timer1,m_Timer2,m_Timer3,m_Timer4,m_Timer5;

    //远程敌人出场
    void RemoteToScreen();

    //远程敌人数组
    Enemy_Remote m_remotes[REMOTE_NUM];

    //护盾出场
    void ShieldToScreen();

    //护盾数组
    Shield m_shields[SHIELD_NUM];

    //奖励分数出场
    void PointsToScreen();

    //奖励分数数组
    Points m_pointses[POINTS_NUM];

    //清屏道具出场
    void ClearToScreen();

    //清屏道具数组
    Clear m_clears[POINTS_NUM];

    //玩家护盾值
    int shield_num;

    //远程敌人出场间隔记录
    int m_enemy_recorder;
    int remote_interval;

    //护盾出场间隔记录
    int m_shield_recorder;
    int shield_interval;

    //奖励分数出场间隔记录
    int m_points_recorder;
    int points_interval;

    //清屏道具出场间隔记录
    int m_clear_recorder;
    int clear_interval;

    //碰撞检测
    void CollisionDetection();

    //记录游戏时间
    QTimer game_Timer;

    //记录玩家得分
    int score,highscore,totalscore;

    //结束暂停界面
    Subscene m_sub;

    //对继续按钮响应
    void React_con();

    //对结束按钮响应
    void React_fin();

    //暂停
    int is_Pause;
    void m_Pause();

    //操作说明
    QLabel *label_instruct;

    //显示目前得分 最高分 总得分 护盾值
    QLabel *label_score,*label_high,*label_total,*label_shield;
    void update_label();

    //显示游戏状态（暂停/未暂停）
    QLabel *m_state;

    //记录音乐开关状态
    bool is_bgm,last_bgm;

    //关闭与打开音乐实现
    QPushButton m_bgm,m_shout;
    void control_bgm();
    void music_check();

    //音乐
    QSoundEffect *mu_bgm;

    //储存难度
    int now_diff,temp_diff;

    //更新难度
    void Add_diff();
    void Red_diff();

    //处理异常关闭
    void closeEvent(QCloseEvent *);

};
#endif // MAINSCENE_H
