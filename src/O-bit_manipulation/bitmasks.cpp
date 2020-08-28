#include <iostream>
#include <cstdint>

// this is one of the times where using an unsigned integer is good
// otherwise, refrain from doing so you can get weird unexpected
// behavior doe

int main()
{
    // note, use of constexpr instead of const
    // b/c constexpr is defined during compile time, whereas
    // const is runtime
    constexpr std::uint_fast8_t bitmask1{1 << 0};    // 0000 0001
    constexpr std::uint_fast8_t bitmask2{1 << 1};    // 0000 0010
    constexpr std::uint_fast8_t bitmask3{1 << 2};    // 0000 0100
    constexpr std::uint_fast8_t bitmask4{1 << 3};    // 0000 1000

    std::uint_fast8_t my_bits{0b0000'0001};

    // we can use bitwise AND to determine if a bit flag is on or off
    std::cout << "Bit 0 is " << ((my_bits & bitmask1) ? "on\n" : "off\n");
    std::cout << "Bit 1 is " << ((my_bits & bitmask2) ? "on\n" : "off\n");

    // we can use |= to set a bit to a mask
    // we can set multiple masks too, just use bitwise ORs in parentheses
    my_bits |= bitmask2;

    std::cout << "Bit 0 is " << ((my_bits & bitmask1) ? "on\n" : "off\n");
    std::cout << "Bit 1 is " << ((my_bits & bitmask2) ? "on\n" : "off\n");

    // we can reset bits with the bitwise AND and NOT operators
    my_bits &= ~(bitmask1 | bitmask2);

    std::cout << "Bit 0 is " << ((my_bits & bitmask1) ? "on\n" : "off\n");
    std::cout << "Bit 1 is " << ((my_bits & bitmask2) ? "on\n" : "off\n");

    // we can then flip bits using the bitwise XOR operator
    my_bits ^= (bitmask1 | bitmask2);

    std::cout << "Bit 0 is " << ((my_bits & bitmask1) ? "on\n" : "off\n");
    std::cout << "Bit 1 is " << ((my_bits & bitmask2) ? "on\n" : "off\n");

    my_bits ^= (bitmask1 | bitmask2);

    std::cout << "Bit 0 is " << ((my_bits & bitmask1) ? "on\n" : "off\n");
    std::cout << "Bit 1 is " << ((my_bits & bitmask2) ? "on\n" : "off\n");

    // bitmasks can be useful when we have a stupid function like foo(bool a, bool b, bool c, ...)
    // idk why you'd ever need a function with three thousand bool parameters but that's just
    // how it be like sometimes
}