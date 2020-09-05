#include <iostream>
#include <functional>
#include <utility>

// so why do we want function pointers?
// well, what if we did something like this?

// sort in ascending order
auto ascending(int x, int y) -> bool
{
    return (x > y);
}

// sort in descending order
auto descending(int x, int y) -> bool
{
    return (x < y);
}

// selection sort algorithm
auto sel_sort(int *arr, int size, std::function<bool(int, int)> sort = ascending) -> void
{
    for (int i{0}; i < (size - 1); ++i)
    {
        int j{i};
        for (int x{i + 1}; x < size; ++x)
        {
            if (sort(arr[j], arr[x]))
                j = x;
        }
        std::swap(arr[i], arr[j]);
    }
}

// print array
auto print_arr(int *arr, int size) -> void
{
    for (auto i{0}; i < size; ++i)
    {
        std::cout << arr[i] << ' ';
    }   std::cout << '\n';
}

auto main() -> int
{
    int arr[10] {9, 3, 6, 7, 5, 2, 1, 8, 4, 10};
    sel_sort(arr, 10);
    print_arr(arr, 10);
    sel_sort(arr, 10, descending);
    print_arr(arr, 10);
    return 0;
}

// the point being, you can use function pointers to point to functions which
// can be used the case of storing functions in an array, or providing a function 
// to a function (functionception).
// native syntax for function pointers are bulky: type (*name)(params){address (depends on use)}
// can use a type alias to make it less bulky.
// std::function is a bit neater in this situation: std::function<type(params)> name