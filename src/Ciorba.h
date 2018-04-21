#ifndef _CIORBA_H_INCLUDED
#define _CIORBA_H_INCLUDED

class Ciorba : public Mancare { // abstract class, inherits virtual getName
public:
  Ciorba(void); //constructor implicit
  Ciorba(float x, int y, std::string tip);
  Ciorba(float x, int y, bool z, bool k, std::string tip);
  Ciorba(const Ciorba& x);
  ~Ciorba();
  virtual std::string getName(void);
  virtual void addArdei(void);
  virtual void addSmantana(void);
  static int vanzari;
  static int getVanzari();
protected:
  std::string* name;
  bool smantana;
  bool ardei;
};

class CiorbaBurta : public Ciorba {
public:
  using Ciorba::Ciorba;
};

class CiorbaLegume : public Ciorba {
public:
  using Ciorba::Ciorba;
};

class CiorbaCiuperci : public Ciorba {
public:
  using Ciorba::Ciorba;
  std::string getName(void);
  void addArdei(void);
  void addSmantana(void);
};

#endif
