#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include "Observer.h"

/**
 * @file Observable.h
 * @brief Defines the Observable class, which provides an interface for the Observer design pattern.
 */

/**
 * @namespace utils
 * @brief Namespace containing all utils files of the Flood It application.
 *
 * The `utils` namespace groups all the classes responsible for utils functions
 * of the game like Observer/able.
 */
namespace utils {

    /**
     * @class Observable
     * @brief The Observable class provides an interface for observable objects that can notify observers of changes.
     *
     * This class serves as a base for any object that needs to maintain a list of observers and notify them
     * when its state changes. It defines the necessary methods to add, remove, and notify observers.
     */
    class Observable {
    public:
        /**
         * @brief Default destructor for the Observable class.
         */
        virtual ~Observable() = default;

        /**
         * @brief Adds an observer to the list of observers.
         *
         * This method is used to register an observer that will be notified when the observable's state changes.
         *
         * @param obs Pointer to the observer to be added.
         */
        virtual void addObserver(Observer* obs) = 0;

        /**
         * @brief Removes an observer from the list of observers.
         *
         * This method is used to unregister an observer so that it no longer receives notifications of state changes.
         *
         * @param obs Pointer to the observer to be removed.
         */
        virtual void removeObserver(Observer* obs) = 0;

        /**
         * @brief Notifies all registered observers of a state change.
         *
         * This method is called to inform all observers that the observable's state has changed.
         */
        virtual void notifyObserver() = 0;
    };
}

#endif //OBSERVABLE_H
