# Laboratorium 1: Translacja i biblioteki C++ #
## W ramach pierwszych zajęć zaprojektowano strukturę projektu C++ z wykorzystaniem Makefile i różnych typów bibliotek. Implementacja obejmowała: ##

  -Dynamiczną bibliotekę współdzieloną libhello.so zawierającą funkcję hello::print z liczonymi wywołaniami.

  -Statyczną bibliotekę liboperations.a z funkcjami do operacji na wektorach i stringach.

  -Programy testujące działanie powyższych funkcji i poprawność linkowania.
  
  -Całość została skompilowana z użyciem ręcznie napisanego Makefile.
  

# Laboratorium 2: Zarządzanie pamięcią i struktury danych #

## Celem było stworzenie własnej uproszczonej wersji std::vector<char>: ##

  -Implementacja struktury MiniVector z ręcznym zarządzaniem dynamiczną pamięcią.

   -Funkcje do inicjalizacji, modyfikowania rozmiaru (expand/shrink), dodawania/usuwania elementów.

  -Mechanizmy usuwania po indeksie i po wartości, czyszczenie wektora, i bezpieczne zwalnianie pamięci.
  
# Laboratorium 3: Klasy, listy dynamiczne i reguła 5/0 #

## Projekt obejmował zaprojektowanie klas Subtask oraz Task: ##

  -Subtask reprezentuje pojedyncze zadanie z priorytetem i statusem wykonania.

  -Task zarządza listą podzadań jako jednokierunkowa lista wskaźników, zachowując kolejność wg priorytetu.

  -Implementacja głębokiego kopiowania i przenoszenia (rule of 5).
   
# Laboratorium 4: Nie odbyło się #
# Laboratorium 5: Szablony i STL #

## Laboratorium poświęcone było użyciu szablonów oraz kontenerów STL: ##

  - Implementacja klasy szablonowej Sensor<T> z użyciem std::variant, std::optional i std::vector.

  - Operacje RMS, minimum, przeciążenie operatorów <<, >, !=.

  - Kolekcja SensorCollection grupująca sensory wg typu z użyciem unordered_map i list.

  - Implementacja metod operujących na kolekcji z użyciem algorytmów STL: reverse, remove_if, copy_if, max_element, accumulate.

# Laboratorium 6: Polimorfizm i RTTI #

## Zadaniem było stworzenie systemu zarządzania flotą transportową Federacji Handlowej: ##

  - Klasy Cargo, RawMaterialCargo, ManufacturedGoodsCargo, HazardousWasteCargo z wykorzystaniem dziedziczenia.

  - Polimorficzne klasy statków TransportVessel, Freighter, ScoutShip z metodą loadCargo uwzględniającą typy ładunków.

  - Dynamiczne rzutowanie i RTTI przy generowaniu raportów floty (generateLogisticsReport).

  - Obsługa wyjątków logicznych, załadunku niebezpiecznych odpadów oraz filtracja wg poziomu zagrożenia.

# Laboratorium 7: Szablony – Macierze i specjalizacje #

## Zadanie dotyczyło implementacji klasy szablonowej Matrix<T, Rows, Cols>: ##

  - Operatory [], +, - oraz metoda transpose().

  - Klasa pochodna SquareMatrix<T, N> z obliczaniem wyznacznika (determinantu).

  - Statyczna metoda identity() do tworzenia macierzy jednostkowej.

  - Specjalizacja klasy SquareMatrix<T, 2> z uproszczonym algorytmem determinantu.
