#include <iostream>
#include <windows.h>
#include <stdlib.h>

#define N 3

#define fflush while (getchar()!='\n')

typedef struct {
    char brand[15];
    char model[15];;
    int year;
    int power;
    int weight;
    char color[10];
    int cost;
} car;

void init(car* a) {
    a->brand[0] = 0;
    a->model [0] = 0;
    a->year = 0;
    a->power = 0;
    a->weight = 0;
    a->color[0] = 0;
    a->cost = 0;
}

void read(car* a) {
    printf("Введите марку автомобиля: "); scanf_s("%s", a->brand, 15); fflush;
    printf("Введите модель: "); scanf_s("%s", a->model, 15); fflush;
    printf("Введите год производства: "); scanf_s("%d", &a->year); fflush;
    printf("Введите мощность автомобиля: "); scanf_s("%d", &a->power, 4); fflush;
    printf("Введите массу автомобиля: "); scanf_s("%d", &a->weight, 4); fflush;
    printf("Введите цвет: "); scanf_s("%s", a->color, 10); fflush;
    printf("Введите цену автомобиля: "); scanf_s("%d", &a->cost, 10); fflush;
}

void display(car* a) {
    printf("\n%15s %-15s %4d год || %4d л.с., %5d кг, %10s || %10d рублей\n\n", a->brand, a->model, a->year, a->power, a->weight, a->color, a->cost);
}

void sravnit(car* a) {
    system("cls");
    int choice1 = 0, choice2 = 0;
    printf("Введите номера двух машин, которые надо сравнить: ");
    scanf_s("%d %d", &choice1, &choice2); fflush;
    choice1--; choice2--;
    printf("\n%15s %-15s  ||  %d год  ||  %4d л.с.  ||  %5d кг  ||  %8dр\n", (a + choice1)->brand, (a + choice1)->model, (a + choice1)->year, (a + choice1)->power, (a + choice1)->weight, (a + choice1)->cost);
    printf("%15s %-15s  ||  %d год  ||  %4d л.с.  ||  %5d кг  ||  %8dр\n", (a + choice2)->brand, (a + choice2)->model, (a + choice2)->year, (a + choice2)->power, (a + choice2)->weight, (a + choice2)->cost);
}

int main() {
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    car* cars;
    cars = (car*)calloc(N, sizeof(car));
    for (int i = 0; i < N; i++) {
        init(cars + i);
        read(cars + i);
        display(cars + i);
    }

    sravnit(cars);
}
