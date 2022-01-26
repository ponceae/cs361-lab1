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
  #include <errno.h>
  
struct item6 {
	uint32_t member1;
	uint16_t member2;
	int16_t member3;
	char member4[8];
	int64_t member5;
};
  
int main (int argc, char **argv)
{
	char* filename;
	if (argc != 2) {
		//FIX
		printf("Invalid number of arguments!\n");
		return EXIT_FAILURE;
	} else {
		filename = argv[1];
	}
	//check if file is valid
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
		//FIX ERROR CHECKING
		//printf("Opening file filename failed: %s\n", strerror(errno));
		return EXIT_FAILURE;
    }
	uint32_t item1;
	fseek(file, 32, SEEK_SET);
	fread(&item1, sizeof(uint32_t), 1, file);
	printf("Item 1:\n\tDecimal: %i\n\tHex: 0x%x\n", item1, item1);
	uint8_t item2;
	fseek(file, 300, SEEK_SET);
	fread(&item2, sizeof(uint8_t), 1, file);
	printf("Item 2:\n\tDecimal: %i\n\tHex: 0x%x\n", item2, item2);
	uint16_t item3;
	fseek(file, 123, SEEK_CUR);
	fread(&item3, sizeof(uint16_t), 1, file);
	printf("Item 3:\n\tDecimal: %i\n\tHex: 0x%x\n", item3, item3);
	int32_t item4;
	fseek(file, 512, SEEK_SET);
	fread(&item4, sizeof(int32_t), 1, file);
	printf("Item 4:\n\tDecimal: %d\n\tHex: 0x%x\n", item4, item4);
	char item5[255];
	fseek(file, 1234, SEEK_SET);
	fgets(item5, 255, file);
	printf("Item 5:\n\t%s",item5);
	struct item6 item6;
	fseek(file, 2573, SEEK_SET);
	fread(&item6, sizeof(struct item6), 1, file);
	printf("Item 6:\n\tMember 1: %i\n", item6.member1);
	printf("\tMember 2: %i\n", item6.member2);
	printf("\tMember 3: %d\n", item6.member3);
	printf("\tMember 4: %s\n", item6.member4);
	printf("\tMember 5: %ld\n", item6.member5);
	uint64_t item7;
	fseek(file, 3003, SEEK_SET);
	fread(&item7, sizeof(uint64_t), 1, file);
	printf("Item 7:\n\tDecimal: %lu\n\tHex: 0x%lx\n", item7, item7);
	uint32_t item8;
	fseek(file, -100, SEEK_END);
	fread(&item8, sizeof(uint32_t), 1, file);
	printf("Item 8:\n\tDecimal: %i\n\tHex: 0x%x\n", item8, item8);
	
	
	//write to file part



	


	

	

	

	
	
	

	

	
	

	




	


	
	
	
		
	
	
	//lab1 output
	
	//printf("Item %d", item.itemnumber);
	
	
	
	
}

