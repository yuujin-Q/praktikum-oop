#include "A.hpp"

int main() {
    /* cons */
    A x('1');
    A y('2');

    /* ccons */
    A z(x);

    /* cassign */
    z = y;
    
    /* show */
    z.show();

    /* dest */
    return 0;
}