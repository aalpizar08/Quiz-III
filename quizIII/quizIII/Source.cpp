#include <iostream>
#include <conio.h>
using namespace std;

struct Node {//define el nodo
	int number;
	Node* next;
};
void insert(Node*&, int);//insertar
void display(Node*);//mostrar
void search(Node*, int);
int main() {
	Node* list = NULL;
	int option = 0;
	while (option != 3) {
		int number = 0;
		cout << "Menu" << endl;
		cout << "1.- Insertar elementos al final" << endl;
		cout << "2.- Mostrar elementos de la lista" << endl;
		cout << "3.- Buscar elemento en la lista" << endl;
		cout << "4.- Salir" << endl;
		cin >> option;

		switch (option){
		case 1:cout << "Digite su numero: ";
			cin >> number;
			insert(list, number);
			cout << endl;
			system("pause");
			break;
		case 2:
			display(list);
			system("pause");
			break;
		case 3:
			cout << "Digite el numero que desea buscar: " << endl;
			cin >> number;
			search(list, number);
			system("pause");
			break;
		}
		
		system("cls");
	}
	system("PAUSE");
	return 0;
}
void insert(Node*& list, int number) {
	Node* newNode = new Node(); //crear nuevo nodo
	newNode->number = number;//asignar valor al nodo
	newNode->next = nullptr;//el nuevo nodo tiene que apuntar a nulo para que sea el ultimo
	Node* aux1 = list;//auxiliar para recorrer la lista

	if (list == nullptr) {//si la lista esta vacia
		list = newNode;
	}
	else{//recorre la lista hastra el final
		while (aux1->next != nullptr) {
			aux1 = aux1->next;
		}
		aux1->next = newNode;
	}
	
	cout << "Elemento " << number << " agregado correctamente" << endl;
}

void display(Node* list) {
	Node* current = new Node();//crea nuevo nodo
	current = list;
	while (current != NULL) {//recorre la lista hasta el final
		cout << current->number << " -> ";//imprime el valor que esta en este espacio
		current = current->next;//pasa al siguiente
	}
}

void search(Node* list, int number) {
	bool detectNumber = false;//condicional que detecta si esta o no el numero
	Node* current = new Node();//crear nuevo nodo
	current = list;

	while (current->next != nullptr) {//recorre toda la lista
		if (current->number == number) {//condicional para cuando encuentre el numero buscado
			detectNumber = true;//cambia la variable a true
		}
		current = current->next;//mueve al siguiente nodo
	}
	if (!detectNumber) {
		cout << number << " NO esta en la lista" << endl;
	}
	if (detectNumber) {
		cout << number << " SI esta en la lista" << endl;
	}
}
