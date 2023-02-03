
#ifndef SIMPLEX_METHOD_CALCULATOR_SIMPLEXCALC_H
#define SIMPLEX_METHOD_CALCULATOR_SIMPLEXCALC_H

#endif //SIMPLEX_METHOD_CALCULATOR_SIMPLEXCALC_H

#include "s_vars.h"
#include "fmt/format.h"

#include <utility>
#include <vector>
#include <iostream>

class SimplexCalc{
public:
    std::vector<constraint> constraints;
    objective_function obj_func;

    void add_constraint(const std::vector<std::string>& l_coefficients, const std::vector<float>& n_coefficients, std::string sign, float equal_to){
        constraint new_constraint;
        new_constraint.l_coefficients = l_coefficients;
        new_constraint.n_coefficients = n_coefficients;
        new_constraint.sign = std::move(sign);
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
        std::vector<constraint> new_constraints;
        for(int i=0; i<constraints.size(); i++){
            constraint current_constraint = constraints.at(i);
            if(current_constraint.sign == "="){
                continue;
            }
            else{
                current_constraint.l_coefficients.push_back(greek_letters.at(i));
                current_constraint.n_coefficients.push_back(1);
                if(current_constraint.sign == ">="){
                    current_constraint.l_coefficients.push_back(greek_letters.at(i));
                    current_constraint.n_coefficients.push_back(-1);
                }
                current_constraint.sign = "=";
                new_constraints.push_back(current_constraint);
            }
        }
        constraints = new_constraints;
    }

    void set_objective_function(std::string name, std::vector<std::string> l_coefficients, std::vector<float> n_coefficients){
        obj_func.name = std::move(name);
        obj_func.l_coefficients = std::move(l_coefficients);
        obj_func.n_coefficients = std::move(n_coefficients);
    }

    objective_function get_objective_functions() const{
        return obj_func;
    }
};