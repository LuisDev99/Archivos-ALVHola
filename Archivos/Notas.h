#pragma once
#pragma warning(disable : 4996)
#pragma warning(suppress : 4996)
class Notas{
public:
	static void registrarAlumnos();
	static void consultarAlumnos();
	static void registrarMaterias();
	static void consultarMaterias();
	static void registrarNotas();
	static void consultarNotas();
	static int busquedaCodigo_alumno(char *);
	static int busquedacodigo_materia(char *);
	static char* obtenerNombre_alumno(const int);
	static char* obtenerNombre_materia(const int);
	static void calcularPromedioAlumno();
	static void calcularPromedioMAteria();
};