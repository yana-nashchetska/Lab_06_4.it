#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_06_4.it/Lab_06_4.it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64it
{
	TEST_CLASS(UnitTest64it)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int m[5] = { 20, -10, -67, 35, 11 };
			int t = Sum(m, 5);
			Assert::AreEqual(t, 113);
		}
	};
}
