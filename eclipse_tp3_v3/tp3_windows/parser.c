#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
/// \fn int parser_EmployeeFromText(FILE*, LinkedList*)
/// \brief
/// \param pFile
/// \param pArrayListEmployee
/// \return
int parser_EmployeeFromText(FILE *pFile, LinkedList *pArrayListEmployee) {
	Employee *pAux;
	int r;
	int retorno;
	char nombre[50];
	char horasTrabajadas[50];
	char id[50];
	char sueldo[50];
	retorno = -1;
	if (pFile != NULL && pArrayListEmployee != NULL) {
		r = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre,
				horasTrabajadas, sueldo);
		do {
			r = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre,
					horasTrabajadas, sueldo);
			if (r == 4) {
				pAux = employee_newParametros(id, nombre, horasTrabajadas,
						sueldo);
				if (ll_add(pArrayListEmployee, pAux) == -1) {
					employee_delete(pAux);
				} else {
					retorno = 0;
				}
			} else
				break;
		} while (!feof(pFile));
	}
	return retorno;
}
/// \fn int parser_EmployeeFromBinary(FILE*, LinkedList*)
/// \brief
/// \param pFile
/// \param pArrayListEmployee
/// \return
int parser_EmployeeFromBinary(FILE *pFile, LinkedList *pArrayListEmployee) {
	Employee *pAux;
	int retorno;
	retorno = -1;
	if (pFile != NULL && pArrayListEmployee != NULL) {
		do {
			pAux = employee_new();
			fread(pAux, sizeof(Employee), 1, pFile);
			if (!feof(pFile)) {
				if (ll_add(pArrayListEmployee, pAux) == -1) {
					employee_delete(pAux);
				}
			}
			retorno = 0;
		} while (!feof(pFile));
	}
	return retorno;
}
/// \fn int parser_EmployeeToText(FILE*, LinkedList*)
/// \brief
/// \param pFile
/// \param pArrayListEmployee
/// \return
int parser_EmployeeToText(FILE *pFile, LinkedList *pArrayListEmployee) {
	Employee *pAux;
	int retorno;
	int i;
	int id;
	char nombre[128];
	int sueldo;
	int horas;
	int largo;
	largo = ll_len(pArrayListEmployee);
	fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");
	for (i = 0; i < largo; i++) {
		pAux = (Employee*) ll_get(pArrayListEmployee, i);
		if (pAux == NULL) {
			break;
		}
		employee_getId(pAux, &id);
		employee_getNombre(pAux, nombre);
		employee_getSueldo(pAux, &sueldo);
		employee_getHorasTrabajadas(pAux, &horas);
		fprintf(pFile, "%d,%s,%d,%d\n", id, nombre, horas, sueldo);
	}
	if (i == largo) {
		retorno = 0;
	} else {
		retorno = -1;
	}
	return retorno;
}
/// \fn int parser_EmployeeToBinary(FILE*, LinkedList*)
/// \brief
/// \param pFile
/// \param pArrayListEmployee
/// \return
int parser_EmployeeToBinary(FILE *pFile, LinkedList *pArrayListEmployee) {
	Employee *pAux;
	int retorno;
	int largo;
	int i;
	retorno = -1;
	if (pFile != NULL && pArrayListEmployee != NULL) {
		largo = ll_len(pArrayListEmployee);
		for (i = 0; i < largo; i++) {
			pAux = ll_get(pArrayListEmployee, i);
			fwrite(pAux, sizeof(Employee), 1, pFile);
		}
		retorno = 0;
	}
	return retorno;
}
