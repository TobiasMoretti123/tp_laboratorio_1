#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "utn.h"
#include "validaciones.h"
/// \fn Employee employee_new*()
/// \brief Inicializa todos los campos del empleado en 0
/// \return El empleado inicializado
Employee* employee_new() {
	Employee *pEmpleado;
	pEmpleado = (Employee*) calloc(sizeof(Employee), 1);
	return pEmpleado;
}
/// \fn Employee employee_newParametros*(char*, char*, char*, char*)
/// \brief carga el empleado con los parametros ingresados como char
/// \param idStr La cadena de caracteres del id
/// \param nombreStr La cadena de caracteres del nombre
/// \param horasTrabajadasStr La cadena de caracteres de las horas trabajadas
/// \param sueldoStr La cadena de caracteres del sueldo
/// \return El empleado con los parametros cargados
Employee* employee_newParametros(char *idStr, char *nombreStr,
		char *horasTrabajadasStr, char *sueldoStr) {
	Employee *pEmpleado;
	pEmpleado = employee_new();
	if (pEmpleado != NULL && idStr != NULL && nombreStr != NULL
			&& horasTrabajadasStr != NULL && sueldoStr != NULL) {
		if (employee_setId(pEmpleado, atoi(idStr)) == -1
				|| employee_setNombre(pEmpleado, nombreStr) == -1
				|| employee_setHorasTrabajadas(pEmpleado,
						atoi(horasTrabajadasStr)) == -1
				|| employee_setSueldo(pEmpleado, atoi(sueldoStr)) == -1)
			employee_delete(pEmpleado);
	}
	return pEmpleado;
}
/// \fn Employee employee_newParametrosConDato*(int*, char*, int*, int*)
/// \brief carga el empleado con los parametros ingresados con los valores reales
/// \param id El id a cargar
/// \param nombre El nombre a cargar
/// \param horasTrabajadas Las horas trabajadas a cargar
/// \param sueldo El sueldo a cargar
/// \return El empleado cargado
Employee* employee_newParametrosConDato(int *id, char *nombre,
		int *horasTrabajadas, int *sueldo) {
	Employee *pEmpleado;
	if (id != NULL && nombre != NULL && horasTrabajadas != NULL
			&& sueldo != NULL) { // validar si falla delete
		pEmpleado = employee_new();
		if (pEmpleado == NULL || employee_setId(pEmpleado, *id) == -1
				|| employee_setNombre(pEmpleado, nombre) == -1
				|| employee_setHorasTrabajadas(pEmpleado, *horasTrabajadas)
						== -1 || employee_setSueldo(pEmpleado, *sueldo) == -1) {
			employee_delete(pEmpleado);
		}
	}
	return pEmpleado;
}
/// \fn void employee_delete(Employee*)
/// \brief Borra el empleado
/// \param this el empleado a borrar
void employee_delete(Employee *this) {
	if (this != NULL) {
		free(this);
	}
}
/// \fn int employee_setId(Employee*, int)
/// \brief Coloca el id igresado en el cliente
/// \param this el empleado a colocar el id
/// \param id El id a colocar
/// \return -1 si hubo error 0 si no
int employee_setId(Employee *this, int id) {
	int retorno;
	retorno = -1;
	if (this != NULL && id > 0) {
		this->id = id;
		retorno = 0;
	}
	return retorno;
}
/// \fn int employee_getId(Employee*, int*)
/// \brief
/// \param this
/// \param id
/// \return
int employee_getId(Employee *this, int *id) {
	int retorno;
	retorno = -1;
	if (this != NULL && id != NULL) {
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}
/// \fn int employee_setNombre(Employee*, char*)
/// \brief
/// \param this
/// \param nombre
/// \return
int employee_setNombre(Employee *this, char *nombre) {
	int retorno;
	retorno = -1;
	if (this != NULL && nombre != NULL) {
		strcpy(this->nombre, nombre);
		retorno = 0;
	}
	return retorno;
}
/// \fn int employee_getNombre(Employee*, char*)
/// \brief
/// \param this
/// \param nombre
/// \return
int employee_getNombre(Employee *this, char *nombre) {
	int retorno;
	retorno = -1;
	if (this != NULL && nombre != NULL) {
		strcpy(nombre, this->nombre);
		retorno = 0;
	}
	return retorno;
}
/// \fn int employee_setHorasTrabajadas(Employee*, int)
/// \brief
/// \param this
/// \param horasTrabajadas
/// \return
int employee_setHorasTrabajadas(Employee *this, int horasTrabajadas) {
	int retorno;
	retorno = -1;
	if (this != NULL && horasTrabajadas > 0) {
		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}
/// \fn int employee_getHorasTrabajadas(Employee*, int*)
/// \brief
/// \param this
/// \param horasTrabajadas
/// \return
int employee_getHorasTrabajadas(Employee *this, int *horasTrabajadas) {
	int retorno;
	retorno = -1;
	if (this != NULL && horasTrabajadas != NULL) {
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}
/// \fn int employee_setSueldo(Employee*, int)
/// \brief
/// \param this
/// \param sueldo
/// \return
int employee_setSueldo(Employee *this, int sueldo) {
	int retorno;
	retorno = -1;
	if (this != NULL && sueldo > 0) {
		this->sueldo = sueldo;
		retorno = 0;
	}
	return retorno;
}
/// \fn int employee_getSueldo(Employee*, int*)
/// \brief
/// \param this
/// \param sueldo
/// \return
int employee_getSueldo(Employee *this, int *sueldo) {
	int retorno;
	retorno = -1;
	if (this != NULL && sueldo != NULL) {
		*sueldo = this->sueldo;
		retorno = 0;
	}
	return retorno;
}
/// \fn int employee_compareByName(void*, void*)
/// \brief
/// \param employee
/// \param employeeToCompare
/// \return
int employee_compareByName(void *employee, void *employeeToCompare) {
	Employee *unEmpleado;
	Employee *otroEmpleado;
	char nombre1[50];
	char nombre2[50];
	int retorno;
	if (employee != NULL && employeeToCompare != NULL) {
		unEmpleado = (Employee*) employee;
		otroEmpleado = (Employee*) employeeToCompare;
		if (employee_getNombre(unEmpleado, nombre1) == 0
				&& employee_getNombre(otroEmpleado, nombre2) == 0) {
			retorno = strcmp(nombre1, nombre2);
		}
	}
	return retorno;
}
/// \fn int employee_compareByID(void*, void*)
/// \brief
/// \param employee
/// \param employeeToCompare
/// \return
int employee_compareByID(void *employee, void *employeeToCompare) {
	Employee *unEmpleado;
	Employee *otroEmpleado;
	int idEmpleado1;
	int idEmpleado2;
	int retorno;
	retorno = 0;
	if (employee != NULL && employeeToCompare != NULL) {
		unEmpleado = (Employee*) employee;
		otroEmpleado = (Employee*) employeeToCompare;
		if (employee_getId(unEmpleado, &idEmpleado1) == 0
				&& employee_getId(otroEmpleado, &idEmpleado2) == 0) {
			if (idEmpleado1 > idEmpleado2) {
				retorno = 1;
			} else {
				if (idEmpleado1 < idEmpleado2) {
					retorno = -1;
				}
			}
		}
	}
	return retorno;
}
/// \fn int employee_compareBySalary(void*, void*)
/// \brief
/// \param employee
/// \param employeeToCompare
/// \return
int employee_compareBySalary(void *employee, void *employeeToCompare) {
	Employee *unEmpleado;
	Employee *otroEmpleado;
	int sueldo1;
	int sueldo2;
	int retorno;
	retorno = 0;
	if (employee != NULL && employeeToCompare != NULL) {
		unEmpleado = (Employee*) employee;
		otroEmpleado = (Employee*) employeeToCompare;
		if (employee_getSueldo(unEmpleado, &sueldo1) == 0
				&& employee_getSueldo(otroEmpleado, &sueldo2) == 0) {
			if (sueldo1 > sueldo2) {
				retorno = 1;
			} else {
				if (sueldo1 < sueldo2) {
					retorno = -1;
				}
			}
		}
	}
	return retorno;
}
/// \fn int employee_compareByWorkingHours(void*, void*)
/// \brief
/// \param employee
/// \param employeeToCompare
/// \return
int employee_compareByWorkingHours(void *employee, void *employeeToCompare) {
	Employee *unEmpleado;
	Employee *otroEmpleado;
	int horasTrabajadas1;
	int horasTrabajadas2;
	int retorno;
	retorno = 0;
	if (employee != NULL && employeeToCompare != NULL) {
		unEmpleado = (Employee*) employee;
		otroEmpleado = (Employee*) employeeToCompare;
		if (employee_getSueldo(unEmpleado, &horasTrabajadas1) == 0
				&& employee_getSueldo(otroEmpleado, &horasTrabajadas2) == 0) {
			if (horasTrabajadas1 > horasTrabajadas2) {
				retorno = 1;
			} else {
				if (horasTrabajadas1 < horasTrabajadas2) {
					retorno = -1;
				}
			}
		}
	}
	return retorno;
}
/// \fn int employee_edit(Employee*)
/// \brief
/// \param this
/// \return
int employee_edit(Employee *this) {
	char nombre[50];
	int horas;
	int sueldo;
	int id;
	int retorno;
	int respuesta;
	retorno = -1;
	if (this != NULL && employee_getHorasTrabajadas(this, &horas) == 0
			&& employee_getSueldo(this, &sueldo) == 0
			&& employee_getNombre(this, nombre) == 0
			&& employee_getId(this, &id) == 0) {
		printf("Usted va a modificar a:\nID:%d\nNombre:%s\nHoras trabajadas:%d\nSueldo:%d\n",
				id, nombre, horas, sueldo);
		if (utn_getInt(&respuesta, 2,
				"1)Todo\n2)Nombre\n3)Horas trabajadas\n4)Sueldo\nQue quiere modificar?:",
				"Opcion invalida ", 1, 4, 4, 0) == 1) {
			switch (respuesta) {
			case 1:
				if (employee_editName(this, nombre) == 0
						&& employee_editWorkingHours(this, horas) == 0
						&& employee_editSalary(this, sueldo) == 0) {
					retorno = 0;
				}
				break;
			case 2:
				if (employee_editName(this, nombre) == 0) {
					retorno = 0;
				}
				break;
			case 3:
				if (employee_editWorkingHours(this, horas) == 0) {
					retorno = 0;
				}
				break;
			case 4:
				if (employee_editSalary(this, sueldo) == 0) {
					retorno = 0;
				}
				break;
			}
		}
	}
	return retorno;
}
int employee_editName(Employee *this, char *nombre) {
	int retorno;
	retorno = -1;
	if (this != NULL && nombre != NULL) {
		if (utn_getName(nombre, 50, "Ingrese nuevo nombre: ",
				"Nombre invalido ", 4) == 1) {
			printf("Nuevo nombre:%s\n", nombre);
			if (employee_setNombre(this, nombre) == 0) {
				retorno = 0;
			}
		}
	}
	return retorno;
}
int employee_editSalary(Employee *this, int salary) {
	int retorno;
	retorno = -1;
	if (this != NULL && salary > 0) {
		if (utn_getInt(&salary, 20, "Ingrese sueldo: ", "Sueldo invalida ", 0,
				1000000, 4, 0) == 1) {
			printf("Nuevo sueldo:%d\n", salary);
			if (employee_setSueldo(this, salary) == 0) {
				retorno = 0;
			}
		}
	}
	return retorno;
}
int employee_editWorkingHours(Employee *this, int workingHours) {
	int retorno;
	retorno = -1;
	if (this != NULL && workingHours > 0) {
		if (utn_getInt(&workingHours, 20, "Ingrese horas trabajadas: ",
				"Hora invalida ", 0, 10000, 4, 0) == 1) {
			printf("Nueva horas trabajadas:%d\n", workingHours);
			if (employee_setHorasTrabajadas(this, workingHours) == 0) {
				retorno = 0;
			}
		}
	}
	return retorno;
}

/// \fn int employee_print(Employee*, int)
/// \brief
/// \param this
/// \param index
/// \return
int employee_print(Employee *this, int index) {
	int retorno;
	char nombre[50];
	int horas;
	int sueldo;
	retorno = -1;
	if (this != NULL) {
		if (index >= 0 && employee_getNombre(this, nombre) == 0
				&& employee_getHorasTrabajadas(this, &horas) == 0
				&& employee_getSueldo(this, &sueldo) == 0) {
			printf("|%-8d|%-15s|%-6d|%-7d|\n", index + 1, nombre, horas,
					sueldo);
			retorno = 0;
		}
	}
	return retorno;
}
/// \fn int employee_remove(Employee*)
/// \brief
/// \param this
/// \return
int employee_remove(Employee *this) {
	int retorno;
	char nombre[20];
	char respuesta[3];
	int id;
	retorno = -1;
	if (this != NULL) {
		if (employee_getNombre(this, nombre) == 0
				&& employee_getId(this, &id) == 0) {
			printf("Usted esta por dar de baja a\nID:%d\nNombre:%s\n", id,
					nombre);
			if (utn_getText(respuesta, 3, "Esta seguro?: ",
					"Respuesta invalida ", 4) == 1) {
				strlwr(respuesta);
				if (strcmp(respuesta, "si") == 0) {
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

