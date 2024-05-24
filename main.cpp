#include <iostream>

using namespace std;

struct Array
{
	int* Address;
	int* PreAddress;
	int MaxCount;

};

int main()
{
	int Number = 0;

	Array Member;

	Member.Address = new int[10];
	Member.PreAddress = 0;
	Member.MaxCount = 10;

	for (int i = 0; i < 10; ++i)
	{
		Member.Address[i] = i + 1;
	}

	cin >> Number;

	srand(time(NULL));

	int RandomNumber = rand() % 10;

	Member.Address[RandomNumber] = Number;
	Member.PreAddress = Member.Address;
	Member.Address = new int[Member.MaxCount + 1];
	Member.MaxCount++;

	for(int i = 0; i < Member.MaxCount - 1; ++i)
	{
		Member.Address[i] = Member.PreAddress[i];
	}

	delete[] Member.PreAddress;

	for(int i = 0; i < Member.MaxCount; ++i)
	{
		cout << Member.Address[i] << " " << endl;
	}

	delete[] Member.Address;
}