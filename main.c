#include <stdio.h>

#include "files.h"
#include "gui.h"
#include "structs.h"

int main(void){
    Samochod *lista_samochodow = NULL;
    Klient *lista_klientow = NULL;
    wczytaj_samochody(&lista_samochodow);
    menu_glowne(&lista_samochodow);
    return 0;
}