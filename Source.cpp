#include "function.h"



int main()
{
	
	//Declaracion de variables
	int option;
	int* size;
    int *array_list;
    bool status = true;
	array_list = nullptr;
	size = nullptr;
	size = new int;
	*size = 0;

	while (status) {

		Console::Clear();
		option = menu(); //funcion menu

		switch ( option ){

			case 1: //listar elementos
				element_list(array_list, size); break; 
			  
			case 2: //Añadir elemento al final
				int new_element;
				cout << "Ingrese nuevo elemento : " << endl; cin >> new_element;
				add_end(array_list, size, new_element); break;

			case 3: //Añadir elemento al inicio
				int new_element_t;
				cout << "Ingrese nuevo elemento : " << endl; cin >> new_element_t;
				add_opening(array_list, size, new_element_t); break;

			case 4: //Eliminar posicion
				int eliminator;
				do {
					cout << "Ingrese la posicion a eliminar : " << endl; cin >> eliminator;
				} while (eliminator < 1 ||eliminator > *size + 1);	
				delete_position(array_list, size, eliminator); break;

			case 5: //Modificar posicion 
				int modificator;
				cout << "Ingrese la posicion a modificar : " << endl; cin >> modificator;
				modify_position(array_list, size, modificator);
				; break;

			case 6: //Insertar en posicion  
				int add_position;
				cout << "Ingrese la posicion a insertar : " << endl; cin >> add_position;
				insert_position(array_list, size, add_position); break;

			case 7: //Ordenar de mayor a menor 
				array_list = order_major_minor(array_list, size);
				; break;

			case 0: //Salir
				status = false;
				break;  
		}		

		
		system("pause");
	}
	return 0;
};
