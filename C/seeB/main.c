/*
 * seeb	     	View files in binary form
 * @author:	stablestud
 * @date:	20-07-2018
 */

#include "options.h"
#include "file.h"


int main(int argc, char *argv[])
{
	int returnv = handleParams(argc, argv);
	
	if (returnv == -1)
		return 0;
	else if (returnv)
		return 1;

	if (!files)
		return 1;

	for (int i = 0, cfiles = files; i < files; i++) {
		if (files > 1)
			printf("%s:\n", list->name);

		printFile(list);
		deQueFile();
		--cfiles;

		if (cfiles - i > 0)
			puts("");
	}

	return 0;
}
