#include <iostream>

// the "this" and "*this" pointers are used by the compiler when compiling 
// classes, but can also be explicitly used by us.
// they essentially point to the class itself, or the object that was worked on
// by a function of a class

// pointing to the class itself
class Foo
{
private:
    int bar;

public:
    Foo(int bar)
    {
        this->bar = bar;    // differentiates between the local "bar" and the class's "bar"
    }

    // we can use this to link functions to each other
    Foo& add(int var)       {bar += var; return *this;}
    Foo& subtract(int var)  {bar -= var; return *this;}
    Foo& multiply(int var)  {bar *= var; return *this;}
    Foo& divide(int var)    {bar /= var; return *this;}

    int get() {return bar;}
};


auto main() -> int
{
    Foo foo(5);

    std::cout << foo.get() << '\n';
    foo.add(5).subtract(2).multiply(10).divide(4);
    std::cout << foo.get() << '\n';
    
    return 0;
}