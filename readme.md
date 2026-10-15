# Porównanie Wydajności Kontenerów w C++ (`std::vector` vs `std::list` vs Tablica Dynamiczna)

Przejrzysty i efektywny skrypt benchmarkowy napisany w języku C++, zaprojektowany w celu oceny i porównania czasu wykonywania kluczowych operacji na podstawowych strukturach danych: **`std::vector`**, tradycyjnej **tablicy dynamicznej (`new int[]`)** oraz **`std::list`** (liście dwukierunkowej).

## 📈 Przegląd Benchmarku

Program przeprowadza serię testów wydajnościowych na $N = 100\,000$ losowo wygenerowanych elementów, aby przeanalizować, jak różne układy pamięci i wzorce dostępu wpływają na efektywność czasową.

### Testowane Operacje:

1. **Wypełnianie (Dodawanie):** Wprowadzenie $100\,000$ losowych liczb całkowitych (`rand()`) do struktury.

2. **Sortowanie:** Układanie elementów w kolejności rosnącej (`std::sort` dla struktur ciągłych, wbudowana metoda `.sort()` dla listy).

3. **Usuwanie ze środka:** Usunięcie elementu znajdującego się w dokładnej połowie kolekcji (indeks $50\,000$).

4. **Wstawianie do środka:** Wstawienie wartości testowej (`123`) z powrotem w środek kontenera.

## 📂 Fragment Kodu Źródłowego

Główne założenia pomiaru czasu z wykorzystaniem biblioteki `<chrono>`:

```cpp
#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <cstdlib>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    const int N = 100000;
    int random_numbers[N];
    for (int i = 0; i < N; i++) {
        random_numbers[i] = rand();
    }
    // ... pomiar czasu dla wektora, tablicy oraz listy
    return 0;
}
```

## 🚀 Uruchomienie i Kompilacja

Aby uzyskać jak najbardziej wiarygodne wyniki, upewnij się, że kompilujesz kod z **włączonymi optymalizacjami** (`-O3`), ponieważ wersje bez optymalizacji mogą drastycznie zafałszować czasy dostępu do pamięci i iteratorów.

### Wymagania wstępne

* Kompilator C++ obsługujący standard **C++11** lub nowszy (np. `g++`, `clang++`, MSVC).

### Kompilacja i Uruchomienie (Linux / macOS / MinGW)

```bash
# Zapisz plik jako benchmark.cpp i skompiluj z flagą -O3
g++ -O3 -std=c++11 benchmark.cpp -o benchmark

# Uruchom benchmark
./benchmark
```

## 📊 Oczekiwane Wyniki i Analiza

| Operacja | `std::vector` | Tablica Dynamiczna (`new[]`) | `std::list` |
| :--- | :--- | :--- | :--- |
| **Organizacja pamięci** | Ciągła | Ciągła | Rozproszona (Węzły) |
| **Początkowe dodawanie** | Szybkie | Szybkie | Wolniejsze (Narzut na węzły) |
| **Szybkość sortowania** | **Najszybsza** ($O(N \log N)$) | **Najszybsza** ($O(N \log N)$) | Wolniejsza (Przeskakiwanie wskaźników) |
| **Usuwanie ze środka** | Wolne ($O(N)$ - przesuwanie pamięci) | Wolne ($O(N)$ - przesuwanie pamięci) | Szybkie usuwanie, ale wolne docieranie ($O(N)$) |
| **Wstawianie do środka** | Wolne ($O(N)$ - przesuwanie pamięci) | Wolne ($O(N)$ - przesuwanie pamięci) | Szybkie wstawianie, ale wolne docieranie ($O(N)$) |

* **`std::vector` oraz Tablice Dynamiczne:** Osiągają świetne rezultaty dzięki spójności pamięci (cache locality) i optymalnemu sortowaniu. Modyfikacje w środku struktury wymagają jednak przesunięcia pozostałych elementów, przez co operacje wstawiania i usuwania są kosztowne czasowo.

* **`std::list`:** Posiada narzut wydajnościowy przy początkowym dodawaniu elementów oraz sortowaniu ze względu na alokację pojedynczych węzłów na sterczy. Zyskuje jednak strukturę przy operacjach zmiany powiązań (po odnalezieniu właściwego iteratora).

## 🛡️ Licencja

Projekt jest dostępny jako open-source na licencji [MIT](LICENSE).