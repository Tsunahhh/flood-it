#ifndef OBSERVER_H
#define OBSERVER_H

/**
 * @file Observer.h
 * @brief Defines the Observer class, which serves as an interface for observing changes in observable objects.
 */

namespace utils {

    /**
     * @class Observer
     * @brief The Observer class serves as an interface for all observers in the Observer design pattern.
     * 
     * This class defines the method that observers must implement to receive updates from observable objects.
     * Any class that needs to be notified of changes in an observable should implement this interface.
     */
    class Observer {
    public:
        /**
         * @brief Default destructor for the Observer class.
         */
        virtual ~Observer() = default;

        /**
         * @brief Updates the observer with the latest changes from the observable.
         * 
         * This method is called by the observable to notify the observer of any changes. 
         * Implementing classes should define their own behavior for handling updates.
         */
        virtual void updateObs() = 0;
    };
}

#endif //OBSERVER_H