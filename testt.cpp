#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>

using namespace std;

struct Cargo
{
    int id;
    char cargo_name[50];
    char departure[50];
    char destination[50];
    int distance;
    double weight;
    double price;
};

Cargo* readFromFile(const char* filename, int& count)
{
    ifstream fin;
    fin.open(filename);
    
    if (fin) {
        int lines = 0;
        int temp_id, temp_dist;
        char temp_c[50], temp_dep[50], temp_dest[50];
        double temp_w, temp_p;

        while (fin >> temp_id >> temp_c >> temp_dep >> temp_dest >> temp_dist >> temp_w >> temp_p) {
            lines++;
        }

        fin.clear();
        fin.seekg(0, ios::beg);
        Cargo* arr = new Cargo[lines];
        count = lines;

        for (int i = 0; i < count; i++) {
            fin >> arr[i].id;
            fin >> temp_c;
            strcpy(arr[i].cargo_name, temp_c);
            fin >> temp_dep;
            strcpy(arr[i].departure, temp_dep);
            fin >> temp_dest;
            strcpy(arr[i].destination, temp_dest);
            fin >> arr[i].distance >> arr[i].weight >> arr[i].price;
        }

        fin.close();
        cout << "Всё хорошо, записи загружены: " << count << endl;
        return arr;
    }
    else {
        cout << "Файл не найден" << endl;
        count = 0;
        return NULL;
    }
}

void printDatabase(const Cargo* arr, int count) {
    if (arr == NULL || count == 0) {
        cout << "База данных пуста" << endl;
        return;
    }

    cout << "\n=========================================================================================\n";
    cout << "| " << setw(4) << "ID"
         << " | " << setw(22) << "Наименование груза"
         << " | " << setw(15) << "Отправление"
         << " | " << setw(15) << "Назначение"
         << " | " << setw(6)  << "Км"
         << " | " << setw(7)  << "Вес(т)"
         << " | " << setw(10) << "Цена(руб)" << " |\n";
    cout << "=========================================================================================\n";

    for (int i = 0; i < count; i++) {
	cout << "| " << setw(4) << arr[i].id
             << " | " << setw(22) << arr[i].cargo_name
             << " | " << setw(15) << arr[i].departure
             << " | " << setw(15) << arr[i].destination
             << " | " << setw(6)  << arr[i].distance
             << " | " << setw(7)  << fixed << setprecision(1) << arr[i].weight
             << " | " << setw(10) << fixed << setprecision(2) << arr[i].price << " |\n";
    }
    cout << "=========================================================================================\n";
}

void editRecord(Cargo* arr, int count) {
    if (arr == NULL || count == 0) {
        cout << "База данных пуста" << endl;
        return;
    }

    int target_id;
    cout << "Введите ID записи для редактирования: ";
    cin >> target_id;

    int index = -1;
    for (int i = 0; i < count; i++) {
        if (arr[i].id == target_id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Запись с таким ID не найдена" << endl;
        return;
    }

    cout << "Введите новое наименование груза: ";
    cin >> arr[index].cargo_name;
    cout << "Введите новый город отправления: ";
    cin >> arr[index].departure;
    cout << "Введите новый город назначения: ";
    cin >> arr[index].destination;
    cout << "Введите новое расстояние (км): ";
    cin >> arr[index].distance;
    cout << "Введите новый вес (тонны): ";
    cin >> arr[index].weight;
    cout << "Введите новую стоимость (руб): ";
    cin >> arr[index].price;

    cout << "Данные изменены\n";
}

void calcstats(const Cargo* arr, int count) {
	if (arr == NULL || count == 0) {
        	cout << "База данных пуста" << endl;
        		return;
    	}

    	double total_weight = 0.0;
    	double total_price = 0.0;
    	int total_distance = 0;

    	for (int i = 0; i < count; i++) {
        	total_weight += arr[i].weight;
        	total_price += arr[i].price;
        	total_distance += arr[i].distance;
    	}

        double avg_price = total_price / count;

    	cout << "\n--- РЕЗУЛЬТАТЫ ВЫЧИСЛЕНИЙ ---\n";
    	cout << "Общее количество перевозок: " << count << endl;
    	cout << "Суммарный вес грузов:       " << total_weight << " т\n";
    	cout << "Общая стоимость перевозок: " << fixed << setprecision(2) << total_price << " руб.\n";
    	cout << "Средняя стоимость рейса:   " << avg_price << " руб.\n";
    	cout << "-----------------------------\n";
}


