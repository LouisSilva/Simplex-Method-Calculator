#ifndef SIMPLEX_METHOD_CALCULATOR_S_VARS_H
#define SIMPLEX_METHOD_CALCULATOR_S_VARS_H

#endif //SIMPLEX_METHOD_CALCULATOR_S_VARS_H

#include <vector>
#include <string>

struct constraint {
    std::vector<std::string> l_coefficients;
    std::vector<float> n_coefficients;
    std::string sign;
    float equal_to;
};

struct objective_function{
    std::string name;
    std::vector<std::string> l_coefficients;
    std::vector<float> n_coefficients;
};

std::vector<std::string> greek_letters = {"α", "β", "δ", "ε", "ζ", "η", "θ", "κ", "λ", "μ", "ξ", "ρ", "τ", "φ", "χ", "ψ", "ω", "Γ", "Δ", "Θ", "Λ", "Ξ", "Π", "Σ", "σ", "ς", "Φ", "Ψ", "Ω"};