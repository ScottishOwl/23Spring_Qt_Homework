
#ifndef SUBSCENE_H
#define SUBSCENE_H


#include <QWidget>
#include <QPushButton>
#include <QCloseEvent>
#include "config.h"

class Subscene : public QWidget
{
    Q_OBJECT
public:
    explicit Subscene(QWidget *parent = nullptr);

//    处理异常关闭
    void closeEvent(QCloseEvent *);

    //继续按钮、结束按钮
    QPushButton b_con,b_fin;


signals:
    void Close_signal();
};

#endif // SUBSCENE_H
