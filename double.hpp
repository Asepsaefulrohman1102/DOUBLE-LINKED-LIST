#ifndef SLL_HPP_INCLUDED
#define SLL_HPP_INCLUDED

#include <iostream>

using namespace std;

#define Nil NULL

typedef int infotype;
typedef struct tElmtlist *address;
typedef struct tElmtlist
{
    infotype Info;
    address Next;
    address Prev;
} ElmtList;

typedef struct List
{
    address First;

    bool ListEmpty(List L);
    void CreateList(List *L);
    address Alokasi(infotype X);
    void Dealokasi(address *P);
    void insertDepan(List *L, infotype databaru);
    void insertBelakang(List *L, infotype databaru);
    void PrintInfo(List L, bool asc);
    void deleteDepan(List *L);
    void deleteBelakang(List *L);
    //cari data
    void Cari(List L, infotype cari);
    int nbEl(List L);
    void reverse(List *L, List *L2);
};

#define Info(P) (P)->Info
#define Next(P) (P)->Next
#define Prev(P) (P)->Prev
#define First(L) ((L).First)

#endif // SLL_HPP_INCLUDED
