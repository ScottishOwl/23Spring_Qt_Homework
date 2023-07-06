#ifndef GLOBAL_H
#define GLOBAL_H
 
//此代码仅是一个模板，元素比较单一，但功能接口比较全，各种类型都可以通过在相应的工厂中改变参数实现，或是继承强大的基类实现
//游戏效果可以在全局变量中便捷的控制，添加新元素时注意添加相应的全局变量
//某些细节可能不条理，可以进行适当地调整
//代码中间很少加注释，参考度娘
 
#include <QtWidgets>
 
//Name
#define BLOODSUPPLYNAME 1
#define BOMBSUPPLYNAME 2
#define BULLETSUPPLYNAME 3
#define PLAYERPLANENAME 4
#define ENEMYPLANENAME 5
#define PLAYERBULLETNAME 6
#define ENEMYBULLETNAME 7
#define BOMBNAME 8
 
//Size
#define SCENEWIDTH  1000
#define SCENEHEIGHT  1000
#define BLOODSUPPLYSIZE 30
#define BOMBSUPPLYSIZE 30
#define BULLETSUPPLYSIZE 30
#define PLAYERPLANESIZE 40
#define FISHSIZE 100
#define BOSSSIZE 200
#define PLAYERBULLETSIZE 20
#define FISHBULLETSIZE1 20
#define FISHBULLETSIZE2 20
#define FISHBULLETSIZE3 20
#define BOSSBULLETSIZE1 80
#define BOSSBULLETWIDTH2 200
#define BOSSBULLETHEIGHT2 40
#define BOSSBULLETSIZE3 200
#define BOSSBULLETWIDTH4 200
#define BOSSBULLETHEIGHT4 200
#define BOMBSIZE 800
 
//Speed
#define BLOODSUPPLYSPEED 20
#define BOMBSUPPLYSPEED 20
#define BULLETSUPPLYSPEED 20
#define PLAYERPLANESPEED 10
#define FISHSPEED 10
#define BOSSSPEED 2
#define PLAYERBULLETSPEED 50
#define FISHBULLETSPEED1 20
#define FISHBULLETSPEED2 20
#define FISHBULLETSPEED3 20
#define BOSSBULLETSPEED1 5
#define BOSSBULLETSPEED2 20
#define BOSSBULLETSPEED3 20
#define BOSSBULLETSPEED4 5
#define BOMBSPEED 10
 
//UpdateTime, 因为包含一些内部逻辑， 直接改动可能会有错误， 改之前确保理解advance函数中step的意义
const int PLAYERSHOOTSTEP  = 5;
const int BOSSSHOOTSTEP = 20;
const int FISHSHOOTSTEP = 20;
const int BOMBPIXSTEP = 10;
const int BOSSPIXSTEP = 10;
 
//Score
#define FISHSCORE 10
#define BOSSSCORE 1000
 
//Hp
#define FISHHP 10
#define BOSSHP 1000
 
//UP（上限）
#define PLAYERPLANEBLOOD 3
#define PLAYERPLANEBOMB 3
#define PLAYERPLANEBULLET 3
 
//只实现了boss的动态、玩家的动态和炸弹动态，背景滚动和爆炸效果同理，这里懒得写了
//想要改变动态效果的话注意图片数量，然后自行在飞机、子弹工厂以及控制台中进行相应的改变
const QString background = ":/image/background/background.jpeg";
const QString bloodsupplypix = ":/image/bloodsupply/bloodsupply.png";
const QString bomb0 = ":image/bomb/bomb0.png";
const QString bomb1 = ":image/bomb/bomb1.png";
const QString bombsupplypix = ":/image/bombsupply/bombsupply.png";
const QString boss0 = ":/image/enemyplane/boss0.png";
const QString boss1 = ":/image/enemyplane/boss1.png";
const QString boss2 = ":/image/enemyplane/boss2.png";
const QString boss3 = ":/image/enemyplane/boss3.png";
const QString bossbullet0 = ":/image/enemybullet/bossbullet0.png";
const QString bossbullet1 = ":/image/enemybullet/bossbullet1.png";
const QString bossbullet2 = ":/image/enemybullet/bossbullet2.png";
const QString bossbullet3 = ":/image/enemybullet/bossbullet3.png";
const QString bulletsupplypix = ":/image/bulletsupply/bulletsupply.png";
const QString fish0 = ":/image/enemyplane/fish0.png";
const QString fish1 = ":/image/enemyplane/fish1.png";
const QString fish2 = ":/image/enemyplane/fish2.png";
const QString fishbullet0 = ":/image/enemybullet/fishbullet0.png";
const QString fishbullet1 = ":/image/enemybullet/fishbullet1.png";
const QString fishbullet2 = ":/image/enemybullet/fishbullet2.png";
const QString playerbullet0 = ":/image/playerbullet/playerbullet0.png";
const QString playerbullet1 = ":/image/playerbullet/playerbullet1.png";
const QString playerbullet2 = ":/image/playerbullet/playerbullet2.png";
const QString playerplane0 = ":/image/PlayerPlane/playerplane0.png";
const QString playerplane1 = ":/image/PlayerPlane/playerplane1.png";
const QString playerplane2 = ":/image/PlayerPlane/playerplane2.png";
const QString playerplane3 = ":/image/PlayerPlane/playerplane3.png";
 
#endif // GLOBAL_H