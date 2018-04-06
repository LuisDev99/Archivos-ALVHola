//header
#include "Notas.h"
//librerias
#include <stdlib.h>
#include <fstream>
#include <iostream>
#pragma warning(disable : 4996)
#pragma warning(suppress : 4996)

using namespace std;

void Notas::registrarAlumnos(){
	ofstream archivoAlumnos("alumnos.dat", ios::app); 
	if (!archivoAlumnos){
		cout << "No se pudo abrir el archivo." << endl;
	}
	else{
		int cuenta, edad, cantidad;
		char nombre[50];

		cout << "****INGRESO DE ALUMNOS***" << endl;
		cout << "Cantidad de alumnos a ingresar: ";
		cin >> cantidad;
		cout << endl;
		for (int i = 0; i < cantidad; i++)	{
			cout << "Numero de cuenta: ";
			cin >> cuenta;
			cout << "\nIngrese el nombre: ";
			cin >> nombre;
			cout << "\nIngrese la edad: ";
			cin >> edad;
			archivoAlumnos <<cuenta << ' '<< nombre << ' '<< edad << endl;
			cout << endl;
		}
	}

	archivoAlumnos.close();
}

void Notas::consultarAlumnos(){
	ifstream archivoAlumnos("alumnos.dat", ios::in);

	
	if (!archivoAlumnos){
		cout << "Error al intentar abrir el archivo." << endl;
		return;
	}

	int cuenta, edad;
	char nombre[50];

	cout << " **** CONSULTA DE ALUMNOS ****" << endl;
	archivoAlumnos.seekg(0, ios::beg);
	while (archivoAlumnos >> cuenta >> nombre >> edad){
		cout << "Cuenta: "<<cuenta<<','<<" Nombre: "<<nombre<<','<<" Edad: "<<edad<<endl;
	}
	archivoAlumnos.close();
}

void Notas::registrarMaterias(){
	ofstream archivoMaterias("Materias.dat", ios::app);

	if (!archivoMaterias){
		cout << "No se pudo abrir el archivo." << endl;
		return;
	}
	else{
		int cantidad, codigo;
		char nombre[30];

		cout << "****INGRESO DE MATERIAS****" << endl;

		cout << "Ingrese la cantidad de materias: ";
		cin >> cantidad;
		cout << endl;
		for (int i = 0; i < cantidad; i++){
			cout << "Ingrese el codigo de la materia: ";
			cin >> codigo;
			cout << "\nIngrese el nombre de la materia: ";
			cin >> nombre;
			cout << endl;

			archivoMaterias << codigo << ' ' << nombre << endl;
		}
	}

	archivoMaterias.close();
}

void Notas::consultarMaterias(){
	ifstream archivoMaterias("Materias.dat", ios::in);

	if (!archivoMaterias){
		cout << "No se pudo leer el archivo." << endl;
		return;
	}

	cout << "**** REPORTE DE ARCHIVOS****" << endl;

	int codigo;
	char nombre[30];
	archivoMaterias.seekg(0, ios::beg);

	while (archivoMaterias >> codigo >> nombre){
		cout << "Codigo de materia: " << codigo << ", Nombre de materia: " << nombre << endl;
	}
}

void Notas::registrarNotas(){
	ofstream archivoNotas("Notas.dat", ios::app);

	if (!archivoNotas){
		cout << "No se pudo crear el archivo. " << endl;
		return;
	}

	cout << "****  INGRESO DE MATERIAS ***" << endl;

	int opcion = 0;
	int nota = 0;
	do{
		char nombreMateria[30];
		char nombreAlumno[50];
		int codigoMateria = 0;
		int codigoAlumno = 0;

		do{
			cout << "Ingrese el nombre de la materia: ";
			cin >> nombreMateria;
			codigoMateria = busquedacodigo_materia(nombreMateria);
		} while (codigoMateria==-1);

		do{
			cout << "Ingrese el nombre del alumno: ";
			cin >> nombreAlumno;
			codigoAlumno = busquedaCodigo_alumno(nombreAlumno);
		} while (codigoAlumno == -1);

		cout << "Ingrese la nota: ";
		cin >> nota;

		archivoNotas << codigoMateria << ' ' << codigoAlumno << ' ' << nota << endl;
		opcion = -1;
	} while (opcion != -1);
	archivoNotas.close();
}

int Notas::busquedacodigo_materia(char *nombreMateria){
	ifstream archivoMateria("Materias.dat", ios::app);

	if (!archivoMateria){
		cout << "No se pudo leer el archivo." << endl;
		return -1;
	}

	archivoMateria.seekg(0, ios::beg);
	int codigo;
	char nombre[30];

	while (archivoMateria >> codigo >> nombre){
		if (strcmp(nombre, nombreMateria) == 0){
			archivoMateria.close();
			return codigo;
		}
	}

	return -1;
}

int Notas::busquedaCodigo_alumno(char *nombreAlumno){
	ifstream archivoAlumno("alumnos.dat", ios::app);

	if (!archivoAlumno){
		cout << "No se pudo leer el archivo." << endl;
		return -1;
	}

	int codigo, edad;
	char nombre[30];

	archivoAlumno.seekg(0, ios::beg);
	while (archivoAlumno >> codigo >> nombre >> edad){
		if (strcmp(nombreAlumno, nombre) == 0){
			archivoAlumno.close();
			return codigo;
		}
	}
	return -1;
}

char* Notas::obtenerNombre_alumno(const int codigoAlumno){
	ifstream archivoAlumno("alumnos.dat", ios::app);

	if (!archivoAlumno){
		cout << "No se pudo abrir el archivo" << endl;
		return nullptr;
	}

	int codigo, edad;
	char nombre[50];

	while (archivoAlumno >> codigo >> nombre>>edad){
		if (codigo == codigoAlumno){
			char *retorno = new char[strlen(nombre)];
			std::strcpy(retorno, nombre);
			retorno[strlen(nombre)] = '\0';
			archivoAlumno.close();
			return retorno;
		}
	}

	archivoAlumno.close();
	return NULL;
}


void Notas::consultarArchivo() {
	ifstream archivoNotas("Notas.dat", ios::in);

	if (!archivoNotas) {
		cout << "No se pudo abrir el archivo." << endl;
		return;
	}

	int codigoMateria, codigoAlumno, nota;

	archivoNotas.seekg(0, ios::beg);

	while (archivoNotas >> codigoMateria >> codigoAlumno >> nota) {
		cout << "Nota de materia: " << obtenerNombre_materia(codigoMateria) << ", Nombre de alumno: " << obtenerNombre_alumno(codigoAlumno) << ", Nota: " << nota;
	}
}

char* Notas::obtenerNombre_materia(const int codigoMateria){
	ifstream archivoAlumno("Materias.dat", ios::app);

	if (!archivoAlumno){
		cout << "No se pudo abrir el archivo" << endl;
		return nullptr;
	}

	int codigo, edad;
	char nombre[50];

	while (archivoAlumno >> codigo >> nombre >> edad){
		if (codigo == codigoMateria){
			char *retorno = new char[strlen(nombre)];
			strcpy(retorno, nombre);
			retorno[strlen(nombre)] = '\0';
			archivoAlumno.close();
			return retorno;
		}
	}

	archivoAlumno.close();
	return NULL;
}




void Notas::consultarNotas(){
	ifstream archivoNotas("Notas.dat", ios::in);

	if (!archivoNotas){
		cout << "No se pudo abrir el archivo." << endl;
		return;
	}

	int codigoMateria, codigoAlumno, nota;

	archivoNotas.seekg(0, ios::beg);

	while (archivoNotas >> codigoMateria >> codigoAlumno >> nota){
		cout << "Nota de materia: " << obtenerNombre_materia(codigoMateria) << ", Nombre de alumno: " << obtenerNombre_alumno(codigoAlumno) << ", Nota: " << nota;
	}
}