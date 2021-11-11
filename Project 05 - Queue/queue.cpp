#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <iostream>
#include <sstream>
#include <algorithm>

#define MAXQUEUE 200
#define MAXQUEUEPERTELLER 50
#define MAXTELLER 4

using namespace std;

class Queue
{
private:
	string kodeAntrian[MAXQUEUE];
	int front;
	int rear;
	int counter;
	int jmlTeller;
	string prefixTeller[MAXTELLER];
	int counterTeller[MAXTELLER];

public:
	Queue();
	void gotoxy(short int x, short int y);
	void reset();
	int isEmpty();
	int isFull();
	string leadingZero(int angka, int length);
	string genQueueCode();
	void insQueue();
	void procQueue();
	void printQueue();
};

Queue::Queue()
{
	reset();
}

void Queue::reset()
{
	prefixTeller[0] = "A";
	prefixTeller[1] = "B";
	prefixTeller[2] = "C";
	prefixTeller[3] = "D";

	counterTeller[0] = 0;
	counterTeller[1] = 0;
	counterTeller[2] = 0;
	counterTeller[3] = 0;
	rear = -1;
	front = 0;
	counter = 0;
	jmlTeller = 4;
	for (int i = 0; i < MAXQUEUE; i++)
		kodeAntrian[i] = "";
}

int Queue::isEmpty()
{
	if (counter == 0)
		return 1;
	else
		return 0;
}

int Queue::isFull()
{
	if (rear == MAXQUEUE - 1)
		return 1;
	else
		return 0;
}

string Queue::leadingZero(int angka, int length)
{
	stringstream ss;
	ss << angka;
	string s;
	ss >> s;
	string kata;
	kata = s;
	int i;
	for (i = 0; i < (length - s.length()); i++)
	{
		kata = "0" + kata;
	}
	return kata;
}

string Queue::genQueueCode()
{
	int angkaRandom;
	string kode;
	srand(time(0));
	while (true)
	{
		angkaRandom = rand() % 4;
		if (counterTeller[angkaRandom] < MAXQUEUEPERTELLER)
		{
			counterTeller[angkaRandom]++;
			break;
		}
		if (counterTeller[0] == MAXQUEUEPERTELLER &&
				counterTeller[1] == MAXQUEUEPERTELLER &&
				counterTeller[2] == MAXQUEUEPERTELLER &&
				counterTeller[3] == MAXQUEUEPERTELLER)
		{
			return " ";
		}
	}
	kode = prefixTeller[angkaRandom] + leadingZero(counterTeller[angkaRandom], 3);
	return kode;
}

void Queue::insQueue()
{
	if (isFull())
	{
		if (counter == 0)
		{
			reset();
			insQueue();
		}
		else
		{
			printf("Antrian Penuh ...");
			getch();
		}
	}
	else
	{
		string kodeGen;
		kodeGen = genQueueCode();
		rear = (rear + 1) % MAXQUEUE;
		kodeAntrian[rear] = kodeGen;
		counter++;
	}
}

void Queue::procQueue()
{
	if (isEmpty())
	{
		printf("Antrian Masih Kosong ...");
		getch();
	}
	else
	{
		kodeAntrian[front] = "";
		front = (front + 1) % MAXQUEUE;
		counter--;
	}
}

void Queue::printQueue()
{
	int baris = 1;
	if (isEmpty())
	{
		gotoxy(40, 1);
		printf("Antrian Masih Kosong ...");
	}
	else
		for (int i = front; i <= rear; i++)
		{
			gotoxy(40, baris++);
			cout << leadingZero(i + 1, 3) << ". " << kodeAntrian[i];
			if (rear == front)
			{
				cout << " [front/rear]\n";
			}
			else if (i == front)
			{
				cout << " [front]\n";
			}
			else if (i == rear)
			{
				cout << " [rear]\n";
			}
		}
}

void Queue::gotoxy(short int x, short int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = {x, y};
	SetConsoleCursorPosition(h, c);
}

int main()
{
	Queue Antrian;
	char tekan;
	int terus = 1;
	while (terus == 1)
	{
		system("cls");
		Antrian.printQueue();
		Antrian.gotoxy(1, 1);
		printf("Menu Pilihan		\n");
		printf("1. Tambah Antrian	\n");
		printf("2. Proses Antrian	\n");
		printf("3. Reset Antrian	\n");
		printf("4. Selesai		  \n\n");
		printf("Pilihan Anda [1..4][ ]\b\b");
		tekan = ' ';
		while (!(tekan >= '1' && tekan <= '4'))
		{
			tekan = getch();
		}
		printf("%c\n", tekan);
		switch (tekan)
		{
		case '1':
			Antrian.insQueue();
			break;
		case '2':
			Antrian.procQueue();
			break;
		case '3':
			Antrian.reset();
			break;
		default:
			terus = 0;
		}
	}
	return 0;
}