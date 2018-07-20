/*
 * file.h	Manages file handling
 * @author	stablestud
 * @date	20-07-2018
 */

#ifndef FILE_H
#define FILE_H

#include <stdio.h>


typedef struct FILE_NODE {
	FILE *file;
	char* name;
	struct FILE_NODE *next;
} F;

extern F *list;
extern int files;

extern int queFile(char *filename);
extern int deQueFile(void);
extern int printFile(F *fstruct);

#endif /* FILE_H include guard */
