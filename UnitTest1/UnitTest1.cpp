#include "pch.h"
#include "CppUnitTest.h"
#include <queue>
#include "../LB_12.6.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestCreateQueueFromFile)
        {
            // Arrange
            queue<char> testQueue;
            string filename = "test_input.txt";
            ofstream file(filename);
            if (!file.is_open()) {
                Assert::Fail(L"Failed to create test file.");
            }
            file << "Test string for createQueueFromFile function.";
            file.close();

            // Act
            createQueueFromFile(testQueue, filename);

            // Assert
            Assert::AreEqual((size_t)45, testQueue.size());
        }

        TEST_METHOD(TestSelectEnglishChars)
        {
            // Arrange
            queue<char> originalQueue;
            originalQueue.push('H');
            originalQueue.push('e');
            originalQueue.push('l');
            originalQueue.push('l');
            originalQueue.push('o');
            originalQueue.push(' ');
            originalQueue.push('W');
            originalQueue.push('o');
            originalQueue.push('r');
            originalQueue.push('l');
            originalQueue.push('d');
            originalQueue.push('!');
            queue<char> englishCharsQueue;
            queue<char> otherCharsQueue;

            // Act
            selectEnglishChars(originalQueue, englishCharsQueue, otherCharsQueue);

            // Assert
            Assert::AreEqual((size_t)8, englishCharsQueue.size());
            Assert::AreEqual((size_t)4, otherCharsQueue.size());
        }
	};
}
