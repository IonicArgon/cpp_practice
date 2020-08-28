#include <iostream>

// c++ reads from top down, so functions defined after the main() function
// are not recognized as actual functions, unless we use
// a forward declaration

int add(int a, int b);

int main()
{
    std::cout << "here i'm using a forward declaration\n";
    std::cout << add(2, 3);
    return 0;
}

int add(int a, int b) 
{
    return a + b;
}