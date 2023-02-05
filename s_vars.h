#ifndef SIMPLEX_METHOD_CALCULATOR_S_VARS_H
#define SIMPLEX_METHOD_CALCULATOR_S_VARS_H

#endif //SIMPLEX_METHOD_CALCULATOR_S_VARS_H

#include <vector>
#include <string>
#include <map>

struct constraint {
    std::map<std::string, float> coefficients;
    std::string sign;
    float equal_to;
};

struct objective_function{
    std::string name;
    std::map<std::string, float> coefficients;
};

struct tableau{
    std::vector<std::vector<float>> matrix;
    std::vector<std::string> basic_variables;
    std::vector<std::string> column_names;
};

std::vector<std::string> greek_letters = {"α", "β", "δ", "ε", "ζ", "η", "θ", "κ", "λ", "μ", "ξ", "ρ", "τ", "φ", "χ", "ψ", "ω", "Γ", "Δ", "Θ", "Λ", "Ξ", "Π", "Σ", "σ", "ς", "Φ", "Ψ", "Ω"};