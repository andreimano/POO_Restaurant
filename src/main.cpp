/*
Restaurant:
La un restaurant exista mai multe mese. La fiecare masa se pot aseza unul sau
mai multi clienti (maxim in functie de capacitatea mesei). Clientii sosesc in
grupuri si se aseaza la o masa suficient de mare. Apoi comanda din meniul care
contine mai multe feluri de mancare si bauturi, fiecare avand un pret. Fiecare
client comanda pentru el. Dupa ce mananca parasesc masa (eventual pe rand).
Cand un client paraseste masa el doreste nota de plata pentru ce a consumat el.
La final se elibereaza nota de plata pentru clientii ramasi. Scrieti un program
care sa permita aceste operatiuni.
Precizari:
* Felurile de mancare pot fi cel putin:
Ciorba - de burta, de legume (cu sau fara smantana/ardei)
       - de ciuperci
Fel principal - de pui (frigarui sau tocana)
              - de vita (chateaubriand - cat de bine facut sa fie
                                       - stroganoff sau file)
              - garnitura - cartofi prajiti/piure
                          - orez sarbesc
Desert - inghetata la cupa (3-5 cupe)
       - tort krantz
Bauturi - Vin varsat (rosu / alb)
        - Sticle de vin (Bordeux 1996 / Castel Bolovanu 2004)
        - Bere (cu / fara alcool)
        - Apa plata
*/

//init, copiere, parametr

#include "Restaurant.h"

int main() {
  Restaurant* rest = new Restaurant;
  rest->init();
  rest->afiseazaComenzile();
  delete rest;
}
