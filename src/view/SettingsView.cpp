//
// Created by tsuna on 23/10/2024.
//

#include "SettingsView.h"

view::SettingsView::SettingsView(QWidget *parent) :
_settings{},
_settingsLayout{new QGridLayout{this}},
_widthSB{nullptr},
_heightSB{nullptr}
{
    initLabels();
    initSettings();
    setLayout(_settingsLayout);
    _settingsLayout->setSpacing(20);
}

void view::SettingsView::initLabels() {
    _settingsLBL = new QLabel("Settings", this);
    _settingsLBL->setStyleSheet("font-size: 30px; font-weight: bolder;");
    _settingsLayout->addWidget(_settingsLBL, 0, 0, 1, 2);
    _widthLBL = new QLabel("Width: ", this);
    _settingsLayout->addWidget(_widthLBL, 2, 0, 1, 1);
    _heightLBL = new QLabel("Height: ", this);
    _settingsLayout->addWidget(_heightLBL, 3, 0, 1, 1);
    _colorsLBL = new QLabel("Nombre de couleurs: ", this);
    _settingsLayout->addWidget(_colorsLBL, 4, 0, 1, 1);
}

void view::SettingsView::initSettings() {
    _widthSB = new QSpinBox(this);
    _widthSB->setValue(DEFAULT_WIDTH);
    _widthSB->setMinimum(MIN_SIZE);
    _widthSB->setMaximum(MAX_SIZE),
    _settingsLayout->addWidget(_widthSB, 2, 1, 1, 1);

    _heightSB = new QSpinBox(this);
    _heightSB->setValue(DEFAULT_HEIGHT);
    _heightSB->setMinimum(MIN_SIZE);
    _heightSB->setMaximum(MAX_SIZE);
    _settingsLayout->addWidget(_heightSB, 3, 1, 1, 1);

    _colorsSB = new QSpinBox(this);
    _colorsSB->setValue(5);
    _colorsSB->setMinimum(MIN_COLORS);
    _colorsSB->setMaximum(MAX_COLORS);
    _settingsLayout->addWidget(_colorsSB, 4, 1, 1, 1);

    _playBT = new QPushButton("Play", this);
    _settingsLayout->addWidget(_playBT, 5, 0, 1, 1);
    _leaveBT = new QPushButton("Leave", this);
    _settingsLayout->addWidget(_leaveBT, 5, 1, 1, 1);

    // Connect buttons with the methods
    connect(_playBT, &QPushButton::clicked, this, &SettingsView::play);
    connect(_leaveBT, &QPushButton::clicked, this, &SettingsView::leave);
}

model::Settings view::SettingsView::getSettings() {
    return {
        _widthSB->value(),
        _heightSB->value(),
        _colorsSB->value(),
        0
    };
}

view::SettingsView::~SettingsView() {

}







