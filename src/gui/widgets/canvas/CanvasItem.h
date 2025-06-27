// CanvasItem.h
#ifndef CANVASITEM_H
#define CANVASITEM_H

#include <QGraphicsRectItem>
#include <QString>

class CanvasItem : public QGraphicsRectItem
{
public:
    explicit CanvasItem(const QString &type);

protected:
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QString componentType;
};

#endif // CANVASITEM_H