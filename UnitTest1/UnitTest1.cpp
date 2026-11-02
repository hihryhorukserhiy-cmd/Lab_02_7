#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_2_7/Set.h"
#include"../lab_2_7/BitString.h"
#include "../lab_2_7/Set.cpp"
#include"../lab_2_7/BitString.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			BitString bs(0, 1);
			BitString bsShihft = bs << 3;
			Assert::AreEqual(8UL, bsShihft.GetLow());
		}
	};
}
