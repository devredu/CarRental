/**
 * @file cars.h
 * @brief Funkcje zarządzające listą samochodów.
 * @details Plik zawiera deklaracje funkcji odpowiedzialnych za operacje na liście jednokierunkowej samochodów,
 * takich jak dodawanie, usuwanie, edytowanie, wyświetlanie listy oraz wyszukiwanie samochodów.
 */

#ifndef CARRENTAL_CARS_H
#define CARRENTAL_CARS_H

#include "structs.h"

/**
 * @brief Pozwala na dodawanie nowego samochodu do listy.
 * @details Funkcja wyświetla podmenu i pobiera od użytkownika dane pojazdu. Przeprowadza pełną walidację:
 * sprawdza czy pojazd o danym numerze rejestracyjnym już istnieje oraz weryfikuje czy rok produkcji
 * mieści się w poprawnym zakresie (1900-2026). Tworzy nowy element listy, w którym zapisuje pobrane dane, status domyślnie
 * ustawiany jest jako dostępny, a ciągi tekstowe są formatowane do postaci wielkich liter przy pomocy funkcji pomocniczej.
 * @param lista_samochodow Podwójny wskaźnik na początek listy samochodów.
 * @return void
 */
void dodaj_samochod(Samochod **lista_samochodow);

/**
 * @brief Pozwala na usuwanie konkretnego samochodu po numerze rejestracyjnym.
 * @details Funkcja wyświetla podmenu i pobiera od użytkownika numer rejestracyjny pojazdu, po czym przeszukuje listę wypożyczeń.
 * Jeśli samochód nie istnieje lub jest aktualnie wypożyczony, funkcja zwraca o tym komunikat i kończy działanie.
 * W przypadku gdy samochód istnieje i jest dostępny, funkcja przeszukuje listę samochodów i zwalnia zajmowaną przez dany samochód
 * pamięć (usuwa samochód).
 * @param lista_wypozyczen Wskaźnik na początek listy wypożyczeń.
 * @param lista_samochodow Podwójny wskaźnik na początek listy samochodów.
 * @return void
 */
void usun_samochod(Wypozyczenie *lista_wypozyczen, Samochod **lista_samochodow);

/**
 * @brief Pozwala na edytowanie danych konkretnego samochodu po numerze rejestracyjnym.
 * @details Funkcja wyświetla podmenu, w którym umożliwia edycję danego samochodu. Początkowo pobiera od użytkownika
 * indywidualny numer rejestracyjny pojazdu i na jego podstawie wyszukuje samochód w liście. Jeśli wskazany przez numer
 * rejestracyjny samochód nie istnieje, funkcja zwraca o tym komunikat i kończy działanie. Po znalezieniu elementu,
 * umożliwia nadpisanie (edycję) marki, modelu, koloru oraz roku produkcji, z wyłączeniem numeru rejestracyjnego,
 * który jest indywidualny i nie podlega zmianie.
 * @param lista_samochodow Podwójny wskaźnik na początek listy samochodów.
 * @return void
 */
void edytuj_samochod(Samochod **lista_samochodow);

/**
 * @brief Wyświetla listę wszystkich samochodów z opcją sortowania.
 * @details Funkcja wyświetla podmenu wyboru sposobu wyświetlania (rejestracja, marka, kolor, rok, status lub brak sortowania).
 * Na podstawie wybranej opcji dynamicznie alokuje tablicę wskaźników na struktury, kopiuje do niej elementy listy,
 * sortuje je algorytmem Bubble Sort, po czym wyświetla kolejne podmenu ze wszystkimi samochodami oraz zwalnia tablicę tymczasową.
 * @param lista_samochodow Wskaźnik na początek listy samochodów.
 * @return void
 */
void wyswietl_samochody(Samochod *lista_samochodow);

/**
 * @brief Pozwala na wyszukanie konkretnego samochodu po numerze rejestracyjnym.
 * @details Funkcja wyświetla podmenu i pobiera od użytkownika szukany numer rejestracyjny, przeszukuje listę samochodów
 * i po znalezieniu wyświetla szczegółowe informacje o danym samochodzie. Jeśli nie uda się odnaleźć samochodu o podanym numerze
 * rejestracyjnym, funkcja wyświetla komunikat i kończy działanie.
 * @param lista_samochodow Wskaźnik na początek listy samochodów.
 * @return void
 */
void wyszukaj_samochod(Samochod *lista_samochodow);

#endif //CARRENTAL_CARS_H