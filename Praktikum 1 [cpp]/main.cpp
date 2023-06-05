/**
 * Identitas: 13521074 - Eugene Yap Jin Quan
 * Tanggal : 2023/02/09
 * Topik : Praktikum 1
 */
 
#include "Paper.hpp"
using namespace std;

/*
ctor A
ctor B
ctor C
cctor C
fold A(1)
fold B(1)
fold C(1)
glue C
fold C(2)
setName C => X
fold C(1)
glue C
fold C(2)
dtor C
dtor X
dtor B
dtor A
 */
int main() {
	Paper A('A');
	Paper B('B');
	Paper C('C');
	Paper CC(C);
	A.fold();
	B.fold();
	C.fold();
	C.glue();
	
	
	C.setName('X');
	CC.fold();
	CC.glue();
	

	return 0;
}
