/* cars.c -- use list as ADT */
/* compile with list.c */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void showcars(Car car);
char * s_gets(char * st, int n);

int main(void)
{
	List cars;
	Car temp;

	InitializeList(&cars);
	if (ListIsFull(&cars))
	{
		fprintf(stderr, "No free data! Programm shutdown\n");
		exit(1);
	}

	/* collect and save info */
	puts("Enter car mark and model:");
	while (s_gets(temp.mark, TSIZE) != NULL && temp.mark[0] != '\0' && s_gets(temp.model, TSIZE) != NULL && temp.model != '\0')
	{
		puts("Enter horse power:");
		scanf("%d", &temp.horsepower);
		while (getchar() != '\n')
			continue;
		if (AddCar(temp, cars) == false)
		{
			fprintf(stderr, "Issue with get data\n");
			break;
		}
		if (ListIsFull(&cars))
		{
			puts("List is full");
			break;
		}
		puts("Enter next car (or empty string for exit)");
	}
	if (ListIsEmpty(&cars))
	{
		printf("No input data\n");
	}
	else
	{
		printf("List of cars:\n");
		Traverse(&cars, showcars);
	}
	printf("You entered &d cars\n", ListCarsCount(&cars));

	/* erase */
	EmptyTheList(&cars);
	printf("Programm executed\n");

	return 0;
}

void showcars(Car car)
{
	printf("Car mark: %s Model: %s HorsePower: %d\n",car.mark, car.model, car.horsepower);
}

char * s_gets(char * st, int n)
{
	char * ret_val;
	char * find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n'); 				/* find new string */
		if (find)								/* if not a NULL */
			*find = '\0';						/* put there null symbol */
		else
			while (getchar() != '\n')
				continue;						/* kick string remainder */
	}
	return ret_val;
}