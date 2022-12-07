#include "pch.h"
#include "CppUnitTest.h"
#include "../ChyrunSofialab7.2.2/ChyrunSofialab7.2.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest722
{
	TEST_CLASS(UnitTest722)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t;
			const int l = 6, n = 1;
			int max = 0, k = 0, imax = 0, jmax = 0;
			int** a = new int* [l];
			for (int i = 0; i < l; i++)
				a[i] = new int[n];
			for (int i = 0; i < l; i++)
				for (int j = 0; j < n; j++)
					a[i][j] = i + j + 1;
			t = Max(a, jmax, l, max, imax,0);
			Assert::AreEqual(t, 6);
		}
	};
}
