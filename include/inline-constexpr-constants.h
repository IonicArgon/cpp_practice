// this is by far the superior method as long as we're using C++17 or higher
// we define all the constants in a namespace as an inline constexpr
// they're instantiated once through all files and are compile-time constants too

#ifndef CONSTANTS_INLINE_EXPR_H
#define CONSTANTS_INLINE_EXPR_H

namespace constantsInlineExpr
{
    inline constexpr double kPi{3.1415};
    inline constexpr double kEuler{2.7182};
    inline constexpr double kAvogadro{6.022};
    inline constexpr double kGolden_ratio{1.618};
}

#endif