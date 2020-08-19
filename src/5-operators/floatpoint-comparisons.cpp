#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

// turns out, floating point precision kinda sucks sometimes

void float_comparison_exact()
{
    double d1{100.0 - 99.99};       // this should be 0.01
    double d2{10.0 - 9.99};         // this also should be 0.01

    std::cout << std::setprecision(16);
    std::cout << "the value of d1 is: " << d1 << "\n";
    std::cout << "the value of d2 is: " << d2 << "\n";

    if (d1 == d2)
        std::cout << "d1 == d2\n";
    else if (d1 > d2)
        std::cout << "d1 > d2\n";
    else if (d1 < d2)
        std::cout << "d1 < d2\n";
}

// this happens because computers are binary systems, only 0s and 1s, so we
// operate on a base 2 system.
// it is hard to finitely define some decimals in a base 2 system in scientific
// notation and thus rounding errors occur.
// we can get around this through the use of approximate comparisons
// this is one naive approach

bool naive_approx_compare(double a, double b, double epsilon)
{
    return std::abs(a - b) <= epsilon;
}
// this one is okay but like it gets suckier for the larger and smaller numbers
// plus we have to constantly change epsilon based on the size of the numbers
// this is a better approach by Donald Knuth

bool knuth_approx_compare(double a, double b, double epsilon)
{
    return (std::abs(a - b) <= (std::max(std::abs(a), std::abs(b)) * epsilon));
}
// we now input a percentage for epsilon and it automatically changes it in proportion
// to how large the numbers are.
// its not perfect though because the math breaks down when numbers approach 0
// in that case, we can use both the naive and knuth approach to create an all inclusive
// comparison function

bool hybrid_approx_compare(double a, double b, double absEpsilon, double relEpsilon)
{
    double diff{std::abs(a - b)};

    // check if they're close, if they are, use an absolute comparison
    if (diff <= absEpsilon)
        return true;
    
    // otherwise default to Knuth's algorithm
    return (std::abs(a - b) <= (std::max(std::abs(a), std::abs(b)) * relEpsilon));
}

int main()
{
    std::cout << std::boolalpha;
    double a{0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1};
    double b{1.0};
    double c{0.0};

    std::cout << naive_approx_compare(a, b, 1e-12)              << "\n";
    std::cout << naive_approx_compare(a - b, c, 1e-12)          << "\n";
    std::cout << knuth_approx_compare(a, b, 1e-8)               << "\n";
    std::cout << knuth_approx_compare(a - b, c, 1e-8)           << "\n";
    std::cout << hybrid_approx_compare(a, b, 1e-12, 1e-8)       << "\n";
    std::cout << hybrid_approx_compare(a - b, c, 1e-12, 1e-8)   << "\n";
    float_comparison_exact();
    return 0;
}