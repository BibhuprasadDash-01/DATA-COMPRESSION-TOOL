#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Run-Length Encoding (Compression)
void compressRLE(char *input) {
    int count, i = 0;
    printf("Compressed Output: ");
    while (input[i] != '\0') {
        count = 1;
        while (input[i] == input[i + 1]) {
            count++;
            i++;
        }
        printf("%d%c", count, input[i]);
        i++;
    }
    printf("\n");
}

// Run-Length Decoding (Decompression)
void decompressRLE(char *input) {
    int i = 0;
    printf("Decompressed Output: ");
    while (input[i] != '\0') {
        int count = 0;

        // Read the number part
        while (isdigit(input[i])) {
            count = count * 10 + (input[i] - '0');
            i++;
        }

        // Repeat the character 'count' times
        for (int j = 0; j < count; j++) {
            printf("%c", input[i]);
        }
        i++;
    }
    printf("\n");
}

int main() {
    char str[100], compressed[100];

    printf("Enter a string to compress using RLE: ");
    scanf("%s", str);
    compressRLE(str);

    printf("Enter a compressed string to decompress (e.g. 3a2b4c): ");
    scanf("%s", compressed);
    decompressRLE(compressed);

    return 0;
}
