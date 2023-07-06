#ifndef SUPPLY_H
#define SUPPLY_H
 
#include "flyer.h"
 
class Supply : public Flyer
{
public:
    Supply(qreal w, qreal h, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent = 0)
        :Flyer(w, h, speed, pixs, scene, parent) {
 
    }
    ~Supply() {
 
    }
    QRectF boundingRect() const {
        return m_pixs.at(0).rect();
    }
    QPainterPath shape() const {
        QPainterPath path;
        path.addRect(boundingRect());
        return path;
    }
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
        Q_UNUSED(option);
        Q_UNUSED(widget);
        painter->drawPixmap(0, 0, m_pixs.at(0));
    }
    void advance(int) {
        if (!checkPos(DOWN)) {
            posLost();
            return;
        }
        QPointF pos = scenePos();
        pos.ry() += m_speed;
        setPos(pos);
    }
 
    void posLost() {
        setVisible(false);
        deleteLater();
    }
 
    void doCollide() {
 
    }
 
    void fall() {
        setVisible(false);
        deleteLater();
    }
};
 
#endif // SUPPLY_H