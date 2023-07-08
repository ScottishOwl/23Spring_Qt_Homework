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
#define PIC_RATE 50  //玩家敌人及道具更新频率为500ms(帧率的x倍)

/*音乐配置数据*/
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
#define BULLET_INTERVAL 25  //发射子弹时间间隔

/*护盾配置数据*/
#define SHIELD1_PATH ":/res/shield1.png" //护盾资源图片
#define SHIELD1_PATH2 ":/res/shield1(1).png" //护盾动作2
#define SHIELD_SPEED 5  //护盾速度
#define SHIELD_NUM 5  //护盾总数
#define SHIELD_INTERVAL 400  //护盾出现时间间隔
#define SHIELD_APPEAR_UNLIKELINESS 10  //护盾可以出现后出现的概率的倒数
#define SHIELD_DEFENSE_NUM 2  //护盾提供的护盾值

/*奖励分数配置数据*/
#define POINTS1_PATH ":/res/points.png" //奖励分数资源图片1
#define POINTS1_PATH2 ":/res/points(1).png" //奖励分数1动作2
#define POINTS_SPEED 6  //奖励分数速度
#define POINTS_NUM 2  //奖励分数总数
#define POINTS_INTERVAL 50  //奖励分数出现时间间隔
#define POINTS_APPEAR_UNLIKELINESS 20  //奖励分数可以出现后出现的概率的倒数

/*清屏道具配置数据*/
#define CLEAR1_PATH ":/res/clear.png" //清屏道具资源图片
#define CLEAR1_PATH2 ":/res/clear(1).png" //清屏道具动作2
#define CLEAR_SPEED 7  //清屏道具速度
#define CLEAR_NUM 1  //清屏道具总数
#define CLEAR_INTERVAL 800  //清屏道具出现时间间隔
#define CLEAR_APPEAR_UNLIKELINESS 40  //清屏道具可以出现后出现的概率的倒数

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
#define REMOTE_INTERVAL 50  //远程敌人出场间隔

/*结束按钮配置数据*/
#define SUB_WIDTH 300  //结束窗口宽度
#define SUB_HEIGHT 100  //结束窗口高度


#endif // CONFIG_H
