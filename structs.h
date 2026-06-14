/**
 * @file structs.h
 * @brief Definicje struktur danych reprezentujących bazę wypożyczalni samochodów.
 * @details Plik zawiera struktury dla list jednokierunkowych przechowujących dane
 * o samochodach, klientach i wypożyczeniach.
 */
#ifndef CARRENTAL_STRUCTS_H
#define CARRENTAL_STRUCTS_H

/**
 * @brief Struktura reprezentująca samochód.
 */
typedef struct Samochod {
    /** @brief Unikalny numer rejestracyjny pojazdu. */
    char nr_rejestracyjny[20];
    /** @brief Marka pojazdu. */
    char marka[20];
    /** @brief Model pojazdu. */
    char model[30];
    /** @brief Rok produkcji pojazdu. */
    int rok_produkcji;
    /** @brief Kolor nadwozia pojazdu. */
    char kolor[30];
    /** @brief Status pojazdu. */
    int status;
    /** @brief Wskaźnik na następny element listy. */
    struct Samochod *next;
} Samochod;

/**
 * @brief Struktura reprezentująca klienta.
 */
typedef struct Klient {
    /** @brief Unikalny numer karty klienta. */
    int numer_karty;
    /** @brief Imie klienta. */
    char imie[20];
    /** @brief Nazwisko klienta. */
    char nazwisko[30];
    /** @brief Adres zamieszkania klienta. */
    char adres[50];
    /** @brief Numer telefonu kontaktowego klienta. */
    char numer_telefonu[10];
    /** @brief Wskaźnik na następny element listy. */
    struct Klient *next;
} Klient;

/**
 * @brief Struktura reprezentująca wypożyczenie.
 */
typedef struct Wypozyczenie {
    /** @brief Unikalny numer wypożyczenia. */
    char numer_wypozyczenia[20];
    /** @brief Numer karty istniejącego klienta. */
    int numer_karty_klienta;
    /** @brief Numer rejestracyjny istniejącego pojazdu. */
    char nr_rejestracyjny[20];
    /** @brief Data rozpoczęcia wypożyczenia. */
    char data_od[11];
    /** @brief Planowana data zwrotu pojazdu. */
    char data_do[11];
    /** @brief Wskaźnik na następny element listy. */
    struct Wypozyczenie *next;
} Wypozyczenie;

#endif