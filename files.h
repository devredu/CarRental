/**
 * @file files.h
 * @brief Funkcje zarządzające zapisem i odczytem danych z plików tekstowych.
 * @details Plik zawiera deklaracje funkcji obsługujących logikę zapisywania (w formacie CSV - dane oddzielone średnikiem) oraz odczytywania
 * danych z plików tekstowych i ładowania ich do list jednokierunkowych.
 */

#ifndef CARRENTAL_FILES_H
#define CARRENTAL_FILES_H

#include "structs.h"

/**
 * @brief Zapisuje aktualną listę samochodów do pliku tekstowego.
 * @details Otwiera (tworzy jeśli nie ma) plik "samochody.txt" w trybie nadpisywania. Przechodzi przez całą listę jednokierunkową
 * i zapisuje każdy z samochodów w nowej linii, oddzielając pola średnikami.
 * @param lista_samochodow Wskaźnik na początek listy samochodów.
 */
void zapisz_samochody(Samochod *lista_samochodow);

/**
 * @brief Wczytuje dane z pliku tekstowego do listy samochodów.
 * @details Otwiera plik "samochody.txt" w trybie odczytu. Parsuje linie za pomocą fscanf i dynamicznie alokuje pamięć dla każdego samochodu z pliku,
 * podpinając je kolejno do końca listy jednokierunkowej.
 * W przypadku gdy funkcja nie znajdzie pliku tekstowego, kończy swoje działanie.
 * @param lista_samochodow Wskaźnik na początek listy samochodów.
 */
void wczytaj_samochody(Samochod **lista_samochodow);

/**
 * @brief Zapisuje aktualną listę klientów do pliku tekstowego.
 * @details Otwiera (tworzy jeśli nie ma) plik "klienci.txt" w trybie nadpisywania. Przechodzi przez całą listę jednokierunkową
 * i zapisuje każdego klienta w nowej linii, oddzielając pola średnikami.
 * @param lista_klientow Wskaźnik na początek listy klientów.
 */
void zapisz_klientow(Klient *lista_klientow);

/**
 * @brief Wczytuje dane z pliku tekstowego do listy z klientami.
 * @details Otwiera plik "klienci.txt" w trybie odczytu. Parsuje linie za pomocą fscanf i dynamicznie alokuje pamięć dla każdego klienta z pliku,
 * podpinając ich kolejno do końca listy jednokierunkowej.
 * W przypadku gdy funkcja nie znajdzie pliku tekstowego, kończy swoje działanie.
 * @param lista_klientow Wskaźnik na początek listy klientów.
 */
void wczytaj_klientow(Klient **lista_klientow);

/**
 * @brief Zapisuje aktualną listę wypożyczeń do pliku tekstowego.
 * @details Otwiera (tworzy jeśli nie ma) plik "wypozyczenia.txt" w trybie nadpisywania. Przechodzi przez całą listę jednokierunkową
 * i zapisuje każde wypożyczenie w nowej linii, oddzielając pola średnikami.
 * @param lista_wypozyczen Wskaźnik na początek listy wypożyczeń.
 */
void zapisz_wypozyczenia(Wypozyczenie *lista_wypozyczen);

/**
 * @brief Wczytuje dane z pliku tekstowego do listy z wypożyczeniami.
 * @details Otwiera plik "wypozyczenia.txt" w trybie odczytu. Parsuje linie za pomocą fscanf i dynamicznie alokuje pamięć dla każdego wypożyczenia z pliku,
 * podpinając je kolejno do końca listy jednokierunkowej.
 * W przypadku gdy funkcja nie znajdzie pliku tekstowego, kończy swoje działanie.
 * @param lista_wypozyczen Wskaźnik na początek listy wypożyczeń.
 */
void wczytaj_wypozyczenia(Wypozyczenie **lista_wypozyczen);

#endif //CARRENTAL_FILES_H