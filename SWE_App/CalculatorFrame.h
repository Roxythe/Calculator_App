#pragma once
#include <wx/wx.h>
#include <wx/grid.h>
#include <wx/tokenzr.h>


class CalculatorFrame : public wxFrame {
public:
	CalculatorFrame(const wxString& title);

	wxTextCtrl* display; // shows input and result
	wxBoxSizer* mainSizer;

	friend class ButtonFactory;
	void CreateButtons();
	void PerformCalculation();

	// Event Handler
	void OnButtonClicked(wxCommandEvent& event);

};
