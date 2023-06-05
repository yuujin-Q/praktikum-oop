#include <iostream>
#include "Expression.hpp"
#include "AddExpression.hpp"
#include "NegativeExpression.hpp"
#include "SubstractExpression.hpp"
using namespace std;

int main() {
    Expression *e1;
    Expression *e2;
    Expression *e3;
    e1 = new AddExpression(new TerminalExpression(4), new TerminalExpression(6));
    e2 = new SubstractExpression(new TerminalExpression(4), new TerminalExpression(6));
    e3 = new NegativeExpression(new TerminalExpression(1));
    cout << "e1 = " << e1->solve() << endl;
    cout << "e2 = " << e2->solve() << endl;
    cout << "e3 = " << e3->solve() << endl;

 /*
Contoh Main

Contoh Output

e = new AddExpression(
  new TerminalExpression(4),
  new TerminalExpression(6)
);
e->solve()
10
e = new SubstractExpression(
  new TerminalExpression(4),
  new TerminalExpression(6)
);
e->solve()
-2
e = new NegativeExpression(
  new TerminalExpression(1)
);
e->solve()
-1
*/   
}