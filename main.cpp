#include "double.hpp"

int main()
{
    // mengecek apakah list kosong
    List L;
    L.CreateList(&L);
    cout << "List Kosong : " << L.ListEmpty(L) << endl;

    //insert depan
    cout << "Insert Depan" << endl;
    L.insertDepan(&L, 1);
    L.insertDepan(&L, 2);
    L.insertDepan(&L, 3);
    L.insertDepan(&L, 4);
    L.insertDepan(&L, 5);
    L.insertDepan(&L, 6);

    cout << endl;
    //insert Belakang
    cout << "Insert Belakang" << endl;
    L.insertBelakang(&L, 7);
    L.insertBelakang(&L, 5);
    L.insertBelakang(&L, 8);
    L.insertBelakang(&L, 5);

    cout << endl;
    //cari data
    cout << "Cari Data" << endl;
    L.Cari(L, 5);

    return 0;
}
