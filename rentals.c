#include "rentals.h"
#include "structs.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dodaj_wypozyczenie(Samochod *lista_samochodow, Klient *lista_klientow, Wypozyczenie **lista_wypozyczen){
    Wypozyczenie *nowe = (Wypozyczenie*)malloc(sizeof(Wypozyczenie));
    if (nowe == NULL) {
        return;
    }
    nowe->next = NULL;

    system(CLEAR);
    printf("=====================================\n");
    printf("| " BOLD "       DODAWANIE WYPOZYCZENIA      " RESET "|\n");
    printf("=====================================\n");
    printf("Podaj numer karty klienta: ");
    int numer_karty;
    scanf("%d", &numer_karty);
    wyczysc_bufor();
    Klient *temp_klient = lista_klientow;
    while (temp_klient != NULL) {
        if (temp_klient->numer_karty == numer_karty) {
            break;
        }
        temp_klient = temp_klient->next;
    }
    if (temp_klient == NULL) {
        printf("\a");
        printf(BOLD_RED "\nBLAD! Nie znaleziono klienta o takim numerze karty." RESET);
        free(nowe);
        zaczekaj();
        return;
    }
    printf("Podaj numer rejestracyjny samochodu: ");
    char nr_rejestracyjny[20];
    scanf("%19s", nr_rejestracyjny);
    wyczysc_bufor();
    zamien_na_wielkie(nr_rejestracyjny);
    Samochod *temp_samochod = lista_samochodow;
    while (temp_samochod != NULL) {
        if (strcmp(temp_samochod->nr_rejestracyjny, nr_rejestracyjny) == 0) {
            break;
        }
        temp_samochod = temp_samochod->next;
    }
    if (temp_samochod == NULL) {
        printf("\a");
        printf(BOLD_RED "\nBLAD! Nie znaleziono samochodu o takim numerze rejestracyjnym." RESET);
        free(nowe);
        zaczekaj();
        return;
    }
    Wypozyczenie *temp_wypozyczenie = *lista_wypozyczen;
    while (temp_wypozyczenie != NULL) {
        if (strcmp(temp_wypozyczenie->nr_rejestracyjny, nr_rejestracyjny) == 0) {
            printf("\a");
            printf(BOLD_RED "\nBLAD! Samochod o takim numerze rejestracyjnym jest juz wypozyczony." RESET);
            free(nowe);
            zaczekaj();
            return;
        }
        temp_wypozyczenie = temp_wypozyczenie->next;
    }
    nowe->next = NULL;
    nowe->numer_karty_klienta = numer_karty;
    strcpy(nowe->nr_rejestracyjny, nr_rejestracyjny);
    while (true) {
        printf("Od kiedy (RRRR-MM-DD): ");
        scanf("%10s", nowe->data_od);
        wyczysc_bufor();
        if (!waliduj_date(nowe->data_od)) {
            printf("\a");
            printf(BOLD_RED "\nBLAD! Niepoprawna data.\n" RESET);
            continue;
        }
        break;
    }
    while (true) {
        printf("Do kiedy (RRRR-MM-DD): ");
        scanf("%10s", nowe->data_do);
        wyczysc_bufor();
        if (!waliduj_date(nowe->data_do)) {
            printf("\a");
            printf(BOLD_RED "\nBLAD! Niepoprawna data.\n" RESET);
            continue;
        }
        if (strcmp(nowe->data_do, nowe->data_od) < 0) {
            printf("\a");
            printf(BOLD_RED "\nBLAD! Data zwrotu nie moze byc wczesniejsza niz data wypozyczenia.\n" RESET);
            continue;
        }
        break;
    }
    printf(GREEN "\nPomyslnie dodano wypozyczenie!" RESET);
    zaczekaj();

    if (*lista_wypozyczen == NULL) {
        *lista_wypozyczen = nowe;
    } else {
        Wypozyczenie *temp = *lista_wypozyczen;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nowe;
    }
}