#include <iostream>
#include <limits>
#include <string>

// in a nutshell, enums are pretty much just user-defined data types
// where every symbolic constant has an automatically assigned
// integer value (although you can assign your own but why tho)
// like so:

enum stateEnum
{
    SUCCESS,
    ERROR
};

// then you can define some variables and stuff, or even use it as a return value

stateEnum some_function(int x)
{
    if (x == 0) 
        return SUCCESS;
    else
        return ERROR;
}

// enums cant have the same enums in the same namespace
// you can also get wacky stuff like comparing 2 different enums together
// since underneath they're just integer values, and we dont want that
// we can avoid this using an enum class

enum class Fruits
{
    APPLE,
    BANANA,
    RED = -1
};

enum class Animals
{
    LIONS,
    BEARS,
    RED = -21
};

// now you cannot compare the two because they're of different enum classes.
// however, this also means you cant implicitely convert the enum to an int now.
// we can get around this with a static_cast

// also note how we can have the same enums now in enum classes vs if we tried to
// do it with purely enums, but like dont do that

// oh yeah also you cannot directly print the enum out b/c it'll convert it to an int
// or throw an error in the case of an enum class. you should make a function instead
// or something similar
std::string returnName(stateEnum x)
{
    switch (x)
    {
    case SUCCESS:
        return "SUCCESS \n";
        break;
    
    case ERROR:
        return "ERROR \n";
        break;

    default:
        return "NIL \n";
    }
}


auto main() -> int
{
    std::cout << returnName(some_function(1));

    // scope resolution operator to select between enum classes
    Fruits fruit{Fruits::APPLE};
    Animals animal{Animals::BEARS};
    stateEnum state{};

    // if (fruit == Animals::LIONS) {} -- this wouldn't work anymore
    std::cout << "fruit: " << static_cast<int>(fruit) <<    '\n';
    std::cout << "animal: " << static_cast<int>(animal) <<  '\n';

    // you can do this to assign an enum technically
    std::cout << "gimme a value (0 or 1): ";
    int i{};
    std::cin >> i;
    state = static_cast<stateEnum>(i);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << static_cast<int>(state) << '\n';
    
    return 0;
}

// overall, enums are useful from preventing the use of magic numbers in stuff
// like function return values
// it can help to clarify code some
// dont use multiple enum values of the same name that's just dum
// you can assign values to enums but like just let c++ do the thing
