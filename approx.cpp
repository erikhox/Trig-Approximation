#include <iostream>
#include "approx.h"
#include "debug.h"

[[maybe_unused]] constexpr double pi{3.14159265358979323846};

// Computers base to the power of exponent
double power(double base, int exponent) {
#ifdef ENABLE_DEBUG
    std::cerr << "power(x, y) called\n:";
#endif

    double result { 1 };
    for (int i = 0; i < exponent; i++) {
            result *= base;
    }
    return result;
}


// computes the factorial of num
double factorial(int num) {
#ifdef ENABLE_DEBUG
    std::cerr << "factorial(x) called\n:";
#endif
    double factorial{ 1.0 };
    for (int i = 1; i <= num; i++) {
        factorial *= i;
    }
    return factorial;
}

// uses taylor series approximation of cosine to approximate "approx" and with the n value of "precision"
double cosine(double approx, int precision) {
#ifdef ENABLE_DEBUG
    std::cerr << "cosine(approx, precision) called\n:";
#endif
    double approxValue { 0.0 };
    for (int n = 0; n <= precision; n++) {
        double numerator = power(-1.0, n) * power(approx, 2 * n);
        double denominator = factorial(2 * n);
        double tempValue = numerator / denominator;
        approxValue += tempValue;
    }
    if (approxValue < 0.001 && approxValue > -0.001) {
        approxValue = 0;
    }
    return approxValue;
}

// uses taylor series approximation of sine to approximate "approx" and with the n value of "precision"
double sine(double approx, int precision) {
#ifdef ENABLE_DEBUG
    std::cerr << "sine(approx, precision) called\n:";
#endif
    double approxValue { 0.0 };
    for (int n = 0; n <= precision; n++) {
        double numerator = power(-1.0, n) * power(approx, (2 * n) + 1);
        double denominator = factorial((2 * n) + 1);
        double tempValue = numerator / denominator;
        approxValue += tempValue;
    }
    if (approxValue < 0.001 && approxValue > -0.001) {
        approxValue = 0;
    }
    return approxValue;
}

// uses taylor series approximation of sine and cosine to approximate "approx" and with the n value of "precision"
double tangent(double approx, int precision) {
#ifdef ENABLE_DEBUG
    std::cerr << "tangent(approx, precision) called\n:";
#endif
    double approxValue = sine(approx, precision) / cosine(approx, precision);
    return approxValue;
}