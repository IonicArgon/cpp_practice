#include <iostream>
#include "constants-c++11.h"
#include "extern-var-constants.h"
#include "inline-constexpr-constants.h"

int main()
{
    // this is nice so long as i don't have a user defined cout
    using std::cout;

    // also notice da use of whitespace to make the code look neater
    cout << constantsCPP11::kPi                 << '\n';
    cout << constantsExternVar::kEuler          << '\n';
    cout << constantsInlineExpr::kGolden_ratio  << '\n';

    return 0;
}