#ifndef _RESTAURANT_H_INCLUDED
#define _RESTAURANT_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Meniu.h"
#include "Client.h"


class Restaurant {
public:
  Restaurant()
    : nrGrupuri(0),
      grupuri(new std::vector<Grup>)
  {}
  Restaurant(int x, std::vector<Grup> y)
    : nrGrupuri(x),
      grupuri(new std::vector<Grup>(y))
  {}
  Restaurant(const Restaurant&);
  ~Restaurant();

  void init();
  void afiseazaComenzile();
  // friend std::istream& operator >> (std::istream&, Grup&);
  void test();
private:
  int nrGrupuri;
  std::vector<Grup>* grupuri;
};

#endif
