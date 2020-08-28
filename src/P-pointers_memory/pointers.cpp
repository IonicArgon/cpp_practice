#include <iostream>
#include <typeinfo>

// every variable has its value stored in a memory location
int some_val{25};                   // somewhere, the value 25 is stored
int val_at_addr{*(&some_val)};      // this accesses the value at the address
int *pointer{&some_val};            // this points to the address of some_val
int *zeroinit_pntr{nullptr};          // zero-initialized pointer

// operator& does not return the literal address, but only the pointer to the address

auto main() -> int
{
    using std::cout;
    cout << "some_val:\t\t"         << some_val    << '\n';
    cout << "some_val's address:\t" << &some_val   << '\n';
    cout << "value at address:\t"   << val_at_addr << '\n';
    cout << "pointer address:\t"    << pointer     << '\n';
    cout << "deref pointer:\t\t"    << *pointer    << '\n';
    // this demonstrates how operator& doesn't return a literal address
    cout << "type at runtime:\t"    << typeid(pointer).name() << '\n';          // "Pi" means "pointer to integer"
    cout << "zeroinit pointer:\t"   << zeroinit_pntr          << '\n';
    //cout << "zeroinit value:\t"     << *zeroinit_pntr         << '\n';        // this is bad, you'll crash the program
    // we now assign it a value;
    zeroinit_pntr = &some_val;
    cout << "zeroinit pointer:\t"   << zeroinit_pntr          << '\n';
    cout << "zeroinit value:\t\t"   << *zeroinit_pntr         << '\n';   
    return 0;
}