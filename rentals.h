/**
 * @file rentals.h
 * @brief Funkcje zarządzające listą wypożyczeń.
 * @details Plik zawiera deklaracje funkcji obsługujące całą logikę wypożyczeń tj. dodawanie, usuwanie, edytowanie
 * i wyświetlanie elementów z listy wypożyczeń.
 */
#ifndef CARRENTAL_RENTALS_H
#define CARRENTAL_RENTALS_H

#include "structs.h"

/**
 * @brief Pobiera dane, tworzy nowe wypożyczenie i dodaje je na koniec listy.
 * @details Funkcja wyświetla podmenu i sprawdza, czy klient o podanym przez użytkownika numerze karty istnieje,
 * sprawdza też czy wybrany samochód jest dostępny do wypożyczenia oraz sprawdza przy pomocy funkcji pomocniczej
 * poprawność wpisanych dat. Jeśli oba warunki są spełnione, funkcja alokuje pamięć na nowy element, uzupełnia
 * dane (pobrane od użytkownika) i zmienia status auta na wypożyczony.
 * @param lista_samochodow Wskaźnik na początek listy samochodów.
 * @param lista_klientow Wskaźnik na początek listy klientów.
 * @param lista_wypozyczen Wskaźnik na wskaźnik na początek listy wypożyczeń.
 * @return void
 */
void dodaj_wypozyczenie(Samochod *lista_samochodow, Klient *lista_klientow, Wypozyczenie **lista_wypozyczen);

/**
 * @brief Usuwa wskazane wypożyczenie z listy na podstawie jej numeru.
 * @details Funkcja wyświetla podmenu i pobiera od użytkownika indywidualny numer wypożyczenia i na jego podstawie
 * wyszukuje element w liście, który następnie usuwa zwalniając pamięć oraz zmienia status samochodu,
 * który był wypożyczony na dostępny.
 * @param lista_samochodow Wskaźnik na wskaźnik na początek listy samochodów.
 * @param lista_wypozyczen Wskaźnik na wskaźnik na początek listy wypożyczeń.
 * @return void
 */
void usun_wypozyczenie(Samochod **lista_samochodow, Wypozyczenie **lista_wypozyczen);

/**
 * @brief Pozwala na edycję danych dla wskazanego na podstawie numeru wypożyczenia.
 * @details Funkcja wyświetla podmenu i pobiera od użytkownika indywidualny numer wypożyczenia i na jego podstawie
 * wyszukuje element w liście i kolejno wyświetla jego dane, umożliwiając w ten sposób ich edycję. Przy zmianie
 * wypożyczanego pojazdu sprawdza, czy taki pojazd istnieje i następnie czy jest on dostępny, jeśli jest, zmienia
 * status poprzedniego samochodu na dostępny, a nowego na wypożyczony. Przeprowadza także ponowną walidację wpisanych dat.
 * @param lista_samochodow Wskaźnik na wskaźnik na początek listy samochodów.
 * @param lista_wypozyczen Wskaźnik na wskaźnik na początek listy wypożyczeń.
 * @return void
 */
void edytuj_wypozyczenie(Samochod **lista_samochodow, Wypozyczenie **lista_wypozyczen);

/**
 * @brief Wyświetla listę wypożyczeń.
 * @details Funkcja przeszukuje listę po czym wyświetla podmenu ze wszystkimi zapisanymi wypożyczeniami
 * oraz kluczowe o nich informacje. Dodatkowo na podstawie porównania obecnej daty (systemowej) z datami wypożyczenia oblicza i wyświetla status:
 * - Zaplanowane (data aktualna jest przed datą początku wypożyczenia)
 * - Do zwrotu dzisiaj (data aktualna jest taka sama jak data zwrotu)
 * - Do zwrotu (data aktualna jest po dacie zwrotu)
 * - Aktualne (data aktualna jest późniejsza niż data początku wypożyczenia i wcześniejsza niż data zwrotu)<br><br>
 * @param lista_wypozyczen Wskaźnik na początek listy wypożyczeń.
 * @return void
 */
void wyswietl_wypozyczenia(Wypozyczenie *lista_wypozyczen);

#endif //CARRENTAL_RENTALS_H
