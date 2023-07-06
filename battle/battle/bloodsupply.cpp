#include "bloodsupply.h"
 
BloodSupply::BloodSupply(qreal w, qreal h, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent)
    :Supply(w, h, speed, pixs, scene, parent) {
 
}
 
BloodSupply::~BloodSupply() {
 
}
 
int BloodSupply::name() const
{
    return BLOODSUPPLYNAME;
}