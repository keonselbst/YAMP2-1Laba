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
        cout << "��������: \n1) �������� ������� � ����; \n2) ������� ������� � ����; \n3) ������; \n4) �����.\n";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "\n������� ��� �������� : ";
            cin >> a_catalog;
            cout << "\n������� ��� ����� : ";
            cin >> a_file;
            cout << "������� ��� ��������\n" << "->";
            cin >> year;
            cout << "������� ����� ��������\n" << "->";
            cin >> mounth;
            cout << "������� ���� ��������\n" << "->";
            cin >> day;
            cout << "������� ������������\n" << "->";
            cin >> spec;
            cout << "������� ������ �����\n" << "->";
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
            cout << "\n������� ��� �������� : ";
            cin >> a_catalog;
            cout << "\n������� ��� ����� : ";
            cin >> a_file;
           /* cout << "������� ��� ��������\n" << "->";
            cin >> year;
            cout << "������� ����� ��������\n" << "->";
            cin >> mounth;
            cout << "������� ���� ��������\n" << "->";
            cin >> day;
            cout << "������� ������������\n" << "->";
            cin >> spec;
            cout << "������� ������ �����\n" << "->";
            cin >> size;*/

            b.catalog = a_catalog;
            b.file = a_file;
            tmp.remove_elem(b);
            break;
        case 3:
            cout << "\n���-�������\n";
            tmp.print();
            break;
        case 4:
            break;
        default:
            cout << "������." << endl;
            break;
        }
    }

    system("pause");
    return 0;

}