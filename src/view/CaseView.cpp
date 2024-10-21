//
// Created by tsuna on 21/10/2024.
//
#include "CaseView.h"

view::CaseView::CaseView(int x, int y, const QColor &color, QWidget *parent) :
        QWidget(parent), _x(x), _y(y)
{
    setAutoFillBackground(true);

    QPalette palette = this->palette();
    palette.setColor(QPalette::Window, color);
    setPalette(palette);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void view::CaseView::mousePressEvent(QMouseEvent *event) {
    emit clicked(_y, _x);
}

void view::CaseView::setColor(const QColor &color) {
    QPalette palette = this->palette();
    palette.setColor(QPalette::Window, color);
    setPalette(palette);
}

