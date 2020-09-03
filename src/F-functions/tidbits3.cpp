#include <iostream>
#include <cmath>
#include <tuple>


// we can use tuples to return as many values as we want

auto return_trig_ratios(double x) -> std::tuple<double, double, double>
{
    return{ sin(x), cos(x), tan(x) };
}


auto main() -> int
{
    double var {0.5};

    // we can store the return values like this
    std::tuple tup_var {return_trig_ratios(var)};
    // and then access them like so
    std::cout << std::get<0>(tup_var) << '\t';
    std::cout << std::get<1>(tup_var) << '\t';
    std::cout << std::get<2>(tup_var) << '\n';

    // or we can store them like this
    double sin_, cos_, tan_;
    std::tie(sin_, cos_, tan_) = return_trig_ratios(var);
    std::cout << sin_ << '\t' << cos_ << '\t' << tan_ << '\n';

    // or, since C++17, we can do this instead.
    auto [sin__, cos__, tan__]{return_trig_ratios(var)};
    std::cout << sin__ << '\t' << cos__ << '\t' << tan__ << '\n';

    // there are other ways of doing this, such as a return structure or using out parameters.
    // out perameters should be seldom used. structs can be used when the struct can be reused (non-trival use)
    // tuples are good otherwise.
    return 0;
}