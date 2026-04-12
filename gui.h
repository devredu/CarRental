#ifndef CARRENTAL_GUI_H
#define CARRENTAL_GUI_H

#ifdef _WIN32
    #include <windows.h>
    #define CLEAR "cls"
#else
    #include <unistd.h>
    #define CLEAR "clear"
    #define Sleep(ms) usleep((ms) * 1000)
#endif

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

void menu_glowne(Samochod **list_samochodow);
void menu_samochod(Samochod **lista_samochodow);
void menu_klient();
void menu_wypozyczenie();

#endif //CARRENTAL_GUI_H