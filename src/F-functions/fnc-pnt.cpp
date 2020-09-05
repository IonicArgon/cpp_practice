#include <iostream>
#include <functional>

// functions are really just pointers to the address of the beginning of the
// code inside of the function. e.g.

using func_typealias = int(*)(int);

auto foo(int x = 0) -> int           // this just points to some address where the code begins
{
    return x;
}

auto main() -> int
{
    foo();                           // this invokes the code at the beginning of said address.

    // we can see the address of the function by doing this
    std::cout << reinterpret_cast<void*>(foo) << '\n';
    // on some other machines, we dont need the reinterpret_cast, but b/c of how GCC works, we have to here.

    // we can create a pointer to this address like so
    int (*baz)(int){ &foo };        // yes it's pretty bloated
    // or like this
    func_typealias bar{ &foo};
    // or like this
    std::function<int(int)> foo2 { &foo };

    std::cout << reinterpret_cast<void*>(baz) << '\t' << reinterpret_cast<void*>(bar) << '\n';
    std::cout << (*baz)(5) << '\t' << bar(2) << '\t' << foo2(7) << '\n';        // note that we cannot use default values with pointers

    return 0;
}