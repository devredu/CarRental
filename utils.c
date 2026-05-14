#include "utils.h"
#include "gui.h"
#include <stdio.h>
#include <ctype.h>

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
bool waliduj_date(const char *data){
    if (strlen(data) != 10) {
        return false;
    }
    if (data[4] != '-' || data[7] != '-') {
        return false;
    }
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) {
            continue;
        }
        if (!isdigit(data[i])) {
            return false;
        }
    }
    int rok, miesiac, dzien;
    sscanf(data, "%d-%d-%d", &rok, &miesiac, &dzien);
    if (rok < 2000 || rok > 2100) {
        return false;
    }
    if (miesiac < 1 || miesiac > 12) {
        return false;
    }
    if (dzien < 1 || dzien > 31) {
        return false;
    }
    return true;
}