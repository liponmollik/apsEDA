// ToolboxWidget.h
#ifndef TOOLBOXWIDGET_H
#define TOOLBOXWIDGET_H

#include <QWidget>
#include <QListWidget>

class ToolboxWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ToolboxWidget(QWidget *parent = nullptr);

private:
    QListWidget *listWidget;
    void populateTools();
};

#endif // TOOLBOXWIDGET_H