/**
 * @file files.h
 * @brief Funkcje zarządzające zapisem i odczytem danych z plików tekstowych.
 * @details Plik zawiera funkcje obsługujące logikę zapisywania danych (w formacie CSV - dane oddzielone średnikiem) oraz odczytywania
 * danych z plików tekstowych i ładowania ich do list jednokierunkowych.
 */

#ifndef CARRENTAL_FILES_H
#define CARRENTAL_FILES_H

#include "structs.h"

/**
 * @brief Zapisuje aktualną listę samochodów do pliku tekstowego.
 * @details
 * @param lista_samochodow Wskaźnik na początek listy samochodów.
 */
void zapisz_samochody(Samochod *lista_samochodow);

/**
 * @brief Wczytuje dane z pliku tekstowego do listy z samochodami.
 * @details
 * @param lista_samochodow Wskaźnik na początek listy samochodów.
 */
void wczytaj_samochody(Samochod **lista_samochodow);

/**
 * @brief Zapisuje aktualną listę klientów do pliku tekstowego.
 * @details
 * @param lista_klientow Wskaźnik na początek listy klientów.
 */
void zapisz_klientow(Klient *lista_klientow);

/**
 * @brief Wczytuje dane z pliku tekstowego do listy z klientami.
 * @details
 * @param lista_klientow Wskaźnik na początek listy klientów.
 */
void wczytaj_klientow(Klient **lista_klientow);

/**
 * @brief Zapisuje aktualną listę wypożyczeń do pliku tekstowego.
 * @details
 * @param lista_wypozyczen Wskaźnik na początek listy wypożyczeń.
 */
void zapisz_wypozyczenia(Wypozyczenie *lista_wypozyczen);

/**
 * @brief Wczytuje dane z pliku tekstowego do listy z wypożyczeniami.
 * @details
 * @param lista_wypozyczen Wskaźnik na początek listy wypożyczeń.
 */
void wczytaj_wypozyczenia(Wypozyczenie **lista_wypozyczen);

#endif //CARRENTAL_FILES_H