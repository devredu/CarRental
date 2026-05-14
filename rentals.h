#ifndef CARRENTAL_RENTALS_H
#define CARRENTAL_RENTALS_H

#include "structs.h"

void dodaj_wypozyczenie(Samochod *lista_samochodow, Klient *lista_klientow, Wypozyczenie **lista_wypozyczen);
void usun_wypozyczenie(Wypozyczenie **lista_wypozyczen);
void wyswietl_wypozyczenia(Wypozyczenie *lista_wypozyczen);

#endif //CARRENTAL_RENTALS_H