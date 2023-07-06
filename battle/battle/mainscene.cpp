#include "mainscene.h"
#include "config.h"
#include <QPainter>
#include <QKeyEvent>
#include <QIcon>
#include <QTimer>
#include <ctime>
#include <QRandomGenerator>

Mainscene::Mainscene(QWidget *parent)
    : QWidget(parent)
{
    //调用初始化场景
    InitScene();

    //启动游戏
    playGame();

}

//清理动态变量，防止内存泄露
Mainscene::~Mainscene()
{
    delete keyRespondTimer;
    delete label_score;
    delete label_high;
    delete label_total;
    delete m_state;
    delete mu_bgm;
    delete mu_shout;
    delete label_instruct;
}

void Mainscene::InitScene()
{
    //初始难度储存
    now_diff = temp_diff = REMOTE_SPEED;
    remote_interval = REMOTE_INTERVAL;


    //加载图标
    setWindowIcon(QIcon(GAME_LABEL));

    //设置窗口尺寸与标题
    setFixedSize(GAME_WIDTH+SCORE_WIDTH,GAME_HEIGHT);
    setWindowTitle(GAME_TITLE);

    //将按钮效果绑定
    connect(&m_sub.b_con,&QPushButton::released, this, &Mainscene::React_con);
    connect(&m_sub.b_fin,&QPushButton::released, this, &Mainscene::React_fin);
    connect(&m_sub,&Subscene::Close_signal, this, &Mainscene::React_fin);

    //定时器设置
    m_Timer.setInterval(GAME_RATE);

    //创建键盘定时器对象，并连接信号槽
    keyRespondTimer = new QTimer(this);
    connect(keyRespondTimer, &QTimer::timeout, this, &Mainscene::keyslot);

    //远程敌人出场间隔 初始化
    for(int i = 0; i < REMOTE_NUM; i++)
    {
        m_remotes[i].Init();
    }
    m_arecorder = 0;

    //分数初始化
    highscore = score = totalscore = 0;

    //记录当前游戏状态:未暂停
    is_Pause = 0;

    //音乐文件初始化
    mu_bgm = new QSoundEffect();
    mu_bgm->setSource(QUrl::fromLocalFile(MUSIC_BGM));
    mu_bgm->setSource(QUrl::fromLocalFile(MUSIC_BGM));
    mu_bgm->setVolume(3);
    mu_bgm->setLoopCount(QSoundEffect::Infinite);  //设置无限循环播放

    mu_shout = new QSoundEffect();
    int number = QRandomGenerator::global()->bounded(2);
    /*mu_shout->setSource(number==0?(QUrl::fromLocalFile(MUSIC_SHOUT)):(QUrl::fromLocalFile(MUSIC_BGM)));*/
    /*mu_shout->setSource(QUrl::fromLocalFile(MUSIC_SHOUT));*/
    if(number==0){
        mu_shout->setSource(QUrl::fromLocalFile(MUSIC_SHOUT));
    }
    else
    {
        mu_shout->setSource(QUrl::fromLocalFile(MUSIC_BLAME));
    }
    mu_shout->setVolume(3);
    mu_shout->setLoopCount(QSoundEffect::Infinite);  //设置无限循环播放

    //记录音乐状态：均开启
    is_bgm = last_bgm = 1;
    is_shout = last_shout = 1;
    connect(&m_bgm, &QPushButton::clicked, this, &Mainscene::control_bgm);
    connect(&m_shout, &QPushButton::clicked, this, &Mainscene::control_shout);
    m_bgm.setParent(this);
    m_shout.setParent(this);
    m_bgm.setText("开启/关闭音乐");
    m_shout.setText("开启/关闭人声");
    QFont music_font;
    music_font.setFamily("华文新魏");
    music_font.setPointSize(15);
    m_bgm.setFont(music_font);
    m_shout.setFont(music_font);
    m_bgm.setFixedSize(150,50);
    m_shout.setFixedSize(150,50);
    m_bgm.move( 10 + GAME_WIDTH,GAME_HEIGHT*25/32);
    m_shout.move( 10 + GAME_WIDTH,GAME_HEIGHT*27/32);

    music_check();


    //标签初始化
    QFont in_font;
    in_font.setFamily("华文新魏");
    in_font.setPointSize(SCORE_SIZE*11/12);
    QPalette in_pa;
    in_pa.setColor(QPalette::WindowText,Qt::black);

    label_instruct=new QLabel(this);
    label_instruct->setFont(in_font);
    label_instruct->move(10 + GAME_WIDTH,GAME_HEIGHT*8/16);
    label_instruct->setFixedSize(500,200);
    label_instruct->setPalette(in_pa);
    label_instruct->setText(QString("操作说明:")
    + QString("<br>") + QString("<br>") + QString("WASD控制移动")
    + QString("<br>") + QString("<br>") + QString("J增加难度 / K降低难度")
    + QString("<br>") + QString("<br>") + QString("回车键暂停"));

    QFont m_font;
    m_font.setFamily("华文新魏");
    m_font.setPointSize(SCORE_SIZE);
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::black);

    label_score=new QLabel(this);
    label_score->setFont(m_font);
    label_score->move(10 + GAME_WIDTH,GAME_HEIGHT*0);
    label_score->setFixedSize(500,100);
    label_score->setPalette(pa);

    label_high=new QLabel(this);
    label_high->setFont(m_font);
    label_high->move(10 + GAME_WIDTH,GAME_HEIGHT/8);
    label_high->setFixedSize(500,100);
    label_high->setPalette(pa);

    label_total=new QLabel(this);
    label_total->setFont(m_font);
    label_total->move(10 + GAME_WIDTH,GAME_HEIGHT*2/8);
    label_total->setFixedSize(500,100);
    label_total->setPalette(pa);

    m_state=new QLabel(this);
    m_state->setFont(m_font);
    m_state->move(10 + GAME_WIDTH,GAME_HEIGHT*3/8);
    m_state->setFixedSize(500,100);
    m_state->setPalette(pa);
    QString str4 = QString("当前状态:游戏中");
    m_state->setText(str4);

    update_label();

    //随机数种子
    srand((unsigned int)time(NULL)) ;
}

void Mainscene::playGame()
{
    //启动定时器
    m_Timer.start();

    //监听定时器发送的信号
    connect(&m_Timer , &QTimer::timeout,[=](){

        //敌人出场
        RemoteToScreen();

        //更新游戏中元素坐标
        updatePosition();

        //绘制到屏幕中
        update();

        //碰撞检测
        CollisionDetection();
    });
}

void Mainscene::RemoteToScreen()
{
    m_arecorder++;
    //未达到出场间隔 直接return
    if(m_arecorder < remote_interval ) return;
    m_arecorder = 0;

    for(int i = 0 ;i < REMOTE_NUM ;i++)
    {
        //如果是空闲 则出场
        if(m_remotes[i].m_Free)
        {
            m_remotes[i].m_Free=0;

            //图片加载
            m_remotes[i].Init();

            //坐标
            m_remotes[i].m_x = MOVE_LEFT+ rand()%( MOVE_RIGHT - MOVE_LEFT );
            qDebug()<<rand();
            m_remotes[i].m_y = -m_remotes[i].m_Rect.height();
            break;
        }
    }
}

void Mainscene::updatePosition()
{
    //更新地图的坐标
    m_map.mapPosition();

    //更新玩家动作
    m_hero.Change();

    //远程敌人位置更新
    for(int i = 0; i < REMOTE_NUM; i++)
    {
        if(m_remotes[i].m_Free == 0)
        {
                if(m_remotes[i].m_y>=GAME_HEIGHT)
                {
                    //分数更新
                    score++;
                    totalscore++;
                    if(score > highscore) highscore = score;

                    //显示分数更新
                    update_label();
                }
            m_remotes[i].updatePosition();
        }
    }
}

void Mainscene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    //绘制地图
    painter.drawPixmap(0,m_map.m_map1_posY,m_map.m_map1);
    painter.drawPixmap(0,m_map.m_map2_posY,m_map.m_map2);

    //绘制玩家
    if(m_hero.m_model == 1)painter.drawPixmap(m_hero.m_x,m_hero.m_y,m_hero.m_player);
    else if(m_hero.m_model == 2)painter.drawPixmap(m_hero.m_x,m_hero.m_y,m_hero.m_player2);
    else if(m_hero.m_model == 3)painter.drawPixmap(m_hero.m_x,m_hero.m_y,m_hero.m_player3);
    //绘制远程敌人
    for(int i = 0; i < REMOTE_NUM; i++)
    {
        //非空闲才绘制
        if(m_remotes[i].m_Free == 0)
        {
            if(m_remotes[i].m_model == 1)painter.drawPixmap(m_remotes[i].m_x,m_remotes[i].m_y,m_remotes[i].m_enemy);
            else if(m_remotes[i].m_model == 2)painter.drawPixmap(m_remotes[i].m_x,m_remotes[i].m_y,m_remotes[i].m_enemy2);

            //绘制子弹(若非空闲才绘制)
            for(int j = 0; j < BULLET_NUM; j++)
            {
                if(m_remotes[i].m_bullets[j].m_Free == 0)
                {
                    painter.drawPixmap(m_remotes[i].m_bullets[j].m_x,m_remotes[i].m_bullets[j].m_y,m_remotes[i].m_bullets[j].m_Bullet);
                }
            }
        }
    }

}

//碰撞检测
void Mainscene::CollisionDetection()
{
    //遍历所有非空闲的敌人
    for(int i = 0 ;i < REMOTE_NUM;i++)
    {
        if(m_remotes[i].m_Free)
        {
            //空闲敌人 跳转下一次循环
            continue;
        }

        //遍历所有 非空闲的子弹
        for(int j = 0 ; j < BULLET_NUM;j++)
        {
            if(m_remotes[i].m_bullets[j].m_Free)
            {
                //空闲子弹 跳转下一次循环
                continue;
            }

            //如果子弹矩形框和玩家矩形框相交，发生碰撞，同时变为空闲状态即可
            if(m_hero.m_Rect.intersects(m_remotes[i].m_bullets[j].m_Rect))
            {
                is_bgm = is_shout = 0;
                music_check();
                m_remotes[i].m_bullets[j].m_Free = 1;
                score = 0;
                update_label();
                temp_diff = now_diff;
                //游戏暂停
                m_Timer.stop();
                m_sub.show();
            }
        }
    }
}

void Mainscene::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        //控制难度
        case Qt::Key_K:
        Red_diff();
        break;

        case Qt::Key_J:
        Add_diff();
        break;

        //回车暂停
        case Qt::Key_Return:
        m_Pause();
        break;
    }

    //判断如果不是长按时自动触发的按下,就将key值加入容器
    if(!event->isAutoRepeat())
        keys.append(event->key());

    //如果定时器不在运行，就启动一下
    if(!keyRespondTimer->isActive())
        keyRespondTimer->start(4);
}

void Mainscene::keyReleaseEvent(QKeyEvent *event){

    //判断如果不是长按时自动触发的释放,就将key值从容器中删除
    if(!event->isAutoRepeat())
        keys.removeAll(event->key());

     //容器空了，关闭定时器
    if(keys.isEmpty())
        keyRespondTimer->stop();

}

void Mainscene::keyslot()
{
    //对键盘指令作出相应：反击、移动

    int limit_right = MOVE_RIGHT; //右边界
    int limit_left = MOVE_LEFT; //左边界
    int limit_up =0 ; //上边界
    int limit_down = GAME_HEIGHT - m_hero.m_player.height(); //下边界

    foreach (int key, keys) {
        switch (key) {

            //向上移动
        case Qt::Key_W:
            if(m_hero.m_y >= limit_up )
                m_hero.setPosition(m_hero.m_x,m_hero.m_y - HERO_SPEED);
            break;

            //向左移动
        case Qt::Key_A:
            if(m_hero.m_x >= limit_left )
                m_hero.setPosition(m_hero.m_x - HERO_SPEED,m_hero.m_y);
            break;

            //向下移动
        case Qt::Key_S:
            if(m_hero.m_y <= limit_down )
                m_hero.setPosition(m_hero.m_x,m_hero.m_y + HERO_SPEED);
            break;

            //向右移动
        case Qt::Key_D:
            if(m_hero.m_x <= limit_right )
                m_hero.setPosition(m_hero.m_x + HERO_SPEED ,m_hero.m_y);
            break;

        default:
            break;
        }
    }
}

//对继续按钮响应
void Mainscene::React_con()
{
    //恢复音乐状态
    is_bgm = last_bgm;
    is_shout = last_shout;
    music_check();

    m_sub.hide();

    //清空场上敌人
    for(int i = 0; i < REMOTE_NUM; i++)
    {
        m_remotes[i].m_Free = 1;
        //将子弹回归初始位置
        for(int j = 0; j < BULLET_NUM; j++)
        {
            m_remotes[i].m_bullets[j].m_Free = 1;
        }
    }

    //清空键盘指令容器
    foreach (int key, keys)
    {
        keys.removeOne(key);
    }

    //重新初始化位置
    m_hero.setPosition((GAME_WIDTH - m_hero.m_player.width()) * 0.5,GAME_HEIGHT - m_hero.m_player.height());

    //恢复难度
    now_diff = temp_diff;
    remote_interval = 120 - 10 * now_diff;

    for(int i = 0; i < REMOTE_NUM; i++)
    {
        m_remotes[i].m_Speed = now_diff;
        m_remotes[i].bullet_interval = 90 - 10 * now_diff;
        for(int j = 0; j < BULLET_NUM; j++)
        {
            m_remotes[i].m_bullets[j].m_Speed = now_diff * 2;
        }
    }

    //游戏重新开始
    m_Timer.start();
}

//对结束按钮响应
void Mainscene::React_fin()
{
    m_sub.close();
    this->close();
}

//暂停操作
void Mainscene::m_Pause()
{
    //恢复游戏
    if(is_Pause == 1)
    {
        //清空键盘指令容器
        foreach (int key, keys)
        {
            keys.removeOne(key);
        }

        //恢复暂停前的状态
        m_hero.setPosition(m_hero.temp_x,m_hero.temp_y);

        now_diff = temp_diff;
        remote_interval = 120 - 10 * now_diff;
        for(int i = 0; i < REMOTE_NUM; i++)
        {
            m_remotes[i].m_Speed = now_diff;
            m_remotes[i].bullet_interval = 90 - 10 * now_diff;
            for(int j = 0; j < BULLET_NUM; j++)
            {
                m_remotes[i].m_bullets[j].m_Speed = now_diff * 2;
            }
        }

        //继续
        m_Timer.start();
        is_Pause = 0;

        //恢复音乐状态
        is_bgm = last_bgm;
        is_shout = last_shout;

        //更改标签显示
        QString str4 = QString("当前状态:游戏中");
        m_state->setText(str4);
    }

    //暂停游戏
    else if(is_Pause == 0)
    {
        //记录暂停前状态
        m_hero.temp_x = m_hero.m_x;
        m_hero.temp_y = m_hero.m_y;
        temp_diff = now_diff;
        //清空键盘指令容器
        foreach (int key, keys)
        {
            keys.removeOne(key);
        }

        //关闭音乐
        is_bgm = 0;
        is_shout = 0;

        //暂停
        m_Timer.stop();
        is_Pause = 1;

        //更改标签显示
        QString str4 = QString("当前状态:已暂停");
        m_state->setText(str4);
    }

    //检测是否需要播放音乐
    music_check();
}

void Mainscene::update_label()
{
    //显示分数更新
    QString str1 = QString("目前得分：%1").arg(score);
    label_score->setText(str1);

    QString str2 = QString("最高得分：%1").arg(highscore);
    label_high->setText(str2);

    QString str3 = QString("总计得分：%1").arg(totalscore);
    label_total->setText(str3);

    if(is_Pause == 1)
    {
        QString str4 = QString("当前状态:已暂停");
        m_state->setText(str4);
    }
    else if(is_Pause == 0)
    {
        QString str4 = QString("当前状态:游戏中");
        m_state->setText(str4);
    }
}

void Mainscene::control_bgm()
{
    if(is_Pause == 1)return;

    //关闭音乐
    if(last_bgm == 1)
    {
        is_bgm = 0;
        last_bgm = 0;
    }

    //开启音乐
    else if(last_bgm == 0)
    {
        is_bgm = 1;
        last_bgm = 1;
    }
    music_check();
}

void Mainscene::control_shout()
{
    if(is_Pause == 1)return;

    //关闭音乐
    if(last_shout == 1)
    {
        is_shout = 0;
        last_shout = 0;
    }

    //开启音乐
    else if(last_shout == 0)
    {
        is_shout = 1;
        last_shout = 1;
    }
    music_check();
}

void Mainscene::music_check()
{
    if(is_bgm)
    {
        mu_bgm->play();
    }

    else if(is_bgm == 0)
    {
        mu_bgm->stop();
    }

    if(is_shout)
    {
        mu_shout->play();
    }

    else if(is_shout == 0)
    {
        mu_shout->stop();
    }
}

void Mainscene::Add_diff()
{
    if(now_diff <= 7)
    {
        now_diff++;
        remote_interval = 120 - 10 * now_diff;
        for(int i = 0; i < REMOTE_NUM; i++)
        {

            m_remotes[i].m_Speed = now_diff;
            m_remotes[i].bullet_interval = 90 - 10 * now_diff;
            for(int j = 0; j < BULLET_NUM; j++)
            {
                m_remotes[i].m_bullets[j].m_Speed = now_diff * 2;
            }
        }
    }
}

void Mainscene::Red_diff()
{
    if(now_diff >= 4)
    {
        now_diff--;
        for(int i = 0; i < REMOTE_NUM; i++)
        {
            m_remotes[i].m_Speed = now_diff;
            m_remotes[i].bullet_interval = 90 - 10 * now_diff;
            for(int j = 0; j < BULLET_NUM; j++)
            {
                m_remotes[i].m_bullets[j].m_Speed = now_diff * 2;
            }
        }
    }
}

void Mainscene::closeEvent(QCloseEvent *)
{
    emit m_sub.Close_signal();
}
