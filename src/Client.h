#ifndef _CLIENT_H_INCLUDED
#define _CLIENT_H_INCLUDED

class Client {
public:
  Client();
  Client(std::vector<Produs*> p, float n);
  Client(const Client&);
  ~Client();

  float getNotaClient();
  friend std::istream& operator >> (std::istream&, Client&);
private:
  std::vector<Produs*>* comanda; //eventual std::unique_ptr
  float nota;
};

class Grup {
public:
  Grup();
  Grup(std::vector<Client>* vc, int x, float y);
  Grup(int x);
  Grup(const Grup&);

  ~Grup();

  float getNota();
  void setNrClienti(int);
  friend std::istream& operator >> (std::istream&, Grup&);
private:
  std::vector<Client>* clienti;
  int numarClienti;
  float notaTotala;
};

#endif
