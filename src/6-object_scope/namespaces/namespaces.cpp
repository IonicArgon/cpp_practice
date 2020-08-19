#include <iostream>
#include "complex-math.h"
#include "simple-math.h"

// so namespaces are cool because you can use them
// to separate scopes
// this can be used to prevent errors pertaining to the
// one definition rule (i.e. function with same name, parameters
// but different functions).

int multiplication(int a, int b);

int main()
{
    // operator:: is used for scope resolution
    // you can also use it without a prefix if you want to reference this file's global scope

    // we can also use aliases for longer qualified names since
    // nested namespace names can get long
    namespace foo = complexMath::arithmetic;
    namespace bar = complexMath::geometry;
    std::cout << "the product of 6 & 7 is: " <<     foo::multiplication(6, 7) <<                    '\n';
    std::cout << "the product of 10 & 5 is: " <<    simpleMath::multiplication(10, 5) <<            '\n';
    std::cout << "the product of 7 & 5 is: " <<     ::multiplication(7, 5) <<                       '\n';
    std::cout << "the perimeter of a 10 x 27 rectangle is: " << bar::rectangePerimeter(10, 27) <<   '\n';
}

int multiplication(int a, int b)
{
    return (a * b);
}