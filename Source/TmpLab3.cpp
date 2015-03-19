#include "Classes.h"

using namespace std;

void main(){

	int n = 0;
	int value = 0;
	int poryadok = 0;

	char operation[5];
	
	///Работа со списками
	cout << "Primer raboty so spiskami." << endl;
	cout << "Operazii:" << endl << "add <poryadok> <value>" << endl << "del <poryadok>" << endl;
	MainList myList;

	/** Получение числа операций */
	cout << "Vvedite kolichestvo operziy:" << endl;
	cin >> n;

	/** Цикл обработки команд 	*/
	for (int i = 0; i < n; i++){
		cout << "Vvedite operziyu " << i + 1 << ":" << endl;
		cin >> operation;
		cin >> poryadok;
		if (!strcmp(operation, "del")){ ///Обработка команды удаления элемента
			myList.delList(poryadok);
		}
		else if (!strcmp(operation, "add")){ ///Обработка команды добавления элемента
			cin >> value;
			myList.addList(poryadok, value);
		}
		fflush(stdin); ///Очистка буфера ввода
	}
	myList.print(); ///Вывод значений
	
	///Работа со стеком
	cout << "-------------------------------------------------" << endl;
	cout << "Primer raboty so stekom." << endl;
	cout << "Operazii:" << endl << "push <value>" << endl << "pop" << endl;
	MainStack myStack;
	cout << "Vvedite kolichestvo operaziy:" << endl;
	cin >> n;
	for (int i = 0; i < n; i++){
		cout << "Vvedite operaziyu " << i + 1 << ":" << endl;
		cin >> operation;
		if (!strcmp(operation, "pop")){
			myStack.delFromStack();
		}
		else if (!strcmp(operation, "push")){
			cin >> value;
			myStack.addToStack(value);
		}
		fflush(stdin);
	}
	myStack.printStack();

	///Работа с очередью
	cout << "-------------------------------------------------" << endl;
	cout << "Primer raboty s otsheredyu." << endl;
	cout << "Operazii:" << endl << "add <value>" << endl << "del" << endl;
	MainLine myLine;
	cout << "Vvedite kolichestvo operaziy:" << endl;
	cin >> n;
	for (int i = 0; i < n; i++){
		cout << "Vvedite operaziyu " << i + 1 << ":" << endl;
		cin >> operation;
		if (!strcmp(operation, "del")){
			myLine.delFromLine();
		}
		else if (!strcmp(operation, "add")){
			cin >> value;
			myLine.addToLine(value);
		}
		fflush(stdin);
	}
	myLine.printLine();
	system("pause");
}
