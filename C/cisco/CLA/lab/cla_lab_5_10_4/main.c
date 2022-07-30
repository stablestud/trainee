#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct element
{
	int value;
	struct element *next;
};

struct element *head = NULL;

void addtoque(int val);
void printque(void);
void freemem(void);


int main(void)
{
	int values[10] = { 2, 4, 5, 6, 7, 8, 9, 1, 3, 0};

	for (int i = 0; i < 10; i++)
		addtoque( values[i] );

	printque();
	freemem();

	return 0;
}

void addtoque(int val)
{
	struct element *current = head;

	if (NULL == current) {
		head = malloc( sizeof(struct element) * 1 );
		current = head;
	} else {
		while (current->next != NULL)
			current = current->next;

		current->next = malloc( sizeof(struct element) * 1 );
		current = current->next;
	}

	current->value = val;

	return;
}

void printque(void)
{
	struct element *current = head;

	while (current) {
		printf("%d\n", current->value );
		current = current->next;
	}
}

void freemem(void)
{
	struct element *current = head;

	while (current) {
		struct element *aux = current;
		current = current->next;
		free( aux );
	}

	puts("Memory freed.");

	return;
}
