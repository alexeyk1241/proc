#include "stdafx.h"
#include "CppUnitTest.h"
#include "C:\Users\Алексей\source\repos\ConsoleApplication4\ConsoleApplication4\Numbers.cpp"
#include <vector>

using namespace simple_shapes;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;


namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
		void testfiles(ifstream &in, ifstream &in_test)
		{
			vector<string> strings1;
			string test;
			while (!getline(in, test).eof())
				strings1.push_back(test);
			strings1.push_back(test);

			vector<string> strings2;
			string out;
			while (!getline(in_test, out).eof())
				strings2.push_back(out);
			strings2.push_back(out);

			for (int i = 0; i < out.length(); i++)
			{
				Assert::AreEqual(strings1[i], strings2[i]);
			}
		}

	public:
		
		TEST_METHOD(TestSimple)
		{
				ifstream ifst("test_simple.txt");

				vector<string> string1;
				string1.push_back("2");
				string1.push_back("5 10 см");

				vector<string> string2;
				string out;
				while (!getline(ifst, out).eof())
				{
					string2.push_back(out);
				}
				string2.push_back(out);


				for (int i = 0; i < string2.size(); i++)
				{
					Assert::AreEqual(string1[i], string2[i]);
				}
		}

		TEST_METHOD(TestComplex)
		{
			ifstream ifst("test_complex.txt");

			vector<string> string1;
			string1.push_back("1");
			string1.push_back("12 -169 м");

			vector<string> string2;
			string out;
			while (!getline(ifst, out).eof())
			{
				string2.push_back(out);
			}
			string2.push_back(out);


			for (int i = 0; i < string2.size(); i++)
			{
				Assert::AreEqual(string1[i], string2[i]);
			}
		}

		TEST_METHOD(TestPolcoor)
		{
			ifstream ifst("test_polcoor.txt");

			vector<string> string1;
			string1.push_back("3");
			string1.push_back("20 40");

			vector<string> string2;
			string out;
			while (!getline(ifst, out).eof())
			{
				string2.push_back(out);
			}
			string2.push_back(out);


			for (int i = 0; i < string2.size(); i++)
			{
				Assert::AreEqual(string1[i], string2[i]);
			}
		}

		TEST_METHOD(TestInSort)
		{
			ifstream ifst("filein.txt");//Входной фаил
			ofstream ofst("fileout.txt", ios::trunc);//Выходной
			container c;
			Init(c);
			In(c,ifst);
			Sort(c);
			Out(c,ofst);

			ifstream in("fileout.txt");//Выходной
			ifstream in_test("out_test.txt");//Образец выходного

			testfiles(in, in_test);
		}

		TEST_METHOD(TestResSimple)
		{
			ifstream ifst("test_simple.txt");
			container c;
			Init(c);
			In(c, ifst);
			numbers *s = new numbers;
			simple* t = new simple;
			s = (numbers*)InSimple(*t, ifst);
			s->key = SIMPLE;
			Node* current = c.Top;
			float Ressimple = numbers_s(current->data);
			float test = 0.5;

			Assert::AreEqual(Ressimple, test);
		}

		TEST_METHOD(TestResComplex)
		{
			ifstream ifst("test_complex.txt");
			container c;
			Init(c);
			In(c, ifst);
			numbers *s = new numbers;
			complex* t = new complex;
			s = (numbers*)InComplex(*t, ifst);
			s->key = COMPLEX;
			Node* current = c.Top;
			float Rescomplex = numbers_s(current->data);
			float test = 169.425507;

			Assert::AreEqual(Rescomplex, test);
		}

		TEST_METHOD(TestResPolcoor)
		{
			ifstream ifst("test_polcoor.txt");
			container c;
			Init(c);
			In(c, ifst);
			numbers *s = new numbers;
			polcoor* t = new polcoor;
			s = (numbers*)InPolcoor(*t, ifst);
			s->key = POLCOOR;
			Node* current = c.Top;
			float Respolcoor = numbers_s(current->data);
			float test = 52.8410950;

			Assert::AreEqual(Respolcoor, test);
		}

		TEST_METHOD(TestOutSimple)
		{
			ifstream ifst("test_simple.txt");
			ofstream ofst("test_simple_out.txt", ios::trunc);
			container c;
			Init(c);
			In(c,ifst);
			Out(c,ofst);

			ifstream in("test_simple_out.txt");
			ifstream in_test("simple_out.txt");

			testfiles(in, in_test);

		}

		TEST_METHOD(TestOutComplex)
		{
			ifstream ifst("test_complex.txt");
			ofstream ofst("test_complex_out.txt", ios::trunc);
			container c;
			Init(c);
			In(c, ifst);
			Out(c, ofst);

			ifstream in("test_complex_out.txt");
			ifstream in_test("complex_out.txt");

			testfiles(in, in_test);

		}

		TEST_METHOD(TestOutPolcoor)
		{
			ifstream ifst("test_polcoor.txt");
			ofstream ofst("test_polcoor_out.txt", ios::trunc);
			container c;
			Init(c);
			In(c, ifst);
			Out(c, ofst);

			ifstream in("test_polcoor_out.txt");
			ifstream in_test("polcoor_out.txt");

			testfiles(in, in_test);

		}

		TEST_METHOD(TestOnlyComplex)
		{
			ifstream ifst("filein.txt");
			ofstream ofst("outfilter.txt", ios::trunc);
			container c;
			Init(c);
			In(c, ifst);
			Out_only_complex(c,ofst);

			ifstream in("outfilter.txt");
			ifstream in_test("outfilter_test.txt");

			testfiles(in, in_test);
		}
	};
}