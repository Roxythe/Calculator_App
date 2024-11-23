#include "CalculatorApp.h"
#include "CalculatorFrame.h"

bool CalculatorApp::OnInit() 
{
	CalculatorFrame* calculator = new CalculatorFrame("Calculator");
	calculator->Show(true);
	return true;
}





