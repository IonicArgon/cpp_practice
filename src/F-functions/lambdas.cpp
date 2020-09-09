#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <string>
#include <string_view>

// consider the following

auto foo(const std::string_view bar) -> bool
{
    return (bar.find("berry") != std::string_view::npos);
}

auto foo2() -> void
{
    std::array<std::string_view, 6> food {"apple", "blueberry", "strawberry", "walnut", "banana", "blackberry"};

    auto arr_count { std::count_if(food.begin(), food.end(), foo) };

    std::cout << arr_count << " berries were found." << '\n';
}

// it works but we created a whole function that we'll never use again. instead, we can 
// use a "lambda", an "anonymous function" (function that has no name, a functor)

auto foo3() -> void
{
    std::array<std::string_view, 12> months
    {
        "January",  "Feburary",     "March",
        "April",    "May",          "June", 
        "July",     "August",       "September",
        "October",  "November",     "December"
    }; 

    auto arr_count { std::count_if(months.begin(), months.end(), 
                                    [](const std::string_view a)
                                    { 
                                        return (a.find("ember") != std::string_view::npos); 
                                    }) };

    std::cout << arr_count << " months end with \"-ember\".\n";
}

// the lambda consists of
// [captures](parameters) -> return type (optional)
//      {
//          statements;
//      }

// we can store lambdas in a variable for later use btw

auto foo4() -> void
{
    auto is_odd {
        [](const auto& a) -> bool
        {
            return ((a % 2) != 0);
        }
    };

    std::array<int, 10> ints {9, 2, 6, 3, 5, 4, 0, 7, 1, 8};

    auto arr_count { std::count_if(ints.begin(), ints.end(), is_odd) };

    std::cout << "there are " << arr_count << " even numbers in the list.\n";
}

// we can also do this doe

auto def_lambda() -> void
{
    // using function pointers
    int (*add1)(int, int) 
    {
        [](int a, int b) -> int
        {
            return (a + b);
        }
    };

    // using std::function
    std::function add2 
    {
        [](int a, int b) -> int
        {
            return (a + b);
        }
    };

    // using auto
    auto add3 
    {
        [](int a, int b) -> int
        {
            return (a + b);
        }
    };

    std::cout << add1(1, 2) << '\t' << add2(3, 4) << '\t' << add3(5, 6) << '\n';
}

// auto can be used for the function parameters for a lambda, but note that a NEW, UNIQUE 
// lambda is generated for each different type
auto generic_lambda() -> void
{
    auto gen_lambda 
    {
        [](const auto& a)
        {
            static int call_count { 0 };
            std::cout << "count " << call_count++ << ": " << a << '\n';
        }
    };

    gen_lambda("hello");
    gen_lambda(1);
    gen_lambda(2);
    gen_lambda(3);
    gen_lambda("world");
    gen_lambda(1.6);
    gen_lambda(82.5);
}

// lambdas must always return the same value type, you cant have one return return an int and another return a double

auto lambda_capture() -> void
{
    // lambdas can only access global identfiers, entities known at compile time, and static entities. 
    // if you want to use anything else, you need to use the capture clause.
    std::array<std::string_view, 6> distros 
    {
        "arch",
        "debian",
        "ubuntu",
        "manjaro",
        "gentoo",
        "hannah montana linux"
    };

    std::cout << "search substring: ";
    std::string substr {};
    std::cin >> substr;

    auto found { std::find_if(distros.begin(), distros.end(),
                              [substr](std::string_view a) 
                              {
                                  return (a.find(substr) != std::string_view::npos);
                              }) };

    if (found == distros.end())
        std::cout << "no distro found\n";
    else
        std::cout << "found \"" << *found << "\"\n";

    // by default, captures are const value, so you either need to make the lambda mutable, or
    // capture by reference if you wanna edit it.
    // mutable would be [foo]() mutable {};
    // capture by reference would be [&foo](){};
    // you can use "=" for default capture by value, and "&" for default capture by reference
    // like so: [=](){};    [&](){};
    // you can also define values in the capture clause

    // note, captures by value will COPY the value over, much like a function, so use references 
    // if you want to edit the value directly
}

auto main() -> int
{
    foo2();
    foo3();
    foo4();
    def_lambda();
    generic_lambda();
    lambda_capture();
    return 0;
}