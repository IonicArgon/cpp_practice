#include <iostream>
#include <vector>


int foo { 5 };
// the void pointer
void *bar { &foo };
// this can hold any type and can return the address of any 
// variable, but cannot be dereferenced to return a value

// this is for later
int int_arr[] { 1, 2, 3, 4, 5 };
std::vector char_vec { 'a', 'b', 'c', 'd', 'e' };

auto main() -> int
{
    //std::cout << *bar << '\n';        // this is illegal!

    // if you want to dereference it, cast it first
    int* baz{static_cast<int*>(bar)};
    std::cout << *baz << '\n';          // this is legal

    // void* is kinda iffy so it's best that i leave it be 
    // (i can avoid type checking, also it's wonky for dyn malloc stuff)
    // oh yeah i can also do this:
    bar = nullptr;

    // for-each loops
    // ranged based for loops, they're done like this
    for (const auto &i : int_arr)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';
    // auto is not necessary, but it's handy because it means we dont have to
    // use a long ass type.
    // using a reference is also technically not necessary but copying arrays
    // can be expensive, which is why it is done.
    // and then we use "const" because in this application, we don't want 
    // the loop to write to the array, so the const protects the array.

    // they can also be used with other data types besides an array, like a vector
    for (int j { 0 }; const auto &i : char_vec)
    {
        std::cout << i << '\t' << j << '\n';
        ++j;
    }
    std::cout << '\n';

    // final note: you cannot use pointers to an array on for-each loops because
    // the loop needs to know the size of the array. pointers do not know the size
    // of the array.
}