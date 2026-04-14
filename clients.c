#include "clients.h"
#include "structs.h"
#include "gui.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void dodaj_klienta(Klient **lista_klientow){
    Klient *nowy = (Klient*)malloc(sizeof(Klient));
    if (nowy == NULL) {
        return;
    }
    nowy->next = NULL;

    system(CLEAR);
    printf("===============================\n");
    printf(BOLD "      DODAWANIE KLIENTOW    \n" RESET);
    printf("===============================\n");
    while (true) {
        printf("Podaj numer karty klienta (0-9999): ");
        if (scanf("%d", &nowy->numer_karty) == 1) {
            if (nowy->numer_karty > 0 && nowy->numer_karty <= 9999) {
                int duplikat = 0;
                Klient *sprawdzenie = *lista_klientow;
                while (sprawdzenie != NULL) {
                    if (sprawdzenie->numer_karty == nowy->numer_karty) {
                        printf("\a");
                        printf(BOLD_RED "\nBLAD! Klient o takim numerze karty jest juz dodany!\n\n" RESET);
                        duplikat = 1;
                        break;
                    }
                    sprawdzenie = sprawdzenie->next;
                }
                if (duplikat) {
                    wyczysc_bufor();
                    continue;
                }
                wyczysc_bufor();
                break;
            } else {
                printf("\a");
                printf(BOLD_RED "\nBLAD! Podaj prawidlowy numer karty (0000-9999).\n\n" RESET);
            }
        } else {
            printf("\a");
            printf(BOLD_RED "\nBLAD! Numer karty moze zawierac tylko cyfry.\n\n" RESET);
        }
        wyczysc_bufor();
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
    scanf(" %29[^\n]s", nowy->adres);
    // pobiera tylko do bialego znaku, jakos to naprawic jak jest adres np. Kielce, ul. Warszawska 67
    wyczysc_bufor();
    zamien_na_wielkie(nowy->adres);
    while (true) {
        printf("Podaj numer telefonu (9 cyfr): ");
        scanf("%s", nowy->numer_telefonu);
        if (strlen(nowy->numer_telefonu) != 9) {
            printf(BOLD_RED "\nBLAD! Numer telefonu musi miec dokladnie 9 cyfr.\n\n" RESET);
            continue;
        }
        wyczysc_bufor();
        int czy_cyfry = 1;
        for (int i = 0; i < 9; i++) {
            if (!isdigit(nowy->numer_telefonu[i])) {
                czy_cyfry = 0;
                break;
            }
        }
        if (czy_cyfry == 0) {
            printf("\a");
            printf(BOLD_RED "\nBLAD! Numer moze zawierac tylko cyfry.\n\n" RESET);
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
        printf(BOLD_RED "\nBLAD! Lista jest pusta. Musisz najpierw dodac klientow!" RESET);
        zaczekaj();
        return;
    }

    // DODAC SPRAWDZANIE CZY klient nie wypozycza czegos aktualnie

    system(CLEAR);
    printf("===============================\n");
    printf(BOLD "      USUWANIE KLIENTA    \n" RESET);
    printf("===============================\n");
    int numer_karty;
    printf("Podaj numer karty klienta do usuniecia: ");
    scanf("%d", &numer_karty);
    wyczysc_bufor();

    Klient *temp = *lista_klientow;

    if (numer_karty == temp->numer_karty) {
        *lista_klientow = temp->next;
        free(temp);
        printf(GREEN "\nPomyslnie usunieto klienta!" RESET);
        zaczekaj();
        return;
    }
    Klient *poprzedni = temp;
    temp = temp->next;

    while (temp != NULL) {
        if (numer_karty == temp->numer_karty) {
            poprzedni->next = temp->next;
            free(temp);
            printf(GREEN "\nPomyslnie usunieto klienta!" RESET);
            zaczekaj();
            return;
        }
        poprzedni = temp;
        temp = temp->next;
    }
    printf("\a");
    printf(BOLD_RED "\nBLAD! Nie znaleziono klienta o podanym numerze karty." RESET);
    zaczekaj();
}

void wyswietl_klientow(Klient *lista_klientow){
    if (lista_klientow == NULL) {
        printf("\a");
        printf(BOLD_RED "\nBLAD! Lista jest pusta. Musisz najpierw dodac klientow!" RESET);
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