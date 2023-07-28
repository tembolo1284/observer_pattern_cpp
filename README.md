# observer_pattern_cpp

In quantitative finance, the Observer design pattern is a popular choice in C++. The Observer pattern is a behavioral design pattern that allows an object, known as the subject, to maintain a list of its dependents, called observers, and notify them automatically of any state changes. This pattern is useful in various financial applications, such as modeling real-time market data, managing portfolios, and handling event-driven systems.

In the context of quantitative finance, the Observer pattern is commonly used for implementing event handling and updating views based on changes in underlying data. Here's how it works:

Subject: The subject is an object that holds the data of interest. It maintains a list of its observers and provides methods to attach, detach, and notify them.

Observer: The observer is an interface or abstract class that defines the update method. Observers register with the subject to receive notifications when the subject's state changes.

Concrete Subject: A specific implementation of the subject that holds the actual financial data or information. It notifies its registered observers when there's a relevant update.

Concrete Observer: A specific implementation of the observer that receives notifications from the subject and updates its view or performs necessary calculations based on the new data.

Using the Observer pattern helps decouple the subject and observer objects, promoting flexibility and maintainability. It allows for easy addition or removal of observers without affecting the subject's core functionality. Furthermore, it simplifies the handling of asynchronous events and data updates.


- `include/observer.hpp`: Header file containing the `Observer` and `ConcreteSubject` classes implementing the Observer pattern.
- `src/observer.cpp`: Source file containing the implementation of the methods in `observer.hpp`.
- `tests/observer_test.cpp`: Test file using Google Test to verify the functionality of the Observer pattern.
- `main.cpp`: The main program file where you can use the Observer pattern.

## Building and Running

Follow the steps below to build and run the project:

1. Build the project by typing in `bazel build src:Main`
2. Run the project by typing in `bazel run src:Main`
3. You can build the project manually with g++ by typing in `g++ -I lib/include src/main.cpp lib/src/*.cpp -o main`

## Usage

To use the Observer pattern in your own project:

1. Include the `observer.hpp` header file in your source files where you want to implement the Observer pattern.
2. Create a concrete subject class (`ConcreteSubject`) that maintains a list of observers and provides methods to attach, detach, and notify them.
3. Create observer classes (`Observer`) that implement the `update` method to handle notifications from the subject.
4. In your application, instantiate the subject and observers, attach the observers to the subject, and call the `notify` method on the subject whenever its state changes.

Refer to the example in `main.cpp` to see how to use the Observer pattern in a quantitative finance context.

## Testing

The project includes unit tests for verifying the correctness of the Observer pattern implementation. To run the tests, simply type 
`bazel test lib/test:Observer_Test`

