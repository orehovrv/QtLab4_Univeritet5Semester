#include "square.h"

SQUARE::SQUARE(QObject *parent): QObject(parent), QGraphicsItem() {
    color = 0;
    this->setFlag(ItemIsSelectable);
    randomPos();
}

SQUARE::~SQUARE() {

}

QRectF SQUARE::boundingRect() const {
    return QRectF (-40, -40, 80, 80);
}

void SQUARE::setColor(int c) {
    color = c;
}

int SQUARE::getColor() {
    return color;
}

void SQUARE::randomPos() {
    this->setPos(mapToScene(rand() % 510, rand() % 510));
}

void SQUARE::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setPen(Qt::NoPen);

    switch(color) {
        case 0: {
            QBrush brush(QColor(169, 178, 195));
            painter->setBrush(brush);
            }
            break;

        case 1: {
            QBrush brush(QColor(255, 140, 105));
            painter->setBrush(brush);
            }
            break;

        default: {
            QBrush brush(QColor(255, 99, 71));
            painter->setBrush(brush);
            }
            break;
    }


    painter->drawRect(-40, -40, 80, 80);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void SQUARE::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton) {
        if(mapToScene(event->pos()).x() < 550 && mapToScene(event->pos()).x() > 0)
            this->setX(mapToScene(event->pos()).x());
        if(mapToScene(event->pos()).y() < 550 && mapToScene(event->pos()).y() > 0)
            this->setY(mapToScene(event->pos()).y());
    }
}

void SQUARE::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton)
        this->setCursor(QCursor(Qt::ClosedHandCursor));
    else if (event->buttons() & Qt::RightButton)
        this->setSelected(true);
    Q_UNUSED(event);
}

void SQUARE::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    this->setCursor(QCursor(Qt::ArrowCursor));
    this->setSelected(false);
    Q_UNUSED(event);
}
