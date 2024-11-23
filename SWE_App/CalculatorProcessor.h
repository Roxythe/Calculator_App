#pragma once
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <wx/wx.h>

class CalculatorProcessor
{
public:
	// Singleton instance
	static CalculatorProcessor* GetInstance();

	// Calculate method
	double Calculate(const std::string& expression);

private:
	// Default constructor
	CalculatorProcessor() {}

	// Delete copy constructor and assignment operator
	CalculatorProcessor(const CalculatorProcessor&) = delete;
	CalculatorProcessor& operator=(const CalculatorProcessor&) = delete;

	// Helper function for calculation
	double ApplyOperation(double operand1, double operand2, char operation);
	double ApplyUnaryFunction(const std::string& func, double operand);

	// Shunting yard helpers
	bool IsOperator(char oper) const;
	bool IsUnaryFunction(const std::string& token) const;
	int GetPrecedence(char op) const;
	bool IsHigherPrecedence(const std::string& op1, std::string& op2) const;

};

