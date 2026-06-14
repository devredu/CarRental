/**
 * @file gui.h
 * @brief Funkcje odpowiedzialne za tekstowy interfejs użytkownika.
 * @details Plik zawiera deklaracje funkcji odpowiedzialnych za wyświetlanie menu w terminalu, komunikację z użytkownikiem,
 * pobieranie danych od użytkownika i sterowanie działaniem całego programu.
 */

#ifndef CARRENTAL_GUI_H
#define CARRENTAL_GUI_H

#include "structs.h"

/**
 * @brief Funkcja wyświetlająca i obsługująca główne menu programu.
 * @details Funkcja wyświetla główne menu programu i odpowiada za przełączanie się pomiędzy interfejsami: samochodów, klientów i wypożyczeń.
 * Jest ona zabezpieczenia przed wyborem opcji spoza zakresu. Wybór opcji "0" automatycznie zapisuje wszystkie wprowadzone przez
 * użytkownika dane do poszczególnych plików tekstowych i kończy działanie programu.
 *
 *
 * Struktura menu:
 * - Zarządzanie samochodami
 * - Zarządzanie klientami
 * - Zarządzanie wypożyczeniami
 * - Zapisz i wyjdź
 *
 * @param lista_samochodow Wskaźnik na wskaźnik na początek listy samochodów.
 * @param lista_klientow Wskaźnik na wskaźnik na początek listy klientów.
 * @param lista_wypozyczen Wskaźnik na wskaźnik na początek listy wypożyczeń.
 * @return void
 */
void menu_glowne(Samochod **lista_samochodow, Klient **lista_klientow, Wypozyczenie **lista_wypozyczen);

/**
 * @brief Funkcja wyświetlająca i obsługująca menu zarządzania samochodami.
 * @details Funkcja wyświetla menu do zarządzania samochodami. Posiada opcje wywołujące inne funkcje służące do: dodawania,
 * usuwania, edytowania, wyświetlania listy oraz wyszukiwania samochodów. Posiada też opcję powrotu do menu głównego.
 * Funkcja jest zabezpieczona przed wyborem opcji spoza zakresu.
 *
 *
 * Struktura menu:
 * - Dodaj samochód
 * - Usuń samochód
 * - Edytuj samochód
 * - Wyświetl listę samochodów
 * - Wyszukaj samochód
 * - Wróć do menu głównego
 *
 * @param lista_wypozyczen Wskaźnik na wskaźnik na początek listy wypożyczeń.
 * @param lista_samochodow Wskaźnik na wskaźnik na początek listy samochodów.
 * @return void
 */
void menu_samochod(Wypozyczenie **lista_wypozyczen, Samochod **lista_samochodow);

/**
 * @brief Funkcja wyświetlająca i obsługująca menu zarządzania klientami.
 * @details Funkcja wyświetla menu do zarządzania klientami. Posiada opcje wywołujące inne funkcje służące do: dodawania,
 * usuwania oraz wyświetlania listy klientów. Posiada też opcję powrotu do menu głównego. Funkcja jest zabezpieczona
 * przed wyborem opcji spoza zakresu.
 *
 *
 * Struktura menu:
 * - Dodaj klienta
 * - Usuń klienta
 * - Edytuj klienta
 * - Wyświetl listę klientów
 * - Wróć do menu głównego
 *
 * @param lista_wypozyczen Wskaźnik na wskaźnik na początek listy wypożyczeń.
 * @param lista_klientow Wskaźnik na wskaźnik na początek listy klientów.
 * @return void
 */
void menu_klient(Wypozyczenie **lista_wypozyczen, Klient **lista_klientow);

/**
 * @brief Funkcja wyświetlająca i obsługująca menu zarządzania wypożyczeniami.
 * @details Funkcja wyświetla menu do zarządzania wypożyczeniami. Posiada opcje wywołujące inne funkcje służące do:
 * dodawania, usuwania, edytowania oraz wyświetlania listy wypożyczeń. Posiada też opcję powrotu do menu głównego.
 * Funkcja jest zabezpieczona przed wyborem opcji spoza zakresu.
 *
 *
 * Struktura menu:
 * - Dodaj wypożyczenie
 * - Usuń wypożyczenie
 * - Edytuj wypożyczenie
 * - Wyświetl listę wypożyczeń
 * - Wróć do menu głównego
 *
 * @param lista_samochodow Wskaźnik na wskaźnik na początek listy samochodów.
 * @param lista_klientow Wskaźnik na wskaźnik na początek listy klientów.
 * @param lista_wypozyczen Wskaźnik na wskaźnik na początek listy wypożyczeń.
 * @return void
 */
void menu_wypozyczenie(Samochod **lista_samochodow, Klient **lista_klientow, Wypozyczenie **lista_wypozyczen);

#endif //CARRENTAL_GUI_H