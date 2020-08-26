#include <iostream>
#include <iterator>

// here we declare a fix width int array
int array[5]{9, 18, 27, 36, 45};
// here we make a pointer to said array
int* arry_ptr{array};
// here's another but specifying which element in the array
int* arry_ptr_2{&array[0]};


auto main() -> int
{
    // you will notice that directly passing the array returns a pointer to the
    // first element of the array
    using std::cout;
    cout << "passing the whole ass array\t"     << array    << '\n';
    cout << "passing the pointer to array\t"    << arry_ptr << '\n';
    cout << "passing the element pointer\t"     << arry_ptr_2 << '\n';

    // they all output the same address because arrays will decay down to a pointer
    // that points towards the first element of the array
    
    // this is for memory reasons, like if you were to pass an array to a function.
    // passing the whole array would mean copying over the whole array, which would
    // use too much space. so it just passes a pointer to the first element instead

    // now this demonstrates that all the elements are laid out sequentially in memory.
    // each address will be 4 bytes after each address, in order, because ints will
    // be 4 bytes on this machine.
    cout << "element 0\t" << &array[0] << '\n';
    cout << "element 1\t" << &array[1] << '\n';
    cout << "element 2\t" << &array[2] << '\n';
    cout << "element 3\t" << &array[3] << '\n';
    cout << "element 4\t" << &array[4] << '\n';

    // now watch this voodoo magic
    cout << "element 1 address:\t" << &array[1] << '\n';
    cout << "element 1 address:\t" << array + 1 << '\n';
    cout << "element 1 value:\t"   << array[1]  << '\n';
    cout << "element 1 value:\t"   << *(array + 1) << '\n';

    // the compiler just treats operator[] as a pointer to the array.
    // indexing elements using operator[] is the same as using pointer arithmetic to
    // access the array elements, since the array elements are in sequential order in mem.

    // now lets use a pointer to iterate through an array
    int arr_size{static_cast<int>(std::size(array))};
    for (int* ptr{array}; ptr < (array + arr_size); ++ptr)
    {
        cout << *ptr << '\n';
    }
    
}