#include "pch.h"
#include "CppUnitTest.h"
#include "../CDDS_Optimise/HashTable.h"
#include "../CDDS_Optimise/HashTable.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CDDSOptimiseTask2Test
{
	TEST_CLASS(CDDSOptimiseTask2Test)
	{
	public:
		
		TEST_METHOD(HashDataReturn)
		{
			HashTable<int> table;
			table.Add(10, "Ten");
			Assert::AreEqual(table["Ten"], 10);
		}
		TEST_METHOD(HashDataRemove)
		{
			HashTable<int> table;
			table.Add(10, "Ten");
			table.Remove("Ten");
			Assert::AreEqual(table["Ten"], NULL);
		}
		TEST_METHOD(HashTableClear)
		{
			HashTable<int> table;
			table.Add(10, "Ten");
			table.Add(20, "Twenty");
			table.Clear();
			Assert::AreEqual(table["Ten"], NULL);
			Assert::AreEqual(table["Twenty"], NULL);
		}
	};
}
