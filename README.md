# Flood-It
## Description

FloodIt est un jeu de puzzle développé en C++ avec Qt6. Le but du jeu est de remplir une grille de couleurs en un nombre minimal de mouvements, en commençant dans le coin supérieur gauche. Ce projet a été réalisé dans le cadre du cours de ALTIRc5 à la Haute École Bruxelles-Brabant (HE2B), et met en pratique les concepts de programmation orientée objet et de développement d'interfaces graphiques avec Qt.

Framework Used: **Qt6.7.X**

## Fonctionnalités



## Pré-requis
Avant d'installer le projet, assure-toi d'avoir les éléments suivants :

- **Qt6** (minimum 6.7.X requis)
- Un compilateur C++ compatible (mingw_64)

### Installation de Qt6

Si Qt6 n'est pas encore installé, tu peux le télécharger et l'installer depuis le site officiel [Qt](https://www.qt.io/download).

## Structure
```
./
    |->include/
        ->*.h
    |->src/ 
        |->model/
            ->*.cpp
        |->utils
            ->*.cpp
        |->view/
            ->*.cpp
        ->main.cpp
    |->CMakeLists.txt
    |->.gitignore
    |->LICENSE
    |->README.md
```