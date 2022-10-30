#include "god.h"

GOD::GOD(QObject *parent): QObject(parent), QGraphicsItem() {
    color = 0;
    this->setFlag(ItemIsSelectable);
    randomPos();
}

GOD::~GOD() {

}

void GOD::randomPos() {
    this->setPos(mapToScene(rand() % 510, rand() % 510));
}

QRectF GOD::boundingRect() const {
    return QRectF (-40, -40, 80, 80);
}

void GOD::setColor(int c) {
    color = c;
    switch(color) {
        case 0: {
            QImage i(":/res/zeus.png");
            img = QPixmap::fromImage(i.scaled(80, 80));
            } break;

        case 1: {
            QImage i(":/res/poseidon.png");
            img = QPixmap::fromImage(i.scaled(80, 80));
            } break;

        default: {
            QImage i(":/res/hades.png");
            img = QPixmap::fromImage(i.scaled(80, 80));
            } break;
    }
}

int GOD::getColor() {
    return color;
}

void GOD::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setPen(Qt::NoPen);

    painter->drawPixmap(-40, -40, 80, 80, img, 0, 0, 80, 80);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void GOD::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton) {
        if(mapToScene(event->pos()).x() < 550 && mapToScene(event->pos()).x() > 0)
            this->setX(mapToScene(event->pos()).x());
        if(mapToScene(event->pos()).y() < 550 && mapToScene(event->pos()).y() > 0)
            this->setY(mapToScene(event->pos()).y());
    }
}

void GOD::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton)
        this->setCursor(QCursor(Qt::ClosedHandCursor));
    else if (event->buttons() & Qt::RightButton)
        this->setSelected(true);
    Q_UNUSED(event);
}

void GOD::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    this->setCursor(QCursor(Qt::ArrowCursor));
    this->setSelected(false);
    Q_UNUSED(event);
}
