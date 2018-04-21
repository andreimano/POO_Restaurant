#include "Meniu.h"
#include "Desert.h"
#include <string>

Desert::Desert(void)
  : Mancare(),
    nume(new std::string(""))
{
  ++Desert::vanzari;
}

Desert::Desert(float x, int y, std::string z)
  : Mancare(x, y),
    nume(new std::string(z))
{
  ++Desert::vanzari;
}

Desert::~Desert() {
  delete nume;
}

std::string Desert::getName() {
  return *nume;
}

int Desert::getVanzari() {
  return vanzari;
}

TortKrantz::TortKrantz(void)
  : Desert()
{}

TortKrantz::TortKrantz(float x, int y, std::string z)
  : Desert(x, y, z)
{}

TortKrantz::TortKrantz(const TortKrantz& x) {
  pretProdus = x.pretProdus;
  cantitateComandata = x.cantitateComandata;
  nume = x.nume;
}

Inghetata::Inghetata()
  : Desert(),
    cupe(0)
{}

Inghetata::Inghetata(float x, int y, std::string z, int c)
  : Desert(x, y, z),
    cupe(c)
{}

Inghetata::Inghetata(const Inghetata& x) {
  pretProdus = x.pretProdus;
  cantitateComandata = x.cantitateComandata;
  nume = x.nume;
  cupe = x.cupe;
}
