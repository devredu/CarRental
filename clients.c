#include "clients.h"
#include "structs.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void dodaj_klienta(Klient **lista_klientow){
    Klient *nowy = (Klient*)malloc(sizeof(Klient));
    if (nowy == NULL) {
        return;
    }
    nowy->next = NULL;

    system(CLEAR);
    printf("=====================================\n");
    printf("| " BOLD "       DODAWANIE KLIENTOW         " RESET "|\n");
    printf("=====================================\n");
    printf("Podaj numer karty klienta (0-9999): ");
    if (scanf("%d", &nowy->numer_karty) == 1) {
        if (nowy->numer_karty > 0 && nowy->numer_karty <= 9999) {
            Klient *temp = *lista_klientow;
            while (temp != NULL) {
                if (temp->numer_karty == nowy->numer_karty) {
                    printf("\a");
                    printf(BOLD_RED "\nBLAD! Klient o takim numerze karty jest juz dodany." RESET);
                    free(nowy);
                    wyczysc_bufor();
                    zaczekaj();
                    return;
                }
                temp = temp->next;
            }
            wyczysc_bufor();
        } else {
            printf("\a");
            printf(BOLD_RED "\nBLAD! Podaj prawidlowy numer karty (0-9999)." RESET);
            free(nowy);
            wyczysc_bufor();
            zaczekaj();
            return;
        }
    } else {
        printf("\a");
        printf(BOLD_RED "\nBLAD! Numer karty musi skladac sie z cyfr." RESET);
        free(nowy);
        wyczysc_bufor();
        zaczekaj();
        return;
    }
    printf("Podaj imie: ");
    scanf("%19s", nowy->imie);
    wyczysc_bufor();
    zamien_na_wielkie(nowy->imie);
    printf("Podaj nazwisko: ");
    scanf("%29s", nowy->nazwisko);
    wyczysc_bufor();
    zamien_na_wielkie(nowy->nazwisko);
    printf("Podaj adres: ");
    scanf(" %29[^\n]", nowy->adres);
    wyczysc_bufor();
    zamien_na_wielkie(nowy->adres);
    while (true) {
        printf("Podaj numer telefonu (9 cyfr): ");
        scanf("%s", nowy->numer_telefonu);
        wyczysc_bufor();
        if (strlen(nowy->numer_telefonu) != 9) {
            printf(BOLD_RED "\nBLAD! Numer telefonu musi miec dokladnie 9 cyfr.\n" RESET);
            continue;
        }
        int sprawdz_cyfry = 1;
        for (int i = 0; i < 9; i++) {
            if (!isdigit(nowy->numer_telefonu[i])) {
                sprawdz_cyfry = 0;
                break;
            }
        }
        if (sprawdz_cyfry == 0) {
            printf("\a");
            printf(BOLD_RED "\nBLAD! Numer musi skladac sie z liczb.\n" RESET);
            continue;
        }
        break;
    }
    printf(GREEN "\nPomyslnie dodano klienta!" RESET);
    zaczekaj();

    if (*lista_klientow == NULL) {
        *lista_klientow = nowy;
    } else {
        Klient *temp = *lista_klientow;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nowy;
    }
}

void usun_klienta(Klient **lista_klientow){
    if (*lista_klientow == NULL) {
        printf("\a");
        printf(BOLD_RED "\nBLAD! Lista jest pusta. Musisz najpierw dodac klientow." RESET);
        zaczekaj();
        return;
    }
    // no jakes sprawdzenie trzeba dodac czy klient nie ma wypozyczonego auta aktualnie czy cos takieigo

    system(CLEAR);
    printf("=====================================\n");
    printf("| " BOLD "        USUWANIE KLIENTOW         " RESET "|\n");
    printf("=====================================\n");
    int numer_karty;
    printf("Podaj numer karty klienta do usuniecia: ");
    scanf("%d", &numer_karty);
    wyczysc_bufor();

    Klient *temp_klient = *lista_klientow;

    if (numer_karty == temp_klient->numer_karty) {
        *lista_klientow = temp_klient->next;
        free(temp_klient);
        printf(GREEN "\nPomyslnie usunieto klienta!" RESET);
        zaczekaj();
        return;
    }
    Klient *poprzedni = temp_klient;
    temp_klient = temp_klient->next;

    while (temp_klient != NULL) {
        if (numer_karty == temp_klient->numer_karty) {
            poprzedni->next = temp_klient->next;
            free(temp_klient);
            printf(GREEN "\nPomyslnie usunieto klienta!" RESET);
            zaczekaj();
            return;
        }
        poprzedni = temp_klient;
        temp_klient = temp_klient->next;
    }
    printf("\a");
    printf(BOLD_RED "\nBLAD! Nie znaleziono klienta o podanym numerze karty." RESET);
    zaczekaj();
}

void edytuj_klienta(Klient **lista_klientow){
    if (*lista_klientow == NULL) {
        printf("\a");
        printf(BOLD_RED "\nBLAD! Lista jest pusta. Musisz najpierw dodac klientow." RESET);
        zaczekaj();
        return;
    }

    system(CLEAR);
    printf("=====================================\n");
    printf("| " BOLD "        EDYCJA KLIENTA            " RESET "|\n");
    printf("=====================================\n");
    int numer_karty;
    printf("Podaj numer karty klienta, ktorego chcesz edytowac: ");
    scanf("%d", &numer_karty);
    wyczysc_bufor();
    Klient *temp = *lista_klientow;
    while (temp != NULL) {
        if (temp->numer_karty == numer_karty) {
            printf("Podaj imie (obecne: %s): ", temp->imie);
            scanf("%19s", temp->imie);
            wyczysc_bufor();
            zamien_na_wielkie(temp->imie);
            printf("Podaj nazwisko (obecne: %s): ", temp->nazwisko);
            scanf("%29s", temp->nazwisko);
            wyczysc_bufor();
            zamien_na_wielkie(temp->nazwisko);
            printf("Podaj adres (obecny: %s): ", temp->adres);
            scanf(" %29[^\n]", temp->adres);
            wyczysc_bufor();
            zamien_na_wielkie(temp->adres);
            while (true) {
                char nowy_numer_telefonu[10];
                printf("Podaj numer telefonu (obecny: %s): ", temp->numer_telefonu);
                scanf("%s", nowy_numer_telefonu);
                wyczysc_bufor();
                if (strlen(nowy_numer_telefonu) != 9) {
                    printf(BOLD_RED "\nBLAD! Numer telefonu musi miec dokladnie 9 cyfr.\n" RESET);
                    continue;
                }
                int czy_cyfry = 1;
                for (int i = 0; i < 9; i++) {
                    if (!isdigit(nowy_numer_telefonu[i])) {
                        czy_cyfry = 0;
                        break;
                    }
                }
                if (czy_cyfry == 0) {
                    printf("\a");
                    printf(BOLD_RED "\nBLAD! Numer musi skladac sie z cyfr.\n" RESET);
                    continue;
                }
                strcpy(temp->numer_telefonu, nowy_numer_telefonu);
                break;
            }
            printf(GREEN "\nPomyslnie edytowano klienta!" RESET);
            zaczekaj();
            return;
        }
        temp = temp->next;
    }
    printf("\a");
    printf(BOLD_RED "\nBLAD! Nie znaleziono klienta o tym numerze." RESET);
    zaczekaj();
}

void wyswietl_klientow(Klient *lista_klientow){
    if (lista_klientow == NULL) {
        printf("\a");
        printf(BOLD_RED "\nBLAD! Lista jest pusta. Musisz najpierw dodac klientow." RESET);
        zaczekaj();
        return;
    }
    system(CLEAR);
    Klient *temp = lista_klientow;
    int licznik = 1;
    while (temp != NULL) {
        printf(GREEN "%d. Numer karty " RESET BOLD "[%d]:" RESET, licznik, temp->numer_karty);
        printf("\n  - Imie: %s", temp->imie);
        printf("\n  - Nazwisko: %s", temp->nazwisko);
        printf("\n  - Adres: %s", temp->adres);
        printf("\n  - Nr. telefonu: %s\n", temp->numer_telefonu);
        temp = temp->next;
        licznik++;
    }
    zaczekaj();
}