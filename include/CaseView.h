//
// Created by tsuna on 21/10/2024.
//

#ifndef FLOOD_IT_CASEVIEW_H
#define FLOOD_IT_CASEVIEW_H

#include <QWidget>
#include <QPalette>
#include <QMouseEvent>

namespace view {
    class CaseView : public QWidget {
        Q_OBJECT

        int _x;
        int _y;


    public:
        CaseView(int x, int y, const QColor & color, QWidget *parent = nullptr);
        void setColor(const QColor & color);
    signals:
        void clicked(int row, int col);
    protected:
        void mousePressEvent(QMouseEvent * event) override;
    };
}

#endif //FLOOD_IT_CASEVIEW_H
