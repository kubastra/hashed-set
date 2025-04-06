#include <iostream>
#include "setHashed.h"
#include <chrono>
#include <fstream>
#include <random>

std::ofstream file("time.dat");

void wstawianie(setHashed zbior, int iteration){
    auto start = std::chrono::high_resolution_clock::now();
    zbior.insert(iteration);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start). count();
    file << iteration << " " << duration << std::endl;
}

void usuwanie(setHashed zbior, int iteration){
    auto start = std::chrono::high_resolution_clock::now();
    zbior.removing(iteration);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start). count();
    file << iteration << " " << duration << std::endl;
}

void zawieranie(setHashed zbior, int iteration){
    auto start = std::chrono::high_resolution_clock::now();
    zbior.contains(iteration);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start). count();
    file << iteration << " " << duration << std::endl;
}

void suma(setHashed zb_1, setHashed zb_2, int iteration){
    auto start = std::chrono::high_resolution_clock::now();
    setHashed sumaa = zb_1 + zb_2;
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start). count();
    file << iteration << " " << duration << std::endl;
}

void roznica(setHashed zb_1, setHashed zb_2, int iteration){
    auto start = std::chrono::high_resolution_clock::now();
    setHashed roznicaa = zb_1 - zb_2;
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start). count();
    file << iteration << " " << duration << std::endl;
}

void czesc_wspolna(setHashed zb_1, setHashed zb_2, int iteration){
    auto start = std::chrono::high_resolution_clock::now();
    setHashed wspolna = zb_1 & zb_2;
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start). count();
    file << iteration << " " << duration << std::endl;
}

void przystawanie(setHashed zb_1, setHashed zb_2, int iteration){
    auto start = std::chrono::high_resolution_clock::now();
    bool przystawaniee = zb_1 == zb_2;
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start). count();
    file << iteration << " " << duration << std::endl;
}


int main() {

    if(!file){
        std::cerr << "Nie udalo sie otworzyc pliku" << std::endl;
        return -1;
    }

    int wybor;
    std::cout << "__________MENU__________ " << std::endl;
    std::cout << "1. wstawianie " << std::endl;
    std::cout << "2. usuwanie " << std::endl;
    std::cout << "3. zawieranie " << std::endl;
    std::cout << "4. suma " << std::endl;
    std::cout << "5. roznica " << std::endl;
    std::cout << "6. czesc wspolna " << std::endl;
    std::cout << "7. identycznosc " << std::endl;
    std::cout << "Wybor: " << std::endl;
    std::cin >> wybor;

    switch(wybor){
        case 1:{
           break;
        }
        case 2:{

            break;
        }
        case 3:{
            break;
        }
        case 4:{
            break;
        }
        case 5:{
            break;
        }
        case 6:{
            break;
        }
        case 7:{
            break;
        }
        default:{
            std::cout << "Zly numer ;c" << std::endl;
            return -2;
        }
    }


    return 0;
}