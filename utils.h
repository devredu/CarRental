#ifndef CARRENTAL_UTILS_H
#define CARRENTAL_UTILS_H

#ifdef _WIN32
    #include <windows.h>
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
    #define Sleep(ms) usleep((ms) * 500)
#endif

void zaczekaj();
void wyczysc_bufor();
void zamien_na_wielkie(char *tekst);

#endif //CARRENTAL_UTILS_H