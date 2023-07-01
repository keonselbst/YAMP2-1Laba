#include <iostream>
#include "windows.h"
#include "HashTable.h"

int main()
{
    system("chcp 1251>nul");
    int n = 2, choice = 0;
    HashTable tmp(10);
    string a_catalog, a_file, spec;
    int year, mounth, day, size;
    HData b;

    while (choice != 4) {
        cout << "Выберите: \n1) Добавить каталог и файл; \n2) Удалить каталог и файл; \n3) Печать; \n4) Выйти.\n";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "\nВведите имя каталога : ";
            cin >> a_catalog;
            cout << "\nВведите имя файла : ";
            cin >> a_file;
            cout << "Введите год создания\n" << "->";
            cin >> year;
            cout << "Введите месяц создания\n" << "->";
            cin >> mounth;
            cout << "Введите день создания\n" << "->";
            cin >> day;
            cout << "Введите спецификацию\n" << "->";
            cin >> spec;
            cout << "Введите размер файла\n" << "->";
            cin >> size;

            b.catalog = a_catalog;
            b.file = a_file;
            b.year = year;
            b.mounth = mounth;
            b.day = day;
            b.specification = spec;
            b.size = size;
            tmp.add(b);
            break;
        case 2:
            cout << "\nВведите имя каталога : ";
            cin >> a_catalog;
            cout << "\nВведите имя файла : ";
            cin >> a_file;
           /* cout << "Введите год создания\n" << "->";
            cin >> year;
            cout << "Введите месяц создания\n" << "->";
            cin >> mounth;
            cout << "Введите день создания\n" << "->";
            cin >> day;
            cout << "Введите спецификацию\n" << "->";
            cin >> spec;
            cout << "Введите размер файла\n" << "->";
            cin >> size;*/

            b.catalog = a_catalog;
            b.file = a_file;
            tmp.remove_elem(b);
            break;
        case 3:
            cout << "\nХэш-таблица\n";
            tmp.print();
            break;
        case 4:
            break;
        default:
            cout << "Ошибка." << endl;
            break;
        }
    }

    system("pause");
    return 0;

}