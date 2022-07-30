#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	struct id {
		char name[20];
		char surname[20];
		int other;
	};

	struct id user1;
	printf("Enter name and surname of user 1: ");
	scanf("%s %s", user1.name, user1.surname );

	struct id user2;
	printf("Enter name and surname of user 2: ");
	scanf("%s %s", user2.name, user2.surname );

	struct id user3;
	printf("Enter name and surname of user 3: ");
	scanf("%s %s", user3.name, user3.surname );

	struct id user4;
	printf("Enter name and surname of user 4: ");
	scanf("%s %s", user4.name, user4.surname );

	/* Adding other data to structs */
	user1.other = user2.other = user3.other = user4.other = 29;

	printf("%s %s\n", user1.name, user1.surname );
	printf("%s %s\n", user2.name, user2.surname );
	printf("%s %s\n", user3.name, user3.surname );
	printf("%s %s\n", user4.name, user4.surname );

	return 0;
}
