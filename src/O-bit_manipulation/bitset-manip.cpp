#include <bitset>
#include <iostream>

// so this isn't really important but might as well
// we can use bitset to directly set the bits of a byte in memory
// sometimes we want to do this in times where space is scarce
// with things like bools, they only require a singular bit
// thus, we can technically shove 8 bools in a single byte

int main()
{
    std::bitset<8> my_bools{0b0000'0000};

    // now we have a bunch of bit "flags" we can use as bools instead
    std::cout << "Current bits: " << my_bools << '\n';
    my_bools.set(0);
    std::cout << "Now it's set to " << my_bools << '\n';
    my_bools.reset(0);
    std::cout << "Now it's set to " << my_bools << '\n';
    my_bools.flip(4);
    std::cout << "Now it's set to " << my_bools << '\n';
    my_bools.flip(4);
    std::cout << "Now it's set to " << my_bools << '\n';

    return 0;
}