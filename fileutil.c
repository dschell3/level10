#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fileutil.h"

// DIRECTIONS
// Choose whether you are doing the 2D array or
// the array of arrays.
// For the 2D array,
//    implement loadFile2D, substringSearch2D, and free2D.
// For the array of arrays, 
//    implement loadFileAA, substringSearchAA, and freeAA.


// Load the text file from the given filename.
// Return a pointer to the array of strings.
// Sets the value of size to be the number of valid
// entries in the array (not the total array length).
char ** loadFileAA(char *filename, int *size)
{
	FILE *in = fopen(filename, "r");
	if (!in)
	{
	    perror("Can't open file");
	    exit(1);
	}
	
	// TODO
	// Allocate memory for an array of strings (arr).
	int capacity = 50;
	int cursor = 0;
	char ** arr = malloc(capacity * sizeof(char *));   			// start with vertical array of 50 strings

	// Read the file line by line.
	char line[1000];                    
    while (fgets(line, sizeof(line), in) != NULL)           	// while not at end of file, process length of line
    {                                                       	// process the file
	    //   Trim newline.
    	char *nl = strchr(line, '\n');
    	if (nl != NULL)   										// if (nl) means the same thing
        	*nl = '\0';

		//   Expand array if necessary (realloc).
		if (cursor == capacity)
		{
			capacity = capacity + (capacity / 2);				// add 50% to capacity
			arr = realloc(arr, capacity * sizeof(char *));		// lengthen array of pointers to strings
		}

		//   Allocate memory for the string (str).
		int stringLength = strlen(line) + 1;					// chars + NULL
		arr[cursor] = malloc(stringLength * sizeof(char)); 		// want space for chars not pointer
		
		//   Copy each line into the string (use strcpy).
		strcpy(arr[cursor], line);								// copy line into array at cursor
		++cursor;												// increment cursor
    }


    // Close the file.
	fclose(in);

	// The size should be the number of entries in the array.
	// set size to the number of chars read
	*size = cursor;
	
	// Return pointer to the array of strings.
	return arr;
}

// Search the array for the target string.
// Return the found string or NULL if not found.
char * substringSearchAA(char *target, char **lines, int size)
{
	for (int i = 0; i < size; ++i)									
	{
		if (strstr(lines[i], target) != NULL)					// is current char = target?
		{
			return lines[i];									// target found
		}
	}
	return NULL;												// target not found
}

// Free the memory used by the array
void freeAA(char ** arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		free(arr[i]); 											// frees each string
	}
	free(arr); 													// frees the array of strings
}

// will not be using 2D array
char (*loadFile2D(char *filename, int *size))[COLS]
{
	FILE *in = fopen(filename, "r");
	if (!in)
	{
	    perror("Can't open file");
	    exit(1);
	}
	
	// TODO
	// Allocate memory for an 2D array, using COLS as the width.
	// Read the file line by line into a buffer.
    //   Trim newline.
	//   Expand array if necessary (realloc).
	//   Copy each line from the buffer into the array (use strcpy).
    // Close the file.
	
	// The size should be the number of entries in the array.
	*size = 0;
	
	// Return pointer to the array.
	return NULL;
}


char * substringSearch2D(char *target, char (*lines)[COLS], int size)
{
    // will not be using 2D array
    return NULL;
}


void free2D(char (*arr)[COLS])
{
	// will not be using 2D array
}