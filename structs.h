#ifndef CARRENTAL_STRUCTS_H
#define CARRENTAL_STRUCTS_H
#include <stdbool.h>

typedef struct Samochod {
    char nr_rejestracyjny[20];
    char marka[20];
    char model[30];
    int rok_produkcji;
    char kolor[30];
    int status;
    struct Samochod *next;
} Samochod;

typedef struct Klient {
    int numer_karty;
    char imie[20];
    char nazwisko[30];
    char adres[50];
    char numer_telefonu[10];
    struct Klient *next;
} Klient;

typedef struct Wypozyczenie {
    int numer_karty_klienta;
    char nr_rejestracyjny[20];
    char data_od[11];
    char data_do[11];
    struct Wypozyczenie *next;
} Wypozyczenie;

#endif