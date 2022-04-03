#include "DynArray.h"
#include <iostream>
#include  <iomanip>
#include <cstdlib>
using namespace std;
using namespace my;
DynArray::DynArray(int filled) : filled(filled)
{
	capacity = filled + 5;
	pData = new int[capacity];
	for (int i = 0; i < filled; i++)
		pData[i] = rand() % 10 +1;
}

DynArray::DynArray(const DynArray& original)
	: filled(original.filled), capacity(original.capacity)
{
	pData = new int[capacity];
	for (int i = 0; i < filled; i++)
		pData[i] = original.pData[i];
	cout << "Конструктор копирования" << endl;
}
DynArray::DynArray(DynArray&& dying) {
	pData = dying.pData;
	dying.pData = nullptr;
}
DynArray& DynArray::operator=(const DynArray& original)
{
	delete[] pData;
	this->filled = original.filled;
	this->capacity = original.capacity;
	pData = new int[capacity];
	for (int i = 0; i < filled; i++)
		pData[i] = original.pData[i];
	cout << "Оператор присваивания " << endl;
	return *this;
}
DynArray& DynArray::operator = (DynArray&& dying) {
	delete[] pData;
	pData = dying.pData;
	dying.pData = nullptr;
	return *this;
}