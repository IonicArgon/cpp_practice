// this is how constants were done pre C++17
// now, its not really a good practice because the way these constants work,
// in every file that this is included in, it creates a whole ass copy
// of every constant here, so it's kinda suck
//      1. can cause longer rebuild times b/c every file would have to be recompiled
//      2. if the constants cant be optimized away, its not memory efficient

#ifndef CONSTANTS_CPP_11_H
#define CONSTANTS_CPP_11_H

namespace constantsCPP11
{
    constexpr double kPi{3.1415};
    constexpr double kEuler{2.7182};
    constexpr double kAvogadro{6.022};
    constexpr double kGolden_ratio{1.618};
}

#endif