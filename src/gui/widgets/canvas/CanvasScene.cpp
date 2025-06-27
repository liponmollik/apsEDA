// CanvasScene.cpp
#include "CanvasScene.h"
#include "CanvasItem.h"
#include <QGraphicsSceneDragDropEvent>
#include <QMimeData>
#include <QDebug>

CanvasScene::CanvasScene(QObject *parent) : QGraphicsScene(parent)
{
    setBackgroundBrush(Qt::white);
    setSceneRect(0, 0, 800, 600);
}

void CanvasScene::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    if (event->mimeData()->hasText()) {
        event->acceptProposedAction();
    }
}

void CanvasScene::dragMoveEvent(QGraphicsSceneDragDropEvent *event)
{
    if (event->mimeData()->hasText()) {
        event->acceptProposedAction();
    }
}

void CanvasScene::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    QString type = event->mimeData()->text();
    QPointF pos = event->scenePos();

    auto *item = new CanvasItem(type);
    item->setPos(pos);
    addItem(item);

    event->acceptProposedAction();
}
