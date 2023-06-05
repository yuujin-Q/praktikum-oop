// 13521074 Eugene Yap Jin Quan
#include "AppreciatingAsset.hpp"
#include <math.h>


// A = P * (1 + r/100)^n
// P present, r rate, n years
// input r tidak perlu dibagi 100
double AppreciatingAsset::getValue(int years) {
    double p = this->x->getValue(years);
    double d = p * pow((1 + this->rate), years);
    return d;
}