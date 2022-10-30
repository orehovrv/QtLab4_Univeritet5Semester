#ifndef GOD_H
#define GOD_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QCursor>

class GOD: public QObject, public QGraphicsItem {
    Q_OBJECT

    char color;

public:
    explicit GOD(QObject * parent = 0);
    ~GOD();

    void setColor(int);
    int getColor();

    void mouseMoveEvent(QGraphicsSceneMouseEvent * event);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);

signals:

private:
    QPixmap img;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void randomPos();

public slots:
};

#endif // GOD_H
