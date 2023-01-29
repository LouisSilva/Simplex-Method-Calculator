#pragma once

#include <vector>
#include <string>

#include "special_vars.h"

class SimplexCalculator {
public:

	std::vector<constraint> constraints_arr;
	objective_function o;

	void set_constraint(std::vector<char> var_letters, std::vector<float> coefficients, int less_more_equal, float equal_to) {
		constraint c = constraint(var_letters, coefficients, var_letters.size(), less_more_equal, equal_to);
		constraints_arr.push_back(c);
	}

	std::vector<constraint> get_constraints() {
		return constraints_arr;
	}

	void set_objective_function(std::vector<char> var_letters, std::vector<float> coefficients, bool rearranged) {
		objective_function temp_o = objective_function(var_letters, coefficients, rearranged);
		o = temp_o;
	}

	objective_function get_objective_function() {
		return o;
	}

private:

	constraint apply_slack(constraint c, char var_name) {
		if (c.less_more_equal == 1) { std::cout << "Cannot apply slack to constraint with '>='"; }
		else if (c.less_more_equal == 2) { std::cout << "This constraint is already in equation form"; }
		else {

			c.var_letters.push_back(var_name);
			c.coefficents.push_back(1);
			c.less_more_equal = 2;
			c.num_vars++;
		}

		return c;
	}

	constraint apply_surplus_and_arbitrary(constraint c, char surplus_name, char arbitrary_name) {
		if (c.less_more_equal == 0) { std::cout << "Cannot apply surplus to constraint with '<='"; }
		else if (c.less_more_equal == 2) { std::cout << "This constraint is already in equation form"; }
		else {

			c.var_letters.push_back(surplus_name);
			c.var_letters.push_back(arbitrary_name);
			c.coefficents.push_back(1);
			c.coefficents.push_back(-1);
			c.less_more_equal = 2;
			c.num_vars += 2;
		}

		return c;
	}

	objective_function rearrange_objecive_function(objective_function f) {
		/*struct objective_function {
			std::vector<char> var_letters;
			std::vector<float> coefficients;
			float equal_to;
		};*/

	}
};