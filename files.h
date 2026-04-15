#ifndef CARRENTAL_FILES_H
#define CARRENTAL_FILES_H

#include "structs.h"

void zapisz_samochody(Samochod *lista_samochodow);
void wczytaj_samochody(Samochod **lista_samochodow);
void zapisz_klientow(Klient *lista_klientow);
void wczytaj_klientow(Klient **lista_klientow);

#endif //CARRENTAL_FILES_H