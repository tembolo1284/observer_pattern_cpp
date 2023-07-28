#ifndef OBSERVER_HPP
#define OBSERVER_HPP
#include <vector>

class Observer {
public:
    virtual void update() = 0;
};

class Subject {
private:
    std::vector<Observer*> observers;

public:
    void attach(Observer* observer);
    void detach(Observer* observer);
    void notify();
};

class ConcreteSubject : public Subject {
private:
    // Financial data or relevant information

public:
    // Methods to update data and trigger notification to observers
};

class ConcreteObserver : public Observer {
private:
    ConcreteSubject* subject; // Reference to the subject being observed

public:
	//ConcreteObserver();
    ConcreteObserver(ConcreteSubject* subject);
    void update() override;
};

#endif // OBSERVER_HPP
