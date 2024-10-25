//
// Created by tsuna on 22/10/2024.
//
#include "GameOverView.h"

#include <utility>


view::GameOverView::GameOverView(model::Settings settings, QWidget *parent) :

QWidget{parent},
_settings{settings},
_states{},
_layout{new QVBoxLayout(this)}

{
    loadSettingsRecords(FILE_PATH);
    initLBL();
    initBTN();
    _states.push_back(settings);
    saveSettingsRecords(FILE_PATH);
}

void view::GameOverView::initLBL() {
    _gameOverLBL = new QLabel("Partie terminée !", this);
    _gameOverLBL->setAlignment(Qt::AlignCenter);
    _gameOverLBL->setStyleSheet("font-size: 32px; font-weight: bolder;");
    _layout->addWidget(_gameOverLBL);

    std::string scoreStr = "Score: " + std::to_string(_settings.score);
    _scoreLBL = new QLabel(QString::fromStdString(scoreStr), this);
    _scoreLBL->setAlignment(Qt::AlignCenter);
    _scoreLBL->setStyleSheet("font-size: 20px; font-weight: bolder;");
    _layout->addWidget(_scoreLBL);

    int bestSc = getBestScore();
    std::string recordStr = "Le record est de " + std::to_string(bestSc);
    _recordLBL = new QLabel(QString::fromStdString(recordStr), this);
    _recordLBL->setAlignment(Qt::AlignCenter);
    _recordLBL->setStyleSheet("font-size: 20px; font-weight: bolder;");
    _layout->addWidget(_recordLBL);
}

void view::GameOverView::initBTN() {
    _buttonWidget = new QWidget(this);
    _buttonLayout = new QHBoxLayout(_buttonWidget);

    _buttonLayout->setSpacing(5);
    _buttonLayout->setAlignment(Qt::AlignCenter);

    _replayBT = new QPushButton("Replay", this);
    _buttonLayout->addWidget(_replayBT);

    _settingBT = new QPushButton("Settings", this);
    _buttonLayout->addWidget(_settingBT);

    _leaveBT = new QPushButton("Leave", this);
    _buttonLayout->addWidget(_leaveBT);

    connect(_replayBT, &QPushButton::clicked, this, &GameOverView::replay);
    connect(_settingBT, &QPushButton::clicked, this, &GameOverView::settings);
    connect(_leaveBT, &QPushButton::clicked, this, &GameOverView::leave);

    _buttonWidget->setLayout(_buttonLayout);
    _layout->addWidget(_buttonWidget);
}

void view::GameOverView::loadSettingsRecords(const std::string& filename) {
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile) {
        std::cerr << "Erreur lors de l'ouverture du fichier !" << std::endl;
        _states.clear();
        return;
    }

    size_t size;
    inFile.read(reinterpret_cast<char*>(&size), sizeof(size));

    _states.resize(size);

    for (size_t i = 0; i < size; ++i) {
        _states[i] = loadSettings(inFile);
    }

    inFile.close();
}

void view::GameOverView::saveSettingsRecords(const std::string& filename) {
    std::ofstream outFile(filename, std::ios::binary);
    if (!outFile) {
        std::cerr << "Erreur lors de l'ouverture du fichier !" << std::endl;
        return;
    }

    size_t size = _states.size();
    outFile.write(reinterpret_cast<const char*>(&size), sizeof(size));

    for (const auto& settings : _states) {
        saveSettings(outFile);
    }

    outFile.close();
}

model::Settings view::GameOverView::loadSettings(std::ifstream &inFile) {
    model::Settings settings;

    if (!(inFile.read(reinterpret_cast<char*>(&settings.width), sizeof(settings.width))) ||
        !(inFile.read(reinterpret_cast<char*>(&settings.height), sizeof(settings.height))) ||
        !(inFile.read(reinterpret_cast<char*>(&settings.colors), sizeof(settings.colors))) ||
        !(inFile.read(reinterpret_cast<char*>(&settings.score), sizeof(settings.score)))) {
        std::cerr << "Erreur lors de la lecture des paramètres !" << std::endl;
        return settings;
    }

    return settings;
}


void view::GameOverView::saveSettings(std::ofstream &outFile) {
    outFile.write(reinterpret_cast<const char*>(&_settings.width), sizeof(_settings.width));
    outFile.write(reinterpret_cast<const char*>(&_settings.height), sizeof(_settings.height));
    outFile.write(reinterpret_cast<const char*>(&_settings.colors), sizeof(_settings.colors));
    outFile.write(reinterpret_cast<const char*>(&_settings.score), sizeof(_settings.score));
}

int view::GameOverView::getBestScore() {
    if (_states.empty()) {
        return _settings.score;
    }

    int best = _settings.score;
    for (const model::Settings& st : _states) {
        if (st.height == _settings.height && st.width == _settings.width && st.colors == _settings.colors) {
            if (best >= st.score) {
                best = st.score;
            }
        }
    }
    return best;
}



