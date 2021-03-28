#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;
using namespace System;


int menu() {
	int op;
	Console::Clear();
	do
	{
		cout << "             MENU            " << endl << endl;
		cout << "1.-LISTAR ELEMENTOS" << endl;
		cout << "2.-AGREGAR AL FINAL" << endl;
		cout << "3.-AGREGAR AL INICIO" << endl;
		cout << "4.-ELIMINAR EN LA POSICION" << endl;
		cout << "5.-MODIFICAR EN POSICION" << endl;
		cout << "6.-INSERTAR EN POSICION" << endl;
		cout << "7.-ORDENAR DE MAYOR A MENOR" << endl << endl;
		cout << "0.-SALIR" << endl << endl;
		cout << "Elija una Opcion: ";
		cin >> op;
	} while (op < 0 ||op > 7);
	return op;
}

//listar elementos
void element_list(int *array_list, int *size) {
	if (array_list != nullptr) {
		for (short i = 0; i < *size; i++) {
			cout << array_list[i] << endl;
		}
	}
	else cout << "El arreglo no tiene elementos" << endl ;
}

//Añadir elementos al final
void add_end(int* &array_list, int* size , int new_element) {
		int* temp = new int [*size + 1];
	if (temp != nullptr) {
		for (int i = 0; i < *size; i++) {
			temp[i] = array_list[i];
		}
		temp[*size] = new_element;
		*size += 1;
		if (array_list != nullptr) delete[]array_list;

		array_list = temp;
	}
}

void add_opening(int*& array_list, int* size, int new_element_t) {
	int* temp = new int[*size + 1];
	if (temp != nullptr) {

		temp[0] = new_element_t;

		for (int i = 0; i < *size; i++) {
			temp[i + 1] = array_list[i];
		}

		*size += 1;
		if (array_list != nullptr) delete[]array_list;

		array_list = temp;
	}
}

void delete_position(int* array_list, int* size, int eliminator) {
	int a = *size, i;
	eliminator--;
	
	if (array_list != nullptr) {
			
		for ( i = 0; i < a; i++) {
			if (i == eliminator) {
				while (i < a) {
					array_list[i] = array_list[i + 1];
					i++;
				}
				break;
			}
		}
		
		*size -= 1;
		
		cout << endl << " El elemento a sido eliminado con exito " << endl;
			
	}
	else cout << "El arreglo no tiene elementos" << endl;
}

void modify_position(int* array_list, int* size, int modificator) {
	int a = *size, i, new_valor_m;
	modificator--;

	if (array_list != nullptr) {
		cout << endl << "Ingrese valor : " << endl; cin >> new_valor_m;
		for (i = 0; i < a; i++) {
			if (i == modificator) {
				array_list[i] = new_valor_m;
				break;
			}
		}

		cout << endl << " El elemento a sido modificado con exito " << endl;

	}
	else cout << "El arreglo no tiene elementos" << endl;
}

void insert_position(int* array_list, int* size, int add_position) {
	int* temp = new int[*size + 1];
	int new_valor_p;
	add_position--;
	if (array_list != nullptr) {
		cout << endl << "Ingrese nuevo valor : " << endl; cin >> new_valor_p;
		for (int i = 0; i < *size + 1; i++) {
			if (i >= add_position) {
				if (i == add_position) {
					temp[i] = new_valor_p;
				}
				else {
					temp[i] = array_list[i - 1];
				}
				break;
			}
			else {
				temp[i] = array_list[i];
			}
		}
		*size += 1;
		if (array_list != nullptr) delete[]array_list;
		
		array_list = temp;
		cout << endl << "El elemento a sido añadido en la nueva posicion con exito" << endl;
		
	}
	else {
		cout<<endl<<"El arreglo no tiene elementos" << endl; 
	}
}

int*  order_major_minor(int* array_list, int* size) {
	int temp;
	if (array_list != nullptr) {
		for (short i = 0; i < *size; i++) {
			for (short j = 0; j < *size - 1; j++) {
				if (array_list[i] > array_list[j]) 
				{
					temp = array_list[i];
					array_list[i] = array_list[j];
					array_list[j] = temp;
				}
			}
		}
		cout << "La lista a sido ordenada" << endl;
		return array_list;
	}
	else cout << "El arreglo no tiene elementos" << endl;
}

