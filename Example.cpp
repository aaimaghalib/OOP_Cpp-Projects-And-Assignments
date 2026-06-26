#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    void eat() {
        cout << "Animal is eating." << endl;
    }
};

// Derived class
class Dog : public Animal {
public:
    void bark() {
        cout << "Dog is barking." << endl;
    }
};

int main() {
    // Create an object of the derived class
    Dog myDog;
    
    // Access the member functions of the base class
    myDog.eat();
    
    // Access the member functions of the derived class
    myDog.bark();
    
    return 0;
}

