#ifndef CARRENTAL_STRUCTS_H
#define CARRENTAL_STRUCTS_H

typedef struct Samochod {
    char nr_rejestracyjny[20];
    char marka[20];
    char model[30];
    int rok_produkcji;
    char kolor[30];
    struct Samochod *next;
} Samochod;

typedef struct Klient {
    int numer_karty;
    char imie[20];
    char nazwisko[30];
    char adres[30];
    char numer_telefonu[10];
    struct Klient *next;
} Klient;

typedef struct Wypozyczenie {
    int numer_karty_klienta;
    char nr_rejestracyjny[20];
    char data_od[15];
    char data_do[15];
    //struct Wypozyczenie *next;
} Wypozyczenie;

#endif