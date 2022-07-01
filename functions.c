#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

/****************************************************************/
/*   PRINTING FUNCTIONS   */
/****************************************************************/

void decToBinary(uint32_t n){
    int* binaryNum = calloc(32,sizeof(int));
  
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    for (int j = 31; j >= 0; j--)
        printf("%d", binaryNum[j]);

    printf("\n");

    free(binaryNum);
}

/****************************************************************/
/*   FUNCTIONS   */
/****************************************************************/

uint32_t sigma0 (uint32_t x){

    uint32_t RotateRight7, RotateRight18, ShiftRight3;

    RotateRight7 = (x >> 7) | (x << 25); 
    RotateRight18 = (x >> 18) | (x << 14); 
    ShiftRight3 = x >> 3; 
    
    return RotateRight7 ^ RotateRight18 ^ ShiftRight3;
}

uint32_t sigma1 (uint32_t x){

    uint32_t RotateRight17, RotateRight19, ShiftRight10;

    RotateRight17 = (x >> 17) | (x << 15); 
    RotateRight19 = (x >> 19) | (x << 13); 
    ShiftRight10 = x >> 10;
    
    return RotateRight17 ^ RotateRight19 ^ ShiftRight10;
}

uint32_t usigma0 (uint32_t x){

    uint32_t RotateRight2, RotateRight13, RotateRight22;

    RotateRight2 = (x >> 2) | (x << 30); 
    RotateRight13 = (x >> 13) | (x << 19); 
    RotateRight22 = (x >> 22) | (x << 10);
    
    return RotateRight2 ^ RotateRight13 ^ RotateRight22;
}

uint32_t usigma1 (uint32_t x){

    uint32_t RotateRight6, RotateRight11, RotateRight25;

    RotateRight6 = (x >> 6) | (x << 26); 
    RotateRight11 = (x >> 11) | (x << 21); 
    RotateRight25 = (x >> 25) | (x << 7); 
    
    return RotateRight6 ^ RotateRight11 ^ RotateRight25;
}

uint32_t choice (uint32_t x, uint32_t y, uint32_t z){

    return (x & y)^((~x) & z);
}

uint32_t majority (uint32_t x, uint32_t y, uint32_t z){
    
    return (x & y) ^ (x & z) ^ (y & z);
}

/*int main(){

    decToBinary(usigma1(16383));
    printf("%x\n",usigma1(16383));

    return 0;
}*/