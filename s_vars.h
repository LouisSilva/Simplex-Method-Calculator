#ifndef SIMPLEX_METHOD_CALCULATOR_S_VARS_H
#define SIMPLEX_METHOD_CALCULATOR_S_VARS_H

#endif //SIMPLEX_METHOD_CALCULATOR_S_VARS_H

#include <vector>
#include <string>

struct constraint {
    std::vector<char> l_coefficients;
    std::vector<float> n_coefficients;
    std::string sign;
    float equal_to;
};

struct objective_function{
    std::string name;
    std::vector<char> l_coefficients;
    std::vector<float> n_coefficients;
};