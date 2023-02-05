
#ifndef SIMPLEX_METHOD_CALCULATOR_SIMPLEXCALC_H
#define SIMPLEX_METHOD_CALCULATOR_SIMPLEXCALC_H

#endif //SIMPLEX_METHOD_CALCULATOR_SIMPLEXCALC_H

#include "s_vars.h"

#include <utility>
#include <vector>
#include <map>
#include <iostream>
#include <fmt/core.h>

class SimplexCalc{
public:
    std::vector<constraint> constraints;
    objective_function obj_func;
    tableau tableau;

    void add_constraint(std::map<std::string, float> coefficients, std::string sign, float equal_to){
        constraint new_constraint;
        new_constraint.coefficients = std::move(coefficients);
        new_constraint.sign = std::move(sign);
        new_constraint.equal_to = equal_to;

        constraints.emplace_back(new_constraint);
    };

    void print_constraints(){
        std::string str_const;
        for(auto current_constraint : constraints){
            str_const = "";
            for(auto & value : current_constraint.coefficients){
                str_const = str_const + std::to_string(value.second) + value.first + ", ";
            }
            str_const.pop_back();str_const.pop_back();
            fmt::print("{0} {1} {2}", str_const, current_constraint.sign, std::to_string(current_constraint.equal_to));
            std::cout << std::endl;
        }
    };

    void convert_constraints(){
        std::vector<constraint> new_constraints;
        int i = 0;
        for(auto & c_constraint : constraints){
            if(c_constraint.sign == "="){
                continue;
            }  // push_back(greek_letters.at(i));
            else{
                c_constraint.coefficients[greek_letters.at(i)] = 1;
                if(c_constraint.sign == ">="){
                    c_constraint.coefficients[greek_letters.at(30-i)] = -1;
                }
                c_constraint.sign = "=";
                new_constraints.emplace_back(c_constraint);
            }
            i++;
        }
        constraints = new_constraints;
    }

    void set_objective_function(std::string name, std::map<std::string, float> coefficients){
        obj_func.name = std::move(name);
        obj_func.coefficients = std::move(coefficients);
    }

    void rearrange_objective_function(){
        for(auto & value : obj_func.coefficients){
            value.second = value.second *-1;
        }
    }

    void print_objective_function(){
        std::string str_const;
        for(auto & c_coefficient : obj_func.coefficients){
            str_const = str_const + std::to_string(c_coefficient.second) + c_coefficient.first + ", ";
        }
        str_const.pop_back();str_const.pop_back();
        fmt::print("{0} + {1} = 0", obj_func.name, str_const);
        std::cout << std::endl;
    }

    void print_basic_variables(const std::vector<std::string>& b_vars){
        std::string to_print;
        for(auto & b_var : b_vars){
            to_print += b_var + ", ";
        }
        to_print.pop_back();to_print.pop_back();
        fmt::print("Basic Variables: {0}", to_print);
    }

    void initialize_tableau(){
        // Clear tableau and initialize needed variables
        tableau.matrix = {};
        tableau.basic_variables = {};
        tableau.column_names = {};

        std::map<std::string, int> vars;

        // Loops over all the constraints and puts the variable names into a map
         for(auto & c_constraint : constraints){
            for(auto & c_constraint_coef_map : c_constraint.coefficients){
                vars[c_constraint_coef_map.first] += 1;
            }
         }

        // Loops over the variable map
        for(auto & var : vars){
            // Pushes basic variables to the tableau
            if(var.second == 1){
                tableau.basic_variables.emplace_back(var.first);
            }
            // Pushes normal variables to the tableau
            else if(var.second > 1){
                tableau.column_names.emplace_back(var.first);
            }
        }
        // Adds the slack variable columns, value column and the objective function row
        tableau.column_names.insert(tableau.column_names.end(), tableau.basic_variables.begin(), tableau.basic_variables.end());
        tableau.column_names.emplace_back("Value");
        tableau.basic_variables.emplace_back(obj_func.name);

        std::vector<float> temp_row;
        for(auto & c_constraint : constraints){
            temp_row.clear();
            for(const auto& current_column_name : tableau.column_names){
                if (current_column_name == "Value"){break;}
                int value_to_push = 0;
                for(auto & coef_map : c_constraint.coefficients){
                    if (coef_map.first == current_column_name){
                        value_to_push = coef_map.second;
                    }
                }
                temp_row.emplace_back(value_to_push);
            }

            temp_row.emplace_back(c_constraint.equal_to);
            tableau.matrix.emplace_back(temp_row);
        }

        temp_row.clear();
        for(const auto& current_column_name : tableau.column_names){
            if (current_column_name == "Value"){break;}
            int value_to_push = 0;
            for(auto & obj_coef_map : obj_func.coefficients){
                if (obj_coef_map.first == current_column_name){
                    value_to_push = obj_coef_map.second;
                }
            }
            temp_row.emplace_back(value_to_push);
        }
        temp_row.emplace_back(0);
        tableau.matrix.emplace_back(temp_row);
    }
};