#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
 
#define Info(P)  (P)->Info
#define Next(P)  (P)->Next
#define Top(S)   (S).Top
#define Max(S)   (S).Max
#define Count(S) (S).Count
#define Nil     NULL
 
#define bool unsigned short int
#define False 0
#define True  !False
 
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
 
// infotype yang ada pada elemen
typedef int InfoType;
 
// membuat elemen stack untuk single link list
typedef struct tElmStack *Address;
typedef struct tElmStack {
    InfoType Info;
    Address  Next;
} ElmStack;
 
// list
typedef struct {
    Address Top;
    int     Count;
} Stack;
 
void CreateStack(Stack *S);
// I.S. Sembarang
// F.S. Terbentuk Stack kosong
 
bool IsEmpty(Stack S);
// Menghasilkan True jika Stack kosong, dan False jika Stack tidak kosong
 
Address Allocate(InfoType X);
// Menghasilkan Address dari alokasi sebuah elemen dengan InfoType X
// Jika alokasi berhasil maka nilai Address tidak Nil dan jika gagal nilai Address Nil
 
void DeAllocate(Address P);
// I.S. P terdefinisi
// F.S. Memori yang digunakan oleh P dikembalikan ke sistem
 
void Push(Stack *S, Address P);
// I.S. Sembarang, P terdefinisi
// F.S. Menempatkan P pada Top dari S
