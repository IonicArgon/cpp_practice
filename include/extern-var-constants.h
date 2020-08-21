// this is one way to get around the problem of duplication of constants
// for every instance of inclusion
// problem is that these might not be optimized as much and they're no longer
// compile time constants

#ifndef CONSTANTS_EXTERN_VAR_H
#define CONSTANTS_EXTERN_VAR_H

namespace constantsExternVar
{
    extern const double kPi;
    extern const double kEuler;
    extern const double kAvogadro;
    extern const double kGolden_ratio;
}

#endif