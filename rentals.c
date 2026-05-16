#include "rentals.h"
#include "structs.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void dodaj_wypozyczenie(Samochod *lista_samochodow, Klient *lista_klientow, Wypozyczenie **lista_wypozyczen){
    Wypozyczenie *nowe = (Wypozyczenie*)malloc(sizeof(Wypozyczenie));
    if (nowe == NULL) {
        return;
    }
    nowe->next = NULL;

    system(CLEAR);
    printf("=====================================\n");
    printf("| " BOLD "       DODAWANIE WYPOZYCZENIA     " RESET "|\n");
    printf("=====================================\n");
    printf("Podaj indywidualny numer wypozyczenia: ");
    scanf("%19s", nowe->numer_wypozyczenia);
    zamien_na_wielkie(nowe->numer_wypozyczenia);
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
    if (temp_samochod->status == 0) {
        printf("\a");
        printf(BOLD_RED "\nBLAD! Samochod o takim numerze rejestracyjnym jest juz wypozyczony." RESET);
        free(nowe);
        zaczekaj();
        return;
    }
    nowe->next = NULL;
    nowe->numer_karty_klienta = numer_karty;
    strcpy(nowe->nr_rejestracyjny, nr_rejestracyjny);
    while (true) {
        printf("Podaj date wypozyczenia (RRRR-MM-DD): ");
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
        printf("Podaj date zwrotu (RRRR-MM-DD): ");
        scanf("%10s", nowe->data_do);
        wyczysc_bufor();
        if (!waliduj_date(nowe->data_do)) {
            printf("\a");
            printf(BOLD_RED "\nBLAD! Niepoprawna data.\n" RESET);
            continue;
        }
        if (strcmp(nowe->data_do, nowe->data_od) < 0) {
            printf("\a");
            printf(BOLD_RED "\nBLAD! Data zwrotu nie moze byc przed data wypozyczenia.\n" RESET);
            continue;
        }
        break;
    }
    temp_samochod->status = 0;
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

void usun_wypozyczenie(Samochod **lista_samochodow, Wypozyczenie **lista_wypozyczen){
    if (*lista_wypozyczen == NULL) {
        printf("\a");
        printf(BOLD_RED "\nBLAD! Lista jest pusta. Musisz najpierw dodac wypozyczenia." RESET);
        zaczekaj();
        return;
    }

    system(CLEAR);
    printf("=====================================\n");
    printf("| " BOLD "        USUWANIE WYPOZYCZENIA     " RESET "|\n");
    printf("=====================================\n");
    char szukany_numer[20];
    printf("Podaj numer wypozyczenia do usuniecia: ");
    scanf("%19s", szukany_numer);
    wyczysc_bufor();
    zamien_na_wielkie(szukany_numer);

    Wypozyczenie *temp_wypozyczenie = *lista_wypozyczen;
    if (strcmp(temp_wypozyczenie->numer_wypozyczenia, szukany_numer) == 0) {
        Samochod *temp_samochod = *lista_samochodow;
        while (temp_samochod != NULL) {
            if (strcmp(temp_samochod->nr_rejestracyjny, temp_wypozyczenie->nr_rejestracyjny) == 0) {
                temp_samochod->status = 1;
                break;
            }
            temp_samochod = temp_samochod->next;
        }
        *lista_wypozyczen = temp_wypozyczenie->next;
        free(temp_wypozyczenie);
        printf(GREEN "\nPomyslnie usunieto wypozyczenie!" RESET);
        zaczekaj();
        return;
    }
    Wypozyczenie *poprzedni = temp_wypozyczenie;
    temp_wypozyczenie = temp_wypozyczenie->next;

    while (temp_wypozyczenie != NULL) {
        if (strcmp(temp_wypozyczenie->numer_wypozyczenia, szukany_numer) == 0) {
            Samochod *temp_samochod = *lista_samochodow;
            while (temp_samochod != NULL) {
                if (strcmp(temp_samochod->nr_rejestracyjny, temp_wypozyczenie->nr_rejestracyjny) == 0) {
                    temp_samochod->status = 1;
                    break;
                }
                temp_samochod = temp_samochod->next;
            }
            poprzedni->next = temp_wypozyczenie->next;
            free(temp_wypozyczenie);
            printf(GREEN "\nPomyslnie usunieto wypozyczenie!" RESET);
            zaczekaj();
            return;
        }
        poprzedni = temp_wypozyczenie;
        temp_wypozyczenie = temp_wypozyczenie->next;
    }
    printf("\a");
    printf(BOLD_RED "\nBLAD! Nie znaleziono wypozyczenia o podanym numerze." RESET);
    zaczekaj();
}

void edytuj_wypozyczenie(Samochod **lista_samochodow, Wypozyczenie **lista_wypozyczen){
    if (*lista_wypozyczen == NULL) {
        printf("\a");
        printf(BOLD_RED "\nBLAD! Lista jest pusta. Musisz najpierw dodac wypozyczenia." RESET);
        zaczekaj();
        return;
    }

    system(CLEAR);
    printf("=====================================\n");
    printf("| " BOLD "        EDYCJA WYPOZYCZENIA       " RESET "|\n");
    printf("=====================================\n");

    char szukany_numer[20];
    printf("Podaj numer wypozyczenia do edycji: ");
    scanf("%19s", szukany_numer);
    wyczysc_bufor();
    zamien_na_wielkie(szukany_numer);

    Wypozyczenie *temp_wypozyczenie = *lista_wypozyczen;
    while (temp_wypozyczenie != NULL) {
        if (strcmp(temp_wypozyczenie->numer_wypozyczenia, szukany_numer) == 0) {
            char nowa_rejestracja[20], data_od[11], data_do[11];

            printf("Wpisz numer rejestracyjny (obecnie: %s): ", temp_wypozyczenie->nr_rejestracyjny);
            scanf("%19s", nowa_rejestracja);
            wyczysc_bufor();
            zamien_na_wielkie(nowa_rejestracja);

            if (strcmp(nowa_rejestracja, temp_wypozyczenie->nr_rejestracyjny) != 0) {
                Samochod *nowy = *lista_samochodow;
                int znaleziony = 0;
                while (nowy != NULL) {
                    if (strcmp(nowy->nr_rejestracyjny, nowa_rejestracja) == 0) {
                        if (nowy->status == 0) {
                            printf(BOLD_RED "\nBLAD! Ten samochod jest juz wypozyczony." RESET);
                            zaczekaj();
                            return;
                        }
                        znaleziony = 1;
                        break;
                    }
                    nowy = nowy->next;
                }
                if (!znaleziony) {
                    printf(BOLD_RED "\nBLAD! Nie znaleziono samochodu o takiej rejestracji." RESET);
                    zaczekaj();
                    return;
                }
                Samochod *stary = *lista_samochodow;
                while (stary != NULL) {
                    if (strcmp(stary->nr_rejestracyjny, temp_wypozyczenie->nr_rejestracyjny) == 0) {
                        stary->status = 1;
                        break;
                    }
                    stary = stary->next;
                }
                nowy->status = 0;
                strcpy(temp_wypozyczenie->nr_rejestracyjny, nowa_rejestracja);
            }

            while (true) {
                printf("Podaj nowa date wypozyczenia (obecna: %s): ", temp_wypozyczenie->data_od);
                scanf("%10s", data_od);
                wyczysc_bufor();
                if (!waliduj_date(data_od)) {
                    printf(BOLD_RED "BLAD! Niepoprawny format daty.\n" RESET);
                    continue;
                }
                break;
            }
            while (true) {
                printf("Podaj nowa date zwrotu (obecna: %s): ", temp_wypozyczenie->data_do);
                scanf("%10s", data_do);
                wyczysc_bufor();
                if (!waliduj_date(data_do)) {
                    printf(BOLD_RED "\nBLAD! Niepoprawny format daty.\n" RESET);
                    continue;
                }
                if (strcmp(data_do, data_od) < 0) {
                    printf(BOLD_RED "\nBLAD! Data zwrotu nie moze byc przed data wypozyczenia.\n" RESET);
                    continue;
                }
                break;
            }
            strcpy(temp_wypozyczenie->data_od, data_od);
            strcpy(temp_wypozyczenie->data_do, data_do);
            printf(GREEN "\nPomyslnie zmieniono wypozyczenie!" RESET);
            zaczekaj();
            return;
        }
        temp_wypozyczenie = temp_wypozyczenie->next;
    }
    printf("\a");
    printf(BOLD_RED "\nBLAD! Nie znaleziono wypozyczenia o takim numerze." RESET);
    zaczekaj();
}

void wyswietl_wypozyczenia(Wypozyczenie *lista_wypozyczen){
    if (lista_wypozyczen == NULL) {
        printf("\a");
        printf(BOLD_RED "\nBLAD! Lista jest pusta. Musisz najpierw dodac wypozyczenia." RESET);
        zaczekaj();
        return;
    }

    char dzisiejsza_data[11];
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    strftime(dzisiejsza_data, sizeof(dzisiejsza_data), "%Y-%m-%d", tm);

    system(CLEAR);
    Wypozyczenie *temp = lista_wypozyczen;
    int licznik = 1;
    while (temp != NULL) {
        printf(GREEN "%d. Wypozyczenie " RESET BOLD "(%s):" RESET, licznik, temp->numer_wypozyczenia);
        printf("\n  Numer karty klienta: %d", temp->numer_karty_klienta);
        printf("\n  Numer rejestracyjny: %s", temp->nr_rejestracyjny);
        printf("\n  Data wypozyczenia: %s", temp->data_od);
        printf("\n  Data zwrotu: %s", temp->data_do);
        if (strcmp(dzisiejsza_data, temp->data_od) < 0) {
            printf("\n  Status: " YELLOW "Zaplanowane\n" RESET);
        } else if (strcmp(dzisiejsza_data, temp->data_do) == 0) {
            printf("\n  Status: " CYAN "Do zwrotu dzisiaj\n" RESET);
        } else if (strcmp(dzisiejsza_data, temp->data_do) > 0) {
            printf("\n  Status: " BOLD_RED "Do zwrotu\n" RESET);
        } else {
            printf("\n  Status: " GREEN "Aktualne\n" RESET);
        }
        temp = temp->next;
        licznik++;
    }
    zaczekaj();
}