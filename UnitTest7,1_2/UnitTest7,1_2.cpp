#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_7.1_2/lab_7.1_2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestCreateFunction)
        {
            int inputMatrix[2][4] = { {14, 14, 12, 14 }, { 14, 11, 14, 11 } };
            int** b = new int* [2];
            for (int i = 0; i < 2; i++)
                b[i] = new int[4];

            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    b[i][j] = inputMatrix[i][j];
                }
            }

          


            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    Assert::AreEqual(b[i][j], inputMatrix[i][j]);
                }
            }
        }
    };
}
