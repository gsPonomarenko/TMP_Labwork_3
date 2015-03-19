#include <iostream>


using namespace std;


struct List{
	int a; //!< Поле значения
	List* next; //!< Указатель на следующий элемент списка
};

class MainList{
public:
	List* head;

	MainList::MainList(){
		head = 0;
	}
	MainList::~MainList(){
		List* tempNext;
		List* temp = head;

		while (temp){
			tempNext = temp->next;
			delete temp;
			temp = tempNext;
		}
	}

	/** addList -- метод добавления элемента
	    delList -- метод удаления элемента
		print -- метод вывода значений на печать
	*/
	void addList(int poryadok, int value);
	void delList(int);
	void print();

};


void MainList::addList(int poryadok, int value){
	int j = 1;

	List* current;
	List* temp;

	current = new List;
	current->a = value;

	if (head == 0){
		current->next = 0;
	}
	else{
		temp = head;
		for (j = 1; j < poryadok; j++){
			temp = temp->next;

		}
		current->next = temp;
	}

	if (poryadok == 1)
		head = current;
	else {
		temp = head;
		for (int i = 1; i < (poryadok - 1); i++){
			temp = temp->next;
		}
		temp->next = current;

	}
}
void MainList::delList(int poryadok){

	List* temp;
	List* tempNext;
	int i = 1;
	temp = head;

	for (; i < poryadok; i++){
		temp = temp->next;
	}

	tempNext = temp->next;
	delete temp;
	temp = head;

	if (poryadok == 1){
		head = tempNext;
	}
	else{
		for (int j = 1; j < (poryadok - 1); j++){
			temp = temp->next;
		}
		temp->next = tempNext;
	}
}
void MainList::print(){
	if (head != 0){
		List* temp = head;
		cout << temp->a << " ";
		while (temp->next){
			temp = temp->next;
			cout << temp->a << " ";
		}
	}
	cout << endl;
}

class MainStack{
public:
	List* head;

	MainStack::MainStack(){
		head = 0;
	}
	MainStack::~MainStack(){
		List* tempNext;
		List* temp = head;

		while (temp){
			tempNext = temp->next;
			delete temp;
			temp = tempNext;
		}
	}
	
	/** addToStack -- метод добавления элемента в стек
	delFromStack -- метод удаления элемента из стека
	printStack -- метод вывода значений на печать
	*/
	void addToStack(int);
	void delFromStack();
	void printStack();

};

void MainStack::addToStack(int value){

	List* current;

	current = new List;
	current->a = value;

	if (head == 0){
		current->next = 0;
	}
	else{
		current->next = head;
	}
	head = current;
}
void MainStack::delFromStack(){
	List* temp;

	temp = head;
	head = head->next;

	delete temp;
}
void MainStack::printStack(){
	if (head != 0){
		List* temp = head;
		cout << temp->a << " ";
		while (temp->next){
			temp = temp->next;
			cout << temp->a << " ";
		}
	}
	cout << endl;
}


class MainLine{
public:
	int* ptr;
	int size;

	MainLine::MainLine(){
		ptr = 0;
		size = 0;
	}
	MainLine::~MainLine(){
		if (ptr != 0)
			delete[] ptr;
	}
	/** addToLine -- метод добавления элемента в очередь
	delFromline -- метод удаления элемента из очереди
	printLine -- метод печати очереди
	*/
	void addToLine(int value);
	void delFromLine();
	void printLine();
};

void MainLine::addToLine(int value){
	int* ptrTemp = 0;
	ptrTemp = new int[size + 1];
	ptrTemp[0] = value;
	for (int i = 0; i < size; i++){
		ptrTemp[i + 1] = ptr[i];
	}
	size++;
	if (ptr != 0){
		delete[] ptr;
	}
	ptr = ptrTemp;

}

void MainLine::delFromLine(){
	int* ptrTemp = 0;
	ptrTemp = new int[size - 1];
	for (int i = 0; i < (size - 1); i++){
		ptrTemp[i] = ptr[i];
	}
	size--;
	if (ptr != 0){
		delete[] ptr;
	}
	ptr = ptrTemp;
}

void MainLine::printLine(){
	if (ptr != 0){
		for (int i = 0; i < size; i++){
			cout << ptr[i] << " ";
		}
	}
	cout << endl;
}
