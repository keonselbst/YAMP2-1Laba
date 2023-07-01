#include "HashTable.h"

using namespace std;

int HashTable::qFunc(int h, int i)
{
	return (h + i * i) % size;
	//return;
}

int HashTable::qFunc_reh(int h0, int g, int i, int number)
{
	//return (h0 + i * g) % (size / (2 * number));
	return (h0 * (number - 1) + g + i ^ 2) % size;
}

int HashTable::Hash(string a_catalog, string a_file)
{
	int n = 0;
	int len = a_catalog.length() + a_file.length(); 
	string str = a_catalog + a_file;

	for (int i = 0; i < len; i++)
	{
		n += ((unsigned char)str.at(i));
	}
	return n;
}

void HashTable::rehashing()
{
	Item* table2 = new Item[size * 2];

	for (int i = 0; i < size; i++)
		table2[i] = table[i];

	delete[] table;
	table = table2;

	size = size * 2;
	++rehashings;
}

HashTable::HashTable(int s)
{
	size = s;
	table = new Item[size];
	elem_count = 0;
}

HashTable::~HashTable()
{
	delete[] table;
}

void HashTable::add(HData elem)
{
	if (elem_count >= size / 2) // ���� ������, �����
		rehashing();

	int h1 = Hash(elem.catalog, elem.file); // ���������� �������� ����������� ������ �������
	int i = 0;
	int place = qFunc(h1, i);
	do
	{
		if (table[place].status == Status::FREE || table[place].status == Status::REMOVED)
		{
			table[place].status = Status::FILLED;
			table[place].data = elem;
			cout << "\n";
			elem_count++;
			break;
		}

		i++;

	} while ((table[place].status == Status::FILLED) && (place < size)); // ����� ���������� ��������
}

bool HashTable::search(HData elem, int& index)
{
	int h0 = Hash(elem.catalog, elem.file);
	int g = Hash(elem.catalog, elem.file); // 2 nomera
	bool flag = false;

	if (rehashings != 0)
	{
		int i = 0;
		int number = 1;
		int place = qFunc_reh(h0, g, i, number); // ���������� ������ ��� �����

		for (int k = 1; k <= rehashings; k++) // ����� ����

		{
			i = 0;
			while (table[place].status != Status::FREE && !flag)
			{
				if (table[place].status == Status::FILLED && table[place].data.catalog == elem.catalog && table[place].data.file == elem.file)
				{
					flag = true;
					index = place;
				}

				i++;
				place = qFunc_reh(h0, g, i, number);
			}
			number++;
		}
		return flag;
	}
	else // ���� ��� �� ����
	{
		int i = 0;
		int place = qFunc(h0, i);
		while (table[place].status != Status::FREE && !flag)
		{
			if (table[place].status == Status::FILLED && table[place].data.catalog == elem.catalog && table[place].data.file == elem.file)
			{
				flag = true;
				index = place;
			}

			i++;
			place = qFunc(h0, i);
		}
		return flag;
	}
}

void HashTable::remove_elem(HData elem)
{
	HData FREE;
	int index = -1;
	if (search(elem, index))
	{
		table[index].status = Status::REMOVED;
		table[index].data = FREE;
		elem_count--;
	}
}

void HashTable::print()
{
	for (int i = 0; i < size; i++)
	{
		if (table[i].status == Status::FILLED)
		{
			cout << "\t��� ��������: " << table[i].data.catalog << "\n" << "\t��� �����: " << table[i].data.file << "\n"
				<< "\t��� ��������: " << table[i].data.year << "\n" << "\t����� ��������: " << table[i].data.mounth << "\n"
				<< "\t���� ��������: " << table[i].data.day << "\n" << "\t������������: " << table[i].data.specification << "\n"
				<< "\t������ �����: " << table[i].data.size << "\n";

			cout << "\n";
		}
	}
}


bool HashTable::find(int KEY) {
	for (int i = 0; i < size; ++i)
		if (table[qFunc(h, i)].data == KEY)
			return table[qFunc(KEY, i)].status == Status::FILLED;
	return false;
}