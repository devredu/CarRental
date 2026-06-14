/**
 * @file utils.h
 * @brief Funkcje pomocnicze oraz makra systemowe używane w projekcie.
 * @details Plik zawiera definicje makr pozwalających na kompilowanie projektu na systemach Windows oraz MacOS,
 * definicje kodów ANSI do terminala oraz deklaracje funkcji walidacyjnych.
*/

#ifndef CARRENTAL_UTILS_H
#define CARRENTAL_UTILS_H
#include <stdbool.h>

#ifdef _WIN32
    #include <windows.h>
    /** @brief Komenda systemowa do czyszczenia terminalu dla systemu Windows. */
    #define CLEAR "cls"
#else
    #include <unistd.h>
    /** @brief Komenda systemowa do czyszczenia terminalu dla systemu MacOS. */
    #define CLEAR "clear"
    /** @brief Makro 'usypiające' działania programu na określoną liczbę milisekund. */
    #define Sleep(ms) usleep((ms) * 500)
#endif

/** @brief Resetuje kolor do domyślnego. */
#define RESET       "\033[0m"
/** @brief Pogrubienie tekstu. */
#define BOLD        "\033[1m"
/** @brief Szary kolor tekstu. */
#define GRAY        "\033[90m"
/** @brief Czerwony kolor tekstu. */
#define RED         "\033[31m"
/** @brief Zielony kolor tekstu. */
#define GREEN       "\033[32m"
/** @brief Żółty kolor tekstu. */
#define YELLOW      "\033[33m"
/** @brief Cyjanowy kolor tekstu. */
#define CYAN        "\033[36m"
/** @brief Pogrubiony, czerwony kolor tekstu. */
#define BOLD_RED    "\033[1;31m"

/**
 * @brief Wyświetla komunikat i zatrzymuje działanie programu do momentu naciśnięcia Enter.
 * @details Używane po wyświetleniu komunikatów o błędach, sukcesach w trakcie działania programu,
 * aby użytkownik zdążył je przeczytać.
 * @return void
 */
void zaczekaj();

/**
 * @brief Czyści bufor dla strumienia wejściowego.
 * @details Usuwa z bufora pozostałości po poprzednich operacjach scanf (np. znaki nowej linii),
 * co zapobiega błędom przy pobieraniu danych od użytkownika.
 * @return void
 */
void wyczysc_bufor();

/**
 * @brief Zamienia wszystkie małe litery w podanym ciągu na duże.
 * @details Modyfikuje oryginalny ciąg znaków. Przydatne w celu standaryzacji
 * danych wprowadzanych przez użytkownika do postaci dużych liter.
 * @param tekst Wskaźnik na ciąg znaków, który ma być zmodyfikowany.
 * @return void
 */
void zamien_na_wielkie(char *tekst);

/**
 * @brief Sprawdza czy wprowadzona przez użytkownika data jest w poprawnym formacie RRRR-MM-DD.
 * @details Dokonuje walidacji daty wpisanej przez użytkownika.
 * W pierwszej kolejności sprawdzana jest długość ciągu oraz obecność myślników. Następnie
 * funkcja sprawdza, czy pozostałe znaki są cyframi, a na końcu sprawdza
 * zakresy kalendarzowe (rok 2000-2100, miesiące 1-12, dni 1-31).
 * @param data Wskaźnik na ciąg znaków, zawierający datę do walidacji.
 * @return true Jeśli data jest prawidłowa.
 * @return false Jeśli data jest nieprawidłowa.
 */
bool waliduj_date(const char *data);

#endif //CARRENTAL_UTILS_H
