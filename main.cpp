#include <string>
#include <iostream>
#include <vector>
#include <format>

#include "special_vars.h"
#include "SimplexCalc.h"
#include "op_overloads.h"

int main() {
	SimplexCalculator calc;

	calc.set_constraint({ 'x','y','z' }, { 25,50.1,14.25 }, 0, 69);
	calc.set_objective_function({ 'x', 'y', 'z'}, {3,4,5}, false);
	std::cout << calc.get_objective_function();
	return 0;
}