# Группа: ИКТГ-2522
Владелец репозитория: Калганова Екатерина\
Состав коллектива: Калганова Екатерина, Пимахина Юлия\
Вариант №16\
Реализация "Грузовых перевозок"

1. Функция “Чтение данных из файла в динамический массив”

```
Cargo* readFromFile(const char* filename, int& count)
{
    ifstream fin;
    fin.open(filename);
    
    if (fin) {
        int lines = 0;
        int temp_id, temp_dist;
        char temp_c[50], temp_dep[50], temp_dest[50];
        double temp_w, temp_p;

        while (fin >> temp_id >> temp_c >> temp_dep >> temp_dest >> temp_dist >> temp>
            lines++;
        }

        fin.clear();
        fin.seekg(0, ios::beg);
        Cargo* arr = new Cargo[lines];
        count = lines;

        for (int i = 0; i < count; i++) {
            fin >> arr[i].id >> arr[i].cargo_name >> arr[i].departure 
                >> arr[i].destination >> arr[i].distance >> arr[i].weight >> arr[i].p>
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
```

2. Функция “Просмотр данных, хранящихся в массиве” *в виде таблицы

```
void printDatabase(const Cargo* arr, int count) {
    if (arr == NULL || count == 0) {
        cout << "База данных пуста" << endl;
        return;
    }
    
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
```

3. Функция “Корректировка данных заданной строки”

```
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
        cout << "Данные успешно изменены!\n";
    } else {
        cout << "Запись с таким ID не найдена" << endl;
    }
}
```

4. Функция "Вычисления"
```
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
```
5. Функция “Сохранение данных в новом файле”

```
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
```

6. Файл "newfile2.txt"
   > не очень поняла, что за файл... выписала тот, который был уже изменен с помощью программы main

Иллюстрация работы программы
<img width="1000" height="1000" alt="изображение" src="https://github.com/user-attachments/assets/3c765704-7c88-442f-9d07-c4876d141f1a" />
<img width="600" height="600" alt="изображение" src="https://github.com/user-attachments/assets/c3bb344c-6166-4e60-9a8d-896d5dc7f1e0" />

**До изменения (файл input.txt):**
<img width="800" height="150" alt="изображение" src="https://github.com/user-attachments/assets/556a6428-60b7-4b1f-99e5-87cfbabf7adf" />

**После изменения (файл newfile2.txt):**
<img width="800" height="150" alt="изображение" src="https://github.com/user-attachments/assets/ddf442b0-d951-41e4-8fc2-1ba4adfcc852" />

# Ответы на контрольные вопросы

1. Дайте определение типу данных "структура"
> Структура - тип данных языка C, определяемый пользователем. Она может содержать произвольное количество полей в виде переменных различных типов, но не может содержать поле того же типа, что и она сама.

2. Какое представление данных соответствует массиву структур
> Массиву структур соответствует табличная форма представления данных. В памяти это непрерывная последовательность структурных переменных, где каждый элемент имеет одинаковую внутреннюю организацию полей

3. Как объявить структурную переменную
> Переменную можно объявить несколькими способами:
- Статически (например struct Cargo item)
- Статическим массивом (например Cargo myDb[10])
- Динамически через указатель (например Cargo* ptr = new Cargo)

4. Для чего предназначена динамическая память
> Динамическая память предназначена для выделения памяти во время работы программы, когда точный размер данных неизвестен на этапе компиляции.

6. Что такое "утечка памяти"
> Утечка памяти - ситуация, когда динамическая память была выделена оператором, но не была своевременно освобождена с помощью delete до потери указателя. Неосвобожденная память остается занятой до завершения программы, что может привести к сбоям программы.

7. Какие средства для работы с текстовыми файлами имеются в C++
> В данном языке используются объекты-потоки, которые образуют канал между программой и устройством чтения-записи. Для работы с ними используется заголовочный файл <fstream>.
- Для открытия файла и чтения данных: std::ifstream (int a; fin >> a)
- Для открытия файла и записи данных: std::ofstream (int a; fout << a)
- Для чтения и записи одновременно: std::fstream
- Проверки через "если": if (fin)
- Закрытие потоков: fin.close()

# Заключение
В ходе выполнения лабораторной работы были освоены навыки работы со структурами в C++, также с динамическим выделением и освобождением памяти. Реализовано консольное приложение для управления информационной базой данных области «Грузовых перевозок». Написаны функции для считывания данных из текстового файла в динамический массив, вывода массива в виде форматированной таблицы, многократного редактирования, добавления, удаления записей, выполнения вычислений и сохранения итоговых данных в новый текстовый файл.
