#include <iostream>

// we have our subtraction function in another file, but
// we still need the forward declaration since its not defined
// before main()

int subtract(int a, int b);

int main()
{
    std::cout << "Subtracting 7 from 10 gives us:\t" << subtract(10, 7) << "\n";
    return 0;
}