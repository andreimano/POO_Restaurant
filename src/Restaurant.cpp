#include "Meniu.h"
#include "Restaurant.h"
#include "Bautura.h"
#include "Ciorba.h"
#include "Desert.h"
#include "FelPrincipal.h"

int Ciorba::vanzari       = 0;
int FelPrincipal::vanzari = 0;
int Desert::vanzari       = 0;
int Bautura::vanzari      = 0;

Restaurant::Restaurant(const Restaurant& x) {
  nrGrupuri = x.nrGrupuri;
  grupuri = x.grupuri; //sigseg copy normal - vezi sigseg_copy.odt
}

Restaurant::~Restaurant() {
  std::cout << "\nNumar total de Ciorbe vandute: " << Ciorba::vanzari;
  std::cout << "\nNumar total de Feluri Principale vandute: " << FelPrincipal::vanzari;
  std::cout << "\nNumar total de Deserturi vandute: " << Desert::vanzari;
//  std::cout << "\nNumar total de Bauturi vandute: " << Bautura::vanzari;
  std::cout << std::endl;
  delete grupuri;
}

void Restaurant::test() {
  std::cout << "test";
  Grup grup;
  grupuri->push_back(grup);
  std::cout << grup.getNota();
}

void Restaurant::afiseazaComenzile() {
  std::vector<Grup>::iterator it = grupuri->begin();
  int indexGrup = 0;
  for(; it != grupuri->end(); it++, indexGrup++) {
    std::cout << "\nGrupul " << indexGrup << std::endl;
    std::cout << "Comanda totala: " << it->getNota() << std::endl;
  }
}

void Restaurant::init() {
  std::cout << "\nIntrodu numarul de grupuri: \n";
  std::cin >> nrGrupuri;
  for(int i = 0; i < nrGrupuri; ++i) {
    std::cout << "\nComanda pentru grupul " << i << std::endl;

    Grup grup;
    std::cin >> grup;
    grupuri->push_back(grup);
  }
}
