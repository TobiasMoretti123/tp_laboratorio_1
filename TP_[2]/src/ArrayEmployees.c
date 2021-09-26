#include "ArrayEmployees.h"
#include "utn.h"
#include "validaciones.h"
/// \fn int initEmployees(Employee*, int)
/// \brief Inicializa El array de empleados con el espacio isEmpy como TRUE
/// \param list El puntero a la lista de empleados
/// \param len El tamaño de la lista
/// \return -1 si hubo algun error o 0 si se inicializo correctamente
int initEmployees(Employee *list, int len) {
	int retorno;
	if (list == NULL || len < 0) {
		retorno = -1;
	} else {
		for (int i = 0; i < len; i++) {
			list[i].isEmpty = 1;
		}
	}
	return retorno;
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
	if (list == NULL || len < 0) {
		retorno = -1;
	} else {
		for (int id = 0; id < len; id++) {
			if (list[id].isEmpty == 1) {
				list[id].id = id + 1;
				get_name(list[id].name, 20, "Ingrese nombre de empleado: ",
						"Nombre no valido", 4);
				get_name(list[id].lastName, 20,
						"Ingrese apellido de empleado: ", "Nombre no valido",
						4);
				get_float(&salary, 20, "Ingrese salario de empleado: ",
						"Saliaro invalido ", 1, 200000, 4, 0);
				get_int(&sector, 20, "Ingrese sector de empleado: ",
						"Sector invalido ", 1, 10, 4, 0);
				list[id].salary = salary;
				list[id].sector = sector;
				list[id].isEmpty = 0;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
/// \fn int findEmployeeById(Employee*, int, int)
/// \brief Busca a un empleado por la ID
/// \param list El puntero a la lista a ser buscada
/// \param len El tamaño de la lista
/// \param id El id a ser buscado
/// \return -1 si no pudo ser encontrado o 0 si se pudo encontrar
int findEmployeeById(Employee *list, int len, int id) {
	int retorno;
	if (list == NULL || len < 0) {
		retorno = -1;
	}
	for (int i = 0; i < len; i++) {
		if (list[i].id == id) {
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
	if (list == NULL || len < 0) {
		retorno = -1;
	} else {
		id = findEmployeeById(list, len, id);
	}
	for (int i = 0; i < len; i++) {
		if (list[id].isEmpty == 0) {
			list[id].isEmpty = 1;
			retorno = 0;
			break;
		} else {
			retorno = -1;
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
	int respuesta;
	int auxSector;
	float auxSalary;
	int index;
	if (list == NULL || len > 0) {
		retorno = -1;
	} else {
		id = findEmployeeById(list, len, id);
	}
	for (int i = 0; i < len; i++) {
		if (list[i].id == id) {
			get_int(&respuesta, 2,
					"Que desea modificar? 1.Nombre 2.Apellido 3.Salario 4.Sector: ",
					"Respuesta invalida ", 1, 4, 4, 0);
			index = i;
			retorno = 0;
			break;
		} else {
			retorno = -1;
		}
	}
	switch (respuesta) {
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
	if (list == NULL || len < 0 || (order < 0 && order > 1)) {
		retorno = -1;
	}
	if (order == 0) {
		for (int i = 0; i < len - 1; i++) {
			for (int j = i + 1; j < len; j++) {
				if (order == 0 && list[i].sector > list[j].sector
						&& stricmp(list[i].lastName, list[j].lastName) > 0) {
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
				if (order == 0 && list[i].sector < list[j].sector
						&& stricmp(list[i].lastName, list[j].lastName) < 0) {
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
	if (list == NULL || length < 0) {
		retorno = -1;
	}
	sortEmployees(list, length, 0);
	printf("ID\tNAME\tLAST NAME\tSALARY\tSECTOR\n");
	for (int i = 0; i < length; i++) {
		if (list[i].isEmpty == 0) {
			printf("%-2d% -10s% -10s% -10.2f% -4d\n", list[i].id, list[i].name,
					list[i].lastName, list[i].salary, list[i].sector);
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
	if (list == NULL
			|| length
					< 0|| promedy==NULL || total == NULL || quantity == NULL) {
		retorno = -1;
	} else {
		for (int i = 0; i < length; i++) {
			if (list[i].isEmpty == 0) {
				auxSalary = list[i].salary;
				acumulador = auxSalary + acumulador;
				contador++;
				index = i;
				retorno = 0;
			}
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

