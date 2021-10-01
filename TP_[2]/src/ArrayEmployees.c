#include "ArrayEmployees.h"
#include "utn.h"
#include "validaciones.h"
/// \fn int initEmployees(Employee*, int)
/// \brief Inicializa El array de empleados con el espacio isEmpy como TRUE
/// \param list El puntero a la lista de empleados
/// \param len El tamaño de la lista
/// \return -1 si hubo algun error o 0 si se inicializo correctamente
void initEmployees(Employee *list, int len) {

	for (int i = 0; i < len; i++) {
		list[i].isEmpty = 1;
	}

}
/// \fn int generateId(Employee*, int)
/// \brief Genera una id empezando desde el 1
/// \param list Puntero a la lista de empleados
/// \param len El tamaño de la lista
/// \return Devuelve el siguiente numero
int generateId(Employee *list, int len) {
	int i;
	int aux;

	for (i = 0; i < len; i++) {
		if (i == 0 || (list[i].id > aux && list[i].isEmpty != 1)) {
			aux = list[i].id;
		}
	}

	return aux + 1;
}
/// \fn int addEmployee(Employee*, int, int, char[], char[], float, int)
/// \brief Añade un empleado siempre y cuando alla espacio en la lista
/// \param list Puntero a la lista de empleados
/// \param len El tamaño de la lista
/// \param id El espacio donde guardar el id
/// \param name El espacio donde guardar el nombre
/// \param lastName El espacio donde guardar el apellido
/// \param salary El espacio donde guardar el salario
/// \param sector El espacio donde guadar el sector
/// \return -1 Si hubo algun error o no encontro espacio vacio 0 si se añadio correctamente
int addEmployee(Employee *list, int len, int id, char name[], char lastName[],
		float salary, int sector) {
	int retorno;
	retorno = -1;
	id = 1000;
	for (int i = 0; i < len; i++) {
		if (list[i].isEmpty == 1) {
			list[i].id = generateId(list, len);
			get_name(list[i].name, 20, "Ingrese nombre de empleado: ",
					"Nombre no valido", 4);
			get_name(list[i].lastName, 20, "Ingrese apellido de empleado: ",
					"Nombre no valido", 4);
			get_float(&salary, 20, "Ingrese salario de empleado: ",
					"Saliaro invalido ", 1, 200000, 4, 0);
			get_int(&sector, 20, "Ingrese sector de empleado: ",
					"Sector invalido ", 1, 10, 4, 0);
			list[i].salary = salary;
			list[i].sector = sector;
			list[i].isEmpty = 0;
			retorno = 0;
			break;
		}
	}
	return retorno;
}
/// \fn int findEmployeeById(Employee*, int, int)
/// \brief Busca a un empleado por la ID
/// \param list El puntero a la lista a ser buscada
/// \param len El tamaño de la lista
/// \param id El id a ser buscado
/// \return -1 si no pudo ser encontrado o la posicion donde fue encontrada
int findEmployeeById(Employee *list, int len, int id) {
	int retorno;
	retorno = -1;
	for (int i = 0; i < len; i++) {
		if (list[i].isEmpty == 0 && list[i].id == id) {
			retorno = i;
			break;
		}
	}
	return retorno;
}

/// \fn int removeEmployee(Employee*, int, int)
/// \brief Da de baja a un empleado y lo borrar del la lista
/// \param list Puntero a la lista de empleados
/// \param len El tamaño de la lista
/// \param id El id a ser dado de baja
/// \return -1 si hubo algun error o no se encontro el empleado 0 si se dio de baja correctamente
int removeEmployee(Employee *list, int len, int id) {
	int retorno;
	int auxId;
	retorno = -1;
	auxId = findEmployeeById(list, len, id);
	for (int i = 0; i < len; i++) {
		if (list[i].isEmpty == 0 && auxId != -1) {
			list[auxId].isEmpty = 1;
			retorno = 0;
			break;
		}
	}
	return retorno;
}
/// \fn int modifyEmployee(Employee*, int, int)
/// \brief Modifica un empleado por nombre o apellido o salario o sector
/// \param list Puntero a la lista a ser modificada
/// \param len El tamaño de la lista
/// \param id El id a ser modificado
/// \return -1 si hubo un error o no se encontro ese ID 0 si se pudo modificar correctamente
int modifyEmployee(Employee *list, int len, int id) {
	int retorno;
	int answerd;
	int auxSector;
	float auxSalary;
	int index;
	int auxId;
	auxId = findEmployeeById(list, len, id);
	for (int i = 0; i < len; i++) {
		if (list[i].isEmpty == 0 && auxId != -1) {
			get_int(&answerd, 2,
					"1.Nombre\n 2.Apellido\n 3.Salario\n 4.Sector\n 5.Todo\nQue desea modificar?:",
					"Respuesta invalida ", 1, 5, 4, 0);
			index = auxId;
			retorno = 0;
			break;
		}
	}
	switch (answerd) {
	case 1:
		get_name(list[index].name, 20, "Ingrese nuevo nombre: ",
				"Nombre invalido ", 4);
		break;
	case 2:
		get_name(list[index].lastName, 20, "Ingrese nuevo apellido: ",
				"Apellido invalido ", 4);
		break;
	case 3:
		get_float(&auxSalary, 20, "Ingrese nuevo salario: ",
				"Salario invalido ", 1, 200000, 4, 0);
		list[index].salary = auxSalary;
		break;
	case 4:
		get_int(&auxSector, 20, "Ingrese nuevo sector: ", "Sector invalido ", 1,
				10, 4, 0);
		list[index].sector = auxSector;
		break;
	case 5:
		get_name(list[index].name, 20, "Ingrese nuevo nombre: ",
				"Nombre invalido ", 4);
		get_name(list[index].lastName, 20, "Ingrese nuevo apellido: ",
				"Apellido invalido ", 4);
		get_float(&auxSalary, 20, "Ingrese nuevo salario: ",
				"Salario invalido ", 1, 200000, 4, 0);
		list[index].salary = auxSalary;
		get_int(&auxSector, 20, "Ingrese nuevo sector: ", "Sector invalido ", 1,
				10, 4, 0);
		list[index].sector = auxSector;
		break;
	}
	return retorno;
}
/// \fn int sortEmployees(Employee*, int, int)
/// \brief Ordena los empleados por orden alfabetico y sector dependiendo del orden que le asignes
/// \param list El puntero a la lista a ser ordenada
/// \param len El tamaño de la lista
/// \param order 1 orden ascendente 0 descendente
/// \return -1 si hubo algun error o 0 si se ordeno correctamente
int sortEmployees(Employee *list, int len, int order) {
	int retorno;
	Employee auxList;
	retorno = -1;
	if (order == 0) {
		for (int i = 0; i < len - 1; i++) {
			for (int j = i + 1; j < len; j++) {
				if (order == 0
						&& stricmp(list[i].lastName, list[j].lastName) > 0
						&& list[i].sector > list[j].sector) {
					auxList = list[i];
					list[i] = list[j];
					list[j] = auxList;
					retorno = 0;
				}
			}
		}
	}
	if (order == 1) {
		for (int i = 0; i < len - 1; i++) {
			for (int j = i + 1; j < len; j++) {
				if (order == 0
						&& stricmp(list[i].lastName, list[j].lastName) < 0
						&& list[i].sector < list[j].sector) {
					auxList = list[i];
					list[i] = list[j];
					list[j] = auxList;
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}
/// \fn int printEmployees(Employee*, int)
/// \brief Imprime la lista de empleado de manera encolumnada
/// \param list El puntero a la lista a ser impresa
/// \param length El tamaño de la lista
/// \return -1 si hubo algun error 0 si se pudo imprimir correctamente
int printEmployees(Employee *list, int length) {
	int retorno;
	retorno = -1;

	printf("ID\tNAME\t LAST NAME\tSALARY\tSECTOR\n");
	for (int i = 0; i < length; i++) {
		if (list[i].isEmpty == 0) {
			printf("%-5d %-10s %-10s %10.2f %3d\n", list[i].id, list[i].name,
					list[i].lastName, list[i].salary, list[i].sector);
			retorno = 0;
		}
	}
	return retorno;
}
/// \fn int salaryTotal(Employee*, int, float*, float*, int*)
/// \brief Calcula el total, promedio de salario y la cantidad de empleados que superan el promedio salarial
/// \param list Puntero a la lista a ser calculada
/// \param length El tamaño de la lista
/// \param promedy Puntero a donde se guarde el promedio
/// \param total Puntero donde se guarde el total
/// \param quantity Puntero donde se guarde la cantidad de empleados que superan el promedio
/// \return -1 Si hubo algun error 0 si se caculo correctamente
int salaryTotal(Employee *list, int length, float *promedy, float *total,
		int *quantity) {
	int retorno;
	int contador = 0;
	int acumulador = 0;
	float auxSalary;
	float promedio;
	int contadorMasSueldo = 0;
	int index = 0;

	for (int i = 0; i < length; i++) {
		if (list[i].isEmpty == 0) {
			auxSalary = list[i].salary;
			acumulador = auxSalary + acumulador;
			contador++;
			index = i;
			retorno = 0;
		}
	}

	promedio = (float) acumulador / contador;
	if (list[index].salary > promedio) {
		contadorMasSueldo++;
	}

	*promedy = promedio;
	*total = acumulador;
	*quantity = contadorMasSueldo;
	return retorno;
}
