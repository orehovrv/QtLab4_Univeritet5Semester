#ifndef SQUARE_H
#define SQUARE_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QCursor>

class SQUARE: public QObject, public QGraphicsItem {
    Q_OBJECT

    char color;
    QBrush brush;

public:
    explicit SQUARE(QObject * parent = 0);
    ~SQUARE();

    void setColor(int);
    int getColor();

    void mouseMoveEvent(QGraphicsSceneMouseEvent * event);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);

signals:

private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void randomPos();

public slots:
};

#endif // SQUARE_H
