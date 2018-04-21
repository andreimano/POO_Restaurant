#ifndef _FEL_PRINCIPAL_INCLUDED
#define _FEL_PRINCIPAL_INCLUDED

class FelPrincipal : public Mancare { // abstract class inherits abstract class
public:
  FelPrincipal(void);
  FelPrincipal(float x, int y, std::string z, float k);
  virtual ~FelPrincipal(); // I want to call the base clase destructor
  // virtual std::string getName(void);  //no longer abstract
  static int vanzari;
  static int getVanzari();
protected:
  std::string* garnitura;
  float pretGarnitura;
};

class MeniuPui : public FelPrincipal {
public:
  MeniuPui(void);
  MeniuPui(float x, int y, std::string z, std::string garn, float k);
  MeniuPui(const MeniuPui&);
  ~MeniuPui();
  std::string getName(void);
private:
  std::string* tip;
};

class MeniuVita : public FelPrincipal {
public:
  // using MeniuPui::MeniuPui;
  MeniuVita(void);
  MeniuVita(float x, int y, std::string z, std::string w, std::string garn, float pg);
  MeniuVita(const MeniuVita&);
  ~MeniuVita();
  std::string getName(void);
private:
  std::string* tip;
  std::string* doneness;
};

#endif
