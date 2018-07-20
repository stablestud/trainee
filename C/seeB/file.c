/*
 * file.c	Manage the files which should be read
 * @author	stablestud
 * @date	20-07-2018
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "options.h"
#include "file.h"


/* Head pointer to the queue (linked list) */
F *list = NULL;
int files = 0;

/* Add file to the queue to be printed */
int queFile(char *filename)
{
	F *current;

	if (list == NULL) {
		list = malloc(sizeof(F));
		current = list;
	} else {
		/* Append to queue */
		for (current = list; current->next != NULL; current = current->next);
		current->next = malloc(sizeof(F));
		current = current->next;
	}

	errno = 0;
	current->next = NULL;
	current->name = filename;
	current->file = fopen(filename, "rb");

	/* Check if its a directory */
	if (!errno) {
		fgetc(current->file);
		rewind(current->file);
	}

	/* Check if valid */
	if (errno || !current->file) {
		fprintf(stderr, "seeb: %s: %s\n", filename, strerror(errno));

		/* Undo changes, as file could not be opened */
		if (list == current) {
			list = NULL;
		} else {
			F *prev;
			for(prev = list; prev->next != current; prev = prev->next);
			prev->next = NULL;
		}

		free(current);

		return 1;
	} else {
		++files;
		return 0;
	}
}

/* Remove top file from the queue */
int deQueFile(void)
{
	F *tmp_f = list;
	list = list->next;

	if (fclose(tmp_f->file)) {
		/* Couldn't close the stream */
		// TODO: Should I add the file to a "to-be-removed" list? //
		fprintf(stderr, "seeb: Couldn't close stream.\n");
		free(tmp_f); // Tmp needs to be removed when resolved //

		return 1;
	} else {
		free(tmp_f);
	}

	return 0;
}

int printFile(F *fstruct)
{
	char *buffer = malloc(sizeof(char) * width);
	int count;
	errno = 0;

	do {
		count = fread(buffer, 1, width, fstruct->file);

		if (errno) {
			fprintf(stderr, "seeb: %s: %s\n", fstruct->name,
				strerror(errno));
			return 1;
		} else {
			for (int i = 0; i < count; i++)
				printf("%02X ", buffer[i]);
			if (!errno && count)
				printf("\n");
		}
	} while (count);

	return 0;
}
