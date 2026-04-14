#include <stdio.h>
#include "files.h"
#include "gui.h"
#include "structs.h"

int main(void){
    Samochod *lista_samochodow = NULL;
    Klient *lista_klientow = NULL;
    wczytaj_samochody(&lista_samochodow);
    //wczytaj_klientow(&lista_klientow);
    menu_glowne(&lista_samochodow, &lista_klientow);
    return 0;
}