#ifndef CARRENTAL_GUI_H
#define CARRENTAL_GUI_H

#define RESET       "\033[0m"
#define BOLD        "\033[1m"
#define GRAY        "\033[90m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define CYAN        "\033[36m"
#define BOLD_RED    "\033[1;31m"
#define BOLD_YELLOW "\033[1;33m"

#include "structs.h"

void menu_glowne(Samochod **lista_samochodow, Klient **lista_klientow, Wypozyczenie **lista_wypozyczen);
void menu_samochod(Samochod **lista_samochodow);
void menu_klient(Klient **lista_klientow);
void menu_wypozyczenie(Wypozyczenie **lista_wypozyczen);

#endif //CARRENTAL_GUI_H