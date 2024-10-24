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

#include "Settings.h"

namespace view {
    class SettingsView : public QWidget {
        static const int MAX_SIZE{80};
        static const int MIN_SIZE{2};
        static const int DEFAULT_WIDTH{20};
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

    public:
        explicit SettingsView(QWidget *parent = nullptr);
        void initSettings();
        void initLabels();
        model::Settings getSettings();
        ~SettingsView();
    };
}

#endif //SETTINGSVIEW_H
