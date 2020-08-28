#include <iostream>
#include <iomanip>

// there's a ""magic"" keyword in C++ called "auto"
// it can be for a number of uses, but the key use is automatic
// type deduction.
// essentially the compiler infers what the type is based on 
// the literal or the return value of a function, e.g.

auto definitely_a_double{6.0};
// since the literal "6.0" is a double, the compiler assumes it'll
// be a double. likewise

auto some_function()
{
    return "hi";
}
// this function doesn't return a <string> string, but a const char[]
// which is the string literal.

// also, prior C++20, you can't use auto in function parameters
// the use of auto as function parameters is similar to function templates
// which allows you to create a generic function that can be used
// on multiple types, but i cant seem to work it out rn, ill prolly
// figure it out later.
// since most of my stuff is gonna be in C++17, ill probably be using
// function templates instead (ARM GCC is not up to date with GCCx86 just yet)

// you can also technically use it to do this

auto main() -> int
{
    std::cout << some_function() << '\n';
    return 0;
}

// this is known as trailing return type syntax
// it can be technically used to organize the code style but like why tho
// this is also used in lambda functions but idk that yet
