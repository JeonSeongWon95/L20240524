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

void InitArray()
{
	Member.PreAddress = 0;
	Member.MaxCount = 10;
	Member.Count = 10;
	Member.Address = new int[Member.MaxCount];
	for (int i = 0; i < Member.MaxCount; ++i)
	{
		Member.Address[i] = i + 1;
	}
}

void RandomInsertData()
{
	int Number = 0;
	cout << "���ڸ� �Է��ϸ� ������ ��ġ�� �߰��˴ϴ�." << endl;
	cin >> Number;
	srand(time(NULL));

	int RandomNumber = rand() % Member.Count + 1;

	Member.PreAddress = Member.Address;
	Member.Address = new int[Member.MaxCount * 2];
	Member.MaxCount = Member.MaxCount * 2;

	for(int i = 0; i < RandomNumber; ++i )
	{
		Member.Address[i] = Member.PreAddress[i];
	}

	Member.Address[RandomNumber] = Number;

	for (int i = RandomNumber + 1; i < Member.MaxCount; ++i)
	{
		Member.Address[i] = Member.PreAddress[i - 1];
	}

	delete[] Member.PreAddress;
	Member.PreAddress = nullptr;

}

void Sizeup()
{
	Member.PreAddress = Member.Address;
	Member.MaxCount *= 2;
	Member.Address = new int[Member.MaxCount];

	for (int i = 0; i < Member.Count; ++i)
	{
		Member.Address[i] = Member.PreAddress[i];
	}
	delete[] Member.PreAddress;

}

void PrintArray()
{
	for (int i = 0; i < Member.Count; ++i)
	{
		cout << Member.Address[i] << " ";
	}
	delete[] Member.Address;
}

int main()
{
	InitArray();
	RandomInsertData();
	Sizeup();
	PrintArray();
}