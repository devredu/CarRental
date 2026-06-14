/**
 * @file rentals.h
 * @brief Funkcje zarządzające listą wypożyczeń.
 * @details Plik zawiera deklaracje funkcji odpowiedzialnych za operacje na liście jednokierunkowej wypożyczeń,
 * takiech jak dodawanie, usuwanie, edytowanie i wyświetlanie listy wypożyczeń.
 */
#ifndef CARRENTAL_RENTALS_H
#define CARRENTAL_RENTALS_H

#include "structs.h"

/**
 * @brief Pozwala na dodawanie nowego wypożyczenia do listy.
 * @details Funkcja wyświetla podmenu i pobiera dane od użytkownika. Przeprowadza pełną walidację:
 * sprawdza, czy klient o podanym numerze karty istnieje, czy wybrany samochód jest aktualnie dostępny
 * oraz weryfikuje poprawność i format wpisanych dat. Jeśli wszystkie warunki są spełnione, tworzy nowy element listy,
 * w którym zapisuje wprowadzone dane oraz zmienia status pojazdu na wypożyczony.
 * @param lista_samochodow Wskaźnik na początek listy samochodów.
 * @param lista_klientow Wskaźnik na początek listy klientów.
 * @param lista_wypozyczen Wskaźnik na wskaźnik na początek listy wypożyczeń.
 * @return void
 */
void dodaj_wypozyczenie(Samochod *lista_samochodow, Klient *lista_klientow, Wypozyczenie **lista_wypozyczen);
/**
 * @brief Pozwala na usuwanie konkretnego wypożyczenia po jego numerze.
 * @details Funkcja wyświetla podmenu i pobiera od użytkownika unikalny numer wypożyczenia po czym przeszukuje listę
 * wypożyczeń. Jeśli szukane wypożyczenie nie istnieje, funkcja zwraca komunikat i kończy działanie.
 * Następnie przeszukuje listę samochodów i po znalezieniu szukanego samochodu, funkcja zmienia status z wypożyczonego
 * na dostępny, a następnie zwalnia zajmowaną przez wskazane wypożyczenie pamięć (usuwa wypożyczenie).
 * @param lista_samochodow Wskaźnik na wskaźnik na początek listy samochodów (wymagany do zmiany statusu auta).
 * @param lista_wypozyczen Wskaźnik na wskaźnik na początek listy wypożyczeń.
 * @return void
 */
void usun_wypozyczenie(Samochod **lista_samochodow, Wypozyczenie **lista_wypozyczen);
/**
 * @brief Pozwala na edytowanie konkretnego wypożyczenia po jego numerze.
 * @details Funkcja wyświetla podmenu, w którym umożliwia edycję danego wypożyczenia. Początkowo pobiera od użytkownika
 * indywidualny numer wypożyczenia, po czym przeszukuje listę i sprawdza czy takie wypożyczenie istnieje. Jeśli nie,
 * zwraca komunikat i kończy działanie. Po znalezieniu, umożliwia nadpisanie (edycję) danych. W przypadku zmiany
 * wypożyczanego pojazdu, funkcja sprawdza istnienie oraz dostępność nowego samochodu - jeśli jest wolny, status
 * poprzedniego auta zmienia się na dostępny, a nowego na wypożyczony.
 * @param lista_samochodow Podwójny wskaźnik na początek listy samochodów.
 * @param lista_wypozyczen Podwójny wskaźnik na początek listy wypożyczeń.
 * @return void
 */
void edytuj_wypozyczenie(Samochod **lista_samochodow, Wypozyczenie **lista_wypozyczen);
/**
 * @brief Wyświetla listę wszystkich wypożyczeń.
 * @details Funkcja przechodzi przez listę wypożyczeń i wyświetla podmenu ze wszystkimi zapisanymi wypożyczeniami.
 * Dodatkowo, poprzez porównanie daty systemowej z datami wypożyczenia, oblicza i wyświetla status:
 * - Zaplanowane (aktualna data jest przed rozpoczęciem wypożyczenia)
 * - Aktualne (wypożyczenie w trakcie trwania)
 * - Do zwrotu dzisiaj (aktualna data pokrywa się z dniem zwrotu)
 * - Po terminie (aktualna data przekroczyła planowany dzień zwrotu)
 * @param lista_wypozyczen Podwójny wskaźnik listy wypożyczeń.
 * @return void
 */
void wyswietl_wypozyczenia(Wypozyczenie *lista_wypozyczen);

#endif //CARRENTAL_RENTALS_H
