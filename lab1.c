/*
 * CS 361: Lab01
 *
 * Name: Nic Plybon
 * This code complies with the JMU Honor Code
 */
  
  #include <stdio.h>
  #include <stddef.h>
  #include <stdint.h>
  #include <stdlib.h>
  #include <stdbool.h>
  
struct item 
{
	uint16_t itemvalue; 

};

int main (int argc, char **argv)
{
	char* filename;
	if (argc != 2) {
		printf("Invalid number of arguments!\n");
		return EXIT_FAILURE;
	} else {
		filename = argv[1];
	}
	//check if file is valid
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to read file!\n");
		return EXIT_FAILURE;
    }
	struct item item1;
	fseek(file, 32, SEEK_SET);
	fread(&item1, sizeof(struct item), 1, file);
	printf("%x", item1.itemvalue);
	
	
		
	
	
	//lab1 output
	
	//printf("Item %d", item.itemnumber);
	
	
	
	
}

