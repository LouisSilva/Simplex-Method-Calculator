#pragma once

#include <iostream>
#include <string>

#include "special_vars.h"

std::ostream &operator<<(std::ostream& os, const constraint& c) {
	std::string cstr, sign;
	for (int i = 0; i < c.num_vars - 1; i++) {
		float current_coefficient = c.coefficents.at(i);

		if (current_coefficient == 1) {
			cstr.append(std::format("{0}{1} + ", c.var_letters.at(i)));
		}
		else {
			cstr.append(std::format("{0}{1} + ", c.coefficents.at(i), c.var_letters.at(i)));
		}

	return os << cstr;
	}

std::ostream& operator<<(std::ostream & os, const objective_function & o); {
	if (c.less_more_equal == 0) { sign = '<='; }
	else if (c.less_more_equal == 1) { sign = '>='; }
	else if (c.less_more_equal == 2) { sign = '='; }
	cstr.append(std::format("{0}{1} {2} {3}", c.coefficents.back(), c.var_letters.back(), sign, c.equal_to));

	return os << cstr;
}


}