#ifndef CARRENTAL_UTILS_H
#define CARRENTAL_UTILS_H
#include <stdbool.h>

#ifdef _WIN32
    #include <windows.h>
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
    #define Sleep(ms) usleep((ms) * 500)
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

void zaczekaj();
void wyczysc_bufor();
void zamien_na_wielkie(char *tekst);
bool waliduj_date(const char *data);

#endif //CARRENTAL_UTILS_H