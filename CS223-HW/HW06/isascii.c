#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void readBit(int c, int total){
    int originalBit = c;
    int bitPos = 7;

    int bit = (c >> bitPos) & 1U;

    if (bit == 1){
        printf("NON-ASCII INPUT:%X at offset 0x%i\n", originalBit, total);
    }
}

int main() {
    auto int c;
    int total = 0;

    while (EOF != (c = getchar())){
        readBit(c, total++);
    }

    //printf("%i", bit);

    return 0;
}