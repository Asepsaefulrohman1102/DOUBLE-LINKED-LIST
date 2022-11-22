#include "double.hpp"

// cek list kosong
bool List::ListEmpty(List L)
{
    if (L.First == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// untuk mengecek apakah list kosong
void List::CreateList(List *L)
{
    First(*L) = Nil; // berguna untuk mengecek apakah list kosong
}

// Alokasi dipanggil saat ada penambahan element
address List::Alokasi(infotype X)
{
    address P; // berguna untuk menunjuk ke alamat yang akan di alokasikan
 
    P = new ElmtList; // untuk membuat elemen baru
    if (P != Nil) //jika alokasi berhasil
    {
        Info(P) = X; // isi info dengan X
        Next(P) = Nil; // next elemen baru diisi dengan NULL
        Prev(P) = Nil; // prev elemen baru diisi dengan NULL
        return P; // mengembalikan elemen baru
    }
    else
    {
        return Nil; // jika alokasi gagal
    }
    // {
    //     Info(P) = X;
    //     Next(P) = Nil;
    //     Prev(P) = Nil;
    // }
    // return P;
}

// insert depan dengan while
void List::insertDepan(List *L, infotype databaru)
{
    address P;
    P = Alokasi(databaru);
    if (ListEmpty(*L))
    { // kosong
        // head = baru;
        First(*L) = P;
    }
    else
    {
        address last = First(*L); // untuk menunjuk ke elemen terakhir
        // while (Next(last) != First(*L))
        // {
        //     last = Next(last);
        // }
        // Next(P) = First(*L);
        // First(*L) = P;
        // Next(last) = First(*L);
        Next(P) = First(*L); // next elemen baru diisi dengan head
        Prev(P) = last; // prev elemen baru diisi dengan elemen terakhir
        First(*L) = P; // head diisi dengan elemen baru

    }

    cout << Info(P) << " Data Masuk" << endl;
}

void List::PrintInfo(List L, bool asc)
{
    address bantu;
    if(ListEmpty(L))
    {
        printf("List Kosong\n"); 
    }
    else {
        bantu = First(L);
        do {
            if(asc)
            {
                printf("|%d| ", Info(bantu));
            }
            bantu = Next(bantu);
        } while (Next(bantu) != Nil);

        if(bantu != Nil && asc==true){
            printf("|%d| ", Info(bantu));
        }

        if (asc == false)
        {
            do {
                printf("|%d| ", Info(bantu));
                bantu = Prev(bantu);
            } while (Prev(bantu) != Nil);
            printf("|%d| ", Info(bantu));
        }
    }
}

// dealokasi dipanggil saat ada penghapusan element
void List::Dealokasi(address *P)
{
    free(*P);
}

// insert belakang
void List::insertBelakang(List *L, infotype databaru)
{
    address P;
    P = Alokasi(databaru); 
    if (ListEmpty(List(*L)))
    { // kosong
        // head = baru;
        First(*L) = P;
    }
    else
    { // isi
        // baru->next = head;
        address Q;
        Q = First(*L);
        while (Next(Q) != Nil)
        {
            Q = Next(Q);
        }
        Next(Q) = P;
        Prev(P) = Q;

    }
    cout << Info(P) << " Data Masuk" << endl;
}

// delete depan
void List::deleteDepan(List *L)
{
    if (ListEmpty(*L))
    {
        cout << "List Kosong" << endl;
    }
    else
    {
        address P;
        P = First(*L);
        First(*L) = Next(P);
        Next(P) = Nil;
        Prev(First(*L)) = Nil;
        Dealokasi(&P);
    }
}

// delete belakang
void List::deleteBelakang(List *L)
{
    if (ListEmpty(*L))
    {
        cout << "List Kosong" << endl;
    }
    else
    {
        address P;
        P = First(*L);
        while (Next(P) != Nil)
        {
            P = Next(P);
        }
        Prev(Next(P)) = Nil;
        Next(P) = Nil;
        Dealokasi(&P);
    }
}

// nbEl
int List::nbEl(List L)
{
    int i = 0;
    address P;
    P = First(L);
    if (ListEmpty(L))
    {
        return 0;
    }
    else
    {
        do
        {
            i++;
            P = Next(P);
        } while (P != First(L));
    }
    return i;
}

// REVERSE
void List::reverse(List *L, List *L2)
{
    address P;
    P = First(*L);
    if (ListEmpty(*L))
    {
        cout << "List Kosong" << endl;
    }
    else
    {
        do
        {
            insertDepan(L2, Info(P));
            P = Next(P);
        } while (P != First(*L));
    }
}

// Cari akan mengecek berapa data yang ditemukan dan menampilkan data yang ditemukan dengan menjumlahkan data yang ditemukan
// void List::cari(List L, infotype cari)
// {
//     address P;
//     P = First(L);
//     int i = 0;
//     if (ListEmpty(L))
//     {
//         cout << "List Kosong" << endl;
//     }
//     else
//     {
//         do
//         {
//             if (Info(P) == cari)
//             {
//                 i++;
//             }
//             P = Next(P);
//         } while (P != First(L));
//     }
//     cout << "Data " << cari << " ditemukan sebanyak " << i << " kali" << endl;
// }



void List::Cari(List L, infotype cari)
{
    address P;
    P = First(L);
    int i = 0;
    if (ListEmpty(L))
    {
        cout << "List Kosong" << endl;
    }
    else
    {
        // do
        // {
        //     if (Info(P) == cari)
        //     {
        //         cout << "Data " << cari << " ditemukan sebanyak " << i << " kali" << endl;
        //         i++;
        //     }
        //     P = Next(P);
        // } while (P != First(L));

        while (P != Nil)
        {
            if (Info(P) == cari)
            {
                
                i++;
            }
            P = Next(P);
            
        }
        

    }
    cout << "Data " << cari << " ditemukan sebanyak " << i << " kali" << endl;
    
    
}

// //cari data yang menampilkan data ditemukan atau tidak
// void List::Cari(List L, infotype X)
// {
//     address P;
//     P = First(L);
//     if (ListEmpty(L))
//     {
//         cout << "List Kosong" << endl;
//     }
//     else
//     {
//         do
//         {
//             if (Info(P) == X)
//             {
//                 cout << infotype(X) << " Data Ketemu" << endl;
//                 break;
//             }
//             else
//             {
//                 P = Next(P);
//             }
//         } while (P != First(L));
//         if (P == Nil)
//         {
//             cout << " Data Tidak Ketemu" << endl;
//         }
//     }
// }
