# Service Locator (Pattern)

## About

The "Service Locator" design pattern is a structure which you can register objects with that lives in the global scope of a program. Once an object has been registered with it, a reference to that object can be retrieved from anywhere in the program.

## How To Use This Pattern Correctly

This design pattern is a reaction to a common issue when developing complex applications such as video games where you need access to a particular object in many parts of the application. This can result in passing around the object through many functions, which can become cumbersome. A classic example of this is a logging structure, which you will benefit from having access to in almost every function of the program.

## How to Misuse This Pattern

1. There should usually only ever be one service locator of a given type, and it should be in the global scope. If it isn't in the global scope, you'll have to pass around the owning object. This eliminates the usefulness of the service locator.

2. You should only use a service locator once you know (or can reasonably predict) a certain object will need to be accessed often and throughout the program.

3. Over-using the service locator can result in *everything* in your program becoming global scoped. That will create a mess. So always use it sparingly.

## Example Explanation

In this example repository:
1. I've created a base class interface of `Logging` which implements one virtual function. (`Logging_struct.h`)
2. I've then created a derived class `ExampleLog` which implements the interface. (`ExampleLog_struct.h`)
3. I've created a service locator, `LogLocator` which stores pointers of `Logging` type. (`LogLocator_struct.h` and `LogLocator_struct.cpp`)
4. In the main file I've created an `ExampleLog`, registered it with the `LogLocator` instance and then retrievied its pointer before calling the interface method on it. (`main.cpp`)

## More Information
1. [Service Locator Pattern (Wikipedia)](https://en.wikipedia.org/wiki/Service_locator_pattern)
2. [Service Locator Pattern - Game Programming Patterns](https://gameprogrammingpatterns.com/service-locator.html)