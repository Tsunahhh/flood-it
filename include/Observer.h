//
// Created by tsuna on 19/10/2024.
//

#ifndef OBSERVER_H
#define OBSERVER_H

namespace utils {
    class Observer {
    public:
        virtual ~Observer() = default;
        virtual void updateObs() = 0;
    };
}

#endif //OBSERVER_H
