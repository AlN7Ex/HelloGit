//list.h -- header file for common list type

#ifndef LIST_H_
#define LIST_H_
#include <stdbool.h> /* C99 */

#define TSIZE 45 /* Array size for name */

struct vehicle
{
	char mark[TSIZE];
	char model[TSIZE];
	int horsepower;
};

typedef struct vehicle Car;

typedef struct node
{
	Car car;
	struct node * next;
} Node;
typedef Node * List;

/* functions prototypes */

void InitializeList(List * plist);
bool ListIsEmpty(const List * plist);
bool ListIsFull(const List * plist);
unsigned int ListCarsCount(const List * plist);
bool AddCar(Car car, List * plist);
void Traverse(const List * plist, void(*pfun)(Car car));
void EmptyTheList(List * plist);

#endif