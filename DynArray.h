#pragma once
using namespace std;
namespace my 
{
	class DynArray {
		int* pData; // ��������� �� ���������� ������
		int filled; // �������������
		int capacity; // �����������
	public:
		DynArray(int filled);
		DynArray(const DynArray& original); // ����������� �����������

		DynArray(DynArray&& dying);							//����������� �����������

		DynArray& operator = (const DynArray& original); // �������� ������������

		DynArray& operator = (DynArray&& dying); // �������� ������������ � ������������

		void print() const {
			for (int i = 0; i < this->filled; i++)
				cout << pData[i] << ' ';
			cout << endl;
		}
		~DynArray() { delete[] pData; }


	};
}
