#include <iostream>
#include <array>
#include <vector>
#include <string>

// std::array and std::vector are standard library implementations of
// C's built-in fixed arrays and dynamic arrays.

// std::array is a fixed array
std::array int_arr { 1, 2, 3, 4, 5 };               // here, i don't have to explicitly declare the type and size
                                                    // as the type and size can be deduced based on whats in the braces.
std::array<const char, 6> char_arr { "Marco" };     // here, I declare the type and size (it's a null-terminated string)

// std::vector is a dynamic array
std::vector int_vec { 5, 4, 3, 2, 1 };              // same thing, no explicit type, size is not needed
std::vector<char> char_vec { 'B', 'o', 'b' };       // explicit type
std::vector<int> default_vec (5);                 // size of five, all elements are assigned default values

// here's a simple struct
struct Person
{
    std::string name {"N/A"};
    int age {0};
    double weight {0.0};
    double height {0.0};
};

// here's an array of people
std::array<Person, 3> people 
{{
        {"Bob", 37, 99999.9, 1.0},
        {"Joe", 69, 50.8, 137.2},
        {"e", static_cast<int>('e'), 101.0, 101.0}
}};                                                 // note the double braces b/c of how std::array is initialized.


// this shows how vectors will clean after itself once it exits scope
auto example(bool early_exit) -> void
{
    std::vector some_vector {"Hello", "Hi"};

    if (early_exit)
        return;

    for (auto &i : some_vector)
    {
        std::cout << i << ' ';
    }   std::cout << '\n';
}

auto main() -> int
{
    // arrays

    // we can do this
    int_arr = { 2, 4, 6, 8, 10 };
    // or we can do this
    int_arr = {3, 6, 9};            //elements 3 and 4 will be 0.
    // as long as the list is not larger than the original size, we're good.

    int_arr[4] = 72;                // this doesn't do bounds checking.
    int_arr.at(4) = 69;             // this does bounds checking.

    // we can use ranged based for loops
    for (auto &i : int_arr)
    {
        std::cout << i << ' ';
    }   std::cout << '\n';

    // we can also manually index it, but that's not prefered.
    for (std::size_t i{0}; i < int_arr.size(); ++i)
    {
        int_arr.at(i) = 3;
    }


    // vectors

    // like arrays, we can do this
    char_vec = {'a', 'b', 'c', 'd', 'e'};       // vectors will automatically resize if it's assigned to this way.
    // we can also do this
    char_vec[0] = 'x';                          // this will not automatically resize the vector
    // or this
    int_vec.at(0) = 36;                         // same thing here, no automatic resizing


    // here's automatic vector cleanup.
    example(false);
    example(true);

    // vectors, unlike dyanmic arrays, remember their length
    std::cout << "int vec size:\t" << int_vec.size() << '\n';

    // we can also resize vectors
    int_vec.resize(10);                        // this will keep the original values, but init the rest with the default value
    for (auto &i : int_vec)
    {
        std::cout << i << ' ';
    }   std::cout << '\n';

    // and here's shrinking it
    int_vec.resize(3);                          // this'll erase values past the newly assigned length
    for (auto &i : int_vec)
    {
        std::cout << i << ' ';
    }   std::cout << '\n';

    // resizing is computationally expensive, so that's why we can init a vector with a size and no values
    for (auto &i : default_vec)
    {
        std::cout << i << ' ';
    }   std::cout << '\n';
    

    // last note: boolean vectors will store 8 booleans in a byte, similar to using bitmasks, which is nice.
    return 0;
}