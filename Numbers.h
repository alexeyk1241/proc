
enum type { COMPLEX, SIMPLE, POLCOOR };
struct complex {
	type key;
	char units[100];
	float real;
	float imaginary;
};
struct simple {

	type key;
	char units[100];
	float numerator;
	float denominator;
};
struct polcoor {
	type key;
	float corner;
	int distance;
};
struct numbers {
	type key;
};

struct Node {
	Node() {
		this->Next = nullptr;
		this->Prev = nullptr;
		this->data = nullptr;
	};
	Node* Next;
	Node* Prev;
	numbers* data;
};
struct container {
	Node* Top;
	int count;
};
