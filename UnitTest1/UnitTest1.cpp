#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_7.2/7.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMethod1)
		{
            const int k = 4;
            const int n = 4;
            int** matrix = new int* [k];
            for (int i = 0; i < k; i++)
                matrix[i] = new int[n];

            int testMatrix[4][4] = {
                {4, 2, 3, 1},
                {10, 7, 8, 9},
                {5, 6, 1, 0},
                {2, 20, 15, 10}
            };

            for (int i = 0; i < k; i++)
                for (int j = 0; j < n; j++)
                    matrix[i][j] = testMatrix[i][j];

            SwapMaxMin(matrix, k, n);

            Assert::AreEqual(matrix[0][3], 10);
            Assert::AreEqual(matrix[1][0], 1);

            Assert::AreEqual(matrix[2][3], 20);
            Assert::AreEqual(matrix[3][1], 0);

            for (int i = 0; i < k; i++)
                delete[] matrix[i];
            delete[] matrix;
		}
	};
}