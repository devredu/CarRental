#include "cars.h"
#include "structs.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dodaj_samochod(Samochod **lista_samochodow){
    Samochod *nowy = (Samochod*)malloc(sizeof(Samochod));
    if (nowy == NULL) {
        return;
    }
    nowy->next = NULL;

    system(CLEAR);
    printf("=====================================\n");
    printf("| " BOLD "       DODAWANIE SAMOCHODU        " RESET "|\n");
    printf("=====================================\n");
    printf("Podaj numer rejestracyjny samochodu: ");
    scanf("%19s", nowy->nr_rejestracyjny);
    wyczysc_bufor();
    zamien_na_wielkie(nowy->nr_rejestracyjny);
    Samochod *temp = *lista_samochodow;
    while (temp != NULL) {
        if (strcmp(temp->nr_rejestracyjny, nowy->nr_rejestracyjny) == 0) {
            printf("\a");
            printf(BOLD_RED "\nBLAD! Samochod o takiej rejestracji jest juz dodany." RESET);
            free(nowy);
            zaczekaj();
            return;
        }
        temp = temp->next;
    }
    printf("Podaj marke samochodu: ");
    scanf(" %19[^\n]", nowy->marka);
    wyczysc_bufor();
    zamien_na_wielkie(nowy->marka);
    printf("Podaj model samochodu: ");
    scanf(" %29[^\n]", nowy->model);
    wyczysc_bufor();
    zamien_na_wielkie(nowy->model);
    printf("Podaj glowny kolor samochodu: ");
    scanf("%29s", nowy->kolor);
    wyczysc_bufor();
    zamien_na_wielkie(nowy->kolor);
    while (true) {
        printf("Podaj rok produkcji samochodu: ");
        if (scanf("%d", &nowy->rok_produkcji) == 1) {
            if (nowy->rok_produkcji > 1900 && nowy->rok_produkcji <= 2026) {
                wyczysc_bufor();
                break;
            } else {
                printf("\a");
                printf(BOLD_RED "\nBLAD! Podaj prawidlowy rok (1900-2026).\n" RESET);
            }
        } else {
            printf("\a");
            printf(BOLD_RED "\nBLAD! Rok musi skladac sie z cyfr.\n" RESET);
        }
        wyczysc_bufor();
    }
    printf(GREEN "\nPomyslnie dodano samochod!" RESET);
    zaczekaj();

    if (*lista_samochodow == NULL) {
        *lista_samochodow = nowy;
    } else {
        temp = *lista_samochodow;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nowy;
    }
}

void usun_samochod(Samochod **lista_samochodow){
    if (*lista_samochodow == NULL) {
        printf("\a");
        printf(BOLD_RED "\nBLAD! Lista jest pusta. Musisz najpierw dodac samochody." RESET);
        zaczekaj();
        return;
    }

    // DODAC SPRAWDZANIE CZY SAMOCHOD NIE JEST AKTUALNIE WYPOZYCZONY
    system(CLEAR);
    printf("=====================================\n");
    printf("| " BOLD "        USUWANIE SAMOCHODU        " RESET "|\n");
    printf("=====================================\n");
    char szukana_rejestracja[20];
    printf("Podaj numer rejestracyjny samochodu do usuniecia: ");
    scanf("%19s", szukana_rejestracja);
    wyczysc_bufor();
    zamien_na_wielkie(szukana_rejestracja);

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

void edytuj_samochod(Samochod **lista_samochodow){
    if (*lista_samochodow == NULL) {
        printf("\a");
        printf(BOLD_RED "\nBLAD! Lista jest pusta. Musisz najpierw dodac samochody." RESET);
        zaczekaj();
        return;
    }

    system(CLEAR);
    printf("=====================================\n");
    printf("| " BOLD "        EDYCJA SAMOCHODU          " RESET "|\n");
    printf("=====================================\n");

    char szukana_rejestracja[20];
    printf("Podaj numer rejestracyjny samochodu do edycji: ");
    scanf("%19s", szukana_rejestracja);
    wyczysc_bufor();
    zamien_na_wielkie(szukana_rejestracja);

    Samochod *temp = *lista_samochodow;
    while (temp != NULL) {
        if (strcmp(temp->nr_rejestracyjny, szukana_rejestracja) == 0) {
            printf("Podaj marke (obecna: %s): ", temp->marka);
            scanf(" %19[^\n]", temp->marka);
            wyczysc_bufor();
            zamien_na_wielkie(temp->marka);
            printf("Podaj model (obecny: %s): ", temp->model);
            scanf(" %29[^\n]", temp->model);
            wyczysc_bufor();
            zamien_na_wielkie(temp->model);
            printf("Podaj glowny kolor (obecny: %s): ", temp->kolor);
            scanf("%29s", temp->kolor);
            wyczysc_bufor();
            zamien_na_wielkie(temp->kolor);
            while (1) {
                int nowy_rok;
                printf("Podaj rok produkcji (obecny: %d): ", temp->rok_produkcji);
                if (scanf("%d", &nowy_rok) == 1) {
                    if (nowy_rok > 1900 && nowy_rok <= 2026) {
                        temp->rok_produkcji = nowy_rok;
                        wyczysc_bufor();
                        break;
                    } else {
                        printf("\a");
                        printf(BOLD_RED "\nBLAD! Podaj prawidlowy rok (1900-2026).\n" RESET);
                    }
                } else {
                    printf("\a");
                    printf(BOLD_RED "\nBLAD! Rok musi skladac sie z cyfr.\n" RESET);
                }
                wyczysc_bufor();
            }
            printf(GREEN "\nPomyslnie edytowano samochod!" RESET);
            zaczekaj();
            return;
        }
        temp = temp->next;
    }
    printf("\a");
    printf(BOLD_RED "\nBLAD! Nie znaleziono samochodu o podanym numerze rejestracyjnym." RESET);
    zaczekaj();
}

void wyswietl_samochody(Samochod *lista_samochodow){
    if (lista_samochodow == NULL) {
        printf("\a");
        printf(BOLD_RED "\nBLAD! Lista jest pusta. Musisz najpierw dodac samochody." RESET);
        zaczekaj();
        return;
    }
    system(CLEAR);
    Samochod *temp = lista_samochodow;
    int licznik = 1;
    while (temp != NULL) {
        printf(GREEN "%d. Rejestracja " RESET BOLD "(%s):" RESET, licznik, temp->nr_rejestracyjny);
        printf("\n  Marka: %s", temp->marka);
        printf("\n  Model: %s", temp->model);
        printf("\n  Kolor: %s", temp->kolor);
        printf("\n  Rok produkcji: %d\n", temp->rok_produkcji);
        temp = temp->next;
        licznik++;
    }
    zaczekaj();
}