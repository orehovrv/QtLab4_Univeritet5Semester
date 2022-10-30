#ifndef TEXT_H
#define TEXT_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QCursor>

class TEXT: public QObject, public QGraphicsItem {
    Q_OBJECT

    QString strText;

public:
    explicit TEXT(QObject * parent = 0);
    ~TEXT();

    void setStr(QString);
    QString getStr();

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

#endif // TEXT_H
