/*
 * CS 361: Lab01
 *
 * Name: Nic Plybon & Adrien Ponce
 * This code complies with the JMU Honor Code
 */

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <string.h>

 // declare whole struct for reading from file

struct item6 {
    uint32_t member1;
    uint16_t member2;
    int16_t member3;
    char member4[8];
    void* member5;
};

 // extracts binary data contents from a file and displays it.
int main (int argc, char **argv)
{

    // declare filename
    char* filename;

    // program must be passed input data file
    if (argc != 2) {
        printf("Invalid number of arguments!\n");
        return EXIT_FAILURE;
    } else {
        // extract filename
        filename = argv[1];
    }
    //check if file is valid
    FILE *file;
    if (!fopen(filename, "r")) {
        printf("Opening file \"%s\" failed: %s\n", filename, strerror(errno));
        return EXIT_FAILURE;
    } else {
        file = fopen(filename, "a+");
    }

    // at byte offset 32 in the file, there is an unsigned 4-byte number
    uint32_t item1;
    fseek(file, 32, SEEK_SET);
    fread(&item1, sizeof(uint32_t), 1, file);
    printf("Item 1:\n\tDecimal: %i\n\tHex: 0x%x\n", item1, item1);

    // at byte offset 300 in the file, there is an unsigned 1-byte number
    uint8_t item2;
    fseek(file, 300, SEEK_SET);
    fread(&item2, sizeof(uint8_t), 1, file);
    printf("Item 2:\n\tDecimal: %i\n\tHex: 0x%x\n", item2, item2);

    // 123 bytes from the end of Item 2 in the file, there is an unsigned 2-byte number
    uint16_t item3;
    fseek(file, 123, SEEK_CUR);
    fread(&item3, sizeof(uint16_t), 1, file);
    printf("Item 3:\n\tDecimal: %i\n\tHex: 0x%x\n", item3, item3);

    // at byte offset 512 in the file, there is a signed 4-byte number
    int32_t item4;
    fseek(file, 512, SEEK_SET);
    fread(&item4, sizeof(int32_t), 1, file);
    printf("Item 4:\n\tDecimal: %d\n\tHex: 0x%x\n", item4, item4);

    // at byte offset 1234 in the file, there is a C string,
    // no longer than 256 characters.
    char item5[255];
    fseek(file, 1234, SEEK_SET);
    fgets(item5, 255, file);
    printf("Item 5:\n\t%s",item5);

    // at byte offset 2573 in the file, there is a struct
    struct item6 item6;
    fseek(file, 2573, SEEK_SET);
    fread(&item6, sizeof(struct item6), 1, file);
    // an unsigned 4-byte number
    printf("Item 6:\n\tMember 1: %i\n", item6.member1);
    // an unsigned 2-byte number
    printf("\tMember 2: %i\n", item6.member2);
    // a signed 2-byte number
    printf("\tMember 3: %d\n", item6.member3);
    // an array of 8 characters
    printf("\tMember 4: ");
    for (int i = 0; i < 8; i++) {
        printf("%c", item6.member4[i]);
    }
    printf("\n");
    // a pointer
    printf("\tMember 5: %p\n", item6.member5);

    // at byte offset 0xbbb in the file, there is an unsigned 8-byte number
    uint64_t item7;
    fseek(file, 3003, SEEK_SET);
    fread(&item7, sizeof(uint64_t), 1, file);
    printf("Item 7:\n\tDecimal: %lu\n\tHex: 0x%lx\n", item7, item7);

    // 100 bytes from the end of the file, there is an unsigned 4-byte number
    uint32_t item8;
    fseek(file, -100, SEEK_END);
    fread(&item8, sizeof(uint32_t), 1, file);
    printf("Item 8:\n\tDecimal: %i\n\tHex: 0x%x\n", item8, item8);

    //write "CS361" (no zero byte at the end) at 16 bytes beyond EOF
    fseek(file, 16, SEEK_END);
    char *str = "CS361";
    fwrite(str, 1, strnlen(str, 5), file);
    fclose(file);
}

