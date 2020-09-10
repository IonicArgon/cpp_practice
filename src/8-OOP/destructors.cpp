#include <iostream>
#include <cassert>

// a destructor is the opposite of a constructor
// whereas the constructor is used to init all the stuff of a created object of said class, 
// destructors are used for the cleanup.
// useful for when the class does stuff like access files or dynamically allocates
// memory.

class FixedArray
{
private:
    int *array_pnt;
    int array_length;

public:
    FixedArray(int len)
    {
        assert(len > 0);

        array_pnt = new int [ static_cast<std::size_t>(len) ] {};
        array_length = len;
        std::cout << "Created new integer array.\n";
    }

    ~FixedArray()         // this is the destructor
    {
        delete[] array_pnt;
        array_pnt = nullptr;
        std::cout << "Destroyed integer array.\n";
    }

    auto get(int pos) -> int
    {
        assert(pos < array_length);
        assert(pos >= 0);
        return (array_pnt[pos]);
    }

    auto set(int pos, int val) -> void
    {
        assert(pos < array_length);
        assert(pos >= 0);

        array_pnt[pos] = val;
    }

    auto size() -> int
    {
        return array_length;
    }

    auto getAddress() -> int**
    {
        return &array_pnt;
    }
};


auto main() -> int
{
    FixedArray obj1{5};

    for (int i{0}; i < obj1.size(); ++i)
    {
        obj1.set(i, i + 1);
    }

    for (int i{0}; i < obj1.size(); ++i)
    {
        std::cout << "Value at " << i << " is " << obj1.get(i) << '\n';
    }

    std::cout << "The starting address of the array is: " << obj1.getAddress() << '\n';

    // this is literally how std::array and std::vector work.
    // they're really just classes with functions that handle all the memory management for you, so that
    // you dont have to. rather nice, innit
    return 0;
}