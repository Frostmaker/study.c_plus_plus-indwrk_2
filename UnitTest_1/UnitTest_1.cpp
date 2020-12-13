#include "pch.h"
#include "CppUnitTest.h"
#include "../IndividWork_2/defs.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest_1
{
	TEST_CLASS(CheckPositivityTest)
	{
	public:
		
		TEST_METHOD(CheckPositivityMethod1)
		{
			int* a = new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
			Assert::AreEqual(check_positivity(a, 10), false);
			delete[] a;
		}


		TEST_METHOD(CheckPositivityMethod2)
		{
			int* a = new int[10]{ -1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
			Assert::AreEqual(check_positivity(a, 10), false);
			delete[] a;
		}


		TEST_METHOD(CheckPositivityMethod3)
		{
			int* a = new int[7]{ 1, 2, 3, 4, -5, 6, 7 };
			Assert::AreEqual(check_positivity(a, 7), false);
			delete[] a;
		}


		TEST_METHOD(CheckPositivityMethod4)
		{
			int* a = new int[5]{ 1, 2, 3, 9, -6 };
			Assert::AreEqual(check_positivity(a, 5), false);
			delete[] a;
		}


		TEST_METHOD(CheckPositivityMethod5)
		{
			int* a = new int[5]{ 1, 2, 3, 4, 5 };
			Assert::AreEqual(check_positivity(a, 5), true);
			delete[] a;
		}
	};



	TEST_CLASS(DeleteCoupleTest)
	{
	public:

		TEST_METHOD(DeleteCoupleMethod1)
		{
			size_t len = 6;
			int* a = new int[len]{ 1, 2, 2, 2, 3, 4 };
			int* res = new int[4]{ 1, 2, 3, 4 };

			delete_elements(a, len);

			for (int i = 0; i < len; ++i)
				Assert::AreEqual(a[i], res[i]);
			
			delete[] a;
			delete[] res;
		}


		TEST_METHOD(DeleteCoupleMethod2)
		{
			size_t len = 6;
			int* a = new int[len] { 2, 2, 2, 4, 4, 4 };
			int* res = new int[4]{ 2, 4, 4, 4 };

			delete_elements(a, len);

			for (int i = 0; i < len; ++i)
				Assert::AreEqual(a[i], res[i]);

			delete[] a;
			delete[] res;
		}


		TEST_METHOD(DeleteCoupleMethod3)
		{
				size_t len = 6;
				int* a = new int[len] { 1, 2, 3, 4, 5, 6 };
				int* res = new int[len]{ 1, 2, 3, 4, 5, 6 };

				delete_elements(a, len);


				for (int i = 0; i < len; ++i)
					Assert::AreEqual(a[i], res[i]);

				delete[] a;
				delete[] res;
		}
	};



	TEST_CLASS(RemoveNegativeTest)
	{
	public:

		TEST_METHOD(RemoveNegativeMethod1)
		{
			size_t len = 6;
			int* a = new int[len] { 1, 2, 2, 2, 3, 4 };
			int* res = new int[len] { 1, 2, 2, 2, 3, 4 };

			remove_negative_rec(a, len);

			for (int i = 0; i < len; ++i)
				Assert::AreEqual(a[i], res[i]);

			delete[] a;
			delete[] res;
		}


		TEST_METHOD(RemoveNegativeMethod2)
		{
			size_t len = 6;
			int* a = new int[len] { 1, -1, 1, -1, 1, -1 };
			int* res = new int[len]{ 1, 0, 1, 0, 1, 0 };

			remove_negative_rec(a, len);

			for (int i = 0; i < len; ++i)
				Assert::AreEqual(a[i], res[i]);

			delete[] a;
			delete[] res;
		}
	};



	TEST_CLASS(FindElemTest)
	{
	public:

		TEST_METHOD(FindElemMethod1)
		{
			int size = 5;
			int m[MAX_ROWS][MAX_COLS] = {
				{1, 2, 3, 5, 6},
				{8, 9, 3, 5, 8},
				{4, 8, 5, 7, 3},
				{2, 8, 5, 4, 3},
				{3, 4, 8, 5, 7}
			};

			Assert::AreEqual(find_elem(m, size, 2), 3);
		}


		TEST_METHOD(FindElemMethod2)
		{
			int size = 4;
			int m[MAX_ROWS][MAX_COLS] = {
				{1, 2, 3, 5},
				{8, 9, 3, 5},
				{4, 8, 5, 7},
				{2, 8, 5, 4}
			};

			Assert::AreEqual(find_elem(m, size, 5), 9);
		}


		TEST_METHOD(FindElemMethod3)
		{
			auto f = [] ()
			{
				int size = 4;
				int m[MAX_ROWS][MAX_COLS] = {
					{1, 2, 3, 4},
					{5, 6, 7, 8},
					{9, 9, 9, 9},
					{9, 9, 9, 9}
				};
				find_elem(m, size, 7);
			};
			Assert::ExpectException<int>(f);
		}
	};



	TEST_CLASS(CreateVectorTest)
	{
	public:

		TEST_METHOD(CreateVectorMethod1)
		{
			int size = 5;
			int m[MAX_ROWS][MAX_COLS] = {
				{-1, 2, 3, 5, 6},
				{-8, -9, -3, -5, -8},
				{-4, -8, 0, 7, -3},
			};

			double* a = new double[3]{ -1, -6.6, -5 };
			double* res;
			res = create_vector(m, 3, 5);
			for (int i = 0; i < 3; ++i) {
				Assert::AreEqual(a[i], res[i]);
			}

			delete[] a;
			delete[] res;
		}


		TEST_METHOD(CreateVectorMethod2)
		{
			auto f = []()
			{
				int size = 4;
				int m[MAX_ROWS][MAX_COLS] = {
					{1, 2, 3, 4},
					{5, 6, 7, 8},
					{9, 9, 9, 9},
					{9, 9, 9, 9}
				};
				create_vector(m, size, size);
			};
			Assert::ExpectException<int>(f);
		}
	};
}
