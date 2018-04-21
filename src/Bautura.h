#ifndef _BAUTURA_H_INCLUDED
#define _BAUTURA_H_INCLUDED

class Bautura : public Produs {
public:
  Bautura(void);
  Bautura(int x, int y, std::string z);
  Bautura(const Bautura&);
  ~Bautura();
  static int getVanzari();
  static int vanzari;
  std::string getName();
private:
  float pretProdus;
  int cantitateComandata;
  std::string* tipBautura;
};

#endif
