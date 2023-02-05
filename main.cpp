#include "SimplexCalc.h"

#include <vector>
#include <string>
#include <iostream>
#include <map>

int main(){
    SimplexCalc calc;

    std::map<std::string, float> coefficients1 = {{"x", 32}, {"y", 21}, {"z", 60}};
    std::string sign1 = "<=";
    float equal_to1 = 50;

    std::map<std::string, float> coefficients2 = {{"x", 52}, {"y", 12}, {"z", 3}};
    std::string sign2 = "<=";
    float equal_to2 = 45;

    calc.add_constraint(coefficients1, sign1, equal_to1);
    calc.add_constraint(coefficients2,sign2,equal_to2);
    calc.convert_constraints();
    calc.print_constraints();

    calc.set_objective_function("P", {{"x", 3}, {"y", 4}, {"z", 5}});
    calc.rearrange_objective_function();
    calc.print_objective_function();

    calc.initialize_tableau();

    return 0;
}