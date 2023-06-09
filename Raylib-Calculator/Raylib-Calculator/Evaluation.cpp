#include <iostream>
#include <string>
#include "exprtk/exprtk.hpp"
#include "Evaluation.h"
#include <cmath>
#include <sstream>
#include <iomanip>
#define print(x) cout << x
using namespace std;

bool isInteger(double value) {
	return std::floor(value) == value || std::ceil(value) == value;
}

string RemoveSpaces(string myString) {
	string result = "";
	for (char c : myString) {
		if (c != ' ') {
			result += c;
		}
	}
	return result;
}

string EvaluateExpression(string expression) {
	expression = RemoveSpaces(expression);

	exprtk::symbol_table<double> symbolTable;
	exprtk::expression<double> expr;
	expr.register_symbol_table(symbolTable);

	exprtk::parser<double> parser;
	if (!parser.compile(expression, expr)) {
		std::cerr << "Compilation error: " << parser.error() << std::endl;

		if (parser.error() == "ERR001 - Empty expression!") {
			return "";
		}
	}

	double result = expr.value();
	//std::cout << "\nResult: " << result << std::endl;

	if (to_string(result) == "nan" || to_string(result) == "inf") {
		return "error";
	}
	else if ((result > 0 && (result < 0.00001f) || (result > 100000000000)) || (result < 0 && (result > -0.00001f) || (result < -100000000000))) {
		// Convert double to string with scientific notation
		std::stringstream ss;
		ss << std::scientific << std::setprecision(3) << result;
		std::string resultString = ss.str();
		return resultString;
	}
	else {
		string lessZeroes;
		string resultString = to_string(result);
		bool decimalPresent = false;
		for (int i = 0; i < resultString.length(); i++) {
			if (resultString[i] == '.') {
				decimalPresent = true;
			}
		}
		if (decimalPresent == true) {
			for (int i = resultString.length()-1; i > 0; i--) {
				if (resultString[i] == '0') {
					resultString.erase(i, 1);
				}
				else {
					i = 0;
				}
			}
		}
		if (resultString[resultString.length() - 1] == '.') resultString.pop_back();
		return resultString;
	}
}

