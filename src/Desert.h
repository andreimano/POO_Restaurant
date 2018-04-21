#ifndef _DESERT_H_INCLUDED
#define _DESERT_H_INCLUDED

class Desert : public Mancare {
public:
  Desert(void);
  Desert(float x, int y, std::string z);
  virtual ~Desert();
  virtual std::string getName();
  static int vanzari;
  static int getVanzari();
protected:
  std::string* nume;
};

class TortKrantz : public Desert {
public:
  TortKrantz();
  TortKrantz(float x, int y, std::string z);
  TortKrantz(const TortKrantz&);
};

class Inghetata : public Desert {
public:
  Inghetata();
  Inghetata(float x, int y, std::string z, int c);
  Inghetata(const Inghetata&);
private:
  int cupe;
};

#endif
