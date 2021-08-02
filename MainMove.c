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
 
