#include "pch.h"
#include "CppUnitTest.h"
#include "../SWE_App/ButtonFactory.h"
#include "../SWE_App/CalculatorFrame.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ButtonFactoryTests
{
	TEST_CLASS(ButtonFactoryTests)
	{

	private:
		wxFrame* testParent;

	public:

		// Initialize wxWidgets before running tests
		TEST_CLASS_INITIALIZE(InitializeWxWidgets)
			{
			wxEntryStart(nullptr, nullptr);
			}

		// Clean up wxWidgets after tests
		TEST_CLASS_CLEANUP(CleanupWxWidgets)
		{
			wxEntryCleanup();
		}

		TEST_METHOD(TestAdditionButtonLabel)
		{
			wxFrame* testParent = new wxFrame(nullptr, wxID_ANY, "Test Frame"); // Create temp frame
			wxButton* button = ButtonFactory::CreateAdditionButton(testParent);
			Assert::AreEqual(" + ", button->GetLabel());
			testParent->Destroy(); // Clean up temp frame
		}

		TEST_METHOD(TestSinButtonLabel)
		{
			wxFrame* testParent = new wxFrame(nullptr, wxID_ANY, "Test Frame");
			wxButton* button = ButtonFactory::CreateSinButton(testParent);
			Assert::AreEqual("SIN ", button->GetLabel());
			testParent->Destroy();
		}

		TEST_METHOD(TestDecimalButtonLabel)
		{
			wxFrame* testParent = new wxFrame(nullptr, wxID_ANY, "Test Frame");
			wxButton* button = ButtonFactory::CreateDecimalButton(testParent);
			Assert::AreEqual(".", button->GetLabel());
			testParent->Destroy();
		}

		TEST_METHOD(TestNumberButton)
		{
			wxFrame* testParent = new wxFrame(nullptr, wxID_ANY, "Test Frame");
			wxButton* button = ButtonFactory::CreateNumberButton(testParent, 5);
			Assert::AreEqual("5", button->GetLabel().ToStdString().c_str());
			testParent->Destroy();
		}

		TEST_METHOD(TestButtonSize)
		{
			wxFrame* testParent = new wxFrame(nullptr, wxID_ANY, "Test Frame");
			wxButton* button = ButtonFactory::CreateAdditionButton(testParent);
			Assert::IsTrue(button->GetSize().GetWidth() > 0);
			Assert::IsTrue(button->GetSize().GetHeight() > 0);
			testParent->Destroy();
		}

		TEST_METHOD(TestButtonPosition)
		{
			wxFrame* testParent = new wxFrame(nullptr, wxID_ANY, "Test Frame");
			wxButton* button = ButtonFactory::CreateAdditionButton(testParent);
			Assert::IsTrue(button->GetPosition().x >= 0);
			Assert::IsTrue(button->GetPosition().y >= 0);
			testParent->Destroy();
		}

		TEST_METHOD(TestOperatorBackgroundColor)
		{
			wxFrame* testParent = new wxFrame(nullptr, wxID_ANY, "Test Frame");
			wxButton* button = ButtonFactory::CreateAdditionButton(testParent);
			Assert::IsTrue(button->GetBackgroundColour() == ButtonColor::OperatorButtonColor);
			testParent->Destroy();
		}

		TEST_METHOD(TestUnaryBackgroundColor)
		{
			wxFrame* testParent = new wxFrame(nullptr, wxID_ANY, "Test Frame");
			wxButton* button = ButtonFactory::CreateCosButton(testParent);
			Assert::IsTrue(button->GetBackgroundColour() == ButtonColor::UnaryButtonColor);
			testParent->Destroy();
		}

		TEST_METHOD(TestClearDisplay)
		{
			// Test frame/display
			wxFrame* testParent = new wxFrame(nullptr, wxID_ANY, "Test Frame");
			CalculatorFrame* frame = new CalculatorFrame("Test Calculator");

			frame->display->SetValue("1234"); // Add values to display
			ButtonFactory::ClearDisplay(frame); // Call clear display method

			Assert::IsTrue(frame->display->IsEmpty());

			// Cleanup
			testParent->Destroy();
			frame->Destroy();
		}

		TEST_METHOD(TestBackspace)
		{
			// Test frame/display
			wxFrame* testParent = new wxFrame(nullptr, wxID_ANY, "Test Frame");
			CalculatorFrame* frame = new CalculatorFrame("Test Calculator");

			frame->display->SetValue("9"); // Add value to display
			ButtonFactory::Backspace(frame); // Call backspace method

			Assert::IsTrue(frame->display->IsEmpty());

			// Cleanup
			testParent->Destroy();
			frame->Destroy();
		}
	};
}