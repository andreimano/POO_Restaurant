#include "Meniu.h"
#include "FelPrincipal.h"
#include <string>

FelPrincipal::FelPrincipal()
  : Mancare::Mancare(),
    garnitura(new std::string("")),
    pretGarnitura(0)
{
  ++FelPrincipal::vanzari;
}

FelPrincipal::FelPrincipal(float x, int y, std::string z, float k)
  : Mancare::Mancare(x, y),
    garnitura{new std::string(z)},
    pretGarnitura(k)
{
  ++FelPrincipal::vanzari;
}


FelPrincipal::~FelPrincipal() {
  delete garnitura;
}

int FelPrincipal::getVanzari() {
  return vanzari;
}

std::string MeniuPui::getName() {
  return *tip;
}

std::string MeniuVita::getName() {
  return *tip;
}

MeniuPui::MeniuPui()
  : FelPrincipal::FelPrincipal(),
    tip(new std::string(""))
{}

MeniuPui::MeniuPui(float x, int y, std::string z, std::string garn, float k)
  : FelPrincipal::FelPrincipal(x, y, garn, k),
    tip(new std::string(z))
{}

MeniuPui::MeniuPui(const MeniuPui& x) {
  pretProdus = x.pretProdus;
  cantitateComandata = x.cantitateComandata;
  garnitura = new std::string("");
  *garnitura += x.garnitura->c_str(); //fixes compiling error
  pretGarnitura = x.pretGarnitura;    //may or may not have been because of this
  tip = new std::string("");
  *tip += x.tip->c_str();
}

MeniuPui::~MeniuPui() {
  delete tip;
}

MeniuVita::MeniuVita()
  : FelPrincipal::FelPrincipal(),
    tip(new std::string("")),
    doneness(new std::string(""))
{} //implicit

MeniuVita::MeniuVita(float x, int y, std::string z, std::string w, std::string garn, float pg)
  : FelPrincipal::FelPrincipal(x, y, garn, pg),
    tip(new std::string(z)),
    doneness(new std::string(w))
{} //initializare cu garnituri

MeniuVita::~MeniuVita() {
  delete doneness;
}

MeniuVita::MeniuVita(const MeniuVita& x) {
  pretProdus = x.pretProdus;
  cantitateComandata = x.cantitateComandata;
  garnitura = new std::string("");
  *garnitura += x.garnitura->c_str(); //fixes compiling error
  pretGarnitura = x.pretGarnitura;    //may or may not have been because of this
  tip = new std::string("");
  *tip += x.tip->c_str();
  doneness = new std::string("");
  *doneness += x.tip->c_str();
}
