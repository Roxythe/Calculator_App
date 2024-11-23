#include "pch.h"
#include <wx/wx.h>

class TestApp : public wxApp
{
public:
	virtual bool OnInIt() { return true; }
};

wxIMPLEMENT_APP_NO_MAIN(TestApp);