#pragma once
using namespace std;
namespace my 
{
	class DynArray {
		int* pData; // указатель на выделенный массив
		int filled; // заполненность
		int capacity; // вместимость
	public:
		DynArray(int filled);
		DynArray(const DynArray& original); // конструктор копирования

		DynArray(DynArray&& dying);							//конструктор перемещения

		DynArray& operator = (const DynArray& original); // оператор присваивания

		DynArray& operator = (DynArray&& dying); // оператор присваивания с перемещением

		void print() const {
			for (int i = 0; i < this->filled; i++)
				cout << pData[i] << ' ';
			cout << endl;
		}
		~DynArray() { delete[] pData; }


	};
}
