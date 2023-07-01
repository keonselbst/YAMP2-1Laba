#pragma once
#include <iostream>

using namespace std;

enum class Status { FREE = 0, FILLED, REMOVED };

struct HData
{
	string catalog;
	string file;
	int year;
	int mounth;
	int day;
	string specification;
	int size;

	bool operator==(const HData& obj)
	{
		return catalog == obj.catalog && file == obj.file && year == obj.year && mounth == obj.mounth && day == obj.day && specification == obj.specification && size == obj.size;
	}

	HData()
	{
		catalog = "";
		file = "";
		year = -1;
		mounth = -1;
		day = -1;
		specification = "";
		size = -1;
	}

	void operator=(const HData obj)
	{

		catalog = obj.catalog;
		file = obj.file;
		year = obj.year;
		mounth = obj.mounth;
		day = obj.day;
		specification = obj.specification;
		size = obj.size;
	}
};

struct Item {
	HData data;
	Status status;

	Item()
	{
		status = Status::FREE;
	}
};



class HashTable
{
	int rehashings = 0;
	int size;
	Item* table;
	int elem_count;

	int qFunc(int, int);

	int qFunc_reh(int, int, int, int);

	int Hash(string, string);

	void rehashing();

public:
	HashTable(int);

	~HashTable();

	void add(HData);

	bool search(HData, int&);

	void remove_elem(HData);

	void print();

	bool find(int);
};
