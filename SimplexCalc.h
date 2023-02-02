
#ifndef SIMPLEX_METHOD_CALCULATOR_SIMPLEXCALC_H
#define SIMPLEX_METHOD_CALCULATOR_SIMPLEXCALC_H

#endif //SIMPLEX_METHOD_CALCULATOR_SIMPLEXCALC_H

#include "s_vars.h"
#include "fmt/format.h"

#include <vector>
#include <iostream>

class SimplexCalc{
public:
    std::vector<constraint> constraints;
    objective_function obj_func;

    void add_constraint(const std::vector<char>& l_coefficients, const std::vector<float>& n_coefficients, std::string sign, float equal_to){
        constraint new_constraint;
        new_constraint.l_coefficients = l_coefficients;
        new_constraint.n_coefficients = n_coefficients;
        new_constraint.sign = sign;
        new_constraint.equal_to = equal_to;

        constraints.push_back(new_constraint);
    };

    void print_constraints(){
        std::string str_const;
        for(auto current_constraint : constraints){
            str_const = "";
            for(int i=0; i<current_constraint.n_coefficients.size(); i++){
                if(i != 0){str_const = str_const + " + ";}
                str_const = str_const + std::to_string(current_constraint.n_coefficients.at(i)) + current_constraint.l_coefficients.at(i);
            }
            fmt::print("{0} {1} {2}", str_const, current_constraint.sign, std::to_string(current_constraint.equal_to));
            std::cout << std::endl;
        }
    };

    void convert_constraints(){
        for(auto current_constraint: constraints){
            if(current_constraint.sign == "="){
                continue;
            }
            else if(current_constraint.sign == "<="){
                std::cout << "λ"
            }
        }
    }

    void set_objective_function(std::string name, std::vector<char> l_coefficients, std::vector<float> n_coefficients){
        obj_func.name = name;
        obj_func.l_coefficients = l_coefficients;
        obj_func.n_coefficients = n_coefficients;
    }

    objective_function get_objective_functions(){
        return obj_func;
    }
};