//
// Created by tsuna on 22/10/24.
//

#ifndef SETTINGSVIEW_H
#define SETTINGSVIEW_H

#include <QWidget>
#include <QSpinBox>
#include <QCheckBox>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

#include "Settings.h"

namespace view {
    class SettingsView : public QWidget {
        Q_OBJECT

        static const int MAX_SIZE{80};
        static const int MIN_SIZE{2};
        static const int DEFAULT_WIDTH{10};
        static const int DEFAULT_HEIGHT{10};
        static const int MAX_COLORS{10};
        static const int MIN_COLORS{3};

        model::Settings _settings;
        QGridLayout *_settingsLayout;

        QLabel *_settingsLBL;
        QLabel *_pseudoLBL;
        QLabel *_widthLBL;
        QLabel *_heightLBL;
        QLabel *_colorsLBL;

        QLineEdit *_pseudoLE;
        QSpinBox *_widthSB;
        QSpinBox *_heightSB;
        QSpinBox *_colorsSB;

        QPushButton *_playBT;
        QPushButton *_leaveBT;
    public:
        explicit SettingsView(QWidget *parent = nullptr);
        void initLabels();
        void initSettings();
        void leave();
        model::Settings getSettings();
        ~SettingsView();
    signals:
        void play();

    };
}

#endif //SETTINGSVIEW_H
