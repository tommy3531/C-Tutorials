#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define BSIZE 16384

void fileCopy(FILE *readFrom, FILE *readTo)
{


	char buf[BSIZE];
	int count;



	while((count = fread(buf, 1, BSIZE, readFrom)) > 0)
	{
		//printf("File Opended");
		fwrite(buf, 1, count, readTo);
	}
	printf("Data Read from read.txt to write.txt, Closing!!!\n");

	fclose(readFrom);
	fclose(readTo);

	printf("Both files are closed\n");

}

/*
 *
 *  Writes a string of characters to file
 */

void fileFputs(FILE *ptr)
{
	if(!ptr)
	{
		printf("The file cannot be opened");
		exit(1);
	}
	fputs("This is written to file with fputs\n", ptr);
} 
