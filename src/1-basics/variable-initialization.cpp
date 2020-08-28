#include <iostream>

int main () 
{
    // variables can be assigned w/ the assignment operator
    int some_value = 1;
    // this is called copy assignment because we're copying a literal over into a variable

    // variables can also be created w/ direct initialization (parenthesis)
    float some_float_value(2.0f);

    // brace initializtion is initialization with {} braces
    // this method is copy
    char some_string[] = {"hello, world"};

    // this method is direct
    char some_other_string[]{"gang gang"};

    // brace initialization good because it prevents you from doing stuff like
    //int another_value{3.5f};
    // normally, direct and copy initialization will drop the fractional component, which is yikes
    // brace initialization will throw an error instead

    // you can initialize multiple values at a time
    int a, b, c, d;

    // you do not necessarily have to assign a value, but you could also zero initialize it
    float zero_initialize{};
    double zero_init_but_with_zero{0};
    // better to assign the zero when its actually being used, empty is better for a temporary assignment value

    // the following doesn't work
    int a_, b_ = 10;
    // only b is initialized, we should be doing
    int a__ = 10, b__ = 10;
    // also note that uninitialized variables are not zero-initialized by default
    // if you did something like std::cout an uninitialized variable, you'll probably
    // get garbage values from the memory previously stored at that location

    // overall, should use direct brace initialization because of the protection
    // and also because you avoid the silly error of <type> name1, name2 = value;

    std::cout << some_value << '\n';
    std::cout << some_float_value << '\n';
    std::cout << some_string << '\n';
    std::cout << some_other_string << '\n';
    std::cout << zero_initialize << '\t' << zero_init_but_with_zero << '\n';
    std::cout << a_ << '\t' << b_ << '\n';
    std::cout << a__ << '\t' << b__ << '\n';

    return 0;
}