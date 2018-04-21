#include <iostream>
#include <vector>
#include "Meniu.h"
#include "Restaurant.h"
#include "Bautura.h"
#include "Ciorba.h"
#include "Desert.h"
#include "FelPrincipal.h"
#include "Client.h"

Client::Client()
  : comanda(new std::vector<Produs*>),
    nota(0)
{}

Client::Client(std::vector<Produs*> p, float n)
  : comanda(new std::vector<Produs*>),
    nota(n)
{}

Client::Client(const Client& x) {
  comanda = x.comanda;
  nota = x.nota;
}

Grup::Grup()
  : clienti(new std::vector<Client>),
    numarClienti(0),
    notaTotala(0)
{}

Grup::Grup(std::vector<Client>* vc, int x, float y)
  : clienti(vc),
    numarClienti(x),
    notaTotala(y)
{}

Grup::Grup(int x)
  : clienti(new std::vector<Client>),
    numarClienti(x),
    notaTotala(0)
{}

Grup::Grup(const Grup& x) {
  clienti = x.clienti;
  numarClienti = x.numarClienti;
  notaTotala = x.notaTotala;
}

Grup::~Grup() {
  // delete clienti;
}

Client::~Client() {
  // delete comanda;
}

float Client::getNotaClient() {
  return nota;
}

float Grup::getNota() {
  std::vector<Client>::iterator it = clienti->begin();
  for(; it!=clienti->end(); it++) {
    notaTotala += it->getNotaClient();
  }
  return notaTotala;
}

std::istream& operator >> (std::istream& in, Client& o) {
  int raspuns = 0, raspuns2 = 0, indexComanda = 0;
  std::cout << "\nBuna seara,\nCiorba?\n1.Da\n2.Nu\n";
  in >> raspuns;
  if(raspuns == 1) {
    std::cout << "\nCe tip?\n1.De burta\n2.De legume\n3.De ciuperci\n";
    in >> raspuns;
    if(raspuns == 1 || raspuns == 2) {
      if(raspuns == 1) {
        o.comanda->push_back(new CiorbaBurta(12, 1, false, false, "Ciorba de Burta"));
        o.nota += 12;
        ++indexComanda;
      } else {
        o.comanda->push_back(new CiorbaLegume(10, 1, false, false, "Ciorba de Legume"));
        o.nota += 10;
        ++indexComanda;
      }
      std::cout << "\nArdei? Smantana?\n1.Ardei\n2.Smantana\n3.Ambele\n4.Nici una\n";
      in >> raspuns2;

      std::vector<Produs*>::const_iterator it = o.comanda->begin();
      Ciorba* aux = dynamic_cast<Ciorba*>(*it);

      switch (raspuns2) {
        case 1:
          aux->addArdei();
          o.nota += 1;
          break;
        case 2:
          aux->addSmantana();
          o.nota += 2;
          break;
        case 3:
          aux->addArdei();
          aux->addSmantana();
          o.nota +=3;
          break;
        default:
          break;
      }
    } else if(raspuns == 3) {
      o.comanda->push_back(new CiorbaCiuperci(10, 1, "Ciuperci"));
      o.nota += 10;
      ++indexComanda;
    }
  }

  raspuns = 0;
  std::cout << "\nFel principal?\n1.Da\n2.Nu\n";
  in >> raspuns;
  if(raspuns == 1) {

    std::cout << "\nGarnitura?\n1.Cartofi Prajiti\n2.Piure de cartofi\n3.Orez sarbesc\n4.Nu\n";
    in >> raspuns2;
    std::string garnitura("");
    float pretGarnitura(0);

    switch (raspuns2) {
      case 1:
        garnitura += "Cartofi Prajiiti";
        pretGarnitura = 3;
        break;
      case 2:
        garnitura += "Piure de cartofi";
        pretGarnitura = 4;
        break;
      case 3:
        garnitura += "Orez sarbesc";
        pretGarnitura = 4;
        break;
      default:
        break;
    }

    std::cout << "\nCe tip?\n1.De pui\n2.De vita\n";
    in >> raspuns;
    if(raspuns == 1) {
      std::cout << "\nFrigarui sau tocana?\n1.Frigarui\n2.Tocana\n";
      in >> raspuns2;
      if(raspuns2 == 1) {
        o.comanda->push_back(new MeniuPui(10, 1, "Frigarui", garnitura, pretGarnitura));
        o.nota += (10 + pretGarnitura);
      }
      if(raspuns2 == 2) {
        o.comanda->push_back(new MeniuPui(11, 1, "Tocana", garnitura, pretGarnitura));
        o.nota += (10 + pretGarnitura);
      }

    } else if(raspuns == 2) {
      std::cout << "\n1.Chateaubriand\n2.Stroganoff\n3.File\n";
      in >> raspuns2;
      std::cout << "\nCat de bine facut sa fie?\n1.In sange\n2.Mediu\n3.Bine facut\n";
      std:: cin >> raspuns;
      std::string doneness;
      if(raspuns == 1) doneness = "In sange";
      if(raspuns == 2) doneness = "Mediu";
      if(raspuns == 3) doneness = "Bine facut";

      switch (raspuns2) {
        case 1:
          o.comanda->push_back(new MeniuVita(15, 1, "Chateaubriand", doneness, garnitura, pretGarnitura));
          o.nota += (15 + pretGarnitura);
          break;
        case 2:
          o.comanda->push_back(new MeniuVita(13, 1, "Stroganoff", doneness, garnitura, pretGarnitura));
          o.nota += (13 + pretGarnitura);
          break;
        case 3:
          o.comanda->push_back(new MeniuVita(14, 1, "File", doneness, garnitura, pretGarnitura));
          o.nota += (14 + pretGarnitura);
          break;
        default:
          break;
      }
    }

    //aux->setGarnituraPrice(3);//this once gave me a segfault
    // ++indexComanda;
  }

  raspuns = 0;
  std::cout << "\nDesert?\n1.Da\n2.Nu\n";
  in >> raspuns;
  if(raspuns == 1) {
    std::cout << "\n1.Inghetata\n2.Tort krantz\n";
    in >> raspuns2;
    if(raspuns2 == 1) {
      std::cout << "\nCate cupe? (intre 3 si 5 cupe)\n";
      in >> raspuns2;
      if(raspuns2 < 3 || raspuns2 > 5)
        raspuns2 = 3; //bug, will fix it some day
      o.comanda->push_back(new Inghetata(raspuns2 * 2, 1, "Inghetata", raspuns2));
      o.nota += (raspuns2 * 2);
    }
    if(raspuns2 == 2) {
      o.comanda->push_back(new TortKrantz(7, 1, "Tort Krantz"));
      o.nota += 7;
    }
  }

  return in;
}

void Grup::setNrClienti(int x) {
  numarClienti = x;
}

std::istream& operator >> (std::istream& in, Grup& o) {
  std::cout << "\nCate persoane sunt in grup?\n";
  int nrClienti;
  in >> nrClienti;
  o.setNrClienti(nrClienti);

  for(int i = 0; i < nrClienti; ++i) {
    Client client;
    std::cout << "\nComanda pentru clientul " << i << std::endl;
    in >> client;
    o.clienti->push_back(client);
  }

  return in;
}
