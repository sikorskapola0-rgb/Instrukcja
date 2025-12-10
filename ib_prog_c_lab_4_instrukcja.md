![loga programu FERS](fers_header.jpg "Title") 
# Wprowadzenie do programowania 
#### Instrukcja do ćwiczenia laboratoryjnego nr 4
#### Temat: Struktury i wskaźniki w języku C
#### Politechnika Gdańska, Wydział Elektroniki, Telekomunikacji i Informatyki, Katedra Inżynierii Biomedycznej
#### Opracował: prof. dr hab. inż. Jacek Rumiński


### Spis treści
- [Wprowadzenie do programowania](#wprowadzenie-do-programowania)
      - [Instrukcja do ćwiczenia laboratoryjnego nr 4](#instrukcja-do-ćwiczenia-laboratoryjnego-nr-4)
      - [Temat: Struktury i wskaźniki w języku C](#temat-struktury-i-wskaźniki-w-języku-c)
      - [Politechnika Gdańska, Wydział Elektroniki, Telekomunikacji i Informatyki, Katedra Inżynierii Biomedycznej](#politechnika-gdańska-wydział-elektroniki-telekomunikacji-i-informatyki-katedra-inżynierii-biomedycznej)
      - [Opracował: prof. dr hab. inż. Jacek Rumiński](#opracował-prof-dr-hab-inż-jacek-rumiński)
    - [Spis treści](#spis-treści)
  - [Wprowadzenie](#wprowadzenie)
      - [Przebieg laboratorium](#przebieg-laboratorium)
  - [Praca z przykładowym projektem wraz z wyjaśnieniami prowadzącego](#praca-z-przykładowym-projektem-wraz-z-wyjaśnieniami-prowadzącego)
  - [Realizacja zadania wskazanego przez prowadzącego](#realizacja-zadania-wskazanego-przez-prowadzącego)
  - [Literatura pomocnicza i załączniki](#literatura-pomocnicza-i-załączniki)

## Wprowadzenie
Celem tego laboratorium jest utrwalenie wiedzy z wykładów oraz praktyczne zapoznanie się z ze złożonymi struktrami danych. 

W języku C wprowadzono struktury danych, które umożliwiają definicję specjalnego typu złożonego, nazwanego właśnie strukturą: struct.

Strukturę definiujemy w sposób następujący:

```C
struct student_t {
  /* collection of variables, e.g.: */
  unsigned int student_index;
  unsigned char student_mark;
};
```

Słowo kluczowe "struct" razem z nazwą struktury "student_t" stanowią nowy typ danych:

```C
struct student_t  student;
/* new type   */ /* variable */
``` 

Typ jest złożony, ponieważ potencjalnie składa się z wielu zmiennych, które mogą mieć różne typy. W tym przypadku struktura `student_t` zawiera dwie zmienne: `student_index` typu `unsigned int` i `student_mark` typu `unsigned char`. Jest to jednocześnie przykład typu danych definiowanego przez użytkownika, ponieważ możemy zdefiniować własne typy danych, które będą odpowiadały naszym potrzebom. 
Definicja złożonego typu danych wymaga, aby zawsze odnosić się do niego przez słowo kluczowe `struct` wraz z nazwą struktury: `struct student_t`. Razem te dwa elementy tworzą nowy typ danych.
Zamiast tak długiej nazwy można uprościć składnię, definiując alias dla tego typu danych za pomocą `typedef`. Przykład: `typedef struct student_t student_type;`. Wówczas możemy używać aliasu `student_type` zamiast pełnej nazwy `struct student_t`.

### Modularność i podlinkowanie plików w języku C

Aby zrozumieć, jak działa modularność i podlinkowanie plików w języku C, zaczniemy od bardzo prostego przykładu programu składającego się z 3 plików:
- example.h – plik nagłówkowy z deklaracjami,
- example.c – plik źródłowy z definicjami funkcji,
- example_main.c – główny program korzystający z funkcji.

#### Plik nagłówkowy example.h

Plik nagłówkowy zawiera deklaracje funkcji, czyli informacje dla kompilatora, że takie funkcje istnieją gdzieś w projekcie:

```C
int add(int a, int b);
int multiply(int a, int b);
```

#### Plik implementacji example.c

Tutaj znajdują się definicje funkcji, czyli ich właściwa implementacja:

```C
#include "example.h" // Podlinkowanie pliku nagłowkowego z deklaracją funkcji

int add(int a, int b)
{
    return a + b;
}

int multiply(int a, int b)
{
    return a * b;
}
```


#### Plik główny example_main.c

Tutaj korzystamy z funkcji zadeklarowanych w nagłówku i zaimplementowanych w innym pliku:

```C
#include <stdio.h> 
#include "example.h" // Podlinkowanie pliku nagłowkowego z deklaracją funkcji

int main()
{
    int x = 5, y = 3;
    printf("Add: %d\n", add(x, y));
    printf("Multiply: %d\n", multiply(x, y));
    return 0;
}
```

#### Kompilacja programu:

Aby połączyć wszystkie pliki w jeden program, kompilujemy je razem:

```sh
gcc example_main.c example.c -o example 
```

#### Uruchomienie:

```sh
./program
```

**WYMAGANIA**
Operacje na strukturach wraz z wykorzystaniem wskaźników zostały omówione na wykładach. 
Przygotowując się do ćwiczenia laboratoryjnego wymagane jest powtórzenie tych zagadnień. 
Zachęcamy do wykonania wszystkich przykładów z wykładów, a poprzez wprowadzanie zmian w kodzie do samodzielnego sprawdzenia działania struktur i wskaźników.


#### Przebieg laboratorium

1. Wejściówka
2. Praca z przykładowym projektem wraz z wyjaśnieniami prowadzącego
3. Realizacja zadania wskazanego przez prowadzącego

## Praca z przykładowym projektem wraz z wyjaśnieniami prowadzącego

W ramach ćwiczenia należy przygotować projekt w języku C, we wskazanym przez prowadzącego środowisku, poprzez sklonowanie projektu z repozytorium GitHub lub GitLab. 

Przykładowy projekt zawiera realizuje następujące funkcjonalności (specyfikacja wymagań):
- Dodawanie rekordu studenta zgodnego z definicją struktury `student_t`.
- Wypisywanie wszystkich rekordów studentów.
- Usuwanie rekordu studenta.
- Zmianę rekordu studenta.


Funkcjonalności te odwzorowane są w kodzie źródłowym w następujący sposób:
- definicja struktury `student_t` znajduje się w pliku `student.h`.
- funkcje do obsługi struktury `student_t` znajdują się: 1) deklaracje w pliku `student.h`, a definicje w pliku `student.c`:
    - `add_student()` - dodaje nowego studenta,
    - `list_students()` - wypisuje wszystkich studentów,
    - `delete_student()` - usuwa studenta o podanym indeksie,
    - `change_student()` - aktualizuje dane studenta o podanym indeksie.
- funkcje do obsługi menu znajdują się w pliku `menu.c`. Umożliwiają one interakcję z użytkownikiem i wywoływanie odpowiednich funkcji do obsługi struktury `student_t`.

Plik nagłówkowy `student.h` zawiera deklaracje funkcji oraz definicję struktury `student_t`, co pozwala na łatwe zarządzanie kodem i jego modularność. W pliku tym znajdziemy:

```C
// Definicja limitu znaków dla nazwiska studenta
#define NAME_CHAR_LIMIT 50

// Definicja struktury studenta
struct student_t
{
    int album;
    char name[NAME_CHAR_LIMIT];
    int grade;
};

// Deklaracje prototypów (sygnatur) funkcji, zgodnie ze specyfikacją wymagań
void list_students(struct student_t *students, int count);
void add_student(struct student_t **students, int *count);
void delete_student(struct student_t *students, int *count);
void change_student(struct student_t *students, int count);
```

Zauważmy, że w deklaracji funkcji add_student() używamy wskaźnika do wskaźnika `struct student_t **students`, co pozwala na dodawanie nowych studentów do tablicy. 
Przekazujemy w ten sposób adres (referencję), na podstawiej której możemy modyfikować tablicę studentów. Więcej na ten temat przedsatwiliśmy w czasie wykładów, omawiając wskaźniki do wskaźników. Zachęcamy do uwaznego studiowania tego materiału. 

Wskaźnik `int *count` pozwala na aktualizację aktualnej liczby studentów w tablicy (zmianę count). Zauważmy, że tylko w funkcjach `add_student()` oraz `delete_student` stosujemy wskaźnik `int *count`. 
Dlaczego? Ponieważ w tych funkcjach modyfikujemy liczbę studentów, a w pozostałych funkcjach tylko ją odczytujemy.

Definicja (implementacja) funkcji znajduje się w pliku `student.c`. Przykładowa implementacja funkcji `add_student()` wygląda następująco:

```C
// Dodaje nowego studenta do tablicy studentów (wskaźnik na wskaźnik można tutaj rozumieć jako przekazanie referencji do tablicy rekordów struktury student_t)
void add_student(struct student_t **students, int *count)
{   
    // Dynamicznie zwiększ pamięć tablicy studentów o jeden element, czyli o jeden rekord rozmiaru struktury student_t
    *students = realloc(*students, (*count + 1) * sizeof(struct student_t));
    // Sprawdź, czy realloc się powiódł
    if (*students == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    // Wskaźnik do nowego studenta, który zostanie dodany
    struct student_t *new_student = &(*students)[*count];
    // Pobierz dane nowego studenta od użytkownika
    printf("Enter student album no.: ");
    // Używamy scanf do pobrania numeru albumu studenta, czytamy int więc bezpośrednio podajemy adres, gdzie wczytana wartość ma być zapisana. 
    scanf("%d", &new_student->album);
    // Pobierz  nazwisko studenta
    printf("Enter student name: ");
    scanf(" %s", new_student->name);
    // Pobierz ocenę studenta
    printf("Enter student grade: ");
    scanf("%d", &new_student->grade);
    // Zwiększ licznik studentów
    (*count)++;
    printf("Student added successfully.\n");
}
```

Zauważmy, że w funkcji `add_student()` nie używamy kontroli poprawnie wpisanych danych przez użytkownika. W praktyce warto dodać takie sprawdzenie, aby uniknąć błędów w działaniu programu (uycie `if` oraz pętli np. `do {} while()`). 

W analogiczny sposób zdefiniowane są pozostałe funkcje, które realizują wymagane funkcjonalności.

W pliku `main.c` znajdują się funkcje do obsługi menu, które umożliwiają interakcję z użytkownikiem.

```C
#include <stdio.h>
#include <stdlib.h>
#include "students.h"

int main()
{
    // Naszą tablicę studentów będziemy przechowywać w pamięci, początkowo jako wskaźnik na NULL, ponieważ nie mamy jeszcze żadnych studentów
    struct student_t *students = NULL;
    // Licznik studentów, początkowo 0, ponieważ nie mamy jeszcze żadnych studentów
    int count = 0;
    // Zmienna do przechowywania wyboru użytkownika w menu
    int choice;

    do
    {
        printf("\n===== Student Management Menu =====\n");
        printf("1. List all students\n");
        printf("2. Add new student\n");
        printf("3. Delete student\n");
        printf("4. Change student\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            list_students(students, count);
            break;
        case 2:
            // Przekazujemy wskaźnik na wskaźnik, aby móc modyfikować tablicę studentów
            add_student(&students, &count);
            break;
        case 3:
            delete_student(students, &count);
            break;
        case 4:
            change_student(students, count);
            break;
        case 5:
            printf("Exiting program...\n");
            break;
        default:
            printf("Wrong choice! Try again.\n");
        }
    } while (choice != 5);

    // Zwolnienie pamięci zajmowanej przez tablicę studentów
    free(students);
    return 0;
}
```

#### Podczas zajęć należy dokończyć implementację funkcji delete_student() oraz change_student().


Jak skompilować i uruchomić program?
1. Otwórz terminal i przejdź do katalogu z projektem.
2. Użyj polecenia `gcc main.c students.c -o lab_4` do skompilowania programu. Upewnij się, że masz zainstalowany kompilator GCC (Linux, Mac OS, inne).
3. Uruchom program poleceniem `./lab_4
<!-- 

## Praca samodzielna związana z rozbudową przykładowego projektu

W ramach ćwiczenia laboratoryjnego należy samodzielnie rozbudować przykładowy projekt o dodatkową funkcjonalność. Proponowana funkcjonalność to dodanie możliwości wprowadzenia kodu przedmiotu, dla którego wystawiana jest ocena dla studenta. 
W tym celu należy:
1. Zmodyfikować strukturę `student_t`, dodając stosowne pole.
2. Zmodyfikować funkcję `add_student()`, aby umożliwić wprowadzenie kodu przedmiotu.
3. Zmodyfikować funkcję `list_students()`, aby wyświetlała kod przedmiotu wraz z innymi informacjami o studencie.
4. Przetestować zmodyfikowany program, aby upewnić się, że nowa funkcjonalność działa poprawnie.

Prowadzący może zaproponować inną funkcjonalność do dodania (np. sprawdzanie poprawności wprowadzonych danych, itp.), w zależności od potrzeb i poziomu zaawansowania studentów. -->


## Realizacja zadania wskazanego przez prowadzącego

Po zapoznaniu się i zrozumieniu przykładowego projektu oraz wykonaniu prostej pracy samodzielnej, prowadzący zleci realizację konkretnego zadania związanego z obsługą struktur i wskaźników w języku C. Zadanie to może polegać na dodaniu nowej funkcjonalności do istniejącego projektu lub na stworzeniu nowego programu od podstaw, wykorzystującego struktury i wskaźniki.

Przykładowe zadania mogą obejmować:
- utworzenie struktury danych dla np. pacjenta:

```C
struct patient {
    char id[12];  /* 11 chars for PESEL, and last char for '\0' */
    char last_name[30];
    char first_name[30];
    unsigned short birth_year;
    char icd10[6];
};

```

- dodanie funkcji do zarządzania listą pacjentów (dodawanie, usuwanie, wyszukiwanie, aktualizacja danych),
- implementację prostego wyszukiwania pacjenta po numerze PESEL,
- itp.

<!-- ## Zadanie domowe

Na zakończenie laboratorium, prowadzący zleci wykonanie zadania domowego, które pozwoli na utrwalenie zdobytej wiedzy i umiejętności. 
Zadanie to polegać będzie na rozbudowie istniejącego projektu w szczególności o:
- dodanie funkcji zapisu i odczytu listy studentów/pacjentów do/z pliku,
- dodanie funkcji sortowania listy studentów/pacjentów według różnych kryteriów (np. nazwisko, numer albumu/PESEL, ocena/ICD10),
- dodanie funkcji wyszukiwania studenta/pacjenta według różnych kryteriów (np. nazwisko, numer albumu/PESEL),

Zadanie domowe w formie sprawozdania należy przesłać na wskazany adres serwisu eNauczanie w terminie do 7 dni od daty laboratorium. 

Zasady oceniania ćwiczenia oraz zadania domowego dostępne są na stronie kursu w serwisie eNauczanie. -->

## Literatura pomocnicza i załączniki

- Materiały z wykładów (serwis eNauczanie)
- Książka: Brian W. Kernighan, Dennis M. Ritchie, "Języka ANSI C. Programowanie", Wydawnictwo Helion, 2020,
- Dokumentacja języka C: https://en.cppreference.com/w/c
- [Struktury w C - W3Schools](https://www.w3schools.com/c/c_structs.php)
- [Przykładowy projekt na GitHub](https://github.com/dartfather/c_prog.git)