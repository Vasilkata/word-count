#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
	if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    } else if(argc > 2) {
		printf("Too many args!\n");
		return -1;
	}

    FILE *file = fopen(argv[1], "r");

    if (!file) {
        perror("Error opening file");
        return 1;
    }

    int character;
    int in_word = 0;
    int word_count = 0;

    while ((character = fgetc(file)) != EOF) {
        if (isspace(character))
            in_word = 0;
        else if (!in_word) {
            in_word = 1;
            word_count++;
        }
    }

    fclose(file);

    printf("Word count: %d\n", word_count);
	return 0;
}
