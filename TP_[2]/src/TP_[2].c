/*
 Una empresa requiere un sistema para administrar su nómina de empleados. Se sabe que
 dicha nómina bajo ninguna circunstancia superara los 1000 empleados.
 Datos:
 .ID
 .Name
 .Last name
 .Salary
 .Sector
 El sistema deberá tener el siguiente menú de opciones:
 1. ALTAS: Se debe permitir ingresar un empleado calculando automáticamente el número
 de Id. El resto de los campos se le pedirá al usuario.
 2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
 o Salario o Sector
 3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
 4. INFORMAR:
 1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
 2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
 NOTA: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
 Tener en cuenta que no se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la
 carga de algún empleado.
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
	int opcionMenuDos;
	int flagAdded = 0;
	float promedio;
	int cantidad = 0;
	float total;
	int auxId;
	initEmployees(arrayEmployees, ELEMENTS);
	do {
		get_int(&opcion, 2,
				"1.Alta\n2.Modificar\n3.Baja\n4.Informar\n5.Salir\nElija una opcion: ",
				"Opcion Invalida\n", 1, 5, 4, 0);
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
				get_int(&auxId, 20, "Que Id desea modificar?: ", "ID invalida ",
						0, 2000, 4, 0);
				function = modifyEmployee(arrayEmployees, ELEMENTS, auxId);
				if (function == 0) {
					printf("El empleado fue modificado correctamente\n");
				} else {
					printf("No se encontro el empleado\n");
				}
			}
			break;
		case 3:
			if (flagAdded == 0) {
				printf("No puede dar de baja un empleado si no ingreso ninguno aun\n");
				break;
			} else {
				get_int(&auxId, 20, "Que Id desea dar de baja?: ",
						"ID invalida ", 0, 2000, 4, 0);
				function = removeEmployee(arrayEmployees, ELEMENTS, auxId);
				if (function == 0) {
					printf("El empleado fue dado de baja correctamente\n");
				} else {
					printf("Error de carga o no se encontro el empleado\n");
				}
			}

			break;
		case 4:
			get_int(&opcionMenuDos, 2,
					"1.Listado de los empleados ordenados alfabéticamente por Apellido y Sector\n2.Total y promedio de los salarios, y cuántos empleados superan el salario promedio\n3.Volver\nQue informe desea ver: ",
					"Opcion invalida\n", 1, 3, 4, 0);

			switch (opcionMenuDos) {
			case 1:
				if (flagAdded == 0) {
					printf(
							"No se puede listar los empleados si no se ingreso ninguno\n");
				} else {
					sortEmployees(arrayEmployees, ELEMENTS, 0);
					function = printEmployees(arrayEmployees, ELEMENTS);
					if (function == -1) {
						printf("Error de carga de lista\n");
					}
				}

				break;
			case 2:
				if (flagAdded == 0) {
					printf("No se puede informar los salarios de empleados no ingresados\n");
				} else {
					function = salaryTotal(arrayEmployees, ELEMENTS, &promedio,
							&total, &cantidad);
					if (function == 1) {
						printf(
								"Total salarios: %.2f\nPromedio de salarios: %.2f\nCantidad de empleados que superan el salario promedio: %d\n",
								total, promedio, cantidad);
					}
				}
				break;
			}
			break;
		case 5:
			printf("Gracias por usar nuestro serivicio");
			break;
		}

	} while (opcion != 5);

	return 0;
}
