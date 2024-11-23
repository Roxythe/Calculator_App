#include "CalculatorProcessor.h"
#include <cmath>
#include <stdexcept>
#include <sstream>
#include <iostream>
#include <wx/wx.h>

CalculatorProcessor* CalculatorProcessor::GetInstance()
{
	static CalculatorProcessor instance;
	return &instance;
}

double CalculatorProcessor::Calculate(const std::string& expression)
{
	std::queue<std::string> outputQue; // Postfix notation queue
	std::stack<std::string> operatorStack; // Operator for shunting yard algorithm

	// Tokenize input expression
	std::istringstream stream(expression);
	std::string token;

	// Shunting yard algorithm convert to postfix notation
	while (stream >> token)
	{
		if (IsUnaryFunction(token))
		{
			operatorStack.push(token);
		}

		// Check if token is a positive or negative number and adjust for negative number tokens
		else if (isdigit(token[0]) || (token[0] == '-' && token.length() > 1) ||
			(token[0] == '.' && token.length() > 1 && isdigit(token[1])))
		{
			// Exception handling for decimal edge cases
			if (token.find("..") != std::string::npos)
			{
				throw std::invalid_argument("Invalid number format: consecutive decimals!");
			}
			if (token == ".")
			{
				throw std::invalid_argument("Invalid number format: standalone decimal!");
			}
			// Check for concatenated token (ex: .9TAN)
			if (token.find("SIN") != std::string::npos ||
				token.find("COS") != std::string::npos ||
				token.find("TAN") != std::string::npos)
			{
				throw std::invalid_argument("Invalid token!");
			}

			outputQue.push(token); // Number
		}
		else if (IsOperator(token[0]))
		{
			while (!operatorStack.empty() && IsHigherPrecedence(operatorStack.top(), token))
			{
				outputQue.push(operatorStack.top());
				operatorStack.pop();
			}
			operatorStack.push(token);
		}
		else
		{
			throw std::invalid_argument("Invalid token in expression: " + token);
		}
	}

	// Pop remaining operators
	while (!operatorStack.empty())
	{
		outputQue.push(operatorStack.top());
		operatorStack.pop();
	}

	// Evaluate postfix expression
	std::stack<double> evalStack;
	while (!outputQue.empty())
	{
		token = outputQue.front();
		outputQue.pop();

		if (isdigit(token[0]) || (token[0] == '-' && token.length() > 1) ||
			(token[0] == '.' && token.length() > 1 && isdigit(token[1])))
		{
			evalStack.push(std::stod(token)); // Convert string to double
		}
		else if (IsOperator(token[0]))
		{
			// Check there are at least two operands
			if (evalStack.size() < 2)
			{
				throw std::invalid_argument("Expression needs at least two operands!");
			}

			// Pop two operands for operation
			double operand2 = evalStack.top(); evalStack.pop();
			double operand1 = evalStack.top(); evalStack.pop();

			// Apply operation and push to stack
			evalStack.push(ApplyOperation(operand1, operand2, token[0]));
		}
		else if (IsUnaryFunction(token)) // Highest tier precedence
		{
			if (evalStack.empty())
			{
				throw std::invalid_argument("Insufficient operand for unary function!");
			}
			double operand = evalStack.top();
			evalStack.pop();
			evalStack.push(ApplyUnaryFunction(token, operand));
		}
	}

	if (evalStack.size() != 1)
	{
		throw std::invalid_argument("Invalid expression: missing operator or incomplete expression!");
	}

	return evalStack.top();
}

double CalculatorProcessor::ApplyOperation(double operand1, double operand2, char operation)
{
	switch (operation)
	{
	case '+': return operand1 + operand2;
	case '-': return operand1 - operand2;
	case '*': return operand1 * operand2;
	case '/':
		if (operand2 == 0) throw std::domain_error("Division by zero undefined!");
		return operand1 / operand2;
	case '%':
		if (operand2 == 0) throw std::domain_error("Modulo zero undefined!");
		return static_cast<int>(operand1) % static_cast<int>(operand2);
	default: throw std::invalid_argument("Invalid operator!");
	}
}

double CalculatorProcessor::ApplyUnaryFunction(const std::string& func, double operand)
{
	if (func == "SIN") return std::sin(operand);
	if (func == "COS") return std::cos(operand);
	if (func == "TAN") return std::tan(operand);
	throw std::invalid_argument("Invalid function!"); // If no valid unary used
}

bool CalculatorProcessor::IsOperator(char oper) const
{
	return oper == '+' || oper == '-' || oper == '*' || oper == '/' || oper == '%';
}

bool CalculatorProcessor::IsUnaryFunction(const std::string& token) const
{
	return token == "SIN" || token == "COS" || token == "TAN";
}

int CalculatorProcessor::GetPrecedence(char op) const
{
	switch (op)
	{
	case '-': case '+': return 1; // Lowest tier precedence
	case '*': case '/': case '%':return 2; // Mid tier
	default: return 0;
	}
}

// Highest precedence operation
bool CalculatorProcessor::IsHigherPrecedence(const std::string& op1, std::string& op2) const
{
	if (IsUnaryFunction(op1)) return true;
	return GetPrecedence(op1[0]) > GetPrecedence(op2[0]);
}
