#include <iostream>

// consider the following
class MyClass
{
private:
    int var1{0}, var2{0}, var3{0};
public:
    //constructors
    MyClass() = default;
    MyClass(int a, int b, int c)
    {
        var1 = a; var2 = b; var3 = c;
    }


    auto print() -> void
    {
        std::cout << var1 << ' ' << var2 << ' ' << var3 << '\n';
    }
};

// y'know, it works, but it's the doodoo way since
// we're copying over the values. plus, for things like consts that
// REQUIRE it to be initialized first, it doesn't work.

// the better solution is this
class MyOtherClass
{
private:
    int var1{4}, var2{5}, var3{6};
public:
    //constructors
    MyOtherClass() = default;
    MyOtherClass(int a , int b , int c )
     : var1{a}, var2{b}, var3{c}
    {}


    auto print() -> void
    {
        std::cout << var1 << ' ' << var2 << ' ' << var3 << '\n';
    }
};
// this has the added advantage that it actually initializes the object with the value,
// rather than first creating the object then copying the value to it

// mmmyeah side note, if a class creates an object of another class, the class within the class
// is constructed first
// also Constructor = default; also exists, so there's that

auto main() -> int
{
    MyClass obj1{1, 2, 3};
    MyOtherClass obj2{};

    obj1.print();
    obj2.print();

    return 0;
}