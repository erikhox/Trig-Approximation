#include <iostream>
#include "approx.h"

int main() {
    double x{};
    int y{};
    std::cout << "enter the value you wish to approximate: \n";
    std::cin >> x;
    std::cout << "enter the level of precision: \n";
    std::cin >> y;
    std::cout << "cosine of " << x << " is approximatly " << cosine(x, y) << '\n';
    std::cout << "sine of " << x << " is approximatly " << sine(x, y) << '\n';
    if (tangent(x, y) == -0) {
        std::cout << "tangent of " << x << " is approximatly " << 0 << '\n';
    } else {
        std::cout << "tangent of " << x << " is approximatly " << tangent(x, y) << '\n';
    }
    return 0;
}