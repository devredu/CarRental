#include "cars.h"
#include "structs.h"
#include "gui.h"
#include <stdio.h>
#include <stdlib.h>

void dodaj_samochod(Samochod **lista_samochodow){
    Samochod *nowy = (Samochod*)malloc(sizeof(Samochod));
    if (nowy == NULL) {
        return;
    }
    system(CLEAR);
    printf("Podaj marke samochodu: ");
    scanf("%19s", nowy->marka);
    printf("Podaj model samochodu: ");
    scanf("%29s", nowy->model);
    printf("Podaj kolor samochodu: ");
    scanf("%29s", nowy->kolor);
    printf("Podaj rok produkcji samochodu: ");
    scanf("%d", &nowy->rok_produkcji);
    printf("Podaj numer rejestracyjny samochodu: ");
    scanf("%19s", nowy->nr_rejestracyjny);

    printf(GREEN "\nPomyslnie dodano samochod!\n" RESET);
    zaczekaj();

    nowy->next = NULL;

    if (*lista_samochodow == NULL) {
        *lista_samochodow = nowy;
    } else {
        Samochod *temp = *lista_samochodow;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nowy;
    }
}

void wyswietl_samochody(Samochod *lista_samochodow){
    system(CLEAR);
    if (lista_samochodow == NULL) {
        printf("\a");
        printf("\nLista jest pusta. Musisz najpierw dodac jakis samochod!\n");
        zaczekaj();
        return;
    }
    Samochod *temp = lista_samochodow;
    while (temp != NULL) {
        printf(GREEN "\n\nRejestracja: " RESET BOLD "%s:" RESET, temp->nr_rejestracyjny);
        printf("\n  Marka: %s", temp->marka);
        printf("\n  Model: %s", temp->model);
        printf("\n  Kolor: %s", temp->kolor);
        printf("\n  Rok produkcji: %d", temp->rok_produkcji);
        temp = temp->next;
    }
    printf("\n");
    zaczekaj();
}