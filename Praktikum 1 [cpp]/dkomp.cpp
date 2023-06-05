#include "Kompleks.h"
#include <iostream>
using namespace std;

int main() {
	Kompleks A(1, 3), B(2, -1);
	Kompleks C = A + B;
	cout << Kompleks::CountKompleksInstance() << endl;
	
	A.Print();
	B.Print();
	C.Print();
	return 0;
}
