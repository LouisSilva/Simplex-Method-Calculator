#pragma once

#include <vector>

struct constraint {
	std::vector<char> var_letters;
	std::vector<float> coefficents;
	int num_vars;
	int less_more_equal;
	float equal_to;
};

struct objective_function {
	std::vector<char> var_letters;
	std::vector<float> coefficients;
	bool rearranged;
};