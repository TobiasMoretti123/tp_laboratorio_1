#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct {
	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;

} Employee;

Employee* employee_new(); //constructor
Employee* employee_newParametros(char *idStr, char *nombreStr,
		char *horasTrabajadasStr, char *sueldo);
Employee* employee_newParametrosConDato(int *id, char *nombre,
		int *horasTrabajadas, int *sueldo);
void employee_delete(Employee *this); //destructor

int employee_setId(Employee *this, int id);
int employee_getId(Employee *this, int *id);

int employee_setNombre(Employee *this, char *nombre);
int employee_getNombre(Employee *this, char *nombre);

int employee_setHorasTrabajadas(Employee *this, int horasTrabajadas);
int employee_getHorasTrabajadas(Employee *this, int *horasTrabajadas);

int employee_setSueldo(Employee *this, int sueldo);
int employee_getSueldo(Employee *this, int *sueldo);

int employee_compareByName(void *employee, void *employeeToCompare);
int employee_compareByID(void *employee, void *employeeToCompare);
int employee_compareBySalary(void *employee, void *employeeToCompare);
int employee_compareByWorkingHours(void *employee, void *employeeToCompare);

int employee_edit(Employee *this);
int employee_editName(Employee *this, char *nombre);
int employee_editSalary(Employee *this, int salary);
int employee_editWorkingHours(Employee *this, int workingHours);


int employee_print(Employee *this, int index);
int employee_remove(Employee *this);
int employee_findID(Employee *this, int len, int *id);

#endif // employee_H_INCLUDED
