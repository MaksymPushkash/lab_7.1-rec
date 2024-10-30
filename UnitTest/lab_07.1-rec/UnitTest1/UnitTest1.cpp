#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_07.1-rec/lab_07.1-rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestMatrixProcessing
{
    TEST_CLASS(UnitTestMatrixProcessing)
    {
    public:

        TEST_METHOD(TestGenerateMatrix)
        {
            vector<vector<int>> matrix(7, vector<int>(6));
            generateMatrix(matrix, 7, 6, 7, 62);

            // Перевірка на розмір матриці
            Assert::AreEqual((int)matrix.size(), 7);
            Assert::AreEqual((int)matrix[0].size(), 6);

            // Перевірка на діапазон значень
            bool isWithinRange = true;
            for (const auto& row : matrix) {
                for (int val : row) {
                    if (val < 7 || val > 62) {
                        isWithinRange = false;
                        break;
                    }
                }
                if (!isWithinRange) break;
            }
            Assert::IsTrue(isWithinRange);
        }

        
    };
}
