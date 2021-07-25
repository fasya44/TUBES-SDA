#include "header.h"
#include "boolean.h"
#include<stdio.h>
#include<math.h>


void fillSrc();
void displaylevel(int level);
void display();
void push(int x);
int pop();
int gameWinCondition();

struct pole
{
    int stack[3];
};

struct pole p[3];

int top[3];
 
void main()
{
    top[2] = top [1] = -1;
    int win = 0;
    int x;
    fillSrc();
    display();
    printf("Tower Neol 17\n");
    printf("Peraturan: 1. Hanya satu cakram yang boleh dipindahkan dalam satu waktu.\n" );
    printf("           2. Setiap perpindahan berupa pengambilan cakram teratas dari.\n" );
    printf("              satu tiang dan memasukkannya ke tiang lain, di atas cakram.\n" );
    printf("              lain yang mungkin sudah ada di tiang tersebut.             \n" );
    printf("           3. Tidak boleh meletakkan cakram di atas cakram lain yang lebih kecil.\n" );
    
    printf("Selamat Bermain!\n");
    while(win != 1) {
        x = pop();
        push(x);
        win = gameWinCondition();
        display();
    }
    printf("Selamat, anda memenangkan game ini!\n");
}

//Mengisi tiang sesuai dengan piring yang ada.
void fillSrc()
{
    p[0].stack[0] = 3;
    p[0].stack[1] = 2;
    p[0].stack[2] = 1;
    top[0] = 2;
}


