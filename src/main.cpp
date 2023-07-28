#include "../include/observer.hpp"
#include <iostream>

int main() {
    ConcreteSubject subject;
    ConcreteObserver observer1(&subject);
    ConcreteObserver observer2(&subject);
    ConcreteObserver observer3(&subject);

      // Trigger a notification
    std::cout << "Notifying the observers...\n";
    subject.notify();

    // Detach observer2 before notification
    subject.detach(&observer2);

    // Trigger another notification
    std::cout << "Notifying the observers again...\n";
    subject.notify();

    // Attach another observer and notify
    subject.attach(&observer3);
    std::cout << "Notifying the observers after attaching observer3...\n";
    subject.notify();
	
    return 0;
}
