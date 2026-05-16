#ifndef CARRENTAL_CARS_H
#define CARRENTAL_CARS_H

#include "structs.h"

void dodaj_samochod(Samochod **lista_samochodow);
void usun_samochod(Wypozyczenie *lista_wypozyczen, Samochod **lista_samochodow);
void edytuj_samochod(Samochod **lista_samochodow);
void wyswietl_samochody(Samochod *lista_samochodow);
void wyszukaj_samochod(Samochod *lista_samochodow);

#endif //CARRENTAL_CARS_H