/**
 * @file main.c
 * @brief Główny plik programu.
 * @details Inicjalizuje wskaźniki struktur bazy danych, ładuje zapisane dane
 * z plików tekstowych oraz uruchamia interfejs użytkownika (menu główne).
 */

#include <stdio.h>
#include "files.h"
#include "gui.h"
#include "structs.h"

/**
 * @brief Główna funkcja sterująca aplikacją.
 * @details Ustawia stan początkowy list na NULL, odpowiada za wywołanie funkcji
 * odczytu danych z plików, a na końcu wywołuje funkcję odpowiadającą za wyświetlenie głównego menu użytkownika.
 * @return int Status zakończenia programu.
 */
int main(void){
    Samochod *lista_samochodow = NULL;
    Klient *lista_klientow = NULL;
    Wypozyczenie *lista_wypozyczen = NULL;
    wczytaj_samochody(&lista_samochodow);
    wczytaj_klientow(&lista_klientow);
    wczytaj_wypozyczenia(&lista_wypozyczen);
    menu_glowne(&lista_samochodow, &lista_klientow, &lista_wypozyczen);
    return 0;
}
