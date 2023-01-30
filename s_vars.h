#ifndef SIMPLEX_METHOD_CALCULATOR_S_VARS_H
#define SIMPLEX_METHOD_CALCULATOR_S_VARS_H

#endif //SIMPLEX_METHOD_CALCULATOR_S_VARS_H

#include <vector>

struct constraint {
    std::vector<char> l_coefficients;
    std::vector<float> n_coefficients;
    bool less, more, equal;
    float equal_to;
};

struct objective_function {
};