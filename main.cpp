#include <iostream>

using namespace std;

struct Array
{
	int* Address;
	int* PreAddress;
	int Count;
	int MaxCount;

};

Array Member;

void InsertData()
{
	srand(time(NULL));

	int Number = 0;
	cin >> Number;

	int RandomNumber = rand() % 10;
	Member.Address[RandomNumber] = Number;

}

void initArray()
{
	for (int i = 0; i < Member.MaxCount; ++i)
	{
		Member.Address[i] = i + 1;
	}

	Member.MaxCount = 10;
	Member.Address = new int[Member.MaxCount];
	Member.PreAddress = 0;
	Member.Count = 10;

}

void Sizeup()
{
	Member.PreAddress = Member.Address;
	Member.Address = new int[Member.MaxCount + 1];
	Member.MaxCount++;
	
	for (int i = 0; i < Member.Count; ++i)
	{
		Member.Address[i] = Member.PreAddress[i];
	}

	delete[] Member.PreAddress;
}

int main()
{
	initArray();
	InsertData();
	Sizeup();

	for(int i = 0; i < Member.Count; ++i)
	{
		cout << Member.Address[i] << " ";
	}

	delete[] Member.Address;
}