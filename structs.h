#ifndef CARRENTAL_STRUCTS_H
#define CARRENTAL_STRUCTS_H

struct Samochod {
    char nr_rejestracyjny[20];
    char marka[20];
    char model[30];
    int rok_produkcji;
    char kolor[30];
    int przebieg;
    int liczba_egzemplarzy;
    int liczba_wypozyczonych;
} Samochod;

struct Klient {
    int numer_karty;
    char imie[20];
    char nazwisko[30];
    char adres[30];
    char numer_telefonu[15];
} Klient;

struct Wypozyczenie {
    int numer_karty_klienta;
    char nr_rejestracyjny[20];
    char data_od[15];
    char data_do[15];
} Wypozyczenie;

#endif