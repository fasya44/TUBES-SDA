#include "header.h"
#include<stdio.h>
#include<math.h>

struct pole
{
    int stack[3];
};

struct pole p[3];

int top[3];

void CreateStack(Stack *S)
{
    Top(*S) = Nil;
    Count(*S) = 0;
}
 
bool IsEmpty(Stack S)
{
    return Top(S) == Nil;
}
 
Address Allocate(InfoType X)
{
    Address P = (Address)malloc(sizeof(ElmStack));
    if (P != Nil)
    {
        Info(P) = X;
        Next(P) = Nil;
    }
    return P;
}
 
void DeAllocate(Address P)
{
    free(P);
}
 
void Push(Stack *S, Address P)
{
    Next(P) = Top(*S);
    Top(*S) = P;
    Count(*S)++;
}
 
void Pop(Stack *S, Address *P)
{
    *P = Top(*S);
    Top(*S) = Next(*P);
    Count(*S)--;
}

void ViewStack(Stack S)
{
    Address P;
    InfoType X[Count(S)];
    int i = 0;
    for (P = Top(S); P != Nil; P = Next(P))
    {
        X[i] = Info(P);
        i++;
    }
    for (i = Count(S) - 1; i >= 0; i--)
        printf("%d ", X[i]);
}
 
void ViewVisual(Stack S[3], int TotalDisk)
{
    int i, j, k;
    Address P;
    InfoType X[3][TotalDisk];
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < TotalDisk - Count(S[i]); j++)
            X[i][j] = 0;
        for (P = Top(S[i]); P != Nil; P = Next(P))
        {
            X[i][j] = Info(P);
            j++;
        }
    }
    for (i = 0; i < TotalDisk; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf(" ");
            if (X[j][i] == 0)
                for (k = 0; k < 2 * TotalDisk - 1; k++)
                    printf(" ");
            else
            {
                for (k = 0; k < TotalDisk - X[j][i]; k++)
                    printf(" ");
                for (k = 0; k < 2 * X[j][i] - 1; k++)
                    printf("=");
                for (k = 0; k < TotalDisk - X[j][i]; k++)
                    printf(" ");
            }
        }
        printf("\n");
    }
    for (i = 1; i <= 3; i++)
    {
        printf(" ");
        for (j = 0; j < TotalDisk - 1; j++)
            printf(" ");
        printf("%d", i);
        for (j = 0; j < TotalDisk - 1; j++)
            printf(" ");
    }
    printf("\n");
}

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

//Menambahkan dan mengurangi nilai yang berada pada tiang
void push(int x)
{
	int pl;
    chooseWhereToPush:
    printf("Pilih tiang yang akan dimasukkan: ");
    scanf("%d", &pl);
    printf("\n");
    if(p[pl].stack[top[pl]] > x || p[pl].stack[top[pl]]==0) { 
        top[pl]++;
        p[pl].stack[top[pl]] = x;
    }
    else {
        printf("Tidak bisa dimasukkan, coba lagi.\n");
        goto chooseWhereToPush;
    }
}

int pop() {
    int pl, x;
    chooseWhereToPop:
    printf("Pilih tiang yang akan dipindahkan : "); 
    scanf("%d", &pl);
    printf("\n");
    if(p[pl].stack[top[pl]] == -1) {
        printf("Tiang kosong, piring tidak bisa dipindahkan, coba lagi.\n");
        goto chooseWhereToPop;
    }
    
    x = p[pl].stack[top[pl]];
    p[pl].stack[top[pl]] = 99;
    top[pl]--;
    return x;
}

//Menampilkan tampilan yang nantinya akan dipanggil oleh display()
void displaylevel(int level)
{
    int i;
    for(i=0; i<3; i++)
    {
        if(p[i].stack[level] == 99 || p[i].stack[level] == 0) {
        	printf("[ ]\t");
        }
        else {
        	printf("[%d]\t",p[i].stack[level]);
        }
    }
    printf("\n");         
}    

//Menampilkan tampilan yang telah dipanggil melalui displaylevel()
void display()
{
    
    int i;
    for(i=2; i>=0; i--)
    {
        displaylevel(i);
    }
}    

 //Menampilkan keadaan game saat menang
int gameWinCondition() {
    if(p[2].stack[0]==3 && p[2].stack[1]==2 && p[2].stack[2]==1) {
        return 1;
    }
    else {
        return 0;
    }
}

