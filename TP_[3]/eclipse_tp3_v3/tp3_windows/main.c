#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"
#include "validaciones.h"

/****************************************************
 Menu:
 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
 3. Alta de empleado
 4. Modificar datos de empleado
 5. Baja de empleado
 6. Listar empleados
 7. Ordenar empleados
 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
 9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
 10. Salir
 *****************************************************/

int main() {
	setbuf(stdout, NULL);
	LinkedList *listaEmpleados;
	int opciones;
	int banderaTexto;
	int banderaBinario;
	int banderaCargado;
	listaEmpleados = ll_newLinkedList();
	banderaTexto = 0;
	banderaBinario = 0;
	banderaCargado = 0;
	do {
		if (utn_getInt(&opciones, 20,
				"1)Cargar archivo como texto\n2)Cargar archivo como binario\n3)Alta empleado\n4)Modificar empleado\n5)Baja de empleado\n6)Listar empleados\n7)Ordenar empleados\n8)Guardar archivo modo texto\n9)Guardar archivo modo binario\n10)Salir\nIngrese opcion: ",
				"Opcion invalida ", 1, 10, 4, 0) == 1) {
			switch (opciones) {
			case 1:
				if (banderaBinario != 1) {
					if (controller_loadFromText("data.csv", listaEmpleados)
							== -1) {
						printf("Error en la carga del archivo o este no existe\n");
					} else {
						printf("Lista cargada correctamente\n\n");
						banderaTexto = 1;
					}
				} else {
					printf("Ya cargo el archivo en modo binario\n");
				}
				break;
			case 2:
				if (banderaTexto != 1) {
					if (controller_loadFromBinary("data.bin", listaEmpleados)
							== -1) {
						printf("Error en la carga del archivo o este no existe\n");
					} else {
						printf("Lista cargada correctamente\n\n");
						banderaBinario = 1;
					}
				} else {
					printf("Ya cargo el archivo en modo texto\n");
				}
				break;
			case 3:
				if (banderaBinario == 1 || banderaTexto == 1) {
					if (controller_addEmployee(listaEmpleados) == 0) {
						printf("Empleado ingresado correctamente\n");
						banderaCargado = 1;
					} else {
						printf("Error en la carga de empleado ");
						printf("O el archivo no fue abierto\n");
					}
				} else {
					printf("Debe cargar el archivo para dar de alta un empleado\n");
				}
				break;
			case 4:
				if (banderaCargado == 1 || banderaTexto == 1
						|| banderaBinario == 1) {
					if (controller_editEmployee(listaEmpleados) == 0) {
						printf("Empleado modificado correctamente\n");
					} else {
						printf("Error en la modificacion de empleado ");
						printf("O el empleado no fue encontrado\n");
					}
				} else {
					printf("De de alta un empleado antes de modificarlo\n");
				}
				break;
			case 5:
				if (banderaCargado == 1 || banderaTexto == 1
						|| banderaBinario == 1) {
					if (controller_removeEmployee(listaEmpleados) == 0) {
						printf("Empleado dado de baja correctamente\n");
					} else {
						printf("Error en la baja de empleado o ");
						printf("No se encontro a ese empleado\n");
					}
				} else {
					printf("De de alta un empleado antes de dar de baja\n");
				}
				break;
			case 6:
				if (controller_ListEmployee(listaEmpleados) == -1) {
					printf("Lista de empleados vacia\n");
				}
				break;
			case 7:
				if (banderaCargado == 1 || banderaTexto == 1
						|| banderaBinario == 1) {
					if (controller_sortEmployee(listaEmpleados) == 0) {
						printf("Empleados ordenados correctamente\n");
					} else {
						printf("Error en el ordenamiento\n");
					}
				} else {
					printf("Tiene que haber empleados a ordenar\n");
				}
				break;
			case 8:
				if (banderaCargado == 1 || banderaTexto == 1) {
					if (controller_saveAsText("data.csv", listaEmpleados)
							== 0) {
						printf("Archivo guardado correctamente\n");
					}
				} else {
					printf("Debe haber cargado el archivo de texto para guardarlo\n");
				}
				break;
			case 9:
				if (banderaCargado == 1 || banderaBinario == 1) {
					if (controller_saveAsBinary("data.bin", listaEmpleados)
							== 0) {
						printf("Archivo guardado correctamente\n");
					}
				} else {
					printf("Debe haber cargado el archivo de binario para guardarlo\n");
				}
				break;
			}
		}
	} while (opciones < 10);

	return 0;
}

