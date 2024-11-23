#include "pch.h"
#include "CppUnitTest.h"
#include "../SWE_App/CalculatorProcessor.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorProcessorTests
{
	TEST_CLASS(CalculatorProcessorTests)
	{
	public:

		TEST_METHOD(TestAddition)
		{
			CalculatorProcessor* processor = CalculatorProcessor::GetInstance();
			double result = processor->Calculate("2 + 2");
			Assert::AreEqual(4.0, result);
		}

		TEST_METHOD(TestSubtraction)
		{
			CalculatorProcessor* processor = CalculatorProcessor::GetInstance();
			double result = processor->Calculate("5 - 3");
			Assert::AreEqual(2.0, result);
		}

		TEST_METHOD(TestMultiply)
		{
			CalculatorProcessor* processor = CalculatorProcessor::GetInstance();
			double result = processor->Calculate("3 * 4");
			Assert::AreEqual(12.0, result);
		}

		TEST_METHOD(TestDivide)
		{
			CalculatorProcessor* processor = CalculatorProcessor::GetInstance();
			double result = processor->Calculate("8 / 2");
			Assert::AreEqual(4.0, result);
		}

		TEST_METHOD(TestModulo)
		{
			CalculatorProcessor* processor = CalculatorProcessor::GetInstance();
			double result = processor->Calculate("9 % 4");
			Assert::AreEqual(1.0, result);
		}

		TEST_METHOD(TestNegative)
		{
			CalculatorProcessor* processor = CalculatorProcessor::GetInstance();
			double result = processor->Calculate("-4 + -4");
			Assert::AreEqual(-8.0, result);
		}

		TEST_METHOD(TestSin)
		{
			CalculatorProcessor* processor = CalculatorProcessor::GetInstance();
			double result = processor->Calculate("SIN 0");
			Assert::AreEqual(0.0, result);
		}


		TEST_METHOD(TestTan)
		{
			CalculatorProcessor* processor = CalculatorProcessor::GetInstance();
			double result = processor->Calculate("TAN 0");
			Assert::AreEqual(0.0, result);
		}

		TEST_METHOD(TestPEMDAS)
		{
			CalculatorProcessor* processor = CalculatorProcessor::GetInstance();
			double result = processor->Calculate("2 + 3 * 4");
			Assert::AreEqual(14.0, result);
		}

		TEST_METHOD(TestInvalidExpression)
		{
			CalculatorProcessor* processor = CalculatorProcessor::GetInstance();
			try
			{
				processor->Calculate("2 +");
				Assert::Fail(L"No exception thrown for invalid expression.");
			}
			catch (const std::invalid_argument&) {}
		}

	};
}