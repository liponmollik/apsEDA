// CanvasView.h
#ifndef CANVASVIEW_H
#define CANVASVIEW_H

#include <QGraphicsView>
#include "CanvasScene.h"

class CanvasView : public QGraphicsView
{
    Q_OBJECT

public:
    explicit CanvasView(CanvasScene *scene, QWidget *parent = nullptr);

protected:
    void wheelEvent(QWheelEvent *event) override;
};

#endif // CANVASVIEW_H