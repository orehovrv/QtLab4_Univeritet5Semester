#include "text.h"

TEXT::TEXT(QObject *parent): QObject(parent), QGraphicsItem() {
    strText = "";
    this->setFlag(ItemIsSelectable);
    randomPos();
}

TEXT::~TEXT() {

}

QRectF TEXT::boundingRect() const {
    return QRectF (0, -10, 100, 10);
}

void TEXT::setStr(QString s) {
    strText = s;
}

QString TEXT::getStr() {
    return strText;
}

void TEXT::randomPos() {
    this->setPos(mapToScene(rand() % 510, rand() % 510));
}

void TEXT::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setPen(QColor(0, 0, 0));
    painter->drawText(0, 0, strText);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void TEXT::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton) {
        if(mapToScene(event->pos()).x() < 510 && mapToScene(event->pos()).x() > 0)
            this->setX(mapToScene(event->pos()).x());
        if(mapToScene(event->pos()).y() < 550 && mapToScene(event->pos()).y() > 10)
            this->setY(mapToScene(event->pos()).y());
    }
}

void TEXT::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton)
        this->setCursor(QCursor(Qt::ClosedHandCursor));
    else if (event->buttons() & Qt::RightButton)
        this->setSelected(true);
    Q_UNUSED(event);
}

void TEXT::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    this->setCursor(QCursor(Qt::ArrowCursor));
    this->setSelected(false);
    Q_UNUSED(event);
}
