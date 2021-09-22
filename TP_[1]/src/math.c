#include "math.h"
/// \fn int SumarValores(int*, int*, int*)
/// \brief Suma dos valores
/// \param numero1 El primer valor
/// \param numero2 El segundo valor
/// \param resultado El puntero al resultado de la suma
/// \return Retorna 1 cuando la funcion es llamada
int SumarValores(int *numero1, int *numero2, int *resultado) {
	int retorno;
	retorno = 1;

	*resultado = *numero1 + *numero2;

	return retorno;
}
/// \fn int RestarValores(int*, int*, int*)
/// \brief Resta dos valores
/// \param numero1 El primer valor
/// \param numero2 El segundo valor
/// \param resultado El puntero al resultado de la resta
/// \return Retorna 1 cuando la funcion es llamada
int RestarValores(int *numero1, int *numero2, int *resultado) {
	int retorno;
	retorno = 1;

	*resultado = *numero1 - *numero2;

	return retorno;
}
/// \fn int DividirValores(int*, int*, float*)
/// \brief Divide dos valores (con distincion de 0 en el segundo valor)
/// \param numero1 El primer valor
/// \param numero2 El segundo valor
/// \param resultado El puntero al resultado de la division
/// \return Retorna 1 en caso de que la division alla sido valida o 0 si no
int DividirValores(int *numero1, int *numero2, float *resultado) {
	int retorno;
	retorno = 0;
	if (*numero2 != 0) {
		*resultado = (float) *numero1 / *numero2;
		retorno = 1;
	}
	return retorno;
}
/// \fn int MultiplicarValores(int*, int*, int*)
/// \brief Multiplica dos valores
/// \param numero1 Primer valor
/// \param numero2 Segundo valor
/// \param resultado El puntero al resultado de la multiplicacion
/// \return Retorna 1 cuando la funcion es llamada
int MultiplicarValores(int *numero1, int *numero2, int *resultado) {
	int retorno;
	retorno = 1;
	*resultado = *numero1 * *numero2;
	return retorno;
}
/// \fn int CalcularFactorial(int*, int*)
/// \brief Pide un numero y calcula su factorial
/// \param numero El numero a ser factorizado
/// \param resultado El puntero al resultado del factorial
/// \return Retorna 1 en caso de que el factorial se alla calculado o 0 si no
int CalcularFactorial(int *numero, int *resultado) {
	int factorial;
	int retorno;
	retorno = 0;
	*resultado = 1;
	factorial = *numero;
	while (factorial > 1) {
		*resultado *= factorial;
		factorial--;
		retorno = 1;
	}
	return retorno;
}

