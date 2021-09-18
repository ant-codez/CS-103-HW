#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void readBit(int c, int total, int *p){
    int originalBit = c;
    int bitPos = 7;

    int bit = (c >> bitPos) & 1U;

    if (bit == 1){
        printf("NON-ASCII INPUT: %X at offset 0x%i\n", originalBit, total);
        *p += 1;
    }
}

int main() {
    auto int c;
    int total = 0;
    int bitsFound = 0;

    while (EOF != (c = getchar())){
        readBit(c, total++, &bitsFound);
    }

    if (bitsFound == 0) {
        printf("The input stream was pure ASCII with a total of %i bytes read.", total);
    }

    return 0;
}