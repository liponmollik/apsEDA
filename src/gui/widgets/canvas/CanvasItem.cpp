// CanvasItem.cpp
#include "CanvasItem.h"
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsTextItem>
#include <QBrush>

CanvasItem::CanvasItem(const QString &type) : componentType(type)
{
    setRect(0, 0, 80, 40);
    setBrush(Qt::lightGray);
    setFlags(ItemIsMovable | ItemIsSelectable);

    auto *label = new QGraphicsTextItem(type, this);
    label->setPos(5, 10);
}

void CanvasItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsRectItem::mouseDoubleClickEvent(event);
    // TODO: Open Property Dialog
}
