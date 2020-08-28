#include <bitset>
#include <iostream>

int main()
{
    std::bitset<4> bits{0b0101};
    std::bitset<4> bits_two{0b1111};

    // there are many bit operations we can do, too
    // bitwise shifts literally shift the bits left or right
    // bits shifted out of the space are lost forever
    std::cout << bits << '\n';
    bits <<= 1;
    std::cout << bits << '\n';
    bits >>= 1;
    std::cout << bits << '\n';

    // bitwise OR applies to all bits
    // acts just like a logical OR, just on individual bits
    // can also be stacked with more bitwise OR operators
    std::cout << (bits | bits_two) << '\n';

    // similarly we have bitwise AND
    std::cout << (bits & bits_two) << '\n';

    // and a bitwise XOR
    std::cout << (bits ^ bits_two) << '\n';

    // and then of course there's all the complementary assignment operators
}