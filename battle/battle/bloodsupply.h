#ifndef BLOODSUPPLY_H
#define BLOODSUPPLY_H
 
#include "supply.h"
 
class BloodSupply : public Supply
{
public:
    BloodSupply(qreal w, qreal h, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent = 0);
    ~BloodSupply();
    int name() const;
};
 
#endif // BLOODSUPPLY_H
