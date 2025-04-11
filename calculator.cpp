#include "calculator.h"
#include <stdexcept>
#include <limits>

int max = std::numeric_limits<int>::max();
int min = std::numeric_limits<int>::min();

int Calculator::add(int a, int b) {
    // TODO
    if((b > 0 &&  a > max - b) || (b < 0 && a < min - b)) {
        throw std::overflow_error("Add Overflow occured");
    }
    return a+b;
}

int Calculator::sub(int a, int b) {
    // TODO
    if((b < 0 && a > max + b) || (b > 0 && a < min + b)) {
        throw std::overflow_error("Sub Overflow occured");
    }
    return a-b;
}

int Calculator::mul(int a, int b) {
    // TODO
    if((b > 0 && (a > max/b || a < min/b) || (b<0 && (a > min/b || a < max/b)))) {
        throw std::overflow_error("Mul Overflow occured");
    }
    return a*b;
}

int Calculator::div(int a, int b) {
    // TODO
    if(b == 0) {
        throw std::invalid_argument("Division by zero");
    }
    if((a == min && b == -1) || (a == -1 && b == min)) {
        throw std::overflow_error("Mul Overflow occured");
    }
    return a/b;
}