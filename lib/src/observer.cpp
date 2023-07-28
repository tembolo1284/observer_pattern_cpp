#include "../include/observer.hpp"
#include <algorithm>
#include <iostream>

void Subject::attach(Observer* observer) {
    observers.push_back(observer);
}

void Subject::detach(Observer* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void Subject::notify() {
    for (Observer* observer : observers) {
        observer->update();
    }
}

//void ConcreteSubject::ConcreteSubject()  {}

// ConcreteObserver class implementation
//ConcreteObserver::ConcreteObserver() : subject(nullptr) {}

ConcreteObserver::ConcreteObserver(ConcreteSubject* subject) : subject(subject) {
    subject->attach(this);
}

void ConcreteObserver::update() {
    // Perform necessary calculations or update the view based on the subject's data
    std::cout << "Received update from the subject!" << "\n";
}
