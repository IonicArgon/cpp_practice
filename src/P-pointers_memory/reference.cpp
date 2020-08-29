#include <iostream>

/* note on value types
 * l-values are values that are stored at a memory address. 
 * r-values are anything that's not
 * these came about b/c of right and left hand sides of the assignment operator
 */

auto ref_smpl() -> void
{
    using std::cout;

    // we use ampersands to denote a reference
    int var{15};
    int &ref_var{var};
    // in this case it means "reference to", not address of

    // we can see here that performing operations to the reference changes the value of var
    cout << "value of var:\t" << var << '\n';
    ++ref_var;
    cout << "value of var:\t" << var << '\n';

    // using operator& on a reference returns the same address as the value
    cout << "addr. of var:\t" << &var << '\n';
    cout << "addr. of ref:\t" << &ref_var << '\n';

    // unlike pointers, references MUST be initialized with a value
    // references also cannot be reassigned with a different value, it'll always
    // point to that memory address after initialization.
}

/* references can be used as function parameters. 
 * in this case they pretty much act the same like pointers pointing back to the address. 
 * the key difference is that when you pass arrays, they do not decay down to a pointer. 
 * references are also inherently safer than pointers but as a consequence are more limited 
 * that pointers.
 * 
 * \param var
 *      some integer value
 */
auto foo(int &var) -> void
{
    var+=15;
}

/* when using references on arrays, it doensn't decay into a pointer. 
 * however, you do need to declare a fixed width though for the parameter. 
 * \param arr
 *      some int array of size 5
 */
auto foo2(int (&arr)[5])
{
    for (int i = 0; i < static_cast<int>(std::size(arr)); ++i)
    {
        arr[i] += (i * 10 % 3);
    }
}

auto main() -> int
{
    using std::cout;
    int bar{7};
    int bar2[5] {15, 20, 25, 30, 35};

    cout << "val of bar:\t" << bar << '\n';
    foo(bar);
    cout << "val of bar:\t" << bar << '\n';

    cout << '\n';

    for (int i = 0; i < static_cast<int>(std::size(bar2)); ++i)
    {
        cout << "bar2 val at " << i << ":\t" << bar2[i] << '\n';
    }
    foo2(bar2);
    cout << '\n';
    for (int i = 0; i < static_cast<int>(std::size(bar2)); ++i)
    {
        cout << "bar2 val at " << i << ":\t" << bar2[i] << '\n';
    }

    cout << '\n';

    ref_smpl();
    return 0;
}