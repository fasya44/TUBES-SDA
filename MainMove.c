#include "header.h"
#include "boolean.h"
#include<stdio.h>
#include<math.h>

void main();
void towers(int, char, char, char);

	void main() {
    	int num,a,b;  
    	printf("\n Masukkan Nomor piring : "); 
    	scanf("%d", &num);
    	a = pow(2,num);
    	b = a-1;
    	printf("Total perpindahan nomor piring ini sebanyak: %d\n",b);
    	printf("\nRincian perpindahan nomor piring ini:\n"); 
    	towers(num, '0', '1', '2');
	}
 
void towers(int num, char from, char to, char aux){
  		if (num == 1){
        printf("\nPindahnya piring 1 dari tiang %c ke tiang %c\n", from, to);
        return;
    } 
    
	towers(num - 1, from, aux, to);
    printf("\nPindahnya piring %d dari tiang %c ke tiang %c\n", num, from, to); 
    towers(num - 1, aux, to, from); 
	}