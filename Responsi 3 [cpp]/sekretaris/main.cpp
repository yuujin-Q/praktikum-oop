#include "sekretaris.h"
#include <iostream>
using namespace std;

int main() {
    Sekretaris s(10, 10);
    s.printStatus();
    string pesann;
    cin >> pesann;
    s.buatMemo(pesann, "aku");
    s.printStatus();


    return 0;
}