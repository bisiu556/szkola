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

    // Generowanie losowych liczb
    int random_numbers[N];
    for (int i = 0; i < N; i++) {
        random_numbers[i] = rand();
    }

    // ==========================================
    // VECTOR
    // ==========================================
    cout << "======= VECTOR =======" << endl;
    vector<int> v;

    // Dodanie liczb
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        v.push_back(random_numbers[i]);
    }
    auto end = chrono::high_resolution_clock::now();
    cout << "Vector: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " mikrosekund" << endl;

    // Sortowanie
    start = chrono::high_resolution_clock::now();
    sort(v.begin(), v.end());
    end = chrono::high_resolution_clock::now();
    cout << "Vector sortowanie: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " mikrosekund" << endl;

    // Usuniêcie ze œrodka
    start = chrono::high_resolution_clock::now();
    v.erase(v.begin() + 50000);
    end = chrono::high_resolution_clock::now();
    cout << "Vector usuwanie: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " mikrosekund" << endl;

    // Dodanie do œrodka
    start = chrono::high_resolution_clock::now();
    v.insert(v.begin() + 50000, 123);
    end = chrono::high_resolution_clock::now();
    cout << "Vector wstawianie: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " mikrosekund" << endl;
    cout << endl;

    // ==========================================
    // TABLICA
    // ==========================================
    cout << "======= TABLICA =======" << endl;
    int* raw_array = new int[N + 1];

    // Dodanie liczb
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        raw_array[i] = random_numbers[i];
    }
    end = chrono::high_resolution_clock::now();
    cout << "Tablica: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " mikrosekund" << endl;

    // Sortowanie
    start = chrono::high_resolution_clock::now();
    sort(raw_array, raw_array + N);
    end = chrono::high_resolution_clock::now();
    cout << "Tablica sortowanie: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " mikrosekund" << endl;

    // Usuniêcie ze œrodka
    start = chrono::high_resolution_clock::now();
    for (int i = 50000; i < N - 1; i++) {
        raw_array[i] = raw_array[i + 1];
    }
    end = chrono::high_resolution_clock::now();
    cout << "Tablica usuwanie: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " mikrosekund" << endl;

    // Dodanie do œrodka
    start = chrono::high_resolution_clock::now();
    for (int i = N - 1; i >= 50000; i--) {
        raw_array[i + 1] = raw_array[i];
    }
    raw_array[50000] = 123;
    end = chrono::high_resolution_clock::now();
    cout << "Tablica dodawanie: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " mikrosekund" << endl;

    delete[] raw_array;
    cout << endl;

    // ==========================================
    // LISTA
    // ==========================================
    cout << "======= LISTA =======" << endl;
    list<int> lst;

    // Dodanie liczb
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        lst.push_back(random_numbers[i]);
    }
    end = chrono::high_resolution_clock::now();
    cout << "Lista: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " mikrosekund" << endl;

    // Sortowanie
    start = chrono::high_resolution_clock::now();
    lst.sort();
    end = chrono::high_resolution_clock::now();
    cout << "Lista sortowanie: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " mikrosekund" << endl;

    // Usuniêcie ze œrodka
    start = chrono::high_resolution_clock::now();
    auto it = lst.begin();
    advance(it, 50000);
    lst.erase(it);
    end = chrono::high_resolution_clock::now();
    cout << "Lista usuwanie: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " mikrosekund" << endl;

    // Dodanie do œrodka
    start = chrono::high_resolution_clock::now();
    auto it2 = lst.begin();
    advance(it2, 50000);
    lst.insert(it2, 123);
    end = chrono::high_resolution_clock::now();
    cout << "Lista dodawanie: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " mikrosekund" << endl;

    return 0;
}
