#include "Meniu.h"
#include "Ciorba.h"
#include <string>
#include <iostream>

Ciorba::Ciorba(void)
  : Mancare(),
    name(new std::string("")),
    smantana{false},
    ardei{false}
{
  ++Ciorba::vanzari;
}

Ciorba::Ciorba(float x, int y, std::string tip)
  : Mancare::Mancare(x, y),
    name(new std::string(tip)),
    smantana{false},
    ardei{false}
{
  ++Ciorba::vanzari;
} // constructor init


Ciorba::Ciorba(float x, int y, bool z, bool k, std::string tip)
  : Mancare::Mancare(x, y),
    name(new std::string(tip)),
    smantana(z),
    ardei(k)
{} // constructor init

Ciorba::Ciorba(const Ciorba& x) { //upcasting
  smantana = x.smantana;
  ardei = x.ardei;
  name = new std::string("");
  *name += x.name->c_str();
} // copy constructor

Ciorba::~Ciorba() {
  delete name;
}

std::string Ciorba::getName() {
  return *name;
}

void Ciorba::addArdei() {
  ardei = true;
}

void Ciorba::addSmantana() {
  smantana = true;
}

int Ciorba::getVanzari() {
  return vanzari;
}

std::string CiorbaCiuperci::getName() {
  return "Ciorba de ciuperci";
}

// Dar nu-i nimic gresit in a manca ciorba de ciuperci cu ardei si smantana :(
void CiorbaCiuperci::addArdei() {
  std::cout << "Chef-ul nostru considera ca esti o persoana dezgustatoare si nu iti va oferi ardei.";
}

void CiorbaCiuperci::addSmantana() {
  std::cout << "Chef-ul nostru considera ca esti o persoana dezgustatoare si nu iti va oferi ardei.";
}
