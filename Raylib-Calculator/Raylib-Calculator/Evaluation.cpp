#pragma once
#include <iostream>
#include <string>
#include "exprtk/exprtk.hpp"
#include "Evaluation.h"
#include <cmath>
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
	}

	double result = expr.value();
	std::cout << "Result: " << result << std::endl;



	if (isInteger(result)) {
		int intValue = static_cast<int>(result);
		if (to_string(intValue) != "-2147483648") return to_string(intValue);
		else return "error";
	}
	else if (to_string(result) == "nan") {
		return "error";
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

