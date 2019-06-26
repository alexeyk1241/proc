#include "Numbers.h"
#include <iostream>
#include <fstream>
using namespace std;
namespace simple_shapes {
	void Init(container &c);
	void Clear(container &c);
	complex* InComplex(complex &p, ifstream &ifst);
	simple* InSimple(simple &t, ifstream &ifst);
	polcoor* InPolcoor(polcoor &l, ifstream &ifst);
	Node* In(ifstream &ifst);
	void In(container &c, ifstream &ifst);
	void Out(container &c, ofstream &ofst);
	void Out(Node *s, ofstream &ofst);
	int addlist(container &c, ifstream &ifst);
	void OutSimple(simple *t, ofstream &ofst);
	void OutComplex(complex *p, ofstream &ofst);
	void OutPolcoor(polcoor *l, ofstream &ofst);
	float numbers_s(numbers *s);
	bool Compare(numbers *p, numbers *t);
	void Sort(container &c);
	void Out_only_complex(container &c, ofstream &ofst);
}
using namespace simple_shapes;
int main(int argc, char* argv[])
{
	int a;
	if (argc != 3) {
		cout << "incorrect command line! "
			"Waited: command in_file out_file"
			<< endl;
		system("pause");
		exit(1);
	}
	ifstream ifst(argv[1]);

	if (!ifst)
	{
		cout << "No input file found!" << endl;
		system("pause");
		exit(1);
		return 0;
	}

	ofstream ofst(argv[2]);	cout << "Start" << endl;
	setlocale(LC_ALL, "Russian");
	container c;
	Init(c);
	In(c, ifst);
	ofst << "Filled container. " << endl;

	Out(c, ofst);
	Sort(c);
	ofst << endl;
	Out(c, ofst);
	ofst << endl;
	Out_only_complex(c, ofst);
	ofst << endl;
	Clear(c);

	ofst << "Empty container. " << endl;
	Out(c, ofst);
	cout << "Stop" << endl;
	system("pause");
	cin >> a;
	return 0;
}