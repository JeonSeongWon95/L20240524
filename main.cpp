#include <iostream>

using namespace std;

struct Array
{
	int* Address;
	int* PreAddress;
	int Count;
	int MaxCount;

};

int Number = 0;

Array Member;

void InitArray()
{
	Member.Address = new int[10];
	Member.PreAddress = 0;
	Member.MaxCount = 10;
	Member.Count = 10;

	for (int i = 0; i < Member.MaxCount; ++i)
	{
		Member.Address[i] = i + 1;
	}
}

void InsertData()
{
	cin >> Number;

	srand(time(NULL));

	int RandomNumber = rand() % Member.Count;

	Member.Address[RandomNumber] = Number;
	Member.PreAddress = Member.Address;
	Member.Address = new int[Member.MaxCount + 1];
	Member.MaxCount++;
}

void Sizeup()
{
	for (int i = 0; i < Member.Count; ++i)
	{
		Member.Address[i] = Member.PreAddress[i];
	}

	delete[] Member.PreAddress;

}

int main()
{
	InitArray();
	InsertData();
	Sizeup();

	for(int i = 0; i < Member.Count; ++i)
	{
		cout << Member.Address[i] << " ";
	}

	delete[] Member.Address;
}