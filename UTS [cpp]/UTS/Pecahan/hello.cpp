// Eugene Yap Jin Quan 13521074
#include <iostream>
#include "Pecahan.hpp"
using namespace std;

// int gcd(int a, int b) {
//     // a = q*b + r
//     if (b == 0) {
//         return a;
//     } else {
//         return gcd(b, a % b);
//     }   
// }

int main() {
    pecahan defP;           // 0/1
    pecahan p1(2, 3);       // 2/3
    pecahan p2(1, 2);       // 1/2
    pecahan p3 = p2 + p2;   // 4/4
    pecahan p4 = p1 - p2;   // 1/6
    pecahan p5 = p2 * 4;    // 4/8

    // test getter, print
    cout << "2/3? ";
    p1.Print();
    cout << endl;

    // test setter
    p1.setPemb(4);
    p1.setPeny(10);
    cout << "4/10? ";
    p1.Print();
    cout << endl;

    // test + - *
    cout << "4/4? ";
    p3.Print();
    cout << endl;

    cout << "1/6? ";
    p4.Print();
    cout << endl;

    cout << "4/8? ";
    p5.Print();
    cout << endl;


    // test real;
    cout << "1/6 = " << p4.RealP() << endl; 
    cout << "4/4 = " << p3.RealP() << endl; 

    // test ==
    cout << "SAMA 1/6, 1/2? " << (p4==p2) << endl;
    cout << "SAMA 4/8, 1/2? " << (p5==p2) << endl;
    // cout << gcd(120, 27) << endl;
    // cout << gcd(27, 120) << endl;
    return 0;
}