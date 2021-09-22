#include "utn.h"
static int esNumerica(char *cadena);
static int getInt(int *pResultado);
static int myGets(char *cadena, int longitud);
static int getFloat(float *pResultado);
static int esDecimal(char *cadena);
/**
 * \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * un máximo de ' longitud - 1' caracteres .
 * \ param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \ param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */
static int myGets(char *cadena, int longitud) {
	if (cadena != NULL && longitud > 0
			&& fgets(cadena, longitud, stdin) == cadena) {
		fflush(stdin);
		if (cadena[strlen(cadena) - 1] == '\n') {
			cadena[strlen(cadena) - 1] = '\0';
		}
		return 0;
	}
	return -1;
}
/**
 * \brief Verifica si la cadena ingresada es numerica
 * \ param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 *
 */
static int getInt(int *pResultado) {
	int retorno = -1;
	char buffer[64];
	if (pResultado != NULL) {
		if (myGets(buffer, sizeof(buffer)) == 0 && esNumerica(buffer)) {
			*pResultado = atoi(buffer);
			retorno = 0;
		}
	}
	return retorno;
}
/**
 * \brief Verifica si la cadena ingresada es numerica
 * \ param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 ( vardadero ) si la cadena es numerica y 0 ( falso ) si no lo es
 */
static int esNumerica(char *cadena) {
	int i = 0;
	int retorno = 1;
	if (cadena != NULL && strlen(cadena) > 0) {
		while (cadena[i] != '\0') {
			if (cadena[i] < '0' || cadena[i] > '9') {
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}
/// \fn int getFloat(float*)
/// \brief verifica si la cadena ingresada es decimal
/// \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// \return Retorna 0 (EXITO) si se obtiene un numero decimal y -1 (ERROR) si no
static int getFloat(float *pResultado) {
	int retorno = -1;
	char buffer[64];
	if (pResultado != NULL) {
		if (myGets(buffer, sizeof(buffer)) == 0 && esDecimal(buffer)) {
			*pResultado = atof(buffer);
			retorno = 0;
		}
	}
	return retorno;
}
/// \fn int esDecimal(char*)
/// \brief verifica si la cadena ingresa es decimal
/// \param cadena cadena de caracteres a ser analizada
/// \return Retorna 1 ( vardadero ) si la cadena es decimal y 0 ( falso ) si no lo es
static int esDecimal(char *cadena) {
	int i = 0;
	int retorno = 1;
	if (cadena != NULL && strlen(cadena) > 0) {
		while (cadena[i] != '\0') {
			if ((cadena[i] < '0' || cadena[i] > '9') && cadena[i] == ',') {
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}

/**
 * \brief Solicita un numero al usuario , luego de verificarlo devuelve el resultado
 * \ param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \ param mensaje Es el mensaje a ser mostrado
 * \ param mensajeError Es el mensaje de Error a ser mostrado
 * \ param minimo Es el numero maximo a ser aceptado
 * \ param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos) {
	int bufferInt;
	int retorno = -1;
	while (reintentos > 0) {
		reintentos--;
		printf("%s", mensaje);
		if (getInt(&bufferInt) == 0) {
			if (bufferInt >= minimo && bufferInt <= maximo) {
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
		}
		printf("%s", mensajeError);
	}
	return retorno;
}
/// \fn int utn_getNumeroConDecimales(float*, char*, char*, float, float, int)
/// \brief Solicita numero al usuario lo verifica y devuelve un estado
/// \param pResultado El puntero al numero a ser verificado
/// \param mensaje El mensaje de peticion de numero
/// \param mensajeError El mensaje que sale cuando hay un error
/// \param minimo El rango minimo
/// \param maximo El rango maximo
/// \param reintentos cantidad de intentos que tiene el usuario
/// \return retorna 0 si se optuvo el numero o -1 si no
int utn_getNumeroConDecimales(float *pResultado, char *mensaje,
		char *mensajeError, float minimo, float maximo, int reintentos) {
	float bufferFloat;
	int retorno = -1;
	while (reintentos > 0) {
		reintentos--;
		printf("%s", mensaje);
		if (getFloat(&bufferFloat) == 0) {
			if (bufferFloat >= minimo && bufferFloat <= maximo) {
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
		}
		printf("%s", mensajeError);
	}
	return retorno;
}
/// \fn void utn_getTexto(char[], char[], char, char, char[], int)
/// \brief pide un texto y lo verifica
/// \param mensaje el mensaje de peticion del texto
/// \param cadena la cadena de caracteres a ser verificada
/// \param maximo El caracter maximo de la cadena
/// \param minimo El caracter minimo de la cadena
/// \param mensajeError El mensaje de error cuando falla
/// \param tam el tamaño de la cadena a ser verificada
void utn_getTexto(char mensaje[], char cadena[], char maximo, char minimo,
		char mensajeError[], int tam) {
	printf("%s", mensaje);
	fflush(stdin);
	fgets(cadena, tam, stdin);
	for (int i = 0; i < tam; i++) {
		if (cadena[i] < minimo && cadena[i] > maximo) {
			printf("%s", mensajeError);
		}
	}
}

