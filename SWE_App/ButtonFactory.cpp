#include "ButtonFactory.h"


//Generic method
wxButton* ButtonFactory::CreateButton(wxWindow* parent, wxWindowID id, const wxString& label, const wxPoint& position, const wxSize& size)
{
	return new wxButton(parent, id, label, position, size);
}

wxGridSizer* ButtonFactory::CreateButtonGrid(CalculatorFrame* parent)
{
	//Grid sizer to organize calculator buttons
	wxGridSizer* gridSizer = new wxGridSizer(6, 4, 5, 5); // Grid dimensions and gap sizes

	// Add buttons to grid sizer
	gridSizer->Add(CreateClearButton(parent), 0, wxEXPAND); // Clear display)
	gridSizer->Add(CreateBackspaceButton(parent), 0, wxEXPAND); // Delete last char in display
	gridSizer->Add(CreateNegativeButton(parent), 0, wxEXPAND); // Declare number as negative
	gridSizer->Add(CreateEqualButton(parent), 0, wxEXPAND); // Calculate answer

	for (int i = 1; i <= 3; ++i) gridSizer->Add(CreateNumberButton(parent, i), 0, wxEXPAND); // 1-3
	gridSizer->Add(CreateAdditionButton(parent), 0, wxEXPAND); // Add

	for (int i = 4; i <= 6; ++i) gridSizer->Add(CreateNumberButton(parent, i), 0, wxEXPAND); // 4-6
	gridSizer->Add(CreateSubtractionButton(parent), 0, wxEXPAND); // Subtract

	for (int i = 7; i <= 9; ++i) gridSizer->Add(CreateNumberButton(parent, i), 0, wxEXPAND); // 7-9
	gridSizer->Add(CreateMultiplyButton(parent), 0, wxEXPAND); // Multiply

	gridSizer->Add(CreateDecimalButton(parent), 0, wxEXPAND); // Decimal
	gridSizer->Add(CreateNumberButton(parent, 0), 0, wxEXPAND); // 0 number
	gridSizer->Add(CreateDecimalButton(parent), 0, wxEXPAND); // Decimal
	gridSizer->Add(CreateDivisionButton(parent), 0, wxEXPAND); // Division

	gridSizer->Add(CreateSinButton(parent), 0, wxEXPAND); // Sin function
	gridSizer->Add(CreateCosButton(parent), 0, wxEXPAND); // Cos function
	gridSizer->Add(CreateTanButton(parent), 0, wxEXPAND); // Tan function
	gridSizer->Add(CreateModuloButton(parent), 0, wxEXPAND); // Modulo operator

	return gridSizer;
}

// Specific methods for operator buttons
wxButton* ButtonFactory::CreateAdditionButton(wxWindow* parent)
{
	wxButton* button = CreateButton(parent, wxID_ANY, ButtonLabel::Add, wxDefaultPosition, wxDefaultSize);
	button->SetBackgroundColour(ButtonColor::OperatorButtonColor);
	button->Bind(wxEVT_BUTTON, &CalculatorFrame::OnButtonClicked, static_cast<CalculatorFrame*>(parent));
	return button;
}

wxButton* ButtonFactory::CreateSubtractionButton(wxWindow* parent)
{
	wxButton* button = CreateButton(parent, wxID_ANY, ButtonLabel::Subtract, wxDefaultPosition, wxDefaultSize);
	button->SetBackgroundColour(ButtonColor::OperatorButtonColor);
	button->Bind(wxEVT_BUTTON, &CalculatorFrame::OnButtonClicked, static_cast<CalculatorFrame*>(parent));
	return button;
}

wxButton* ButtonFactory::CreateMultiplyButton(wxWindow* parent)
{
	wxButton* button = CreateButton(parent, wxID_ANY, ButtonLabel::Multiply, wxDefaultPosition, wxDefaultSize);
	button->SetBackgroundColour(ButtonColor::OperatorButtonColor);
	button->Bind(wxEVT_BUTTON, &CalculatorFrame::OnButtonClicked, static_cast<CalculatorFrame*>(parent));
	return button;
}

wxButton* ButtonFactory::CreateDivisionButton(wxWindow* parent)
{
	wxButton* button = CreateButton(parent, wxID_ANY, ButtonLabel::Divide, wxDefaultPosition, wxDefaultSize);
	button->SetBackgroundColour(ButtonColor::OperatorButtonColor);
	button->Bind(wxEVT_BUTTON, &CalculatorFrame::OnButtonClicked, static_cast<CalculatorFrame*>(parent));
	return button;
}

wxButton* ButtonFactory::CreateModuloButton(wxWindow* parent)
{
	wxButton* button = CreateButton(parent, wxID_ANY, ButtonLabel::Modulo, wxDefaultPosition, wxDefaultSize);
	button->SetBackgroundColour(ButtonColor::OperatorButtonColor);
	button->Bind(wxEVT_BUTTON, &CalculatorFrame::OnButtonClicked, static_cast<CalculatorFrame*>(parent));
	return button;
}

// Specific methods for unary buttons
wxButton* ButtonFactory::CreateSinButton(wxWindow* parent)
{
	wxButton* button = CreateButton(parent, wxID_ANY, ButtonLabel::Sin, wxDefaultPosition, wxDefaultSize);
	button->SetBackgroundColour(ButtonColor::UnaryButtonColor);
	button->Bind(wxEVT_BUTTON, &CalculatorFrame::OnButtonClicked, static_cast<CalculatorFrame*>(parent));
	return button;
}

wxButton* ButtonFactory::CreateCosButton(wxWindow* parent)
{
	wxButton* button = CreateButton(parent, wxID_ANY, ButtonLabel::Cos, wxDefaultPosition, wxDefaultSize);
	button->SetBackgroundColour(ButtonColor::UnaryButtonColor);
	button->Bind(wxEVT_BUTTON, &CalculatorFrame::OnButtonClicked, static_cast<CalculatorFrame*>(parent));
	return button;
}

wxButton* ButtonFactory::CreateTanButton(wxWindow* parent)
{
	wxButton* button = CreateButton(parent, wxID_ANY, ButtonLabel::Tan, wxDefaultPosition, wxDefaultSize);
	button->SetBackgroundColour(ButtonColor::UnaryButtonColor);
	button->Bind(wxEVT_BUTTON, &CalculatorFrame::OnButtonClicked, static_cast<CalculatorFrame*>(parent));
	return button;
}

// Specific methods for auxiliary/augmenter buttons
wxButton* ButtonFactory::CreateEqualButton(wxWindow* parent)
{
	wxButton* button = CreateButton(parent, wxID_ANY, ButtonLabel::Equal, wxDefaultPosition, wxDefaultSize);
	button->SetBackgroundColour(ButtonColor::EqualButtonColor);
	button->Bind(wxEVT_BUTTON, &CalculatorFrame::OnButtonClicked, static_cast<CalculatorFrame*>(parent));
	return button;
}

wxButton* ButtonFactory::CreateClearButton(wxWindow* parent)
{
	wxButton* button = CreateButton(parent, wxID_ANY, ButtonLabel::Clear, wxDefaultPosition, wxDefaultSize);
	button->SetBackgroundColour(ButtonColor::ClearButtonColor);
	button->Bind(wxEVT_BUTTON, &CalculatorFrame::OnButtonClicked, static_cast<CalculatorFrame*>(parent));
	return button;
}

wxButton* ButtonFactory::CreateBackspaceButton(wxWindow* parent)
{
	wxButton* button = CreateButton(parent, wxID_ANY, ButtonLabel::Backspace, wxDefaultPosition, wxDefaultSize);
	button->SetBackgroundColour(ButtonColor::BackspaceButtonColor);
	button->Bind(wxEVT_BUTTON, &CalculatorFrame::OnButtonClicked, static_cast<CalculatorFrame*>(parent));
	return button;
}

wxButton* ButtonFactory::CreateDecimalButton(wxWindow* parent)
{
	wxButton* button = CreateButton(parent, wxID_ANY, ButtonLabel::Decimal, wxDefaultPosition, wxDefaultSize);
	button->SetBackgroundColour(ButtonColor::NumberButtonColor);
	button->Bind(wxEVT_BUTTON, &CalculatorFrame::OnButtonClicked, static_cast<CalculatorFrame*>(parent));
	return button;
}

wxButton* ButtonFactory::CreateNegativeButton(wxWindow* parent)
{
	wxButton* button = CreateButton(parent, wxID_ANY, ButtonLabel::Negative, wxDefaultPosition, wxDefaultSize);
	button->SetBackgroundColour(ButtonColor::AuxButtonColor);
	button->Bind(wxEVT_BUTTON, &CalculatorFrame::OnButtonClicked, static_cast<CalculatorFrame*>(parent));
	return button;
}

// Specific methods for number buttons
wxButton* ButtonFactory::CreateNumberButton(wxWindow* parent, int number)
{
	wxButton* button = CreateButton(parent, wxID_ANY, wxString::Format("%d", number), wxDefaultPosition, wxDefaultSize);
	button->SetBackgroundColour(ButtonColor::NumberButtonColor);
	button->Bind(wxEVT_BUTTON, &CalculatorFrame::OnButtonClicked, static_cast<CalculatorFrame*>(parent));
	return button;
}

// Helper event methods
void ButtonFactory::AppendToDisplay(CalculatorFrame* frame, const wxString& text)
{
	frame->display->AppendText(text);
}

void ButtonFactory::ClearDisplay(CalculatorFrame* frame)
{
	frame->display->Clear();
}

void ButtonFactory::Backspace(CalculatorFrame* frame)
{
	wxString currentText = frame->display->GetValue();
	if (!currentText.IsEmpty())
	{
		currentText.RemoveLast();
		frame->display->SetValue(currentText);
	}
}