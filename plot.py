import matplotlib.pyplot as plt
import numpy as np


def plot_operation(operation_name):
    # Wczytanie danych
    iteracje = []
    czasy = []

    with open('time.dat', 'r') as file:
        for line in file:
            data = line.strip().split()
            if len(data) == 2:  # Sprawdzenie czy linia zawiera 2 wartości
                iteracje.append(int(data[0]))
                czasy.append(int(data[1]))

    # Tworzenie wykresu
    plt.figure(figsize=(10, 6))
    plt.plot(iteracje, czasy, marker='o', linestyle='-', color='b')
    plt.title(f'Złożoność operacji: {operation_name}')
    plt.xlabel('Rozmiar zbioru')
    plt.ylabel('Czas (ns)')
    plt.grid(True)
    plt.tight_layout()
    plt.show()


# Lista dostępnych operacji
operations = {
    1: "Wstawianie",
    2: "Usuwanie",
    3: "Zawieranie",
    4: "Suma zbiorów",
    5: "Różnica zbiorów",
    6: "Część wspólna",
    7: "Identyczność zbiorów"
}

# Wybór operacji do wyświetlenia
print("Dostępne operacje:")
for key, value in operations.items():
    print(f"{key}. {value}")

choice = int(input("Wybierz numer operacji do wyświetlenia (1-7): "))

if choice in operations:
    plot_operation(operations[choice])
else:
    print("Nieprawidłowy wybór!")