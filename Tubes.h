#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#include <iostream>
using namespace std;

typedef struct ElementInduk *adrinduk;
typedef struct ElementChild *adrchild;
typedef struct ElementPointerChild *adrpointerchild;
typedef struct indukartef infotype;
struct mainstat{
    string namastat;
    float angka;
};

struct indukartef{
    string id;
    int level;
    string piece;
    string Set;
    int rarity;
    mainstat stats;
    float substats1;
    float substats2;
    float substats3;
    float substats4;
};
struct ElementInduk{
    infotype info;
    adrpointerchild nextchild;
    adrinduk nextinduk;
};

struct ElementPointerChild{
    adrchild info;
    adrpointerchild next;
};

struct ElementChild{
    string info;
    adrchild next;
};

struct ListInduk{
    adrinduk first;
};

struct ListChild{
    adrchild first;
};

void createListInduk(ListInduk &LI);
void createListChild(ListChild &LC);
adrinduk createElementInduk(infotype data);
adrchild createElementChild(string x);
//adrpointerchild createElementPointerChild(ListChild LC, string x);
void insertFirstInduk(ListInduk &LI, adrinduk ind);//spesifikasi nomor 1
void insertLastInduk(ListInduk &LI, adrinduk ind);//spesifikasi nomor 1
void showAllInduk(ListInduk LI);//spesifikasi nomor 2
void deleteIndukDanRelasi(ListInduk &LI,string idArtef);//spesifikasi nomor 3
adrinduk searchInduk(ListInduk LI,string idArtef);//spesifikasi nomor 4
adrchild searchChild(ListChild LC,string keyword);//spesifikasi nomor 5
void insertFirstChild(ListChild &LC, adrchild chi);//spesifikasi nomor 6
void insertLastChild(ListChild &LC, adrchild chi);//spesifikasi nomor 6
void hubungkanIndukChild(ListInduk &LI, ListChild LC, string idArtef, string namachild);//spesifikasi nomor 7
void showAllIndukChild(ListInduk LI, ListChild LC);//spesifikasi nomor 8
bool findChildInParent(ListInduk LI, ListChild LC, string idArtef, string carichild);//spesifikasi nomor 9
void deleteChildDariInduk(ListInduk &LI, ListChild LC,string idArtef, string carichild);//spesifikasi nomor 10
int banyakDataChild(ListInduk LI, ListChild LC, string idArtef);//spesifikasi nomor 11
bool adaChild(ListChild LC,string namachild);//fungsi buatan sendiri buat gampangin tracing doang
void showAllChild(ListChild LC);//fungsi buatan sendiri buat gampangin tracing doang
bool cekID(ListInduk LI, string idArtef);//fungsi buatan sendiri buat gampangin tracing doang
int indeksInduk(ListInduk LI, string idArtef);//fungsi buatan sendiri buat gampangin tracing doang
int indeksChild(ListChild LC,string namachild);//fungsi buatan sendiri buat gampangin tracing doang
void MulaiMenu();//fungsi buatan sendiri buat gampangin tracing doang






#endif // TUBES_H_INCLUDED
