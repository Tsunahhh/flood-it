//
// Created by tsuna on 24/09/24.
//
#include "GameView.h"

#include <iostream>

view::GameView::GameView(QWidget *parent) : QTableWidget(parent) {
    setRowCount(10);
    setColumnCount(10);
    setShowGrid(false);
    setGeometry(QRect(0, 0, 10 * 50, 10 * 50));

    setEditTriggers(QAbstractItemView::NoEditTriggers);
    setSelectionMode(QAbstractItemView::NoSelection);
    horizontalHeader()->setVisible(false);
    verticalHeader()->setVisible(false);

    for (int i = 0; i < 10; i++) {
        setRowHeight(i, 50);
    }

    for (int i = 0; i < 10; i++) {
        setColumnWidth(i, 50);
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            auto *item = new QTableWidgetItem();
            item->setBackground(QBrush(QColor(255, 0, 0)));
            setItem(i, j, item);
        }
    }

    connect(this, &QTableWidget::cellClicked, this, GameView::onCellClicked);
    setStyleSheet("QTableWidget { border: none; } QTableWidget::item { padding: 0; margin: 0;}");
}

view::GameView::GameView(QWidget *parent, int row, int col) : QTableWidget(parent), _row(row), _col(col) {
    setRowCount(_row);
    setColumnCount(_col);

    setGeometry(QRect(0, 0, _WIDTH_WINDOW, _HEIGHT_WINDOW));
    setEditTriggers(QAbstractItemView::NoEditTriggers);
    setSelectionMode(QAbstractItemView::NoSelection);
    horizontalHeader()->setVisible(false);
    verticalHeader()->setVisible(false);



    for (int i = 0; i < _row; i++) {
        setRowHeight(i, _HEIGHT_WINDOW / _row);
    }

    for (int i = 0; i < _col; i++) {
        setColumnWidth(i, _WIDTH_WINDOW / _col);
    }

    for (int i = 0; i < _row; i++) {
        for (int j = 0; j < _col; j++) {
            auto *item = new QTableWidgetItem();
            item->setBackground(QBrush(QColor(255, 255, 255)));
            setItem(i, j, item);
        }
    }

    connect(this, &QTableWidget::cellClicked, this, GameView::onCellClicked);
    setStyleSheet("QTableWidget { border: none; } QTableWidget::item { padding: 0; margin: 0;}");
}

void view::GameView::onCellClicked(int row, int col) {
    QMessageBox::information(this, "Cell Clicked", QString("Row: %1, Column: %2").arg(row).arg(col));
}
