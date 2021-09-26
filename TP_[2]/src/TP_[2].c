/*
 Una empresa requiere un sistema para administrar su n�mina de empleados. Se sabe que
 dicha n�mina bajo ninguna circunstancia superara los 1000 empleados.
 Datos:
 .ID
 .Name
 .Last name
 .Salary
 .Sector
 El sistema deber� tener el siguiente men� de opciones:
 1. ALTAS: Se debe permitir ingresar un empleado calculando autom�ticamente el n�mero
 de Id. El resto de los campos se le pedir� al usuario.
 2. MODIFICAR: Se ingresar� el N�mero de Id, permitiendo modificar: o Nombre o Apellido
 o Salario o Sector
 3. BAJA: Se ingresar� el N�mero de Id y se eliminar� el empleado del sistema.
 4. INFORMAR:
 1. Listado de los empleados ordenados alfab�ticamente por Apellido y Sector.
 2. Total y promedio de los salarios, y cu�ntos empleados superan el salario promedio.
 NOTA: Se deber� realizar el men� de opciones y las validaciones a trav�s de funciones.
 Tener en cuenta que no se podr� ingresar a los casos 2, 3 y 4; sin antes haber realizado la
 carga de alg�n empleado.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "validaciones.h"
#include "ArrayEmployees.h"

int main(void) {
	setbuf(stdout, NULL);
	Employee arrayEmployees[ELEMENTS];
	int function;
	int opcion;
	int flagAdded = 0;
	float promedio;
	int cantidad = 0;
	float total;

	function = initEmployees(arrayEmployees, ELEMENTS);
	if (function == -1) {
		printf("Error en carga de lista\n");
	}
	do {
		printf("1.Alta\n");
		printf("2.Modificar\n");
		printf("3.Baja\n");
		printf("4.Informar\n");
		printf("5.Salir\n");
		printf("Elija una opcion: ");
		scanf("%d", &opcion);
		switch (opcion) {
		case 1:
			function = addEmployee(arrayEmployees, ELEMENTS, arrayEmployees->id,
					arrayEmployees->name, arrayEmployees->lastName,
					arrayEmployees->salary, arrayEmployees->sector);
			if (function == 0) {
				printf("Empleado dado de alta correctamente\n");
				flagAdded = 1;
			} else {
				printf("Error en la carga de empleado\n");
			}
			break;
		case 2:
			if (flagAdded == 0) {
				printf("No puede modificar empleados si aun no se ingreso ninguno aun\n");
				break;
			} else {
				function = modifyEmployee(arrayEmployees, ELEMENTS, 1);
			}
			if (function == 0) {
				printf("El empleado fue modificado correctamente\n");
			} else {
				printf("Error de carga o no se encontro el empleado\n");
			}
			break;
		case 3:
			if (flagAdded == 0) {
				printf("No puede dar de baja un empleado si no ingreso ninguno aun\n");
				break;
			} else {
				function = removeEmployee(arrayEmployees, ELEMENTS, 1);
			}
			if (function == 0) {
				printf("El empleado fue dado de baja correctamente\n");
			} else {
				printf("Error de carga o no se encontro el empleado\n");
			}
			break;
		case 4:
			if (flagAdded == 0) {
				printf("No puede informar una lista de empleados si no ingreso ninguno aun\n");
			} else {
				function = printEmployees(arrayEmployees, ELEMENTS);
			}
			if (function == -1) {
				printf("Error de informe de lista\n");
			}
			if (salaryTotal(arrayEmployees, ELEMENTS, &promedio, &total,
					&cantidad) == -1) {
				printf("Error de informe total de salario\n");
			} else {
				printf("Total Salarios: %.2f\nPromedio Salarios: %.2f\nCantidad que superan el promedio de salario: %d\n",
						total, promedio, cantidad);
			}
			break;
		case 5:
			printf("Gracias por usar nuestro serivicio");
			break;
		}

	} while (opcion < 5);

	return 0;
}
