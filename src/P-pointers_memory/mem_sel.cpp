#include <iostream>
#include <string>


auto main() -> int
{
    using std::cout;

    // lets say we had a struct
    struct person
    {
        int age{0};
        double height{0.0}; 
    };
    person Bob;

    // we can create a reference to bob
    person &ref_bob{Bob};

    cout << "bob's age:\t" << Bob.age << '\n';
    cout << "bob's height:\t" << Bob.height << '\n';
    cout << '\n';

    ref_bob.height = 117.3;     // this works just as well as
    cout << "bob's height:\t" << Bob.height << '\n';
    cout << '\n';
    
    Bob.height = 40;            // this
    cout << "bob's height:\t" << Bob.height << '\n';
    cout << '\n';

    // you can also use pointers, but you must dereference it first
    person *pnt_bob{&Bob};
    (*pnt_bob).age = 2.5;
    cout << "bob's age:\t" << Bob.age << '\n';
    cout << '\n';

    // it's easier to do it like this with a pointer though
    pnt_bob->age = 1;
    cout << "bob's age:\t" << Bob.age << '\n';
    cout << '\n';

    return 0;
}