#include "Numbers.h"
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;
namespace simple_shapes {
	void Init(container &c);
	void Clear(container &c);
	complex* InComplex(complex &p, ifstream &ifst);
	simple* InSimple(simple &t, ifstream &ifst);
	polcoor* InPolcoor(polcoor &l, ifstream &ifst);
	numbers* In(ifstream &ifst);
	void In(container &c, ifstream &ifst);
	void OutComplex(complex *p, ofstream &ofst);
	void Out(container &c, ofstream &ofst);
	void Out(numbers *s, ofstream &ofst);
	int addnode(container &c, ifstream &ifst);
	void OutSimple(simple *t, ofstream &ofst);
	void OutPolcoor(polcoor *l, ofstream &ofst);
	float numbers_s(simple *t);
	float numbers_s(complex *p);
	bool Compare(numbers *p, numbers *t);
	void Sort(container &c);
	void castl(Node* &current);
	void pocesssort(Node*& headt, Node*& current);
	void Out_only_complex(container &c, ofstream &ofst);

	float numbers_s(simple *t)
	{
		float numbers1 = (t->numerator / t->denominator);
		return numbers1;
	}

	float numbers_s(complex *p)
	{
		float numbers2 = sqrt(pow((p->real), 2) + pow((p->imaginary), 2));
		return numbers2;
	}

	float numbers_s(polcoor *l)
	{
		float numbers3 = (l->distance * cos(l->corner)) + (l->distance * sin(l->corner));
		return numbers3;
	}

	float numbers_s(numbers *s)
	{
		switch (s->key)
		{
		case SIMPLE:
		{
			return numbers_s((simple*)s);
		}break;
		case COMPLEX:
		{
			return numbers_s((complex*)s);
		}break;
		case POLCOOR:
		{
			return numbers_s((polcoor*)s);
		}break;
		default:
		{
			return -1;
		}
		break;
		}
	}

	void Out_only_complex(container &c, ofstream &ofst)
	{
		ofst << "Only complex." << endl;
		Node* current = c.Top;
		for (int i = 0; i < c.count; i++)
		{
			ofst << i << ": ";
			if (current->data->key == type::COMPLEX)
			{
				Out(current->data, ofst);
				ofst << "значение = " << numbers_s(current->data) << endl;
				current = current->Next;
			}
			else
			{
				ofst << endl;
				current = current->Next;
			}

		}
	}

	bool Compare(numbers* first, numbers* second)
	{
		return numbers_s(first) < numbers_s(second);
	}

	void Sort(container & c)
	{
		Node* current = c.Top;
		for (int i = 0; i < c.count; i++)
		{
			if (i > 0)
			{
				if (Compare(current->data, current->Next->data))
				{
					Node p;
					p.data = current->data;
					current->data = current->Next->data;
					current->Next->data = p.data;
					i = 0;
					current = c.Top;
				}
				else
				{
					current = current->Next;
				}
			}
		}
	}

	complex * InComplex(complex & p, ifstream & ifst)
	{
		ifst >> p.real >> p.imaginary >> p.units;;
		return &p;
	}

	simple * InSimple(simple & t, ifstream &ifst)
	{
		ifst >> t.numerator >> t.denominator >> t.units;;
		return &t;
	}

	polcoor * InPolcoor(polcoor & l, ifstream &ifst)
	{
		ifst >> l.corner >> l.distance;
		return &l;
	}

	void Init(container & c)
	{
		c.Top = nullptr;
		c.count = 0;

	}

	void Clear(container & c)
	{
		Node* current = c.Top;
		int i = 1;
		while (i < c.count)
		{
			current = current->Next;
			delete current->Prev;
			i++;
		}
		delete current;
		c.count = 0;
	}

	void OutComplex(complex *p, ofstream &ofst)
	{
		if (p->imaginary < 0)
		{
			ofst << "It is Complex number: действительная часть = " << p->real
				<< ", мнимая часть = " << p->imaginary << endl << p->real << p->imaginary << "i" << ", еденица измерений - " << p->units;
		}
		else
		{
			ofst << "It is Complex number: действительная часть = " << p->real
				<< ", мнимая часть = " << p->imaginary << endl << p->real << "+" << p->imaginary << "i" << ", еденица измерений - " << p->units;
		}
	}
	void Out(container & c, ofstream &ofst)
	{
		Node* current = c.Top;
		ofst << " Container contains " << c.count
			<< " elements." << endl;
		for (int j = 0; j < c.count; j++) {
			ofst << j << ": ";
			Out(current->data, ofst);
			ofst << "значение = " << numbers_s(current->data) << endl;
			current = current->Next;
		}
	}

	void Out(numbers *s, ofstream &ofst)
	{
		switch (s->key) {
		case COMPLEX:
			OutComplex((complex*)s, ofst);
			ofst << endl;
			break;
		case SIMPLE:
			OutSimple((simple*)s, ofst);
			ofst << endl;
			break;
		case POLCOOR:
			OutPolcoor((polcoor*)s, ofst);
			ofst << endl;
			break;
		default:
			cout << "Incorrect figure!" << endl;
		}
	}
	int addnode(container &c, ifstream &ifst)
	{
		if (c.count == 0)
		{
			c.Top = new Node;
			c.Top->Next = c.Top;
			c.Top->Prev = c.Top;
			if ((c.Top->data = In(ifst)) != 0)
				return 1;
			else
				return 0;

		}
		else
		{
			Node *current = c.Top;
			for (int j = 1; j < c.count; j++)
			{
				current = current->Next;
			}
			current->Next = new Node;
			if ((current->Next->data = In(ifst)) != 0)
			{
				c.Top->Prev = current->Next;
				current->Next->Prev = current;
				current->Next->Next = c.Top;
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}

	void OutSimple(simple * t, ofstream &ofst)
	{
		ofst << "It is Simple number: числитель = " << t->numerator
			<< ", знаменатель = " << t->denominator << endl << t->numerator << "/" << t->denominator << ", еденица измерений - " << t->units;
	}

	void OutPolcoor(polcoor * l, ofstream &ofst)
	{
		ofst << "It is Polar coordinates number: угол = " << l->corner
			<< ", расстояние до точки = " << l->distance << endl << "(" << l->distance << "," << l->corner << "°)";
	}

	void In(container &c, ifstream &ifst)

	{
		while (!ifst.eof()) {
			if (addnode(c, ifst) != 0)
				c.count++;
		}
	}

	numbers * In(ifstream &ifst)
	{
		numbers *s = new numbers;
		int key;
		ifst >> key;
		if (key == 1) {
			complex* p = new complex;
			s = (numbers*)InComplex(*p, ifst);
			s->key = COMPLEX;
			return s;
		}
		else if (key == 2)
		{
			simple* t = new simple;
			s = (numbers*)InSimple(*t, ifst);
			s->key = SIMPLE;
			return s;
		}
		else if (key == 3)
		{
			polcoor* l = new polcoor;
			s = (numbers*)InPolcoor(*l, ifst);
			s->key = POLCOOR;
			return s;
		}
		return 0;
	}
}