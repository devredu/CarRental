/**
 * @file clients.h
 * @brief Funkcje zarządzające listą dla klientów.
 * @details Plik zawiera deklaracje funkcji odpowiedzialnych za operacje na liście jednokierunkowej klientów,
 * takiech jak dodawanie, usuwanie, edytowanie i wyświetlanie listy klientów.
 */

#ifndef CARRENTAL_CLIENTS_H
#define CARRENTAL_CLIENTS_H

#include "structs.h"

/**
 * @brief Pozwala na dodawanie nowego klienta do listy.
 * @details Funkcja wyświetla podmenu i pobiera od użytkownika dane. Przeprowadza pełną walidację: sprawdza czy
 * numer karty klienta mieści się w zakresie (0-9999), czy wpisany numer karty klienta nie jest już zajęty oraz weryfikuje,
 * czy numer telefonu jest w poprawnym formacie. Tworzy nowy element listy, w którym zapisuje wpisywane dane tekstowe,
 * przekonwertowane do postaci dużych liter przy pomocy funkcji pomocniczej.
 * @param lista_klientow Wskaźnik na wskaźnik na początek listy klientów.
 * @return void
 */
void dodaj_klienta(Klient **lista_klientow);
/**
 * @brief Pozwala na usuwanie konkretnego klienta po numerze karty klienta.
 * @details Funkcja wyświetla podmenu i pobiera od użytkownika numer karty klienta, po czym przeszukuje listę i sprawdza
 * czy taki klient istnieje, jeśli nie, zwraca komunikat i kończy działanie. Następnie przeszukuje listę wypożyczeń w celu
 * określenia, czy dany klient nie ma aktualnie wypożyczonego samochodu. Jeśli klient posiada aktywne wypożyczenie, funkcja
 * zwróci o tym komunikat i zakończy działanie bez usuwania. W przypadku gdy dany klient istnieje,
 * nie ma aktualnie wypożyczonego samochodu, zwalnia zajmowaną przez niego pamięć (usuwa klienta).
 * @param lista_wypozyczen Wskaźnik na początek listy wypożyczeń.
 * @param lista_klientow Wskaźnik na wskaźnik na początek listy klientów.
 * @return void
 */
void usun_klienta(Wypozyczenie *lista_wypozyczen, Klient **lista_klientow);
/**
 * @brief Pozwala na edytowanie konkretnego klienta po numerze karty klienta.
 * @details Funkcja wyświetla podmenu, w którym umożliwia edycję danego klienta. Początkowo pobiera od użytkownika numer karty klienta,
 * następnie przeszukuje listę w celu odnalezienia szukanego klienta, jeśli go nie znajdzie, zwraca komunikat i kończy działanie.
 * Gdy jednak szukany klient istnieje, kolejno wyświetla aktualne informacje o danym kliencie z możliwością ich
 * nadpisania (zmiany) z wyłączeniem numeru karty klienta, który jest indywidualny i nie podlega zmianie.
 * @param lista_klientow Wskaźnik na wskaźnik na początek listy klientów.
 * @return void
 */
void edytuj_klienta(Klient **lista_klientow);
/**
 * @brief Wyświetla listę wszystkich klientów.
 * @details Funkcja przechodzi przez listę i wyświetla podmenu ze wszystkimi zapisanymi klientami oraz kluczowe o nich informacje.
 * @param lista_klientow Wskaźnik na początek listy klientów.
 * @return void
 */
void wyswietl_klientow(Klient *lista_klientow);

#endif //CARRENTAL_CLIENTS_H