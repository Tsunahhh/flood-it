//
// Created by tsuna on 19/10/2024.
//

#ifndef OBSERVABLE_H
#define OBSERVABLE_H
#include "Observer.h"

namespace utils {
    class Observable {
    public:
        virtual ~Observable() = default;
        virtual void addObserver(Observer* obs) = 0;
        virtual void removeObserver(Observer* obs) = 0;
        virtual void notifyObserver() = 0;
    };
}


#endif //OBSERVABLE_H
