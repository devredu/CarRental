#include "utils.h"
#include "gui.h"
#include <stdio.h>

void zaczekaj(){
    printf("\n");
    printf(GRAY "Nacisnij enter..." RESET);
    getchar();
}

void wyczysc_bufor() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void zamien_na_wielkie(char *tekst) {
    for (int i = 0; tekst[i]; i++) {
        tekst[i] = toupper((unsigned char)tekst[i]);
    }
}

