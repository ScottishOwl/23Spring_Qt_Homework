#ifndef CONFIG_H
#define CONFIG_H

/*游戏配置数据*/
#define GAME_WIDTH 640 //界面宽度
#define GAME_HEIGHT 800 //界面高度
#define MOVE_LEFT 120 //可移动左边界
#define MOVE_RIGHT 520 //可移动右边界
#define SCORE_WIDTH 250 //计分界面宽度
#define GAME_TITLE "键盘大作战" //游戏标题
#define GAME_LABEL ":/res/label.png" //图标资源
#define SCORE_SIZE 20  //分数显示字体大小
#define INSTRUCT_SIZE 10  //游戏说明字体大小
#define GAME_RATE 10    //帧率为10ms
#define PIC_RATE 50  //玩家敌人更新频率为500ms(帧率的x倍)

/*音乐配置数据*/
#define MUSIC_BLAME ":/res/BLAME.wav"
#define MUSIC_SHOUT ":/res/SHOUT.wav" //人声资源路径
#define MUSIC_BGM ":/res/BGM.wav"  //背景音乐路径

/*地图配置数据*/
#define MAP_PATH ":/res/background.jpg"  //地图路径
#define MAP_SCROLL_SPEED 2  //地图滚动速度

/*玩家配置数据*/
#define HERO_PATH ":/res/hero.png"  //玩家路径
#define HERO_PATH2 ":/res/hero2.png"  //玩家动作2路径
#define HERO_PATH3 ":/res/hero3.png"  //玩家动作3路径
#define HERO_SPEED 4  //玩家速度

/*子弹配置数据*/
#define BULLET_PATH ":/res/bullet.png" //子弹路径
#define BULLET_SPEED 8  //子弹速度
#define BULLET_NUM 30  //弹匣中子弹总数
#define BULLET_INTERVAL 50  //发射子弹时间间隔

/*远程敌人配置数据*/
#define REMOTE1_PATH ":/res/1.png"  //远程敌人1资源图片
#define REMOTE1_PATH2 ":/res/1(1).png"  //远程敌人1动作2
#define REMOTE2_PATH ":/res/2.png"  //远程敌人2资源图片
#define REMOTE2_PATH2 ":/res/2(1).png"  //远程敌2动作2
#define REMOTE3_PATH ":/res/3.png"  //远程敌人3资源图片
#define REMOTE3_PATH2 ":/res/3(1).png"  //远程敌人3动作2
#define REMOTE4_PATH ":/res/4.png"  //远程敌人4资源图片
#define REMOTE4_PATH2 ":/res/4(1).png"  //远程敌人4动作2
#define REMOTE5_PATH ":/res/5.png"  //远程敌人5资源图片
#define REMOTE5_PATH2 ":/res/5(1).png"  //远程敌人5动作2
#define REMOTE6_PATH ":/res/6.png"  //远程敌人6资源图片
#define REMOTE6_PATH2 ":/res/6(1).png"  //远程敌人6动作2
#define REMOTE7_PATH ":/res/7.png"  //远程敌人7资源图片
#define REMOTE7_PATH2 ":/res/7(1).png"  //远程敌人7动作2

#define REMOTE_SPEED 4  //远程敌人移动速度
#define REMOTE_NUM 30  //远程敌人总数量
#define REMOTE_INTERVAL 80  //远程敌人出场间隔

/*结束按钮配置数据*/
#define SUB_WIDTH 300  //结束窗口宽度
#define SUB_HEIGHT 100  //结束窗口高度


#endif // CONFIG_H
