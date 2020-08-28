// so this is the header file for multiplication
// we use a header guard to prevent violations of the
// one definition rule

#pragma once            // this technically works too but like it's not supported
                        // by all compilers

#ifndef MULTIPLY_H
#define MULTIPLY_H

int multiply(int a, int b);

#endif