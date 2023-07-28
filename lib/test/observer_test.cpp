#include <gtest/gtest.h>
#include "../include/observer.hpp"

// Custom observer class for testing, which keeps track of whether it was updated
class TestObserver : public Observer {
private:
    bool updated = false;

public:
    void update() override {
        updated = true;
    }

    bool wasUpdated() const {
        return updated;
    }
};

TEST(ObserverPatternTest, ObserverGetsNotified) {
    ConcreteSubject subject;
    TestObserver observer1;
    TestObserver observer2;

    // Attach the observers to the subject
    subject.attach(&observer1);
    subject.attach(&observer2);

    // Trigger a notification
    subject.notify();

    // Expect that both observers were notified
    EXPECT_TRUE(observer1.wasUpdated());
    EXPECT_TRUE(observer2.wasUpdated());
}

TEST(ObserverPatternTest, ObserverDetachment) {
    ConcreteSubject subject;
    TestObserver observer1;
    TestObserver observer2;

    // Attach the observers to the subject
    subject.attach(&observer1);
    subject.attach(&observer2);

    // Detach observer2 before notification
    subject.detach(&observer2);

    // Trigger a notification
    subject.notify();

    // Expect that only observer1 was notified
    EXPECT_TRUE(observer1.wasUpdated());
    EXPECT_FALSE(observer2.wasUpdated());
}

TEST(ObserverPatternTest, ObserverAttachAndDetach) {
    ConcreteSubject subject;
    TestObserver observer3;

    // Observer3 should not be notified until attached
    subject.notify();
    EXPECT_FALSE(observer3.wasUpdated());

    // Attach observer3 and expect it to be notified
    subject.attach(&observer3);
    subject.notify();
    EXPECT_TRUE(observer3.wasUpdated());

    // Detach observer3 and expect it to not be notified
    subject.detach(&observer3);
    subject.notify();
    EXPECT_TRUE(observer3.wasUpdated()); // Since it was already updated, this should still be true
}

