#ifndef CARRENTAL_GUI_H
#define CARRENTAL_GUI_H

#include "structs.h"

void menu_glowne(Samochod **lista_samochodow, Klient **lista_klientow, Wypozyczenie **lista_wypozyczen);
void menu_samochod(Samochod **lista_samochodow);
void menu_klient(Klient **lista_klientow);
void menu_wypozyczenie(Samochod **lista_samochodow, Klient **lista_klientow, Wypozyczenie **lista_wypozyczen);

#endif //CARRENTAL_GUI_H