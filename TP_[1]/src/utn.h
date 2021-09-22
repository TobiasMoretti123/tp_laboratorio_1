#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef UTN_H_
#define UTN_H_

int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos);
int utn_getNumeroConDecimales(float *pResultado, char *mensaje,
		char *mensajeError, float minimo, float maximo, int reintentos);
void utn_getTexto(char mensaje[], char cadena[], char maximo, char minimo,
		char mensajeError[], int tam);
int IngresarEntero(char mensaje[], int max, int minimo, char mensajeError[]);

#endif /* UTN_H_ */
