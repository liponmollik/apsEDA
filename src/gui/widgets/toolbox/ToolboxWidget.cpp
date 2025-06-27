// ToolboxWidget.cpp
#include "ToolboxWidget.h"
#include <QVBoxLayout>
#include <QDrag>
#include <QMimeData>

ToolboxWidget::ToolboxWidget(QWidget *parent) : QWidget(parent)
{
    listWidget = new QListWidget(this);
    listWidget->setDragEnabled(true);
    populateTools();

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(listWidget);
    setLayout(layout);
}

void ToolboxWidget::populateTools()
{
    listWidget->addItem("NAND_GATE");
    listWidget->addItem("OR_GATE");
    listWidget->addItem("FLIP_FLOP");
}