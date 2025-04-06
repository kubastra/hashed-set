#include <iostream>
#include "setHashed.h"
#include <chrono>
#include <fstream>

const int MAX_SIZE = 1000;
std::ofstream file("time.dat");

void measure_operation(int operation_type) {
    for (int size = 1; size <= MAX_SIZE; ++size) {
        setHashed zbior(size);
        setHashed zbior2(size);


        for (int i = 0; i < size; ++i) {
            zbior.insert(i);
            zbior2.insert(i + size / 2);
        }

        auto start = std::chrono::high_resolution_clock::now();

        switch (operation_type) {
            case 1:
                zbior.insert(size + 1);
                break;
            case 2:
                zbior.removing(size / 2);
                break;
            case 3:
                zbior.contains(size / 2);
                break;
            case 4: {
                auto tmp = zbior + zbior2;
                break;
            }
            case 5: {
                auto tmp = zbior - zbior2;
                break;
            }
            case 6: {
                auto tmp = zbior & zbior2;
                break;
            }
            case 7: {
                bool tmp = zbior == zbior2;
                break;
            }
            default:
                break;
        }

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

        file << size << " " << duration << "\n";
    }
}


int main() {
    if(!file) {
        std::cerr << "Nie udalo sie otworzyc pliku" << std::endl;
        return -1;
    }

    std::cout << "__________MENU__________\n";
    std::cout << "1. wstawianie\n";
    std::cout << "2. usuwanie\n";
    std::cout << "3. zawieranie\n";
    std::cout << "4. suma\n";
    std::cout << "5. roznica\n";
    std::cout << "6. czesc wspolna\n";
    std::cout << "7. identycznosc\n";
    std::cout << "Wybor: ";

    int wybor;
    std::cin >> wybor;

    if(wybor < 1 || wybor > 7) {
        std::cout << "Nieprawidlowy wybor\n";
        return -2;
    }

    measure_operation(wybor);
    file.close();

    std::cout << "Pomiar zakonczony. Wyniki w pliku time.dat\n";
    return 0;
}