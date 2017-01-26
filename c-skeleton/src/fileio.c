#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "../include/fileio.h"



int main(int argc, const char *argv[])
{	
	FILE *fin;
	FILE *fout;

	printf("This is from fileio.c \n");

	fin = fopen("../include/data/read.txt", "r");
	fout = fopen("../include/data/write.txt", "w");
	fileFputs(fout);
	//fileCopy(fin, fout);
	
}
