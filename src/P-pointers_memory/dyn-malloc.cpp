#include <iostream>
#include <iomanip>
#include <cstddef>

// new and delete are used to dynamically allocate memory.
// it pretty much requests the OS if it could allocate some memory
// from the heap for the program's objects.
// this is different from static and automatically allocated memory
// which uses the program's stack memory.

int *dynamic_int{ new int{} };

// sometimes new can fail to allocate memory. in this case the program will
// crash unless we do this

double *dyn_double{ new (std::nothrow) double{3.1415} };


/* here's an example function demonstrating dynamically allocating memory
 * to an array
 */
auto dyn_arr_malloc() -> void
{
    using std::cout;
    using std::cin;

    cout << "please enter a pos int: ";
    std::size_t len{};
    cin >> len;

    int *arr{ new int[len]{} };

    cout << "arr el1 address:\t"        << arr << '\n';
    cout << "arr last el address:\t"    << (arr + len) << '\n';

    arr[0] = 21;

    cout << arr[0] << '\n';

    delete[] arr;
}


auto check_for_val(auto *val) -> bool
{
    return (val) ? true : false;
}


auto main() -> int
{
    using std::cout;
    cout << std::boolalpha;

    cout << "address of pointer:\t" << dynamic_int << '\n';
    cout << "value of pointer:\t"   << *dynamic_int << '\n';

    *dynamic_int = 365;
    cout << "value of pointer:\t"   << *dynamic_int << "\n\n";

    cout << "was mem allocated?\t"  << check_for_val(dyn_double) << '\n';
    cout << "address of pointer:\t" << dyn_double << '\n';
    cout << "value of pointer:\t"   << *dyn_double << "\n\n";

    // now we return the memory back to the OS
    delete dynamic_int;
    delete dyn_double;

    // returning the memory wont wipe the address saved on the pointer
    cout << "address of pointer:\t" << dynamic_int << '\n';
    cout << "address of pointer:\t" << dyn_double << '\n';

    // clear the address with nullptr
    dynamic_int = nullptr;
    dyn_double = nullptr;
    cout << "address of pointer:\t" << dynamic_int << '\n';
    cout << "address of pointer:\t" << dyn_double << '\n';

    dyn_arr_malloc();

    return 0;
}
