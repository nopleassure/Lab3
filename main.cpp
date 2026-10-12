#include <iostream>
#include <fstream>
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
            fin >> arr[i].id >> arr[i].cargo_name >> arr[i].departure 
                >> arr[i].destination >> arr[i].distance >> arr[i].weight >> arr[i].price;
        }

        fin.close();
        cout << "Записи успешно загружены: " << count << endl;
        return arr;
    }
    else {
        cout << "Файл не найден" << endl;
        count = 0;
        return NULL;
    }
}

void printDatabase(const Cargo* arr, int count) {
    cout << "\n--- СПИСОК ГРУЗОВ ---\n";
    cout << "ID\tНазвание\tОткуда\t\tКуда\t\tКм\tВес\tЦена\n";
    cout << "-------------------------------------------------------------\n";

    for (int i = 0; i < count; i++) {
        cout << arr[i].id << "\t" 
             << arr[i].cargo_name << "\t\t" 
             << arr[i].departure << "\t\t" 
             << arr[i].destination << "\t\t" 
             << arr[i].distance << "\t" 
             << arr[i].weight << "\t" 
             << arr[i].price << endl;
    }
    cout << "-------------------------------------------------------------\n";
}

void editRecord(Cargo* arr, int count) {
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

    if (index != -1) {
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
    } else {
        cout << "Запись с таким ID не найдена" << endl;
    }
}

void calcstats(const Cargo* arr, int count) {
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
    cout << "Общее количество записей: " << count << endl;
    cout << "Суммарный вес грузов:     " << total_weight << " т\n";
    cout << "Общая стоимость перевозок: " << total_price << " руб.\n";
    cout << "Средняя стоимость рейса:   " << avg_price << " руб.\n";
    cout << "-----------------------------\n";
}

void saveToFile(const Cargo* arr, int count)
{
    char filename[100];
    cout << "Введите имя нового файла для сохранения: ";
    cin >> filename;

    ofstream fout;
    fout.open(filename);
    for (int i = 0; i < count; i++)
    {
        fout << arr[i].id << " "
             << arr[i].cargo_name << " "
             << arr[i].departure << " "
             << arr[i].destination << " "
             << arr[i].distance << " "
             << arr[i].weight << " "
             << arr[i].price << "\n";
    }

    fout.close();
    cout << "Данные сохранены в файл: " << filename << endl;
}

int main()
{
    Cargo* database = NULL;
    int recordCount = 0;
    int choice = 0;

    do
    {
        cout << "\n=== МЕНЮ УПРАВЛЕНИЯ ===\n";
        cout << "1. Чтение данных из файла в динамический массив\n";
        cout << "2. Просмотр данных\n";
        cout << "3. Корректировка данных строки\n";
        cout << "4. Вычисления\n";
        cout << "5. Сохранение данных в новом файле\n";
        cout << "0. Выход\n";
        cout << "Выберите пункт: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                char filename[100];
                cout << "Введите имя файла для чтения: ";
                cin >> filename;

                if (database != NULL) 
                {
                    delete[] database;
                }
                database = readFromFile(filename, recordCount);
                break;
            }
            case 2:
                printDatabase(database, recordCount);
                break;
            case 3:
                editRecord(database, recordCount);
                break;
            case 4:
                calcstats(database, recordCount);
                break;
            case 5:
                saveToFile(database, recordCount);
                break;
            case 0:
                cout << "Завершение программы..." << endl;
                break;
            default:
                cout << "Неверный пункт меню" << endl;
        }
    } 
    while (choice != 0);

    if (database != NULL) 
    {
        delete[] database;
        database = NULL;
    }

    return 0;
}
