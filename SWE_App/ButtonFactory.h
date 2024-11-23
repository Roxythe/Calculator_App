#pragma once
#include <wx/wx.h>
#include <wx/colour.h>
#include "CalculatorFrame.h"

// Colors for buttons
namespace ButtonColor
{
	const wxColour NumberButtonColor = wxColour(170, 215, 230); // Light blue
	const wxColour OperatorButtonColor = wxColour(200, 100, 70); // Orange
	const wxColour EqualButtonColor = wxColour(145, 240, 145); // Light green
	const wxColour UnaryButtonColor = wxColour(150, 80, 150); // Purple
	const wxColour AuxButtonColor = wxColour(170, 115, 80); // Brown
	const wxColour ClearButtonColor = wxColour(255, 30, 30); // Red
	const wxColour BackspaceButtonColor = wxColour(190, 90, 90); // Pink
}

// Button labels displayed on calculator frame
namespace ButtonLabel
{
	const wxString Add = " + ";
	const wxString Subtract = " - ";
	const wxString Multiply = " * ";
	const wxString Divide = " / ";
	const wxString Modulo = " % ";
	const wxString Sin = "SIN ";
	const wxString Cos = "COS ";
	const wxString Tan = "TAN ";
	const wxString Equal = "=";
	const wxString Clear = "Clear";
	const wxString Backspace = "Delete";
	const wxString Negative = "-X";
	const wxString Decimal = ".";
}

class ButtonFactory
{
public:

	// Generic method to make button/grid
	static wxButton* CreateButton(wxWindow* parent, wxWindowID id, const wxString& label, const wxPoint& position, const wxSize& size);
	static wxGridSizer* CreateButtonGrid(CalculatorFrame* parent);

	// Specific button method
	static wxButton* CreateAdditionButton(wxWindow* parent);
	static wxButton* CreateSubtractionButton(wxWindow* parent);
	static wxButton* CreateMultiplyButton(wxWindow* parent);
	static wxButton* CreateDivisionButton(wxWindow* parent);
	static wxButton* CreateModuloButton(wxWindow* parent);

	static wxButton* CreateSinButton(wxWindow* parent);
	static wxButton* CreateCosButton(wxWindow* parent);
	static wxButton* CreateTanButton(wxWindow* parent);

	static wxButton* CreateEqualButton(wxWindow* parent);
	static wxButton* CreateClearButton(wxWindow* parent);
	static wxButton* CreateBackspaceButton(wxWindow* parent);
	static wxButton* CreateDecimalButton(wxWindow* parent);
	static wxButton* CreateNegativeButton(wxWindow* parent);

	static wxButton* CreateNumberButton(wxWindow* parent, int number);

	// Helper functions
	static void AppendToDisplay(CalculatorFrame* frame, const wxString& text);
	static void ClearDisplay(CalculatorFrame* frame);
	static void Backspace(CalculatorFrame* frame);
};

