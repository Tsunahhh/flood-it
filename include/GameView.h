//
// Created by tsuna on 19/10/2024.
//

#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QTableWidget>
#include <QTableWidgetItem>
#include <QBrush>
#include <QColor>
#include <QHeaderView>
#include <QMessageBox>

namespace view {
    class GameView : public QTableWidget {
        Q_OBJECT
            int _col;
            int _row;
            int _WIDTH_WINDOW{500};
            int _HEIGHT_WINDOW{500};

        public:
            explicit GameView(QWidget *parent = nullptr);
            GameView(QWidget *parent = nullptr, int row=5, int col=5);
        private slots:
            void onCellClicked(int row, int column);
    };
}


#endif //GAMEVIEW_H
