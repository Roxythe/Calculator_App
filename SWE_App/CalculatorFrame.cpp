#include "ButtonFactory.h"
#include <cmath>
#include "CalculatorProcessor.h"

CalculatorFrame::CalculatorFrame(const wxString& title)
	: wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(400, 500)),
	mainSizer(new wxBoxSizer(wxVERTICAL))
{
	// Display for the top of calculator
	display = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(380, 50), wxTE_RIGHT);
	display->SetEditable(false); // Prevent user from typing directly into display

	// Main sizer
	mainSizer->Add(display, 0, wxEXPAND | wxALL, 5);

	wxGridSizer* gridSizer = ButtonFactory::CreateButtonGrid(this);
	mainSizer->Add(gridSizer, 1, wxEXPAND | wxALL, 5);

	SetSizer(mainSizer);
	mainSizer->Fit(this);
}

void CalculatorFrame::PerformCalculation()
{
	try
	{
		double result = CalculatorProcessor::GetInstance()->Calculate(display->GetValue().ToStdString());
		display->SetValue(wxString::Format("%g", result));
	}
	catch (const std::exception& exception)
	{
		wxLogError("Calculation error: %s", exception.what());
		display->Clear();
	}
}

// On click event
void CalculatorFrame::OnButtonClicked(wxCommandEvent& event)
{
	wxButton* button = dynamic_cast<wxButton*>(event.GetEventObject());
	if (button == nullptr) return; // Safety check

	// Get label to identify button function
	wxString label = button->GetLabel();

	if (label.IsNumber() || label == ButtonLabel::Decimal || label == ButtonLabel::Add ||
		label == ButtonLabel::Subtract || label == ButtonLabel::Multiply || label == ButtonLabel::Divide ||
		label == ButtonLabel::Modulo || label == ButtonLabel::Sin || label == ButtonLabel::Cos ||
		label == ButtonLabel::Tan)
	{
		ButtonFactory::AppendToDisplay(this, label);
	}
	else if (label == ButtonLabel::Negative)
	{
		ButtonFactory::AppendToDisplay(this, "-"); // Add '-' to display in place of "-X" label
	}
	else if (label == ButtonLabel::Clear)
	{
		ButtonFactory::ClearDisplay(this);
	}
	else if (label == ButtonLabel::Backspace)
	{
		ButtonFactory::Backspace(this);
	}
	else if (label == ButtonLabel::Equal)
	{
		PerformCalculation();
	}
}