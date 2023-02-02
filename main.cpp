#include "SimplexCalc.h"

#include <vector>
#include <string>

int main(){
    SimplexCalc calc;

    std::vector<char> lc = {'x','y','z'};
    std::vector<float> nc = {10,20,30};
    std::string sign = "<=";
    float equal_to = 50;

    std::vector<char> lc2 = {'x','y','z'};
    std::vector<float> nc2 = {5,14,7};
    std::string sign2 = "<=";
    float equal_to2 = 45;

    calc.add_constraint(lc,nc,sign,equal_to);
    calc.add_constraint(lc2,nc2,sign2,equal_to2);
    calc.print_constraints();

    return 0;
}