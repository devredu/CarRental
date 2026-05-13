#include "rentals.h"
#include "structs.h"
#include "gui.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dodaj_wypozyczenie(Wypozyczenie **lista_wypozyczen){
    Wypozyczenie *nowe = (Wypozyczenie*)malloc(sizeof(Wypozyczenie));
    if (nowe == NULL) {
        return;
    }
    nowe->next = NULL;

    system(CLEAR);
    printf("=====================================\n");
    printf("| " BOLD "       DODAWANIE WYPOZYCZENIA        " RESET "|\n");
    printf("=====================================\n");
    printf("Podaj numer karty klienta: ");
    // sprawdzenie czy jest taki klient
    scanf("");
    wyczysc_bufor();
    printf("Podaj numer rejestracyjny samochodu: ");
    // sprawdzenie czy jest taki samochod + sprawdzenie czy nie jest juz wynajety
    scanf("");
    wyczysc_bufor(nowe->nr_rejestracyjny);
    printf("Od kiedy: ");
    // walidacja
    scanf("");
    printf("Do kiedy: ");
    // walidacja
    scanf("");
}