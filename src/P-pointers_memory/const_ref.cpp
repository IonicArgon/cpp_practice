#include <iostream>

// i am aware that using `auto main() -> int` is no different from `int main()` but 
// i guess it just looks nicer?

/* and of course we can use constant references in function parameters
 * \param var
 *      some const/non-const integer
 */
auto const_ref(const int &ref) -> void
{
    std::cout << ref << '\n';
    // now we cant accidentally doodoo the value since it's protected as a const
}

auto main() -> int
{
    // references can be made for constants, too
    const int convar{420};
    const int &ref_con{convar};

    // and constant references can be made for non-constant variables
    int var{360};
    const int &ref_var{var};
    // this treats the value as a constant so you can't directly modify
    // the value, much like constant pointers

    // constant references can be used to extent the life time of r-values since 
    // r-values are primarily expression-scope.
    const int &r_var_ref{2 + 3};

    std::cout << 2 + 3 << '\n';         // "2 + 3" alone would mean the r-value ends after this expression.
    std::cout << r_var_ref << '\n';     // "2 + 3" in r_var_ref stays alive until the reference exits its scope, 
                                        // extending the life time of the r-values
    std::cout << '\n';

    const_ref(convar);
    const_ref(ref_con);
    const_ref(var);
    const_ref(ref_var);
    return 0;
}

// basically we'd use these when passing non-fundamental, non-pointer values to a function since 
// passing shit like a large ass structure or class can be wasteful as it requires more resources 
// to copy it over to the function.