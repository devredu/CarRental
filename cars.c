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
    nowy->next = NULL;

    system(CLEAR);
    printf("Podaj numer rejestracyjny samochodu: ");
    scanf("%19s", nowy->nr_rejestracyjny);
    zamien_na_wielkie(nowy->nr_rejestracyjny);
    Samochod *sprawdzenie = *lista_samochodow;
    while (sprawdzenie != NULL) {
        if (strcmp(sprawdzenie->nr_rejestracyjny, nowy->nr_rejestracyjny) == 0) {
            printf(BOLD_RED "\nBLAD! Samochod o takiej rejestracji jest juz dodany!" RESET);
            free(nowy);
            zaczekaj();
            return;
        }
        sprawdzenie = sprawdzenie->next;
    }
    printf("Podaj marke samochodu: ");
    scanf("%19s", nowy->marka);
    zamien_na_wielkie(nowy->marka);
    printf("Podaj model samochodu: ");
    scanf("%29s", nowy->model);
    zamien_na_wielkie(nowy->model);
    printf("Podaj kolor samochodu: ");
    scanf("%29s", nowy->kolor);
    zamien_na_wielkie(nowy->kolor);
    while (1) {
        printf("Podaj rok produkcji samochodu: ");
        if (scanf("%d", &nowy->rok_produkcji) == 1) {
            if (nowy->rok_produkcji > 1900 && nowy->rok_produkcji <= 2026) {
                while (getchar() != '\n');
                break;
            } else {
                printf(BOLD_RED "\nBLAD! Podaj prawidlowy rok (1900-2026).\n" RESET);
            }
        } else {
            printf(BOLD_RED "\nBLAD! Rok musi skladac sie z liczb.\n" RESET);
        }
        while (getchar() != '\n');
    }

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

void usun_samochod(Samochod **lista_samochodow){
    if (*lista_samochodow == NULL) {
        printf("\a");
        printf(BOLD_RED "\nBLAD! Lista jest pusta. Musisz najpierw dodac jakis samochod!" RESET);
        zaczekaj();
        return;
    }

    // DODAC SPRAWDZANIE CZY SAMOCHOD NIE JEST AKTUALNIE WYPOZYCZONY

    system(CLEAR);
    char szukana_rejestracja[20];
    printf("Podaj numer rejestracyjny samochodu do usuniecia: ");
    scanf("%19s", szukana_rejestracja);
    for (int i = 0; szukana_rejestracja[i]; i++) {
        szukana_rejestracja[i] = toupper(szukana_rejestracja[i]);
    }

    Samochod *temp = *lista_samochodow;

    if (strcmp(temp->nr_rejestracyjny, szukana_rejestracja) == 0) {
        *lista_samochodow = temp->next;
        free(temp);
        printf(GREEN "\nPomyslnie usunieto samochod!" RESET);
        zaczekaj();
        return;
    }
    Samochod *poprzedni = temp;
    temp = temp->next;

    while (temp != NULL) {
        if (strcmp(temp->nr_rejestracyjny, szukana_rejestracja) == 0) {
            poprzedni->next = temp->next;
            free(temp);
            printf(GREEN "\nPomyslnie usunieto samochod!" RESET);
            zaczekaj();
            return;
        }
        poprzedni = temp;
        temp = temp->next;
    }
    printf("\a");
    printf(BOLD_RED "\nBLAD! Nie znaleziono samochodu o podanym numerze rejestracyjnym." RESET);
    zaczekaj();
}

void wyswietl_samochody(Samochod *lista_samochodow){
    if (lista_samochodow == NULL) {
        printf("\a");
        printf(BOLD_RED "\nBLAD! Lista jest pusta. Musisz najpierw dodac jakis samochod!" RESET);
        zaczekaj();
        return;
    }
    system(CLEAR);
    Samochod *temp = lista_samochodow;
    while (temp != NULL) {
        printf(GREEN "Rejestracja " RESET BOLD "(%s):" RESET, temp->nr_rejestracyjny);
        printf("\n  Marka: %s", temp->marka);
        printf("\n  Model: %s", temp->model);
        printf("\n  Kolor: %s", temp->kolor);
        printf("\n  Rok produkcji: %d\n", temp->rok_produkcji);
        temp = temp->next;
    }
    zaczekaj();
}