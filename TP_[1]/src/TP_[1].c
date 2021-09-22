/*
 Tobias Moretti
 DNI: 41668744
 DIV 1-E
 Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
 1. Ingresar 1er operando (A=x)
 2. Ingresar 2do operando (B=y)
 3. Calcular todas las operaciones
 a) Calcular la suma (A+B)
 b) Calcular la resta (A-B)
 c) Calcular la division (A/B)
 d) Calcular la multiplicacion (A*B)
 e) Calcular el factorial (A!)
 4. Informar resultados
 a) “El resultado de A+B es: r”
 b) “El resultado de A-B es: r”
 c) “El resultado de A/B es: r” o “No es posible dividir por cero”
 d) “El resultado de A*B es: r”
 e) “El factorial de A es: r1 y El factorial de B es: r2”
 5. Salir
 • Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
 que contenga las funciones para realizar las cinco operaciones.
 • En el menú deberán aparecer los valores actuales cargados en los operandos A y B
 (donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
 • Deberán contemplarse los casos de error (división por cero, etc)
 • Documentar todas las funciones
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "math.h"

int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	int numeroA;
	int numeroB;
	int banderaNumero1;
	int banderaNumero2;
	int suma;
	int resta;
	float division;
	int multiplicacion;
	int factorialA;
	int respuestaDivicion;
	int respuestaFactorialA;
	int factorialB;
	int respuestaFactorialB;
	do {
		if (banderaNumero1 != 1) {
			printf("1.Ingresar primer operando(A=X)\n");
		} else {
			printf("1.Ingresar primer operando(A=%d)\n", numeroA);
		}
		if (banderaNumero2 != 1) {
			printf("2.Ingresar segundo operando(B=Y)\n");
		} else {
			printf("2.Ingresar segundo operando(B=%d)\n", numeroB);
		}
		printf("3.Calcular todas las operaciones\n");
		printf("4.Informar resultados\n");
		printf("5.Salir\n");
		printf("Elija una opcion: ");
		scanf("%d", &opcion);
		switch (opcion) {
		case 1:
			numeroA = IngresarEntero("Ingrese primer operando(A=X): ", 10000,
					-10000, "Reingrese operando: ");
			banderaNumero1 = 1;
			break;
		case 2:
			numeroB = IngresarEntero("Ingrese segundo operando(A=X): ", 10000,
					-10000, "Reingrese operando: ");
			banderaNumero2 = 1;
			break;
		case 3:
			SumarValores(&numeroA, &numeroB, &suma);
			RestarValores(&numeroA, &numeroB, &resta);
			respuestaDivicion = DividirValores(&numeroA, &numeroB, &division);
			MultiplicarValores(&numeroA, &numeroB, &multiplicacion);
			respuestaFactorialA = CalcularFactorial(&numeroA, &factorialA);
			respuestaFactorialB = CalcularFactorial(&numeroB, &factorialB);
			break;
		case 4:
			printf("a)El resultado de A+B: %d\n", suma);
			printf("b)El resultado de A-B: %d\n", resta);
			if (respuestaDivicion == 1) {
				printf("c)El resultado de A/B: %.2f\n", division);
			} else {
				printf("c)No es posible dividir por cero\n");
			}
			printf("d)El resultado de A*B: %d\n", multiplicacion);
			if (respuestaFactorialA == 1) {
				printf("e)El factorial de A es: %d ", factorialA);
			} else {
				printf("e)Factorial de A no se pudo calcular valor negativo o 0 ");
			}
			if (respuestaFactorialB == 1) {
				printf("y El factorial de B es: %d\n", factorialB);
			} else {
				printf("y Factorial de B no se pudo calcular valor negativo o 0\n");
			}
			break;
		}

	} while (opcion != 5);
	return 0;
}


