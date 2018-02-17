// Copyright 2018 <maojr@gmx.com>
// C++ constructors that have just one parameter automatically perform implicit type conversion.
// For example, if you pass an int when the constructor expects a string pointer parameter,
// the compiler will add the code it must have to convert the int to a string pointer.
// However, you might not always want this automatic behavior.

// You can add explicit to the constructor declaration to prevent implicit conversions.
// This forces the code to either use a parameter of the correct type, or cast the parameter to the correct type.
// That is, if the cast is not visibly expressed in code, an error will result.

// The explicit keyword can only be applied to in-class constructor declarations to explicitly construct an object.

#include <iostream>

class Number {
 public:
    explicit Number(int num) : val(num) {}
    explicit Number(const Number&);
    void print();
 private:
    int val;
};

void Number::print() {
    std::cout << "Number val: " << this->val << std::endl;
}

Number::Number(const Number& num) {
    this->val = num.val;
}

void printIn(Number i) {
    i.print();
}

int main() {
    Number a(11);
    a.print();

    Number b(a);
    // Number c = a;  // compile error: for the explicit copy constructor, no matching constructor for initialization
    // printIn(a);    // compile error: for the explicit copy constructor, no matching constructor for initialization

    // Number m = 11; // compile error: no viable conversion from 'int' to 'Number'
    // printIn(133);  // candidate function not viable: no known conversion from 'int' to 'Number' for 1st argument
    return 0;
}
