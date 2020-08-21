#include <iostream>
#include <string>

// so structs are an aggregate data type in which
// its a type that stores more types within itself
// classes and structs are some examples

struct Student
{
    std::string name{};
    int id{0};
    short grade{9};
    float gpa{0};
};
// we can initialize the values in a struct
// with a default value but then we can
// assign values if we dont wanna use the default
// at least in C++14 and over

// we can create nested structs, too

struct IBStudent
{
    short IBLevel{0};
    Student student;
};

// you can make functions that return structs

auto createBob() -> IBStudent
{
    return {6, {"bob", 327, 11, 3.5}};
}

auto main() -> int
{
    IBStudent bob{createBob()};
    std::cout << bob.student.name   << '\n';
    std::cout << bob.student.id     << '\n';
    std::cout << bob.student.grade  << '\n';
    std::cout << bob.student.gpa    << '\n';
    std::cout << bob.IBLevel        << '\n';

    // can also do this
    std::cout << "The size of struct \"bob\" is:\t" << sizeof(bob) << '\n';
    return 0;
}