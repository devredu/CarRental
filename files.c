#include "files.h"
#include "utils.h"
#include "structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void zapisz_samochody(Samochod *lista_samochodow){
    FILE *plik = fopen("samochody.txt", "w");

    if (plik == NULL) {
        printf(BOLD_RED "BLAD! Nie mozna utworzyc pliku 'samochody.txt'." RESET);
        return;
    }

    Samochod *temp = lista_samochodow;
    while (temp != NULL) {
        fprintf(plik, "%s;%s;%s;%s;%d\n", temp->nr_rejestracyjny, temp->marka, temp->model, temp->kolor, temp->rok_produkcji);
        temp = temp->next;
    }
    fclose(plik);
}

void wczytaj_samochody(Samochod **lista_samochodow){
    FILE  *plik = fopen("samochody.txt", "r");
    if (plik == NULL) {
        return;
    }
    char nr_rejestracyjny[20], marka[20], model[30], kolor[30];
    int rok_produkcji;
    while (fscanf(plik, " %19[^;];%19[^;];%29[^;];%29[^;];%d", nr_rejestracyjny, marka, model, kolor, &rok_produkcji) == 5) {
        Samochod *nowy = (Samochod*)malloc(sizeof(Samochod));
        if (nowy == NULL) {
            break;
        }
        strcpy(nowy->nr_rejestracyjny, nr_rejestracyjny);
        strcpy(nowy->marka, marka);
        strcpy(nowy->model, model);
        strcpy(nowy->kolor, kolor);
        nowy->rok_produkcji = rok_produkcji;
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
    fclose(plik);
}

void zapisz_klientow(Klient *lista_klientow){
    FILE *plik = fopen("klienci.txt", "w");

    if (plik == NULL) {
        printf(BOLD_RED "BLAD! Nie mozna utworzyc pliku 'klienci.txt'." RESET);
        return;
    }

    Klient *temp = lista_klientow;
    while (temp != NULL) {
        fprintf(plik, "%d;%s;%s;%s;%s\n", temp->numer_karty, temp->imie, temp->nazwisko, temp->adres, temp->numer_telefonu);
        temp = temp->next;
    }
    fclose(plik);
}

void wczytaj_klientow(Klient **lista_klientow){
    FILE  *plik = fopen("klienci.txt", "r");
    if (plik == NULL) {
        return;
    }
    char imie[20], nazwisko[30], adres[50], numer_telefonu[10];
    int numer_karty = 0;
    while (fscanf(plik, " %d;%19[^;];%29[^;];%49[^;];%9[^\n]", &numer_karty, imie, nazwisko, adres, numer_telefonu) == 5) {
        Klient *nowy = (Klient*)malloc(sizeof(Klient));
        if (nowy == NULL) {
            break;
        }
        nowy->numer_karty = numer_karty;
        strcpy(nowy->imie, imie);
        strcpy(nowy->nazwisko, nazwisko);
        strcpy(nowy->adres, adres);
        strcpy(nowy->numer_telefonu, numer_telefonu);
        nowy->next = NULL;

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
    fclose(plik);
}

void zapisz_wypozyczenia(Wypozyczenie *lista_wypozyczen) {
    FILE *plik = fopen("wypozyczenia.txt", "w");

    if (plik == NULL) {
        printf(BOLD_RED "BLAD! Nie mozna utworzyc pliku 'wypozyczenia.txt'." RESET);
        return;
    }

    Wypozyczenie *temp = lista_wypozyczen;
    while (temp != NULL) {
        fprintf(plik, "%d;%s;%s;%s\n",
                temp->numer_karty_klienta,
                temp->nr_rejestracyjny,
                temp->data_od,
                temp->data_do);
        temp = temp->next;
    }
    fclose(plik);
}

void wczytaj_wypozyczenia(Wypozyczenie **lista_wypozyczen) {
    FILE *plik = fopen("wypozyczenia.txt", "r");
    if (plik == NULL) {
        return;
    }

    int nr_karty;
    char nr_rej[20], data_od[11], data_do[11];

    while (fscanf(plik, " %d;%19[^;];%10[^;];%10[^\n]", &nr_karty, nr_rej, data_od, data_do) == 4) {
        Wypozyczenie *nowe = (Wypozyczenie*)malloc(sizeof(Wypozyczenie));
        if (nowe == NULL) {
            break;
        }

        nowe->numer_karty_klienta = nr_karty;
        strcpy(nowe->nr_rejestracyjny, nr_rej);
        strcpy(nowe->data_od, data_od);
        strcpy(nowe->data_do, data_do);
        nowe->next = NULL;

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
    fclose(plik);
}