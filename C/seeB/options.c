/*
 * options.c	This source file handles the parameters ("options")
 * 		supplied to the program on startup.
 * @author:	stablestud
 * @date:	20-07-2018
 */

#include <stdio.h>
#include <string.h>

#include "options.h"
#include "file.h"


static int setWidth(char *size);
extern int convertToInt(unsigned *dest, char* string);
static int showUsage(void);
static int showHelp(void);
static int showVersion(void);


unsigned width = 8;

int handleParams(int argc, char *argv[])
{
	int failure = 0;
	int end_of_options = 0;
	char option_mode = 0;

	/* Check if an option was issued at all */
	if (argc == 1)
		return showUsage();

	/* Filter primary options (--version, --help) */
	for (int i = 1; i < argc; i++) {
		if (!strcmp("-v", argv[i])
		||  !strcmp("--version", argv[i])) {
			return showVersion();
		} else if (!strcmp("-h", argv[i])
		||         !strcmp("--help", argv[i])) {
			return showHelp();
		} else if (!strcmp("--", argv[i])) {
			break;
		}
	}
	
	/* Interpret options issued by user */
	for (int i = 1; i < argc; i++) {
		if (end_of_options && !failure) {
			/* End-of-options sign ("--") has been issued,
			 * don't try to interpret options as everything
			 * is going to a filename */
			queFile(argv[i]);

		} else if (option_mode) {
			switch (option_mode) {
			case 'w':
				failure += setWidth(argv[i]);
				break;
			/* Add more options here
			  	.
			  	.
			  	.
			 */
			}
			option_mode = '\0';
		} else if (!strcmp("--", argv[i])) {
			end_of_options = 1;
		} else if (!strcmp("-w", argv[i])
		||         !strcmp("--width", argv[i])) {
			option_mode = 'w';	
		} else if (argv[i][0] == '-') {
			fprintf(stderr, "seeb: Unknown option '%s'\n", argv[i]);
			++failure;
		} else if (!failure) {
			/* Add a file */
			queFile(argv[i]);
		}
	}

	return failure;
}

static int setWidth(char *size)
{
	/* Convert and check if valid value */
	if (convertToInt(&width, size)) {
		fprintf(stderr, "seeb: option '--width' has "
			"incorrect value: '%s'\n", size);
		return 1;
	} else {
		return 0;
	}
}

int convertToInt(unsigned *dest, char* string)
{
	*dest = 0;

	for (int i = 0; string[i] != '\0'; i++) {
		if (string[i] >= '0' && string[i] <= '9') {
			*dest = *dest * 10U + string[i] - '0';
		} else {
			return 1;
		}
	}

	return 0;
}

static int showUsage(void)
{
	puts("seeb: Usage: seeb [options]... filename");
	puts("      Try '--help' for more information");

	return 1;
}

static int showHelp(void)
{
	puts("seeb - View files in a binary represenation");
	puts("");
	puts("Options:");
	puts("-v, --version	- view the programs version");
	puts("-h, --help	- view this help screen");
	puts("-w, --width	- set the amount of characters to be shown");
	puts("		  per line");

	return -1;
}

static int showVersion(void)
{
	/* __DATE__ and __TIME__ will be replaced by the compiler
	 * to a string containing the date and time of compilation */
	printf("seeb v0.0.1, compiled on %s at %s\n", __DATE__, __TIME__);

	return -1;
}
