#include <iostream>

int power(int a, int b) {
    // Base case: if b is 0, return 1
    if (b == 0) {
        return 1;
    }

    // Recursive case: if b is even
    if (b % 2 == 0) {
        int temp = power(a, b / 2);
        return temp * temp;
    }
    // Recursive case: if b is odd
    else {
        int temp = power(a, b / 2);
        return a * temp * temp;
    }
}

int main() {
    int a = 3, b = 5;
    std::cout << "Compute " << a << "^" << b << std::endl;
    int result = power(a, b);
    std::cout << "Result: " << result << std::endl;
    return 0;
}