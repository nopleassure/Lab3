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
