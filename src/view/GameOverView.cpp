//
// Created by tsuna on 22/10/2024.
//
#include "GameOverView.h"

#include <utility>


view::GameOverView::GameOverView(const model::Settings &settings, QWidget *parent) :

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
    int bestSc = getBestScore();

    std::string scoreStr;
    if (bestSc >= _settings.score) {
        scoreStr = "Tu as battu le record! \n Ton score: " + std::to_string(_settings.score);
    } else {
        scoreStr = "Tu n'as pas battu le record! \n Ton score: " + std::to_string(_settings.score);
    }

    _scoreLBL = new QLabel(QString::fromStdString(scoreStr), this);
    _scoreLBL->setAlignment(Qt::AlignCenter);
    _scoreLBL->setStyleSheet("font-size: 20px; font-weight: bolder;");
    _layout->addWidget(_scoreLBL);


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


void view::GameOverView::saveSettingsRecords(const std::string& filename) {
    std::ofstream outFile(filename, std::ios::binary);
    if (!outFile) {
        std::cerr << "Erreur lors de l'ouverture du fichier !" << std::endl;
        return;
    }

    size_t size = _states.size();
    outFile.write(reinterpret_cast<const char*>(&size), sizeof(size));

    for (const auto& settings : _states) {
        saveSettings(outFile, settings);
    }

    outFile.close();
}

void view::GameOverView::saveSettings(std::ofstream &outFile, const model::Settings &settings) {
    outFile.write(reinterpret_cast<const char*>(&settings.width), sizeof(settings.width));
    outFile.write(reinterpret_cast<const char*>(&settings.height), sizeof(settings.height));
    outFile.write(reinterpret_cast<const char*>(&settings.colors), sizeof(settings.colors));
    outFile.write(reinterpret_cast<const char*>(&settings.score), sizeof(settings.score));
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

int view::GameOverView::getBestScore() const {
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



