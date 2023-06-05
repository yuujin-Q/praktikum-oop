#include "RestoranRamen.hpp"
using namespace std;

int main() {
    RestoranRamen ramenshop;

    cout << ramenshop.totalMeja();
    ramenshop.cetakMeja();
    ramenshop.tambahOrder(10, 45000);
    ramenshop.tambahOrder(5, 50000);
    ramenshop.tambahOrder(1, 15000);
    ramenshop.tambahOrder(2, 35000);

    cout << "mejaaaaaaaaa" << endl;
    ramenshop.tambahOrder(10, 15000);
    ramenshop.cetakMeja();

    return 0;
}