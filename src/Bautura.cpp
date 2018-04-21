#include "Meniu.h"
#include "Bautura.h"
#include <string>

Bautura::Bautura(void)
  : pretProdus{0},
    cantitateComandata{0},
    tipBautura(new std::string(""))
{
  ++Bautura::vanzari;
}

Bautura::Bautura(int x, int y, std::string z)
  : pretProdus(x),
    cantitateComandata(y),
    tipBautura(new std::string(z))
{
  ++Bautura::vanzari;
}

Bautura::Bautura(const Bautura& x) {
  pretProdus = x.pretProdus;
  cantitateComandata = x.cantitateComandata;
  tipBautura = new std::string("");
  *tipBautura += *(x.tipBautura);
}

Bautura::~Bautura() {
  delete tipBautura;
}

std::string Bautura::getName() {
  return *tipBautura;
}

int Bautura::getVanzari() {
  return vanzari;
}
