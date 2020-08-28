// here we goin define the function in the namespace
#include "complex-math.h"

namespace complexMath::arithmetic
{
    int multiplication(int a, int b)
    {
        int return_value{0};
        for (int i = 0; i < b; ++i)
        {
            return_value += a;
        }

        return return_value;
    }
}

namespace complexMath::geometry
{
    int rectangePerimeter(int a, int b)
    {
        return ((a * 2) + (b * 2));
    }
}