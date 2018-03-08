#include <conio.h>
#include <iostream>
#include "Notas.h"

#pragma warning(disable : 4996)
#pragma warning(suppress : 4996)

using namespace std;

void main(){
	

	//Notas::registrarAlumnos(); //1
	//notas.consultarAlumnos(); //2
	//notas.registrarMaterias(); 3
	//notas.consultarMaterias(); 4
	//notas.registrarMaterias(); 5
	//notas.registrarNotas(); 6
	Notas::consultarNotas(); 

	int menu = 0;

	//do {

	//	cout << "1. Registrar el Alumno\n2. Consultar Alumno\n3. Registrar Materias\n4. Consultar Materias\n";
	//	cout << "5. Registrar Notas\n6. Consultar Notas\n7. Calcular Promedio de Notas por Alumno\n8. Calcular el promedio de notas por materia";
	//	cin >> menu;


	//	switch (menu)
	//	{
	//	case 1:

	//		break;
	//	case 2:
	//		break;
	//	case 3:
	//		break;
	//	case 4:
	//		break;
	//	case 5:
	//		break;
	//	case 6:
	//		break;
	//	case 7:
	//		break;
	//	case 8:
	//		break;
	//	default:
	//		break;
	//	}


	//} while (menu != 9);




	system("pause");
		
}