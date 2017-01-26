#include <stdio.h>

// scanf() Function
/* 	- Is Used to read data from stdin and store that data in program variables
 *	- scanf("string", &variable(memory address of variable to store input data)
 *      - Stops reading data from stdin once it read a data item that does not match the,
 *	  type of conversion specifier.
 */

int scanfEnterInt(int* i)
{
	printf("%d", &i);
}
