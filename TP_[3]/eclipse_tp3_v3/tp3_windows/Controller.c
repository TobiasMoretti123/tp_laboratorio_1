#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"
#include "validaciones.h"
#include "parser.h"
#include "Controller.h"
/// \fn int controller_loadFromText(char*, LinkedList*)
/// \brief
/// \param path
/// \param pArrayListEmployee
/// \return
int controller_loadFromText(char *path, LinkedList *pArrayListEmployee) {
	FILE *pArchivo;
	int retorno;
	retorno = -1;
	if (path != NULL && pArrayListEmployee != NULL) {
		pArchivo = fopen(path, "r");
		if (parser_EmployeeFromText(pArchivo, pArrayListEmployee) == 0) {
			retorno = 0;
		}
	}
	fclose(pArchivo);
	return retorno;
}
/// \fn int controller_loadFromBinary(char*, LinkedList*)
/// \brief
/// \param path
/// \param pArrayListEmployee
/// \return
int controller_loadFromBinary(char *path, LinkedList *pArrayListEmployee) {
	FILE *pArchivo;
	int retorno;
	retorno = -1;
	if (path != NULL && pArrayListEmployee != NULL) {
		pArchivo = fopen(path, "rb");
		if (parser_EmployeeFromBinary(pArchivo, pArrayListEmployee) == 0) {
			retorno = 0;
		}
	}
	fclose(pArchivo);
	return retorno;
}
/// \fn int controller_addEmployee(LinkedList*)
/// \brief
/// \param pArrayListEmployee
/// \return
int controller_addEmployee(LinkedList *pArrayListEmployee) {
	Employee *pEmpleado;
	int auxId;
	char auxNombre[50];
	int auxHoras;
	int auxSueldo;
	int retorno;
	retorno = -1;
	if (pArrayListEmployee != NULL
			&& utn_getName(auxNombre, 50, "Ingrese nombre: ",
					"Nombre invalido ", 4) == 1
			&& utn_getInt(&auxHoras, 20, "Ingrese horas trabajadas: ",
					"Hora invalida ", 0, 10000, 4, 0) == 1
			&& utn_getInt(&auxSueldo, 20, "Ingrese sueldo: ",
					"Sueldo invalida ", 0, 1000000, 4, 0) == 1) {
		auxId = controller_generateID(pArrayListEmployee);
		if (auxId != -1) {
			pEmpleado = employee_newParametrosConDato(&auxId, auxNombre,
					&auxHoras, &auxSueldo);
			if (pEmpleado != NULL) {
				ll_add(pArrayListEmployee, pEmpleado);
				retorno = 0;
			} else {
				employee_delete(pEmpleado);
			}
		}
	}
	return retorno;
}
/// \fn int controller_editEmployee(LinkedList*)
/// \brief
/// \param pArrayListEmployee
/// \return
int controller_editEmployee(LinkedList *pArrayListEmployee) {
	Employee *pAux;
	int posicion;
	int retorno;
	retorno = -1;
	controller_ListEmployee(pArrayListEmployee);
	if (pArrayListEmployee != NULL
			&& utn_getInt(&posicion, 20, "Que posicion desea modificar?: ",
					"Posicion invalida ", 1, 10000, 4, 0) == 1) {
		pAux = (Employee*) ll_get(pArrayListEmployee, posicion - 1);
		if (employee_edit(pAux) == 0 && pAux != NULL) {
			retorno = 0;
		}
	}
	return retorno;
}
/// \fn int controller_removeEmployee(LinkedList*)
/// \brief
/// \param pArrayListEmployee
/// \return
int controller_removeEmployee(LinkedList *pArrayListEmployee) {
	Employee *pEmpleado;
	int retorno;
	int posicion;
	retorno = -1;
	controller_ListEmployee(pArrayListEmployee);
	if (pArrayListEmployee != NULL) {
		if (utn_getInt(&posicion, 20,
				"Ingrese la posicion que desee dar de baja: ",
				"Posicion invalida ", 1, 10000, 4, 0) == 1) {
			pEmpleado = (Employee*) ll_get(pArrayListEmployee, posicion - 1);
			if (employee_remove(pEmpleado) == 0 && pEmpleado != NULL) {
				ll_remove(pArrayListEmployee, posicion - 1);
				employee_delete(pEmpleado);
				retorno = 0;
			}
		}
	}
	return retorno;
}
/// \fn int controller_ListEmployee(LinkedList*)
/// \brief
/// \param pArrayListEmployee
/// \return
int controller_ListEmployee(LinkedList *pArrayListEmployee) {
	Employee *pAux;
	int retorno;
	int len;
	retorno = -1;
	printf(" ________ ________ _______________ ______ _______ \n");
	printf("|POSICION|ID      |NOMBRE         |HORAS |SUELDO |\n");
	if (pArrayListEmployee != NULL) {
		len = ll_len(pArrayListEmployee);
		for (int i = 0; i < len; i++) {
			pAux = (Employee*) ll_get(pArrayListEmployee, i);
			if (employee_print(pAux, i) == 0) {
				retorno = 0;
			}
		}
	}
	return retorno;
}
/// \fn int controller_sortEmployee(LinkedList*)
/// \brief
/// \param pArrayListEmployee
/// \return
int controller_sortEmployee(LinkedList *pArrayListEmployee) {
	int retorno;
	int orden;
	int respuesta;
	retorno = -1;
	if (pArrayListEmployee != NULL
			&& utn_getInt(&respuesta, 2,
					"1)Ordenar por id\n2)Ordenar por nombre\n3)Ordenar por horas trabajadas\n4)Ordenar por sueldo\nComo quiere ordenar la lista?: ",
					"Opcion invalido", 1, 4, 4, 0) == 1
			&& utn_getInt(&orden, 2,
					"Si desea ordenar de mayor a menor(A-Z) ingrese 0\nSi desea ordenar de menor a mayor(Z-A) ingrese 1\nIngrese: ",
					"Ingreso invalido", 0, 1, 4, 0) == 1) {
		switch (respuesta) {
		case 1:
			ll_sort(pArrayListEmployee, employee_compareByID, orden);
			break;
		case 2:
			ll_sort(pArrayListEmployee, employee_compareByName, orden);
			break;
		case 3:
			ll_sort(pArrayListEmployee, employee_compareByWorkingHours, orden);
			break;
		case 4:
			ll_sort(pArrayListEmployee, employee_compareBySalary, orden);
			break;
		}
		retorno = 0;
	}
	return retorno;
}
/// \fn int controller_saveAsText(char*, LinkedList*)
/// \brief
/// \param path
/// \param pArrayListEmployee
/// \return
int controller_saveAsText(char *path, LinkedList *pArrayListEmployee) {
	FILE *pArchivo;
	int retorno;
	retorno = -1;
	if (path != NULL && pArrayListEmployee != NULL
			&& ll_isEmpty(pArrayListEmployee) == 0) {
		pArchivo = fopen(path, "w");
		if (parser_EmployeeToText(pArchivo, pArrayListEmployee) == 0) {
			retorno = 0;
		}
	}
	fclose(pArchivo);
	return retorno;
}
/// \fn int controller_saveAsBinary(char*, LinkedList*)
/// \brief
/// \param path
/// \param pArrayListEmployee
/// \return
int controller_saveAsBinary(char *path, LinkedList *pArrayListEmployee) {
	FILE *pArchivo;
	int retorno;
	retorno = -1;
	if (path != NULL && pArrayListEmployee != NULL
			&& ll_isEmpty(pArrayListEmployee) == 0) {
		pArchivo = fopen(path, "wb");
		if (parser_EmployeeToBinary(pArchivo, pArrayListEmployee) == 0) {
			retorno = 0;
		}
	}
	fclose(pArchivo);
	return retorno;
}
/// \fn int controller_generateID(LinkedList*)
/// \brief
/// \param pArrayListEmployee
/// \return
int controller_generateID(LinkedList *pArrayListEmployee) {
	Employee *pAux;
	int len;
	int i;
	int id;
	id = -1;
	if (pArrayListEmployee != NULL) {
		len = ll_len(pArrayListEmployee);
		for (i = 0; i < len; i++) {
			pAux = (Employee*) ll_get(pArrayListEmployee, i);
		}
		if (pAux != NULL && i != 0) {
			employee_getId(pAux, &id);
			employee_setId(pAux, id++);
		}
	}
	return id;
}

