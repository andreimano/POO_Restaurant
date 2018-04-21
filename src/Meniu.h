#ifndef _MENIU_H_INCLUDED
#define _MENIU_H_INCLUDED

#include <string>

#define PRET_CBURTA 12 //Ciorba de burta
#define PRET_CLEG   10 //Ciorba de legume
#define PRET_CCIUP  10 //Ciorba ciuperci
#define PRET_ARDEI  1  //Ardei iute
#define PRET_SMANT  2  //Smantana
#define PRET_CPRAJ  3  //Cartofi prajiti
#define PRET_CPIUR  4  //Piure de cartofi
#define PRET_OREZS  4  //Orez sarbesc
#define PRET_MPUI_F 10 //Meniu pui frigarui
#define PRET_MPUI_T 11 //Meniu pui tocana
#define PRET_MVIT_C 15 //Meniu vita Chateaubriand
#define PRET_MVIT_S 13 //Meniu vita Stroganoff
#define PRET_MVIT_F 14 //Meniu vita File
#define PRET_INGH   2  //Inghetata
#define PRET_TKRAN  7  //Tort Krantz
#define PRET_VIN    12 //Vin
#define PRET_BERE   6  //Bere
#define PRET_APA    4  //Apa

class Produs { // interface
public:
  // virtual ~Produs() = 0;
  // note: if you want a pure virtual destructor
  // you must implement it in all your inherited
  // classes; even if that clase is abstract
  virtual float getPrice() = 0;
  virtual int getQty() = 0;
  virtual void setPrice(float) = 0;
  virtual void setQty(int) = 0;
};

class Mancare : public Produs { // abstract class
public:
  Mancare();
  Mancare(float x, int y);
  virtual std::string getName() = 0; // pure virtual function
  float getPrice();
  int getQty();
  void setPrice(float);
  void setQty(int);

protected:
  float pretProdus;
  int cantitateComandata;
};

#endif
