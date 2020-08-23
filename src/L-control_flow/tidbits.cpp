#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>

// file is just for some tidbits from control flow examples i mostly knew
// but didn't know some other small things

using cin_ignore = std::numeric_limits<std::streamsize>;

auto check_if_perfect_square(double x) -> bool
{
    // you can do variable initialization in an if statement for use
    // in the conditional and the rest of the block
    // since C++17

    if (double y{std::sqrt(x)}; (std::floor(y) == y) || (std::ceil(y) == y))
    {
        return true;
    }
    else
    {
        return false;
    }
}

auto get_double() -> double
{
    while (true)
    {
        std::cout << "Enter a double: ";
        double x{};
        std::cin >> x;

        // this is some nice input sanitization practice
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(cin_ignore::max(), '\n');
            std::cout << "Invalid input: not a double.\n";
        }
        else
        {
            std::cin.ignore(cin_ignore::max(), '\n');
            return x;
        }
        // i mean i could also just grab a string then parse it but that's too much effort
    }
}

auto wow_for_loops_doe() -> void
{
    // can do multiple values in a for loop
    for (int i{0}, j{9}; i <= 9; ++i, --j)
    {
        std::cout << i << '\t' << j << '\n';
    }

    std::cout << '\n';

    // can also omit values
    int k{0};
    for ( ; k <= 9; )
    {
        std::cout << k << '\n';
        ++k;
    }

    std::cout << '\n';

    // continue ends 1 iteration of the loop early
    for (int i{0}; i <= 20; ++i)
    {
        if (i % 4 != 0)
            continue;
        
        std::cout << i << '\n';
    }
}

// also note:
//      - breaks break the loop and continues execution at the first statement
//        beyond the loop
//      - returns stop the entire function and it continues execution at the first statement
//        after the function call

// not covering goto statements because they are bad and stupid and stupid and bad
// random number generation is whatever

auto main() -> int
{
    std::cout << std::boolalpha;
    bool is_perfect_sqaure{check_if_perfect_square(get_double())};
    std::cout << "Is the number you entered a perfect square? " << is_perfect_sqaure << '\n';
    wow_for_loops_doe();
    return 0;
}