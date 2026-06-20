/**
 * @file structs.h
 * @brief Deklaracje struktur danych wykorzystywanych w projekcie wypożyczalni samochodów.
 * @details Plik zawiera struktury dla list jednokierunkowych przechowujących dane
 * o samochodach, klientach i wypożyczeniach.
 */

#ifndef CARRENTAL_STRUCTS_H
#define CARRENTAL_STRUCTS_H

/**
 * @brief Struktura reprezentująca samochód.
 */
typedef struct Samochod {
    char nr_rejestracyjny[20]; ///< Unikalny numer rejestracyjny pojazdu.
    char marka[20]; ///< Marka pojazdu.
    char model[30]; ///< Model pojazdu.
    int rok_produkcji; ///< Rok produkcji pojazdu.
    char kolor[30]; ///< Kolor nadwozia pojazdu.
    int status; ///< Status pojazdu.
    struct Samochod *next; ///< Wskaźnik na następny element listy.
} Samochod;

/**
 * @brief Struktura reprezentująca klienta.
 */
typedef struct Klient {
    int numer_karty; ///< Unikalny numer karty klienta.
    char imie[20]; ///< Imię klienta.
    char nazwisko[30]; ///< Nazwisko klienta.
    char adres[50]; ///< Adres zamieszkania klienta.
    char numer_telefonu[10]; ///< Numer telefonu kontaktowego klienta.
    struct Klient *next; ///< Wskaźnik na następny element listy.
} Klient;

/**
 * @brief Struktura reprezentująca wypożyczenie.
 */
typedef struct Wypozyczenie {
    char numer_wypozyczenia[20]; ///< Unikalny numer wypożyczenia.
    int numer_karty_klienta; ///< Numer karty istniejącego klienta.
    char nr_rejestracyjny[20]; ///< Numer rejestracyjny istniejącego pojazdu.
    char data_od[11]; ///< Data rozpoczęcia wypożyczenia.
    char data_do[11]; ///< Planowana data zwrotu pojazdu.
    struct Wypozyczenie *next; ///< Wskaźnik na następny element listy.
} Wypozyczenie;

#endif // CARRENTAL_STRUCTS_H