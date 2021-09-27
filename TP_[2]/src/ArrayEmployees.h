struct {
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}typedef Employee;
#define ELEMENTS 1000
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

int initEmployees(Employee *list, int len);
int addEmployee(Employee *list, int len, int id, char name[], char lastName[],
		float salary, int sector);
int findEmployeeById(Employee *list, int len, int id);
int removeEmployee(Employee *list, int len, int id);
int modifyEmployee(Employee *list, int len, int id);
int printEmployees(Employee *list, int length);
int sortEmployees(Employee *list, int len, int order);
int salaryTotal(Employee *list, int length, float *promedy, float *total,
		int *quantity);

#endif /* ARRAYEMPLOYEES_H_ */
