#ifndef CARRENTAL_CLIENTS_H
#define CARRENTAL_CLIENTS_H

#include "structs.h"

void dodaj_klienta(Klient **lista_klientow);
void usun_klienta(Wypozyczenie *lista_wypozyczen, Klient **lista_klientow);
void edytuj_klienta(Klient **lista_klientow);
void wyswietl_klientow(Klient *lista_klientow);

#endif //CARRENTAL_CLIENTS_H