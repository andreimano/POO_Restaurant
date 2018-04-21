#include "Meniu.h"

Mancare::Mancare()
  : pretProdus{0},
    cantitateComandata{0}
{}

Mancare::Mancare(float x, int y)
  : pretProdus(x),
    cantitateComandata(y)
{}

float Mancare::getPrice() {
  return pretProdus;
}

int Mancare::getQty() {
  return cantitateComandata;
}

void Mancare::setPrice(float x) {
  pretProdus = x;
}

void Mancare::setQty(int x) {
  cantitateComandata = x;
}
