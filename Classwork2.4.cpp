#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "windows.h"
using namespace std;

struct Stack {
	int arr[10] = {};
	int top = -1;
	void clean() {
		top = -1;
	}
	int peek() {
		return arr[top];
	};
	void push( int type) {
		top++;
		arr[top] = type;
	};
	void pop() {
		top--;
	};
	void show() {
		cout << "[ ]-";
		for(int i=0;i<=top;i++){
			if (arr[i] == 0) { cout << "[груз]"; }
			else if (arr[i] == 1) { cout << "[псжр]"; };
			if (i < top) { cout << "-"; }
		}
		int code=_getch();
	
	};
	void creat() {
		int type=2;
		cout << "Заполняем поезд вагонами"<<endl;
		cout << "0-грузовой; 1-пассажирский" << endl;
		for (int i = 0; i < 10; i++) {
				cin >> type;
			push(type);
		}
	};
};






int menu_start() {
	int key = 0;
	int code;
	do {
		system("cls");
		key = (key + 6) % 6;
		if (key == 0) cout << "-> Заполнить поезд" << endl;
		else  cout << "   Заполнить поезд" << endl;
		if (key == 1) cout << "-> Отсортировать на два" << endl;
		else  cout << "   Остортировать на два" << endl;
		if (key == 2) cout << "-> Показать пассажирский" << endl;
		else  cout << "   Показать пассажирский" << endl;
		if (key == 3) cout << "-> Показать грузовой" << endl;
		else  cout << "   Показать грузовой" << endl;
		if (key == 4) cout << "-> Выход" << endl;
		else  cout << "   Выход" << endl;
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}


int main(bool isRunning)
{
	Stack train, p, c;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	isRunning = true;
	
	while (isRunning)
	{
		int answer = 0;
		answer = menu_start();
		switch (answer)
		{
		case 0:train.creat(); break;
		case 1: {
			p.clean(); c.clean();
			for (int i = 0; i < 10; i++) 
			{
				if (train.peek() == 1)
				{
					p.push(1);
					train.pop();
				}
				else if(train.peek() == 0){
					c.push(0);
					train.pop();
				}
			}
			cout << "Готово";
			break; 
		}
		case 2:p.show(); break;
		case 3:c.show(); break;
		case 4: system("cls"); cout << "Goodbye!\n__________________"; isRunning = false;
		}

	}
	return 0;
}
