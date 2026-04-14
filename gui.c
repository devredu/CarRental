#include "gui.h"
#include "structs.h"
#include "cars.h"
#include "utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "files.h"

void menu_glowne(Samochod **lista_samochodow){
    int wybor;
    bool status = true;
    while (status) {
        system(CLEAR);
        printf("===============================\n");
        printf(BOLD "   WYPOZYCZALNIA SAMOCHODOW    \n" RESET);
        printf("===============================\n");
        printf(GREEN "1. " RESET "Zarzadzanie samochodami\n");
        printf(GREEN "2. " RESET "Zarzadzanie klientami\n");
        printf(GREEN "3. " RESET "Wypozyczenia / Zwroty\n");
        printf(GREEN "0. " RESET "Zapisz i wyjdz\n");
        printf("-------------------------------\n");
        printf(BOLD "Wybor: " RESET);

        if (scanf("%d", &wybor) != 1) {
            printf("\a");
            printf(BOLD_RED "\nBLAD! Wpisz liczbe." RESET);
            wyczysc_bufor();
            zaczekaj();
            continue;
        }
        wyczysc_bufor();

        switch (wybor) {
            case 1:
                menu_samochod(lista_samochodow);
                break;
            case 2:
                menu_klient();
                break;
            case 3:
                menu_wypozyczenie();
                break;
            case 0:
                printf("\n");
                printf("Zapisywanie...\n");
                zapisz_samochody(*lista_samochodow);
                Sleep(500);
                printf("Zamykanie...");
                Sleep(1000);
                status = false;
                break;
            default:
                printf("\a");
                printf(BOLD_RED "\nBLAD! Wybierz jedna z opcji!" RESET);
                zaczekaj();
                break;
        }
    }
}

void menu_samochod(Samochod **lista_samochodow){
    int wybor;
    bool status = true;
    while (status) {
        system(CLEAR);
        printf("===============================\n");
        printf(BOLD "    ZARZADZANIE SAMOCHODAMI    \n" RESET);
        printf("===============================\n");
        printf(GREEN "1. " RESET "Dodaj samochod\n");
        printf(GREEN "2. " RESET "Usun samochod\n");
        printf(GREEN "3. " RESET "Edytuj samochod\n");
        printf(GREEN "4. " RESET "Wyswietl liste samochodow\n");
        printf(GREEN "0. " RESET "Wroc do menu glownego\n");
        printf("-------------------------------\n");
        printf("Wybor: ");

        if (scanf("%d", &wybor) != 1) {
            printf("\a");
            printf(BOLD_RED "\nBLAD! Wpisz liczbe." RESET);
            wyczysc_bufor();
            zaczekaj();
            continue;
        }
        wyczysc_bufor();

        switch (wybor) {
            case 1:
                dodaj_samochod(lista_samochodow);
                break;
            case 2:
                usun_samochod(lista_samochodow);
                break;
            case 3:
                // edytowanie samochodu
                break;
            case 4:
                wyswietl_samochody(*lista_samochodow);
                break;
            case 0:
                status = false;
                break;
            default:
                printf("\a");
                printf(BOLD_RED "\nBLAD! Wybierz jedna z opcji!" RESET);
                zaczekaj();
                break;
        }
    }
}

void menu_klient(){
    int wybor;
    bool status = true;
    while (status) {
        system(CLEAR);
        printf("===============================\n");
        printf(BOLD "      ZARZADZANIE KLIENTAMI    \n" RESET);
        printf("===============================\n");
        printf(GREEN "1. " RESET "Dodaj kilienta\n");
        printf(GREEN "2. " RESET "Usun klienta\n");
        printf(GREEN "3. " RESET "Edytuj klienta\n");
        printf(GREEN "4. " RESET "Wyswietl liste klientow\n");
        printf(GREEN "0. " RESET "Wroc do menu glownego\n");
        printf("-------------------------------\n");
        printf("Wybor: ");

        if (scanf("%d", &wybor) != 1) {
            printf("\a");
            printf(BOLD_RED "\nBLAD! Wpisz liczbe." RESET);
            wyczysc_bufor();
            zaczekaj();
            continue;
        }
        wyczysc_bufor();

        switch (wybor) {
            case 1:
                // dodawania klientow
                break;
            case 2:
                // usuwanie klientow
                break;
            case 3:
                // edytowaniie klientow
                break;
            case 4:
                // lista klientow
                break;
            case 0:
                status = false;
                break;
            default:
                printf("\a");
                printf(BOLD_RED "\nBLAD! Wybierz jedna z opcji!" RESET);
                zaczekaj();
                break;
        }
    }
}

void menu_wypozyczenie(){
    int wybor;
    bool status = true;
    while (status) {
        system(CLEAR);
        printf("===============================\n");
        printf(BOLD "      WYPOZYCZENIA / ZWROTY    \n" RESET);
        printf("===============================\n");
        printf(GREEN "1. " RESET "Dodaj wypozyczenie\n");
        printf(GREEN "2. " RESET "Usun wypozyczenie\n");
        printf(GREEN "3. " RESET "Wyswietl liste aktualnie wypozyczonych samochodow\n");
        printf(GREEN "0. " RESET "Wroc do menu glownego\n");
        printf("-------------------------------\n");
        printf("Wybor: ");

        if (scanf("%d", &wybor) != 1) {
            printf("\a");
            printf(BOLD_RED "\nBLAD! Wpisz liczbe." RESET);
            wyczysc_bufor();
            zaczekaj();
            continue;
        }
        wyczysc_bufor();

        switch (wybor) {
            case 1:
                // dodawnie wypozyczenia
                break;
            case 2:
                // usuwanie wypozyczenia
                break;
            case 3:
                // lista aktualnie wypozyczonych
                break;
            case 0:
                status = false;
                break;
            default:
                printf("\a");
                printf(BOLD_RED "\nBLAD! Wybierz jedna z opcji!" RESET);
                zaczekaj();
                break;
        }
    }
}