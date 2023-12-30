<<<<<<< HEAD
#include <iostream>
#include "Tubes.h"
using namespace std;

void createListInduk(ListInduk &LI){
    LI.first = NULL;
}

void createListChild(ListChild &LC){
    LC.first = NULL;
}

adrinduk createElementInduk(infotype data){
    adrinduk ind = new ElementInduk;
    ind->info = data;
    ind->nextchild = NULL;
    ind->nextinduk = NULL;
    return ind;
}

adrchild createElementChild(string x){
    adrchild chi = new ElementChild;
    chi->info = x;
    chi->next = NULL;
    return chi;
}

//adrpointerchild createElementPointerChild(ListChild LC, string x){
//    adrchild chi = LC.first;
//    adrpointerchild pchi = new ElementPointerChild;
//    if (chi==NULL){
//        cout<<"List Data Child Kosong"<<endl;
//        return NULL;
//    }
//    while(chi!=NULL){
//        if(chi->info == x){
//            pchi->info = chi;
//            pchi->next = NULL;
//            return pchi;
//        }
//        chi = chi->next;
//    }
//    return NULL;
//}

void insertFirstInduk(ListInduk &LI, adrinduk ind){
    ind->nextinduk = LI.first;
    LI.first = ind;
}

void insertLastInduk(ListInduk &LI, adrinduk ind){
    adrinduk p = LI.first;
    if(p==NULL){
        LI.first = ind;
    }else{
        while(p->nextinduk!=NULL){
            p = p->nextinduk;
        }
        p->nextinduk = ind;
    }
}

void showAllInduk(ListInduk LI){
    int i = 1;
    adrinduk p = LI.first;
    if(p==NULL){
        cout<<"List Data Parent Kosong"<<endl;
    }else{
        while(p!=NULL){
            cout<<""<<endl;
            cout <<"List Data Parent Ke "<<i<<" :";
            cout<<"ID Artefak: "<<p->info.id<<endl;
            cout<<"Level Artefak: "<<p->info.level<<endl;
            cout<<"Piece: "<<p->info.piece<<endl;
            cout<<"Set: "<<p->info.Set<<endl;
            cout<<"Rarity: "<<p->info.rarity<<endl;
            cout<<"Main Stat: "<<p->info.stats.namastat<<" "<<p->info.stats.angka<<endl;
            cout<<"Sub stat 1: "<<p->info.substats1<<endl;
            cout<<"Sub stat 2: "<<p->info.substats2<<endl;
            cout<<"Sub stat 3: "<<p->info.substats3<<endl;
            cout<<"Sub stat 4: "<<p->info.substats4<<endl;
            cout<<"===================================="<<endl;
            i++;
            p = p->nextinduk;
        }
    }
}

void deleteIndukDanRelasi(ListInduk &LI,string idArtef){
    adrinduk ind = LI.first;
    adrinduk belakang = ind;
    adrpointerchild pchi;
    if(ind==NULL){
        cout<<"List Data Parent Kosong"<<endl;
    }else{
        while(ind!=NULL && ind->info.id != idArtef){
            belakang = ind;
            ind = ind->nextinduk;
        }
        if(ind->info.id == idArtef){
            pchi = ind->nextchild;
            while(pchi!=NULL){
                pchi->info = NULL;
                pchi = pchi->next;
            }
            delete ind->nextchild;
            ind->nextchild = NULL;
            if(ind == LI.first&&LI.first->nextinduk==NULL){
                LI.first = NULL;
            }else if (ind == LI.first && LI.first->nextinduk!=NULL){
                LI.first = LI.first->nextinduk;
                ind->nextinduk = NULL;
            }else if(ind->nextinduk == NULL && ind!=LI.first){
                belakang->nextinduk = NULL;
            }else{
                belakang->nextinduk = ind->nextinduk;
                ind->nextinduk = NULL;
            }
        }else{
            cout<<"Artefak Dengan ID "<<idArtef<<" tidak ditemukan"<<endl;
        }
    }
}

adrinduk searchInduk(ListInduk LI,string idArtef){
    adrinduk ind = LI.first;
    while(ind!=NULL){
        if(ind->info.id == idArtef){
            return ind;
        }
        ind = ind->nextinduk;
    }
    return NULL;
}

adrchild searchChild(ListChild LC,string keyword){
    adrchild chi = LC.first;
    while(chi!=NULL){
        if(chi->info == keyword){
//            cout<<"Child dengan nama: "<<keyword<<" ditemukan pada alamat "<<chi<<endl;
            return chi;
        }
        chi = chi->next;
    }
    return NULL;
}

void insertFirstChild(ListChild &LC, adrchild chi){
    chi->next = LC.first;
    LC.first = chi;
}

void insertLastChild(ListChild &LC, adrchild chi){
    adrchild p = LC.first;
    if(p==NULL){
        LC.first = chi;
    }else{
        while(p->next!=NULL){
            p = p->next;
        }
        p->next = chi;
    }
}

void hubungkanIndukChild(ListInduk &LI, ListChild LC, string idArtef, string namachild){
    adrpointerchild pchi;
    adrpointerchild baru = new ElementPointerChild;
    adrchild chi = LC.first;
    adrinduk cari = LI.first;
    if(chi==NULL){
        cout<<"Tidak Ada List Data Child yang Bisa Dihubungkan"<<endl;
    }else{
        while(chi!=NULL && chi->info!= namachild){
            chi = chi->next;
        }
        if(chi==NULL){
            cout<<"Tidak Ditemukan Data Child Dengan Nama "<<namachild<<endl;
        }else{
            if(cari==NULL){
                cout<<"List Data Parent Kosong"<<endl;
            }else{
                while(cari!=NULL && cari->info.id!=idArtef){
                    cari = cari->nextinduk;
                }
                if(cari==NULL){
                    cout<<"Tidak Ditemukan Data Artefak Dengan ID: "<<idArtef<<endl;
                }else{
                    pchi = cari->nextchild;
                    if(pchi==NULL){
                        cari->nextchild = baru;
                        baru->info = chi;
                        baru->next = NULL;
                    }else{
                        while(pchi->next!=NULL){
                            pchi = pchi->next;
                        }
                        pchi->next = baru;
                        baru->info = chi;
                        baru->next = NULL;
                    }
                }
            }
        }
    }
}

void showAllIndukChild(ListInduk LI, ListChild LC){
    adrinduk ind = LI.first;
    adrpointerchild pchi;
    int i = 1;
    int iterasiSubstat = 0;
    if(ind==NULL){
        cout<<"List Data Artefak Kosong"<<endl;
    }else{
        while(ind!=NULL){
            pchi = ind->nextchild;
            cout <<"Data Artefak Ke "<<i<<" :";
            cout<<"ID Artefak: "<<ind->info.id<<endl;
            cout<<"Level Artefak: "<<ind->info.level<<endl;
            cout<<"Piece: "<<ind->info.piece<<endl;
            cout<<"Set: "<<ind->info.Set<<endl;
            cout<<"Rarity: "<<ind->info.rarity<<endl;
            cout<<"Main Stat: "<<ind->info.stats.namastat<<" "<<ind->info.stats.angka<<endl;
            if (pchi!=NULL){
                cout<<"Sub stat 1: "<<pchi->info->info<<" "<<ind->info.substats1<<endl;
                pchi = pchi->next;
            }else{
//                cout<<"Sub stat 1: 0"<<endl;
            }
            if (pchi!=NULL){
                cout<<"Sub stat 2: "<<pchi->info->info<<" "<<ind->info.substats2<<endl;
                pchi = pchi->next;
            }else{
//                cout<<"Sub stat 2: 0"<<endl;
            }
            if (pchi!=NULL){
                cout<<"Sub stat 3: "<<pchi->info->info<<" "<<ind->info.substats3<<endl;
                pchi = pchi->next;
            }else{
//                cout<<"Sub stat 3: 0"<<endl;
            }
            if (pchi!=NULL){
                cout<<"Sub stat 4: "<<pchi->info->info<<" "<<ind->info.substats4<<endl;
                pchi = pchi->next;
            }else{
//                cout<<"Sub stat 4: 0"<<endl;
            }
            cout<<"===================================="<<endl;
            i++;
            ind = ind->nextinduk;
        }
    }
}

bool findChildInParent(ListInduk LI, ListChild LC, string idArtef, string carichild){
    adrchild chi = LC.first;
    adrinduk ind = LI.first;
    adrpointerchild pchi;
    while(chi!=NULL && chi->info!=carichild){
        chi = chi->next;
    }
    if(chi==NULL){
        return false;
    }else{
        while(ind!=NULL){
            if(ind->info.id == idArtef){
                pchi = ind->nextchild;
                while(pchi!=NULL){
                    if(pchi->info == chi){
                        return true;
                    }
                    pchi = pchi->next;
                }
            }
            ind = ind->nextinduk;
        }
    }
    return false;
}

void deleteChildDariInduk(ListInduk &LI, ListChild LC,string idArtef, string carichild){
    adrpointerchild pchi;
    adrpointerchild belakang;
    adrinduk ind = LI.first;
    adrchild chi = searchChild(LC,carichild);
    int i = 1;
    if(LC.first==NULL){
        cout<<"List Data Child Kosong"<<endl;
    }else if(chi==NULL){
        cout<<"Tidak Ada Data Child Dengan Nama "<<carichild<<endl;
    }else{
        if(ind==NULL){
            cout<<"List Data Artefak Kosong"<<endl;
        }else{
            while(ind!=NULL && ind->info.id!=idArtef){
                ind = ind->nextinduk;
            }
            if(ind==NULL){
                cout<<"Tidak Ada Artefak Dengan ID "<<idArtef<<endl;
            }else{
                pchi = ind->nextchild;
                belakang = pchi;
                while(pchi!=NULL && pchi->info!=chi){
                    belakang = pchi;
                    pchi = pchi->next;
                    i++;
                }
                if(pchi==ind->nextchild){
                    pchi->info = NULL;
                    ind->nextchild = pchi->next;
                    pchi->next = NULL;
                    ind->info.substats1 = 0;
                }else if(pchi->next==NULL){
                    pchi->info=NULL;
                    belakang->next=NULL;
                    ind->info.substats4 = 0;
                }else if(pchi==NULL){
                    cout<<"Tidak Ada Data Child "<<carichild<<" didalam Artefak Dengan ID "<<idArtef<<endl;
                }else{
                    belakang->next = pchi->next;
                    pchi->info = NULL;
                    pchi->next = NULL;
                    if(i==2){
                        ind->info.substats2 = 0;
                    }else if(i==3){
                        ind->info.substats3 = 0;
                    }
                }
            }
        }
    }
}

int banyakDataChild(ListInduk LI, ListChild LC, string idArtef){
    adrinduk ind = LI.first;
    adrpointerchild pchi;
    int i = 0;
    if (LI.first == NULL){
        cout<<"List Data Artefak Kosong"<<endl;
        return 0;
    }else {
        while(ind!=NULL && ind->info.id!=idArtef){
            ind = ind->nextinduk;
        }
        if (ind==NULL){
            cout<<"Tidak Ada Artefak Dengan ID "<<idArtef<<endl;
            return 0;
        }else{
            pchi = ind->nextchild;
            while(pchi!=NULL){
                i++;
                pchi = pchi->next;
            }
            return i;
        }
    }
}

bool adaChild(ListChild LC,string namachild){
    adrchild chi = LC.first;
    bool hasil = false;
    if(LC.first==NULL){
        return false;
    }else{
        while(chi!=NULL){
            if(chi->info==namachild){
                return true;
            }
            chi = chi->next;
        }
    }
    return false;
}

void showAllChild(ListChild LC){
    adrchild chi = LC.first;
    int i = 1;
    if(LC.first==NULL){
        cout<<"List Data Child Kosong"<<endl;
    }else{
        cout<<"Berikut Adalah List Data Child yang Terdaftar"<<endl;
        while(chi!=NULL){
            cout<<i<<". "<<chi->info<<endl;
            i++;
            chi = chi->next;
        }
    }
}

bool cekID(ListInduk LI, string idArtef){
    bool hasil = false;
    adrinduk ind = LI.first;
    while(ind!=NULL){
        if(ind->info.id == idArtef){
            return true;
        }
        ind = ind->nextinduk;
    }
    return false;
}

int indeksInduk(ListInduk LI,string idArtef){
    int i = 1;
    adrinduk ind = LI.first;
    while(ind!=NULL){
        if(ind->info.id==idArtef){
            return i;
        }
        i++;
        ind = ind->nextinduk;
    }
    return 0;
}

int indeksChild(ListChild LC, string namachild){
    int i = 1;
    adrchild chi = LC.first;
    while(chi!=NULL){
        if(chi->info==namachild){
            return i;
        }
        i++;
        chi = chi->next;
    }
    return 0;
}

void MulaiMenu(){
    ListInduk LI;
    ListChild LC;
    adrchild carichild;
    adrinduk ind;
    bool antibreak = true;
    char inputMainStat[100];
    char inputSubStat[100];
    char inputSubStat2[100];
    char inputSubStat3[100];
    char inputSubStat4[100];
    char piece[100];
    char Set[100];
    string pilih;
    string idArtef;
    string idArtefBuatCari;
    string namaSubstatBuatCari;
    int pilihint;
    string lanjut = "";
    infotype data;
    data.stats.namastat = "";
    string datasubstat = "";
    string datasubstatakhir = "";
    string datasubstatakhir2 = "";
    string datasubstatakhir3 = "";
    string datasubstatakhir4 = "";
    createListInduk(LI);
    createListChild(LC);
    data.stats.namastat = "";
    cout<<"Selamat Datang Di Program Artefak Genshin Impact!"<<endl;
    cout<<"Silakan Ikuti Instruksi dibawah Ini Untuk Menjalankan Program!"<<endl;
    cout<<"===================================="<<endl;
    while(lanjut!="stop"){
        cout<<"1. Tambah Artefak Baru (Parent)"<<endl;
        cout<<"2. Tambah Data Substats Baru (child)"<<endl;
        cout<<"3. Lihat Semua Artefak Yang Terdaftar (Show All Induk)"<<endl;
        cout<<"4. Lihat Semua Artefak Yang Terdaftar Beserta Substats nya (Show All Induk with Child)"<<endl;
        cout<<"5. Hapus Data Artefak Beserta Relasinya"<<endl;
        cout<<"6. Cari Artefak (Parent)"<<endl;
        cout<<"7. Cari Child"<<endl;
        cout<<"8. Cari Data Child Pada Artefak"<<endl;
        cout<<"9. Hapus Data Child Pada Artefak Tertentu"<<endl;
        cout<<"10. Hitung Banyak Child Pada Artefak Tertentu"<<endl;
        cout<<"11. Tampilkan Semua Data Child Yang Terdaftar"<<endl;
        cout<<"<=> Ketik Apasaja Selain Opsi Diatas Untuk Keluar Dari Program <=>"<<endl;
        cin>>pilih;
        if(pilih=="1"){
            cout<<"Masukkan ID Artefak: "<<endl;
            cin>>data.id;
            while(cekID(LI,data.id)){
                cout<<"Sudah Ada Artefak Dengan ID "<<data.id<<endl;
                cout<<"Masukkan Ulang ID Artefak: ";
                cin>>data.id;
            }
            cout<<"Masukkan Rarity Artefak: "<<endl;
            cin>>data.rarity;
            while(data.rarity<1 || data.rarity>5){
                cout<<"Rarity Artefak Hanya Bisa Dalam Range 1 Sampai 5"<<endl;
                cout<<"Masukkan Ulang Rarity Artefak: "<<endl;
                cin>>data.rarity;
            }
            cout<<"Masukkan Level Artefak: "<<endl;
            cin>>data.level;
            if(data.rarity==1){
                while(data.level<0||data.level>4){
                    cout<<"Level Artefak Dengan Rarity 1 Hanya Ada Dalam Range 0 Sampai 4"<<endl;
                    cout<<"Masukkan Ulang Level Artefak: "<<endl;
                    cin>>data.level;
                }
            }else if(data.rarity==2){
                while(data.level<0||data.level>8){
                    cout<<"Level Artefak Dengan Rarity 2 Hanya Ada Dalam Range 0 Sampai 8"<<endl;
                    cout<<"Masukkan Ulang Level Artefak: "<<endl;
                    cin>>data.level;
                }
            }else if(data.rarity==3){
                while(data.level<0||data.level>12){
                    cout<<"Level Artefak Dengan Rarity 3 Hanya Ada Dalam Range 0 Sampai 12"<<endl;
                    cout<<"Masukkan Ulang Level Artefak: "<<endl;
                    cin>>data.level;
                }
            }else if(data.rarity==4){
                while(data.level<0||data.level>16){
                    cout<<"Level Artefak Dengan Rarity 4 Hanya Ada Dalam Range 0 Sampai 16"<<endl;
                    cout<<"Masukkan Ulang Level Artefak: "<<endl;
                    cin>>data.level;
                }
            }else if(data.rarity==5){
                while(data.level<0||data.level>20){
                    cout<<"Level Artefak Dengan Rarity 5 Hanya Ada Dalam Range 0 Sampai 20"<<endl;
                    cout<<"Masukkan Ulang Level Artefak: "<<endl;
                    cin>>data.level;
                }
            }
            cout<<"Masukkan Piece Artefak: "<<endl;
            fflush(stdin);
            cin.getline(piece, 100);
            data.piece = piece;
            cout<<"Masukkan Set Artefak: "<<endl;
            fflush(stdin);
            cin.getline(Set, 100);
            data.Set = Set;
            cout<<"Masukkan Nama Main Stats Artefak: "<<endl;
//            while(datasubstat!="."){
//                cin>>datasubstat;
//                if(data.stats.namastat!=""&&datasubstat!="."){
//                    data.stats.namastat = data.stats.namastat+" "+datasubstat;
//                }
//                if(data.stats.namastat=="" && datasubstat!="."){
//                    data.stats.namastat = datasubstat;
//                }
//            }
            fflush(stdin);
            cin.getline(inputMainStat,1000);
            data.stats.namastat = inputMainStat;
            datasubstat = "";
            cout<<"Masukkan Nilai Main Stats (Tidak Perlu Memakai %)"<<endl;
            cin>>data.stats.angka;
            if(data.rarity==1){
                cout<<"Masukkan Nama Substats 1 Artefak: "<<endl;
//                while(datasubstat!="."){
//                    cin>>datasubstat;
//                    if(datasubstatakhir!=""&&datasubstat!="."){
//                        datasubstatakhir = datasubstatakhir+" "+datasubstat;
//                    }
//                    if(datasubstatakhir=="" && datasubstat!="."){
//                        datasubstatakhir = datasubstat;
//                    }
//                }
                fflush(stdin);
                cin.getline(inputSubStat,100);
                carichild = searchChild(LC,inputSubStat);
                if(carichild==NULL){
                    adrchild chi = createElementChild(inputSubStat);
                    insertLastChild(LC,chi);
                }
                    cout<<"Masukkan Nilai Substat 1: "<<endl;
                    cin>>data.substats1;
                    data.substats2 = 0;
                    data.substats3 = 0;
                    data.substats4 = 0;
                    ind = createElementInduk(data);
                    cout<<"1. Insert First"<<endl;
                    cout<<"2. Insert Last"<<endl;
                    cin>>pilihint;
                    while(pilihint<1 || pilihint>2){
                        cout<<"Masukkan Opsi Dengan Benar!"<<endl;
                        cout<<"1. Insert First"<<endl;
                        cout<<"2. Insert Last"<<endl;
                        cin>>pilihint;
                    }
                    if(pilihint==1){
                        insertFirstInduk(LI,ind);
                    }else if(pilihint==2){
                        insertLastInduk(LI, ind);
                    }
                    hubungkanIndukChild(LI,LC,data.id,inputSubStat);
            }else if(data.rarity == 2){
                cout<<"Masukkan Nama Substats 1 Artefak: "<<endl;
//                while(datasubstat!="."){
//                    cin>>datasubstat;
//                    if(datasubstatakhir!=""&&datasubstat!="."){
//                        datasubstatakhir = datasubstatakhir+" "+datasubstat;
//                    }
//                    if(datasubstatakhir=="" && datasubstat!="."){
//                        datasubstatakhir = datasubstat;
//                    }
//                }
                fflush(stdin);
                cin.getline(inputSubStat, 100);
                carichild = searchChild(LC,inputSubStat);
                if(carichild==NULL){
                    adrchild chi = createElementChild(inputSubStat);
                    insertLastChild(LC,chi);
                }
                    cout<<"Masukkan Nilai Substat 1: "<<endl;
                    cin>>data.substats1;
                    data.substats3 = 0;
                    data.substats4 = 0;
                    cout<<"Masukkan Nama Substats 2 Artefak: "<<endl;
                    datasubstat = "";
//                    while(datasubstat!="."){
//                        cin>>datasubstat;
//                        if(datasubstatakhir2!=""&&datasubstat!="."){
//                            datasubstatakhir2 = datasubstatakhir2+" "+datasubstat;
//                        }
//                        if(datasubstatakhir2=="" && datasubstat!="."){
//                            datasubstatakhir2 = datasubstat;
//                        }
//                    }
                    fflush(stdin);
                    cin.getline(inputSubStat2,100);
                    carichild = searchChild(LC,inputSubStat2);
                    if (carichild == NULL){
                        adrchild chi = createElementChild(inputSubStat2);
                        insertLastChild(LC,chi);
                    }
                        cout<<"Masukkan Nilai Substats 2: "<<endl;
                        cin>>data.substats2;
                        ind = createElementInduk(data);
                        cout<<"1. Insert First"<<endl;
                        cout<<"2. Insert Last"<<endl;
                        cin>>pilihint;
                        while(pilihint<1 || pilihint>2){
                            cout<<"Masukkan Opsi Dengan Benar!"<<endl;
                            cout<<"1. Insert First"<<endl;
                            cout<<"2. Insert Last"<<endl;
                            cin>>pilihint;
                        }
                        if(pilihint==1){
                            insertFirstInduk(LI,ind);
                        }else if(pilihint==2){
                            insertLastInduk(LI, ind);
                        }
                        hubungkanIndukChild(LI,LC,data.id,inputSubStat);
                        hubungkanIndukChild(LI,LC,data.id,inputSubStat2);
            }else if(data.rarity == 3){
                cout<<"Masukkan Nama Substats 1 Artefak: "<<endl;
//                while(datasubstat!="."){
//                    cin>>datasubstat;
//                    if(datasubstatakhir!=""&&datasubstat!="."){
//                        datasubstatakhir = datasubstatakhir+" "+datasubstat;
//                    }
//                    if(datasubstatakhir=="" && datasubstat!="."){
//                        datasubstatakhir = datasubstat;
//                    }
//                }
                fflush(stdin);
                cin.getline(inputSubStat,100);
                carichild = searchChild(LC,inputSubStat);
                if(carichild==NULL){
                    adrchild chi = createElementChild(inputSubStat);
                    insertLastChild(LC,chi);
                }
                    cout<<"Masukkan Nilai Substat 1: "<<endl;
                    cin>>data.substats1;
                    data.substats4 = 0;
                    cout<<"Masukkan Nama Substats 2 Artefak: "<<endl;
                    datasubstat = "";
//                    while(datasubstat!="."){
//                        cin>>datasubstat;
//                        if(datasubstatakhir2!=""&&datasubstat!="."){
//                            datasubstatakhir2 = datasubstatakhir2+" "+datasubstat;
//                        }
//                        if(datasubstatakhir2=="" && datasubstat!="."){
//                            datasubstatakhir2 = datasubstat;
//                        }
//                    }
                    fflush(stdin);
                    cin.getline(inputSubStat2, 100);
                    carichild = searchChild(LC,inputSubStat2);
                    if (carichild == NULL){
                        adrchild chi = createElementChild(inputSubStat2);
                        insertLastChild(LC,chi);
                    }
                        cout<<"Masukkan Nilai Substats 2: "<<endl;
                        cin>>data.substats2;
                        cout<<"Masukkan Nama Substats 3 Artefak: "<<endl;
                        datasubstat = "";
//                        while(datasubstat!="."){
//                            cin>>datasubstat;
//                            if(datasubstatakhir3!=""&&datasubstat!="."){
//                                datasubstatakhir3 = datasubstatakhir3+" "+datasubstat;
//                            }
//                            if(datasubstatakhir3=="" && datasubstat!="."){
//                                datasubstatakhir3 = datasubstat;
//                            }
//                        }
                        fflush(stdin);
                        cin.getline(inputSubStat3, 100);
                        carichild = searchChild(LC,inputSubStat3);
                        if (carichild == NULL){
                            adrchild chi = createElementChild(inputSubStat3);
                            insertLastChild(LC,chi);
                        }
                            cout<<"Masukkan Nilai Substats 3: "<<endl;
                            cin>>data.substats3;
                            ind = createElementInduk(data);
                            cout<<"1. Insert First"<<endl;
                            cout<<"2. Insert Last"<<endl;
                            cin>>pilihint;
                            while(pilihint<1 || pilihint>2){
                                cout<<"Masukkan Opsi Dengan Benar!"<<endl;
                                cout<<"1. Insert First"<<endl;
                                cout<<"2. Insert Last"<<endl;
                                cin>>pilihint;
                            }
                            if(pilihint==1){
                                insertFirstInduk(LI,ind);
                            }else if(pilihint==2){
                                insertLastInduk(LI, ind);
                            }
                            hubungkanIndukChild(LI,LC,data.id,inputSubStat);
                            hubungkanIndukChild(LI,LC,data.id,inputSubStat2);
                            hubungkanIndukChild(LI,LC,data.id,inputSubStat3);
            }else if(data.rarity == 4 || data.rarity == 5){
                cout<<"Masukkan Nama Substats 1 Artefak: "<<endl;
//                while(datasubstat!="."){
//                    cin>>datasubstat;
//                    if(datasubstatakhir!=""&&datasubstat!="."){
//                        datasubstatakhir = datasubstatakhir+" "+datasubstat;
//                    }
//                    if(datasubstatakhir=="" && datasubstat!="."){
//                        datasubstatakhir = datasubstat;
//                    }
//                }
                fflush(stdin);
                cin.getline(inputSubStat, 100);
                carichild = searchChild(LC,inputSubStat);
                if(carichild==NULL){
                    adrchild chi = createElementChild(inputSubStat);
                    insertLastChild(LC,chi);
                }
                    cout<<"Masukkan Nilai Substat 1: "<<endl;
                    cin>>data.substats1;
                    cout<<"Masukkan Nama Substats 2 Artefak: "<<endl;
                    datasubstat = "";
//                    while(datasubstat!="."){
//                        cin>>datasubstat;
//                        if(datasubstatakhir2!=""&&datasubstat!="."){
//                            datasubstatakhir2 = datasubstatakhir2+" "+datasubstat;
//                        }
//                        if(datasubstatakhir2=="" && datasubstat!="."){
//                            datasubstatakhir2 = datasubstat;
//                        }
//                    }
                    fflush(stdin);
                    cin.getline(inputSubStat2, 100);
                    carichild = searchChild(LC,inputSubStat2);
                    if (carichild == NULL){
                        adrchild chi = createElementChild(inputSubStat2);
                        insertLastChild(LC,chi);
                    }
                        cout<<"Masukkan Nilai Substats 2: "<<endl;
                        cin>>data.substats2;
                        cout<<"Masukkan Nama Substats 3 Artefak: "<<endl;
                        datasubstat = "";
//                        while(datasubstat!="."){
//                            cin>>datasubstat;
//                            if(datasubstatakhir3!=""&&datasubstat!="."){
//                                datasubstatakhir3 = datasubstatakhir3+" "+datasubstat;
//                            }
//                            if(datasubstatakhir3=="" && datasubstat!="."){
//                                datasubstatakhir3 = datasubstat;
//                            }
//                        }
                        fflush(stdin);
                        cin.getline(inputSubStat3, 100);
                        carichild = searchChild(LC,inputSubStat3);
                        if (carichild == NULL){
                            adrchild chi = createElementChild(inputSubStat3);
                            insertLastChild(LC,chi);
                        }
                            cout<<"Masukkan Nilai Substats 3: "<<endl;
                            cin>>data.substats3;
                            cout<<"Masukkan Nama Substats 4 Artefak: "<<endl;
                            datasubstat = "";
//                            while(datasubstat!="."){
//                                cin>>datasubstat;
//                                if(datasubstatakhir4!=""&&datasubstat!="."){
//                                    datasubstatakhir4 = datasubstatakhir4+" "+datasubstat;
//                                }
//                                if(datasubstatakhir4=="" && datasubstat!="."){
//                                    datasubstatakhir4 = datasubstat;
//                                }
//                            }
                            fflush(stdin);
                            cin.getline(inputSubStat4, 100);
                            carichild = searchChild(LC,inputSubStat4);
                            if (carichild==NULL){
                                adrchild chi = createElementChild(inputSubStat4);
                                insertLastChild(LC,chi);
                            }
                                cout<<"Masukkan Nilai Substats 4: "<<endl;
                                cin>>data.substats4;
                                ind = createElementInduk(data);
                                cout<<"1. Insert First"<<endl;
                                cout<<"2. Insert Last"<<endl;
                                cin>>pilihint;
                                while(pilihint<1 || pilihint>2){
                                    cout<<"Masukkan Opsi Dengan Benar!"<<endl;
                                    cout<<"1. Insert First"<<endl;
                                    cout<<"2. Insert Last"<<endl;
                                    cin>>pilihint;
                                }
                                if(pilihint==1){
                                    insertFirstInduk(LI,ind);
                                }else if(pilihint==2){
                                    insertLastInduk(LI, ind);
                                }
                                hubungkanIndukChild(LI,LC,data.id,inputSubStat);
                                hubungkanIndukChild(LI,LC,data.id,inputSubStat2);
                                hubungkanIndukChild(LI,LC,data.id,inputSubStat3);
                                hubungkanIndukChild(LI,LC,data.id,inputSubStat4);
            }
        }else if(pilih=="2"){
            cout<<"Masukkan Nama Substats: "<<endl;
//            while(datasubstat!="."){
//                cin>>datasubstat;
//                if(datasubstatakhir!=""&&datasubstat!="."){
//                    datasubstatakhir = datasubstatakhir+" "+datasubstat;
//                }
//                if(datasubstatakhir=="" && datasubstat!="."){
//                    datasubstatakhir = datasubstat;
//                }
//            }
//            datasubstat = "";
            fflush(stdin);
            cin.getline(inputSubStat,100);
            if(!adaChild(LC,inputSubStat)){
                cout<<"1. Insert First"<<endl;
                cout<<"2. Insert Last"<<endl;
                cin>>pilihint;
                while(pilihint<1 || pilihint>2){
                    cout<<"Masukkan Opsi Dengan Benar!"<<endl;
                    cout<<"1. Insert First"<<endl;
                    cout<<"2. Insert Last"<<endl;
                    cin>>pilihint;
                }
                if(pilihint==1){
                    insertFirstChild(LC,createElementChild(inputSubStat));
                }else if(pilihint==2){
                    insertLastChild(LC,createElementChild(inputSubStat));
                }
                pilihint = 999123999;
            }else{
                cout<<"Substats "<<inputSubStat<<" Sudah Terdaftar"<<endl;
            }
//            datasubstatakhir = "";
        }else if(pilih=="3"){
            showAllInduk(LI);
        }else if(pilih=="4"){
            showAllIndukChild(LI,LC);
        }else if(pilih=="5"){
            if(LI.first==NULL){
                cout<<"List Artefak Kosong"<<endl;
            }else{
                cout<<"Masukkan ID Artefak yang Akan Dihapus: ";
                antibreak = true;
                cin>>idArtef;
                while(searchInduk(LI,idArtef)==NULL && antibreak){
                    cout<<"Artefak Dengan ID "<<idArtef<<" Tidak Ditemukan"<<endl;
                    cout<<"Silahkan Pilih Opsi Berikut"<<endl;
                    cout<<"1. Masukkan Ulang ID"<<endl;
                    cout<<"2. Batalkan Hapus Artefak"<<endl;
                    cin>>pilih;
                    while(!(pilih=="1" || pilih=="2")){
                        cout<<"Mohon Masukkan Opsi dengan benar!"<<endl;
                        cout<<"1. Masukkan Ulang ID"<<endl;
                        cout<<"2. Batalkan Hapus Artefak"<<endl;
                        cin>>pilih;
                    }
                    if(pilih=="1"){
                        cout<<"Masukkan ID Artefak yang Akan Dihapus: ";
                        cin>>idArtef;
                    }else if(pilih == "2"){
                        cout<<"Berhasil Membatalkan Hapus Artefak"<<endl;
                        antibreak = false;
                    }
                }
                if(antibreak){
                deleteIndukDanRelasi(LI,idArtef);
                cout<<"Artefak Dengan ID "<<idArtef<<" Berhasil Dihapus"<<endl;
                }
            }
        }else if(pilih=="6"){
            cout<<"Masukkan ID Artefak yang Akan Dicari: ";
            cin>>idArtefBuatCari;
            if(searchInduk(LI, idArtefBuatCari)!=NULL){
                cout<<"============================"<<endl;
                cout<<"Artefak Ditemukan Pada Element Ke "<<indeksInduk(LI,idArtefBuatCari)<<endl;
                cout<<"Artefak Berada Pada Alamat "<<searchInduk(LI,idArtefBuatCari)<<endl;
                cout<<"============================"<<endl;
            }else{
                if(LI.first==NULL){
                    cout<<"List Data Artefak Kosong"<<endl;
                    cout<<"============================"<<endl;
                }else{
                    cout<<"Data Artefak Tidak Ditemukan Pada List Parent"<<endl;
                    cout<<"============================"<<endl;
                }
            }
            idArtefBuatCari = "";
        }else if(pilih=="7"){
            datasubstat = "";
            datasubstatakhir = "";
            cout<<"Masukkan Nama Child yang Akan Dicari: ";
            while(datasubstat!="."){
                cin>>datasubstat;
                if(datasubstatakhir!=""&&datasubstat!="."){
                    datasubstatakhir = datasubstatakhir+" "+datasubstat;
                }
                if(datasubstatakhir=="" && datasubstat!="."){
                    datasubstatakhir = datasubstat;
                }
            }
            if(searchChild(LC,datasubstatakhir)!=NULL){
                cout<<"============================"<<endl;
                cout<<"Child Ditemukan Pada Element Ke "<<indeksChild(LC,datasubstatakhir)<<endl;
                cout<<"Child Berada Pada Alamat "<<searchChild(LC, datasubstatakhir)<<endl;
                cout<<"============================"<<endl;
            }else{
                if(LC.first==NULL){
                    cout<<"List Data Child Kosong"<<endl;
                    cout<<"============================"<<endl;
                }else{
                    cout<<"Data Child Tidak Ditemukan Pada List Child"<<endl;
                    cout<<"============================"<<endl;
                }
            }
            datasubstat = "";
            datasubstatakhir = "";
        }else if(pilih == "8"){
            cout<<"Masukkan Child Yang Akan Dicari: ";
            datasubstat = "";
            datasubstatakhir = "";
            while(datasubstat!="."){
                cin>>datasubstat;
                if(datasubstatakhir!=""&&datasubstat!="."){
                    datasubstatakhir = datasubstatakhir+" "+datasubstat;
                }
                if(datasubstatakhir=="" && datasubstat!="."){
                    datasubstatakhir = datasubstat;
                }
            }
            if(searchChild(LC,datasubstatakhir)==NULL){
                if(LC.first==NULL){
                    cout<<"List Data Child Kosong"<<endl;
                    cout<<"============================"<<endl;
                }else{
                    cout<<"Data Child Tidak Ada Didalam List Child"<<endl;
                    cout<<"============================"<<endl;
                }
            }else{
                cout<<"Masukkan ID Artefak yang Akan Dicari Childnya: ";
                cin>>idArtefBuatCari;
                if(searchInduk(LI, idArtefBuatCari)==NULL){
                    if(LI.first==NULL){
                        cout<<"List Data Artefak Kosong"<<endl;
                        cout<<"============================"<<endl;
                    }else{
                        cout<<"Data Artefak Dengan ID "<<idArtefBuatCari<<" Tidak Ditemukan"<<endl;
                        cout<<"============================"<<endl;
                    }
                }else{
                    if(findChildInParent(LI,LC,idArtefBuatCari,datasubstatakhir)){
                        cout<<"Terdapat Child "<<datasubstatakhir<<" didalam Artefak Dengan ID "<<idArtefBuatCari<<endl;
                    }else{
                        cout<<"Tidak Ada Child "<<datasubstatakhir<<" didalam Artefak Dengan ID "<<idArtefBuatCari<<endl;
                    }
                }
            }
        }else if(pilih=="9"){
            cout<<"Masukkan Child Yang Akan Dihapus: ";
            datasubstat = "";
            datasubstatakhir = "";
            while(datasubstat!="."){
                cin>>datasubstat;
                if(datasubstatakhir!=""&&datasubstat!="."){
                    datasubstatakhir = datasubstatakhir+" "+datasubstat;
                }
                if(datasubstatakhir=="" && datasubstat!="."){
                    datasubstatakhir = datasubstat;
                }
            }
            if(searchChild(LC,datasubstatakhir)==NULL){
                if(LC.first==NULL){
                    cout<<"List Data Child Kosong"<<endl;
                    cout<<"============================"<<endl;
                }else{
                    cout<<"Data Child Tidak Ada Didalam List Child"<<endl;
                    cout<<"============================"<<endl;
                }
            }else{
                cout<<"Masukkan ID Artefak yang Akan Dihapus Child "<<datasubstatakhir<<" nya: ";
                cin>>idArtefBuatCari;
                if(searchInduk(LI, idArtefBuatCari)==NULL){
                    if(LI.first==NULL){
                        cout<<"List Data Artefak Kosong"<<endl;
                        cout<<"============================"<<endl;
                    }else{
                        cout<<"Data Artefak Dengan ID "<<idArtefBuatCari<<" Tidak Ditemukan"<<endl;
                        cout<<"============================"<<endl;
                    }
                }else{
                    if(findChildInParent(LI,LC,idArtefBuatCari,datasubstatakhir)){
                        deleteChildDariInduk(LI,LC,idArtefBuatCari,datasubstatakhir);
                        cout<<"Data Child "<<datasubstatakhir<<" Pada Artefak dengan ID "<<idArtefBuatCari<<" Berhasil Dihapus"<<endl;
                    }else{
                        cout<<"Gagal Menghapus Child Pada Artefak!"<<endl;
                        cout<<"Tidak Ada Child "<<datasubstatakhir<<" didalam Artefak Dengan ID "<<idArtefBuatCari<<endl;
                    }
                }
            }
        }else if(pilih=="10"){
            cout<<"Masukkan ID Artefak yang Akan Dihitung Banyak Childnya: ";
                cin>>idArtefBuatCari;
                if(searchInduk(LI, idArtefBuatCari)==NULL){
                    if(LI.first==NULL){
                        cout<<"List Data Artefak Kosong"<<endl;
                        cout<<"============================"<<endl;
                    }else{
                        cout<<"Data Artefak Dengan ID "<<idArtefBuatCari<<" Tidak Ditemukan"<<endl;
                        cout<<"============================"<<endl;
                    }
                }else{
                    cout<<"Banyak Child Pada Artefak Dengan ID "<<idArtefBuatCari<<" adalah "<<banyakDataChild(LI,LC,idArtefBuatCari)<<endl;
                }
        }else if(pilih=="11"){
            showAllChild(LC);
        }else{
            lanjut = "stop";
        }
        if(lanjut!="stop"){
            cout<<"Ketik Apapun Untuk Melanjutkan Program atau Ketik stop Untuk Keluar dari Program"<<endl;
            cin>>lanjut;
        }
        datasubstat = "";
        data.stats.namastat = "";
        datasubstatakhir = "";
        datasubstatakhir2 = "";
        datasubstatakhir3 = "";
        datasubstatakhir4 = "";
        antibreak = true;
        pilih = "999123999";
        data.stats.namastat = "";
        pilihint = 999123999;
    }
}






=======
#include <iostream>
#include "Tubes.h"
using namespace std;

void createListInduk(ListInduk &LI){
    LI.first = NULL;
}

void createListChild(ListChild &LC){
    LC.first = NULL;
}

adrinduk createElementInduk(infotype data){
    adrinduk ind = new ElementInduk;
    ind->info = data;
    ind->nextchild = NULL;
    ind->nextinduk = NULL;
    return ind;
}

adrchild createElementChild(string x){
    adrchild chi = new ElementChild;
    chi->info = x;
    chi->next = NULL;
    return chi;
}

//adrpointerchild createElementPointerChild(ListChild LC, string x){
//    adrchild chi = LC.first;
//    adrpointerchild pchi = new ElementPointerChild;
//    if (chi==NULL){
//        cout<<"List Data Child Kosong"<<endl;
//        return NULL;
//    }
//    while(chi!=NULL){
//        if(chi->info == x){
//            pchi->info = chi;
//            pchi->next = NULL;
//            return pchi;
//        }
//        chi = chi->next;
//    }
//    return NULL;
//}

void insertFirstInduk(ListInduk &LI, adrinduk ind){
    ind->nextinduk = LI.first;
    LI.first = ind;
}

void insertLastInduk(ListInduk &LI, adrinduk ind){
    adrinduk p = LI.first;
    if(p==NULL){
        LI.first = ind;
    }else{
        while(p->nextinduk!=NULL){
            p = p->nextinduk;
        }
        p->nextinduk = ind;
    }
}

void showAllInduk(ListInduk LI){
    int i = 1;
    adrinduk p = LI.first;
    if(p==NULL){
        cout<<"List Data Parent Kosong"<<endl;
    }else{
        while(p!=NULL){
            cout<<""<<endl;
            cout <<"List Data Parent Ke "<<i<<" :";
            cout<<"ID Artefak: "<<p->info.id<<endl;
            cout<<"Level Artefak: "<<p->info.level<<endl;
            cout<<"Piece: "<<p->info.piece<<endl;
            cout<<"Set: "<<p->info.Set<<endl;
            cout<<"Rarity: "<<p->info.rarity<<endl;
            cout<<"Main Stat: "<<p->info.stats.namastat<<" "<<p->info.stats.angka<<endl;
            cout<<"Sub stat 1: "<<p->info.substats1<<endl;
            cout<<"Sub stat 2: "<<p->info.substats2<<endl;
            cout<<"Sub stat 3: "<<p->info.substats3<<endl;
            cout<<"Sub stat 4: "<<p->info.substats4<<endl;
            cout<<"===================================="<<endl;
            i++;
            p = p->nextinduk;
        }
    }
}

void deleteIndukDanRelasi(ListInduk &LI,string idArtef){
    adrinduk ind = LI.first;
    adrinduk belakang = ind;
    adrpointerchild pchi;
    if(ind==NULL){
        cout<<"List Data Parent Kosong"<<endl;
    }else{
        while(ind!=NULL && ind->info.id != idArtef){
            belakang = ind;
            ind = ind->nextinduk;
        }
        if(ind->info.id == idArtef){
            pchi = ind->nextchild;
            while(pchi!=NULL){
                pchi->info = NULL;
                pchi = pchi->next;
            }
            delete ind->nextchild;
            ind->nextchild = NULL;
            if(ind == LI.first&&LI.first->nextinduk==NULL){
                LI.first = NULL;
            }else if (ind == LI.first && LI.first->nextinduk!=NULL){
                LI.first = LI.first->nextinduk;
                ind->nextinduk = NULL;
            }else if(ind->nextinduk == NULL && ind!=LI.first){
                belakang->nextinduk = NULL;
            }else{
                belakang->nextinduk = ind->nextinduk;
                ind->nextinduk = NULL;
            }
        }else{
            cout<<"Artefak Dengan ID "<<idArtef<<" tidak ditemukan"<<endl;
        }
    }
}

adrinduk searchInduk(ListInduk LI,string idArtef){
    adrinduk ind = LI.first;
    while(ind!=NULL){
        if(ind->info.id == idArtef){
            return ind;
        }
        ind = ind->nextinduk;
    }
    return NULL;
}

adrchild searchChild(ListChild LC,string keyword){
    adrchild chi = LC.first;
    while(chi!=NULL){
        if(chi->info == keyword){
//            cout<<"Child dengan nama: "<<keyword<<" ditemukan pada alamat "<<chi<<endl;
            return chi;
        }
        chi = chi->next;
    }
    return NULL;
}

void insertFirstChild(ListChild &LC, adrchild chi){
    chi->next = LC.first;
    LC.first = chi;
}

void insertLastChild(ListChild &LC, adrchild chi){
    adrchild p = LC.first;
    if(p==NULL){
        LC.first = chi;
    }else{
        while(p->next!=NULL){
            p = p->next;
        }
        p->next = chi;
    }
}

void hubungkanIndukChild(ListInduk &LI, ListChild LC, string idArtef, string namachild){
    adrpointerchild pchi;
    adrpointerchild baru = new ElementPointerChild;
    adrchild chi = LC.first;
    adrinduk cari = LI.first;
    if(chi==NULL){
        cout<<"Tidak Ada List Data Child yang Bisa Dihubungkan"<<endl;
    }else{
        while(chi!=NULL && chi->info!= namachild){
            chi = chi->next;
        }
        if(chi==NULL){
            cout<<"Tidak Ditemukan Data Child Dengan Nama "<<namachild<<endl;
        }else{
            if(cari==NULL){
                cout<<"List Data Parent Kosong"<<endl;
            }else{
                while(cari!=NULL && cari->info.id!=idArtef){
                    cari = cari->nextinduk;
                }
                if(cari==NULL){
                    cout<<"Tidak Ditemukan Data Artefak Dengan ID: "<<idArtef<<endl;
                }else{
                    pchi = cari->nextchild;
                    if(pchi==NULL){
                        cari->nextchild = baru;
                        baru->info = chi;
                        baru->next = NULL;
                    }else{
                        while(pchi->next!=NULL){
                            pchi = pchi->next;
                        }
                        pchi->next = baru;
                        baru->info = chi;
                        baru->next = NULL;
                    }
                }
            }
        }
    }
}

void showAllIndukChild(ListInduk LI, ListChild LC){
    adrinduk ind = LI.first;
    adrpointerchild pchi;
    int i = 1;
    int iterasiSubstat = 0;
    if(ind==NULL){
        cout<<"List Data Artefak Kosong"<<endl;
    }else{
        while(ind!=NULL){
            pchi = ind->nextchild;
            cout <<"Data Artefak Ke "<<i<<" :";
            cout<<"ID Artefak: "<<ind->info.id<<endl;
            cout<<"Level Artefak: "<<ind->info.level<<endl;
            cout<<"Piece: "<<ind->info.piece<<endl;
            cout<<"Set: "<<ind->info.Set<<endl;
            cout<<"Rarity: "<<ind->info.rarity<<endl;
            cout<<"Main Stat: "<<ind->info.stats.namastat<<" "<<ind->info.stats.angka<<endl;
            if (pchi!=NULL){
                cout<<"Sub stat 1: "<<pchi->info->info<<" "<<ind->info.substats1<<endl;
                pchi = pchi->next;
            }else{
//                cout<<"Sub stat 1: 0"<<endl;
            }
            if (pchi!=NULL){
                cout<<"Sub stat 2: "<<pchi->info->info<<" "<<ind->info.substats2<<endl;
                pchi = pchi->next;
            }else{
//                cout<<"Sub stat 2: 0"<<endl;
            }
            if (pchi!=NULL){
                cout<<"Sub stat 3: "<<pchi->info->info<<" "<<ind->info.substats3<<endl;
                pchi = pchi->next;
            }else{
//                cout<<"Sub stat 3: 0"<<endl;
            }
            if (pchi!=NULL){
                cout<<"Sub stat 4: "<<pchi->info->info<<" "<<ind->info.substats4<<endl;
                pchi = pchi->next;
            }else{
//                cout<<"Sub stat 4: 0"<<endl;
            }
            cout<<"===================================="<<endl;
            i++;
            ind = ind->nextinduk;
        }
    }
}

bool findChildInParent(ListInduk LI, ListChild LC, string idArtef, string carichild){
    adrchild chi = LC.first;
    adrinduk ind = LI.first;
    adrpointerchild pchi;
    while(chi!=NULL && chi->info!=carichild){
        chi = chi->next;
    }
    if(chi==NULL){
        return false;
    }else{
        while(ind!=NULL){
            if(ind->info.id == idArtef){
                pchi = ind->nextchild;
                while(pchi!=NULL){
                    if(pchi->info == chi){
                        return true;
                    }
                    pchi = pchi->next;
                }
            }
            ind = ind->nextinduk;
        }
    }
    return false;
}

void deleteChildDariInduk(ListInduk &LI, ListChild LC,string idArtef, string carichild){
    adrpointerchild pchi;
    adrpointerchild belakang;
    adrinduk ind = LI.first;
    adrchild chi = searchChild(LC,carichild);
    int i = 1;
    if(LC.first==NULL){
        cout<<"List Data Child Kosong"<<endl;
    }else if(chi==NULL){
        cout<<"Tidak Ada Data Child Dengan Nama "<<carichild<<endl;
    }else{
        if(ind==NULL){
            cout<<"List Data Artefak Kosong"<<endl;
        }else{
            while(ind!=NULL && ind->info.id!=idArtef){
                ind = ind->nextinduk;
            }
            if(ind==NULL){
                cout<<"Tidak Ada Artefak Dengan ID "<<idArtef<<endl;
            }else{
                pchi = ind->nextchild;
                belakang = pchi;
                while(pchi!=NULL && pchi->info!=chi){
                    belakang = pchi;
                    pchi = pchi->next;
                    i++;
                }
                if(pchi==ind->nextchild){
                    pchi->info = NULL;
                    ind->nextchild = pchi->next;
                    pchi->next = NULL;
                    ind->info.substats1 = 0;
                }else if(pchi->next==NULL){
                    pchi->info=NULL;
                    belakang->next=NULL;
                    ind->info.substats4 = 0;
                }else if(pchi==NULL){
                    cout<<"Tidak Ada Data Child "<<carichild<<" didalam Artefak Dengan ID "<<idArtef<<endl;
                }else{
                    belakang->next = pchi->next;
                    pchi->info = NULL;
                    pchi->next = NULL;
                    if(i==2){
                        ind->info.substats2 = 0;
                    }else if(i==3){
                        ind->info.substats3 = 0;
                    }
                }
            }
        }
    }
}

int banyakDataChild(ListInduk LI, ListChild LC, string idArtef){
    adrinduk ind = LI.first;
    adrpointerchild pchi;
    int i = 0;
    if (LI.first == NULL){
        cout<<"List Data Artefak Kosong"<<endl;
        return 0;
    }else {
        while(ind!=NULL && ind->info.id!=idArtef){
            ind = ind->nextinduk;
        }
        if (ind==NULL){
            cout<<"Tidak Ada Artefak Dengan ID "<<idArtef<<endl;
            return 0;
        }else{
            pchi = ind->nextchild;
            while(pchi!=NULL){
                i++;
                pchi = pchi->next;
            }
            return i;
        }
    }
}

bool adaChild(ListChild LC,string namachild){
    adrchild chi = LC.first;
    bool hasil = false;
    if(LC.first==NULL){
        return false;
    }else{
        while(chi!=NULL){
            if(chi->info==namachild){
                return true;
            }
            chi = chi->next;
        }
    }
    return false;
}

void showAllChild(ListChild LC){
    adrchild chi = LC.first;
    int i = 1;
    if(LC.first==NULL){
        cout<<"List Data Child Kosong"<<endl;
    }else{
        cout<<"Berikut Adalah List Data Child yang Terdaftar"<<endl;
        while(chi!=NULL){
            cout<<i<<". "<<chi->info<<endl;
            i++;
            chi = chi->next;
        }
    }
}

bool cekID(ListInduk LI, string idArtef){
    bool hasil = false;
    adrinduk ind = LI.first;
    while(ind!=NULL){
        if(ind->info.id == idArtef){
            return true;
        }
        ind = ind->nextinduk;
    }
    return false;
}

int indeksInduk(ListInduk LI,string idArtef){
    int i = 1;
    adrinduk ind = LI.first;
    while(ind!=NULL){
        if(ind->info.id==idArtef){
            return i;
        }
        i++;
        ind = ind->nextinduk;
    }
    return 0;
}

int indeksChild(ListChild LC, string namachild){
    int i = 1;
    adrchild chi = LC.first;
    while(chi!=NULL){
        if(chi->info==namachild){
            return i;
        }
        i++;
        chi = chi->next;
    }
    return 0;
}

void MulaiMenu(){
    ListInduk LI;
    ListChild LC;
    adrchild carichild;
    adrinduk ind;
    bool antibreak = true;
    char inputMainStat[100];
    char inputSubStat[100];
    char inputSubStat2[100];
    char inputSubStat3[100];
    char inputSubStat4[100];
    char piece[100];
    char Set[100];
    char childCari[100];
    char childCariInduk[100];
    string pilih;
    string idArtef;
    string idArtefBuatCari;
    string namaSubstatBuatCari;
    int pilihint;
    string lanjut = "";
    infotype data;
    data.stats.namastat = "";
    string datasubstat = "";
    string datasubstatakhir = "";
    string datasubstatakhir2 = "";
    string datasubstatakhir3 = "";
    string datasubstatakhir4 = "";
    createListInduk(LI);
    createListChild(LC);
    data.stats.namastat = "";
    cout<<"Selamat Datang Di Program Artefak Genshin Impact!"<<endl;
    cout<<"Silakan Ikuti Instruksi dibawah Ini Untuk Menjalankan Program!"<<endl;
    cout<<"===================================="<<endl;
    while(lanjut!="stop"){
        cout<<"1. Tambah Artefak Baru (Parent)"<<endl;
        cout<<"2. Tambah Data Substats Baru (child)"<<endl;
        cout<<"3. Lihat Semua Artefak Yang Terdaftar (Show All Induk)"<<endl;
        cout<<"4. Lihat Semua Artefak Yang Terdaftar Beserta Substats nya (Show All Induk with Child)"<<endl;
        cout<<"5. Hapus Data Artefak Beserta Relasinya"<<endl;
        cout<<"6. Cari Artefak (Parent)"<<endl;
        cout<<"7. Cari Child"<<endl;
        cout<<"8. Cari Data Child Pada Artefak"<<endl;
        cout<<"9. Hapus Data Child Pada Artefak Tertentu"<<endl;
        cout<<"10. Hitung Banyak Child Pada Artefak Tertentu"<<endl;
        cout<<"11. Tampilkan Semua Data Child Yang Terdaftar"<<endl;
        cout<<"<=> Ketik Apasaja Selain Opsi Diatas Untuk Keluar Dari Program <=>"<<endl;
        cin>>pilih;
        if(pilih=="1"){
            cout<<"Masukkan ID Artefak: "<<endl;
            cin>>data.id;
            while(cekID(LI,data.id)){
                cout<<"Sudah Ada Artefak Dengan ID "<<data.id<<endl;
                cout<<"Masukkan Ulang ID Artefak: ";
                cin>>data.id;
            }
            cout<<"Masukkan Rarity Artefak: "<<endl;
            cin>>data.rarity;
            while(data.rarity<1 || data.rarity>5){
                cout<<"Rarity Artefak Hanya Bisa Dalam Range 1 Sampai 5"<<endl;
                cout<<"Masukkan Ulang Rarity Artefak: "<<endl;
                cin>>data.rarity;
            }
            cout<<"Masukkan Level Artefak: "<<endl;
            cin>>data.level;
            if(data.rarity==1){
                while(data.level<0||data.level>4){
                    cout<<"Level Artefak Dengan Rarity 1 Hanya Ada Dalam Range 0 Sampai 4"<<endl;
                    cout<<"Masukkan Ulang Level Artefak: "<<endl;
                    cin>>data.level;
                }
            }else if(data.rarity==2){
                while(data.level<0||data.level>8){
                    cout<<"Level Artefak Dengan Rarity 2 Hanya Ada Dalam Range 0 Sampai 8"<<endl;
                    cout<<"Masukkan Ulang Level Artefak: "<<endl;
                    cin>>data.level;
                }
            }else if(data.rarity==3){
                while(data.level<0||data.level>12){
                    cout<<"Level Artefak Dengan Rarity 3 Hanya Ada Dalam Range 0 Sampai 12"<<endl;
                    cout<<"Masukkan Ulang Level Artefak: "<<endl;
                    cin>>data.level;
                }
            }else if(data.rarity==4){
                while(data.level<0||data.level>16){
                    cout<<"Level Artefak Dengan Rarity 4 Hanya Ada Dalam Range 0 Sampai 16"<<endl;
                    cout<<"Masukkan Ulang Level Artefak: "<<endl;
                    cin>>data.level;
                }
            }else if(data.rarity==5){
                while(data.level<0||data.level>20){
                    cout<<"Level Artefak Dengan Rarity 5 Hanya Ada Dalam Range 0 Sampai 20"<<endl;
                    cout<<"Masukkan Ulang Level Artefak: "<<endl;
                    cin>>data.level;
                }
            }
            cout<<"Masukkan Piece Artefak: "<<endl;
            fflush(stdin);
            cin.getline(piece, 100);
            data.piece = piece;
            cout<<"Masukkan Set Artefak: "<<endl;
            fflush(stdin);
            cin.getline(Set, 100);
            data.Set = Set;
            cout<<"Masukkan Nama Main Stats Artefak: "<<endl;
//            while(datasubstat!="."){
//                cin>>datasubstat;
//                if(data.stats.namastat!=""&&datasubstat!="."){
//                    data.stats.namastat = data.stats.namastat+" "+datasubstat;
//                }
//                if(data.stats.namastat=="" && datasubstat!="."){
//                    data.stats.namastat = datasubstat;
//                }
//            }
            fflush(stdin);
            cin.getline(inputMainStat,1000);
            data.stats.namastat = inputMainStat;
            datasubstat = "";
            cout<<"Masukkan Nilai Main Stats (Tidak Perlu Memakai %)"<<endl;
            cin>>data.stats.angka;
            if(data.rarity==1){
                cout<<"Masukkan Nama Substats 1 Artefak: "<<endl;
//                while(datasubstat!="."){
//                    cin>>datasubstat;
//                    if(datasubstatakhir!=""&&datasubstat!="."){
//                        datasubstatakhir = datasubstatakhir+" "+datasubstat;
//                    }
//                    if(datasubstatakhir=="" && datasubstat!="."){
//                        datasubstatakhir = datasubstat;
//                    }
//                }
                fflush(stdin);
                cin.getline(inputSubStat,100);
                carichild = searchChild(LC,inputSubStat);
                if(carichild==NULL){
                    adrchild chi = createElementChild(inputSubStat);
                    insertLastChild(LC,chi);
                }
                    cout<<"Masukkan Nilai Substat 1: "<<endl;
                    cin>>data.substats1;
                    data.substats2 = 0;
                    data.substats3 = 0;
                    data.substats4 = 0;
                    ind = createElementInduk(data);
                    cout<<"1. Insert First"<<endl;
                    cout<<"2. Insert Last"<<endl;
                    cin>>pilihint;
                    while(pilihint<1 || pilihint>2){
                        cout<<"Masukkan Opsi Dengan Benar!"<<endl;
                        cout<<"1. Insert First"<<endl;
                        cout<<"2. Insert Last"<<endl;
                        cin>>pilihint;
                    }
                    if(pilihint==1){
                        insertFirstInduk(LI,ind);
                    }else if(pilihint==2){
                        insertLastInduk(LI, ind);
                    }
                    hubungkanIndukChild(LI,LC,data.id,inputSubStat);
            }else if(data.rarity == 2){
                cout<<"Masukkan Nama Substats 1 Artefak: "<<endl;
//                while(datasubstat!="."){
//                    cin>>datasubstat;
//                    if(datasubstatakhir!=""&&datasubstat!="."){
//                        datasubstatakhir = datasubstatakhir+" "+datasubstat;
//                    }
//                    if(datasubstatakhir=="" && datasubstat!="."){
//                        datasubstatakhir = datasubstat;
//                    }
//                }
                fflush(stdin);
                cin.getline(inputSubStat, 100);
                carichild = searchChild(LC,inputSubStat);
                if(carichild==NULL){
                    adrchild chi = createElementChild(inputSubStat);
                    insertLastChild(LC,chi);
                }
                    cout<<"Masukkan Nilai Substat 1: "<<endl;
                    cin>>data.substats1;
                    data.substats3 = 0;
                    data.substats4 = 0;
                    cout<<"Masukkan Nama Substats 2 Artefak: "<<endl;
                    datasubstat = "";
//                    while(datasubstat!="."){
//                        cin>>datasubstat;
//                        if(datasubstatakhir2!=""&&datasubstat!="."){
//                            datasubstatakhir2 = datasubstatakhir2+" "+datasubstat;
//                        }
//                        if(datasubstatakhir2=="" && datasubstat!="."){
//                            datasubstatakhir2 = datasubstat;
//                        }
//                    }
                    fflush(stdin);
                    cin.getline(inputSubStat2,100);
                    carichild = searchChild(LC,inputSubStat2);
                    if (carichild == NULL){
                        adrchild chi = createElementChild(inputSubStat2);
                        insertLastChild(LC,chi);
                    }
                        cout<<"Masukkan Nilai Substats 2: "<<endl;
                        cin>>data.substats2;
                        ind = createElementInduk(data);
                        cout<<"1. Insert First"<<endl;
                        cout<<"2. Insert Last"<<endl;
                        cin>>pilihint;
                        while(pilihint<1 || pilihint>2){
                            cout<<"Masukkan Opsi Dengan Benar!"<<endl;
                            cout<<"1. Insert First"<<endl;
                            cout<<"2. Insert Last"<<endl;
                            cin>>pilihint;
                        }
                        if(pilihint==1){
                            insertFirstInduk(LI,ind);
                        }else if(pilihint==2){
                            insertLastInduk(LI, ind);
                        }
                        hubungkanIndukChild(LI,LC,data.id,inputSubStat);
                        hubungkanIndukChild(LI,LC,data.id,inputSubStat2);
            }else if(data.rarity == 3){
                cout<<"Masukkan Nama Substats 1 Artefak: "<<endl;
//                while(datasubstat!="."){
//                    cin>>datasubstat;
//                    if(datasubstatakhir!=""&&datasubstat!="."){
//                        datasubstatakhir = datasubstatakhir+" "+datasubstat;
//                    }
//                    if(datasubstatakhir=="" && datasubstat!="."){
//                        datasubstatakhir = datasubstat;
//                    }
//                }
                fflush(stdin);
                cin.getline(inputSubStat,100);
                carichild = searchChild(LC,inputSubStat);
                if(carichild==NULL){
                    adrchild chi = createElementChild(inputSubStat);
                    insertLastChild(LC,chi);
                }
                    cout<<"Masukkan Nilai Substat 1: "<<endl;
                    cin>>data.substats1;
                    data.substats4 = 0;
                    cout<<"Masukkan Nama Substats 2 Artefak: "<<endl;
                    datasubstat = "";
//                    while(datasubstat!="."){
//                        cin>>datasubstat;
//                        if(datasubstatakhir2!=""&&datasubstat!="."){
//                            datasubstatakhir2 = datasubstatakhir2+" "+datasubstat;
//                        }
//                        if(datasubstatakhir2=="" && datasubstat!="."){
//                            datasubstatakhir2 = datasubstat;
//                        }
//                    }
                    fflush(stdin);
                    cin.getline(inputSubStat2, 100);
                    carichild = searchChild(LC,inputSubStat2);
                    if (carichild == NULL){
                        adrchild chi = createElementChild(inputSubStat2);
                        insertLastChild(LC,chi);
                    }
                        cout<<"Masukkan Nilai Substats 2: "<<endl;
                        cin>>data.substats2;
                        cout<<"Masukkan Nama Substats 3 Artefak: "<<endl;
                        datasubstat = "";
//                        while(datasubstat!="."){
//                            cin>>datasubstat;
//                            if(datasubstatakhir3!=""&&datasubstat!="."){
//                                datasubstatakhir3 = datasubstatakhir3+" "+datasubstat;
//                            }
//                            if(datasubstatakhir3=="" && datasubstat!="."){
//                                datasubstatakhir3 = datasubstat;
//                            }
//                        }
                        fflush(stdin);
                        cin.getline(inputSubStat3, 100);
                        carichild = searchChild(LC,inputSubStat3);
                        if (carichild == NULL){
                            adrchild chi = createElementChild(inputSubStat3);
                            insertLastChild(LC,chi);
                        }
                            cout<<"Masukkan Nilai Substats 3: "<<endl;
                            cin>>data.substats3;
                            ind = createElementInduk(data);
                            cout<<"1. Insert First"<<endl;
                            cout<<"2. Insert Last"<<endl;
                            cin>>pilihint;
                            while(pilihint<1 || pilihint>2){
                                cout<<"Masukkan Opsi Dengan Benar!"<<endl;
                                cout<<"1. Insert First"<<endl;
                                cout<<"2. Insert Last"<<endl;
                                cin>>pilihint;
                            }
                            if(pilihint==1){
                                insertFirstInduk(LI,ind);
                            }else if(pilihint==2){
                                insertLastInduk(LI, ind);
                            }
                            hubungkanIndukChild(LI,LC,data.id,inputSubStat);
                            hubungkanIndukChild(LI,LC,data.id,inputSubStat2);
                            hubungkanIndukChild(LI,LC,data.id,inputSubStat3);
            }else if(data.rarity == 4 || data.rarity == 5){
                cout<<"Masukkan Nama Substats 1 Artefak: "<<endl;
//                while(datasubstat!="."){
//                    cin>>datasubstat;
//                    if(datasubstatakhir!=""&&datasubstat!="."){
//                        datasubstatakhir = datasubstatakhir+" "+datasubstat;
//                    }
//                    if(datasubstatakhir=="" && datasubstat!="."){
//                        datasubstatakhir = datasubstat;
//                    }
//                }
                fflush(stdin);
                cin.getline(inputSubStat, 100);
                carichild = searchChild(LC,inputSubStat);
                if(carichild==NULL){
                    adrchild chi = createElementChild(inputSubStat);
                    insertLastChild(LC,chi);
                }
                    cout<<"Masukkan Nilai Substat 1: "<<endl;
                    cin>>data.substats1;
                    cout<<"Masukkan Nama Substats 2 Artefak: "<<endl;
                    datasubstat = "";
//                    while(datasubstat!="."){
//                        cin>>datasubstat;
//                        if(datasubstatakhir2!=""&&datasubstat!="."){
//                            datasubstatakhir2 = datasubstatakhir2+" "+datasubstat;
//                        }
//                        if(datasubstatakhir2=="" && datasubstat!="."){
//                            datasubstatakhir2 = datasubstat;
//                        }
//                    }
                    fflush(stdin);
                    cin.getline(inputSubStat2, 100);
                    carichild = searchChild(LC,inputSubStat2);
                    if (carichild == NULL){
                        adrchild chi = createElementChild(inputSubStat2);
                        insertLastChild(LC,chi);
                    }
                        cout<<"Masukkan Nilai Substats 2: "<<endl;
                        cin>>data.substats2;
                        cout<<"Masukkan Nama Substats 3 Artefak: "<<endl;
                        datasubstat = "";
//                        while(datasubstat!="."){
//                            cin>>datasubstat;
//                            if(datasubstatakhir3!=""&&datasubstat!="."){
//                                datasubstatakhir3 = datasubstatakhir3+" "+datasubstat;
//                            }
//                            if(datasubstatakhir3=="" && datasubstat!="."){
//                                datasubstatakhir3 = datasubstat;
//                            }
//                        }
                        fflush(stdin);
                        cin.getline(inputSubStat3, 100);
                        carichild = searchChild(LC,inputSubStat3);
                        if (carichild == NULL){
                            adrchild chi = createElementChild(inputSubStat3);
                            insertLastChild(LC,chi);
                        }
                            cout<<"Masukkan Nilai Substats 3: "<<endl;
                            cin>>data.substats3;
                            cout<<"Masukkan Nama Substats 4 Artefak: "<<endl;
                            datasubstat = "";
//                            while(datasubstat!="."){
//                                cin>>datasubstat;
//                                if(datasubstatakhir4!=""&&datasubstat!="."){
//                                    datasubstatakhir4 = datasubstatakhir4+" "+datasubstat;
//                                }
//                                if(datasubstatakhir4=="" && datasubstat!="."){
//                                    datasubstatakhir4 = datasubstat;
//                                }
//                            }
                            fflush(stdin);
                            cin.getline(inputSubStat4, 100);
                            carichild = searchChild(LC,inputSubStat4);
                            if (carichild==NULL){
                                adrchild chi = createElementChild(inputSubStat4);
                                insertLastChild(LC,chi);
                            }
                                cout<<"Masukkan Nilai Substats 4: "<<endl;
                                cin>>data.substats4;
                                ind = createElementInduk(data);
                                cout<<"1. Insert First"<<endl;
                                cout<<"2. Insert Last"<<endl;
                                cin>>pilihint;
                                while(pilihint<1 || pilihint>2){
                                    cout<<"Masukkan Opsi Dengan Benar!"<<endl;
                                    cout<<"1. Insert First"<<endl;
                                    cout<<"2. Insert Last"<<endl;
                                    cin>>pilihint;
                                }
                                if(pilihint==1){
                                    insertFirstInduk(LI,ind);
                                }else if(pilihint==2){
                                    insertLastInduk(LI, ind);
                                }
                                hubungkanIndukChild(LI,LC,data.id,inputSubStat);
                                hubungkanIndukChild(LI,LC,data.id,inputSubStat2);
                                hubungkanIndukChild(LI,LC,data.id,inputSubStat3);
                                hubungkanIndukChild(LI,LC,data.id,inputSubStat4);
            }
        }else if(pilih=="2"){
            cout<<"Masukkan Nama Substats: "<<endl;
//            while(datasubstat!="."){
//                cin>>datasubstat;
//                if(datasubstatakhir!=""&&datasubstat!="."){
//                    datasubstatakhir = datasubstatakhir+" "+datasubstat;
//                }
//                if(datasubstatakhir=="" && datasubstat!="."){
//                    datasubstatakhir = datasubstat;
//                }
//            }
//            datasubstat = "";
            fflush(stdin);
            cin.getline(inputSubStat,100);
            if(!adaChild(LC,inputSubStat)){
                cout<<"1. Insert First"<<endl;
                cout<<"2. Insert Last"<<endl;
                cin>>pilihint;
                while(pilihint<1 || pilihint>2){
                    cout<<"Masukkan Opsi Dengan Benar!"<<endl;
                    cout<<"1. Insert First"<<endl;
                    cout<<"2. Insert Last"<<endl;
                    cin>>pilihint;
                }
                if(pilihint==1){
                    insertFirstChild(LC,createElementChild(inputSubStat));
                }else if(pilihint==2){
                    insertLastChild(LC,createElementChild(inputSubStat));
                }
                pilihint = 999123999;
            }else{
                cout<<"Substats "<<inputSubStat<<" Sudah Terdaftar"<<endl;
            }
//            datasubstatakhir = "";
        }else if(pilih=="3"){
            showAllInduk(LI);
        }else if(pilih=="4"){
            showAllIndukChild(LI,LC);
        }else if(pilih=="5"){
            if(LI.first==NULL){
                cout<<"List Artefak Kosong"<<endl;
            }else{
                cout<<"Masukkan ID Artefak yang Akan Dihapus: ";
                antibreak = true;
                cin>>idArtef;
                while(searchInduk(LI,idArtef)==NULL && antibreak){
                    cout<<"Artefak Dengan ID "<<idArtef<<" Tidak Ditemukan"<<endl;
                    cout<<"Silahkan Pilih Opsi Berikut"<<endl;
                    cout<<"1. Masukkan Ulang ID"<<endl;
                    cout<<"2. Batalkan Hapus Artefak"<<endl;
                    cin>>pilih;
                    while(!(pilih=="1" || pilih=="2")){
                        cout<<"Mohon Masukkan Opsi dengan benar!"<<endl;
                        cout<<"1. Masukkan Ulang ID"<<endl;
                        cout<<"2. Batalkan Hapus Artefak"<<endl;
                        cin>>pilih;
                    }
                    if(pilih=="1"){
                        cout<<"Masukkan ID Artefak yang Akan Dihapus: ";
                        cin>>idArtef;
                    }else if(pilih == "2"){
                        cout<<"Berhasil Membatalkan Hapus Artefak"<<endl;
                        antibreak = false;
                    }
                }
                if(antibreak){
                deleteIndukDanRelasi(LI,idArtef);
                cout<<"Artefak Dengan ID "<<idArtef<<" Berhasil Dihapus"<<endl;
                }
            }
        }else if(pilih=="6"){
            cout<<"Masukkan ID Artefak yang Akan Dicari: ";
            cin>>idArtefBuatCari;
            if(searchInduk(LI, idArtefBuatCari)!=NULL){
                cout<<"============================"<<endl;
                cout<<"Artefak Ditemukan Pada Element Ke "<<indeksInduk(LI,idArtefBuatCari)<<endl;
                cout<<"Artefak Berada Pada Alamat "<<searchInduk(LI,idArtefBuatCari)<<endl;
                cout<<"============================"<<endl;
            }else{
                if(LI.first==NULL){
                    cout<<"List Data Artefak Kosong"<<endl;
                    cout<<"============================"<<endl;
                }else{
                    cout<<"Data Artefak Tidak Ditemukan Pada List Parent"<<endl;
                    cout<<"============================"<<endl;
                }
            }
            idArtefBuatCari = "";
        }else if(pilih=="7"){
            datasubstat = "";
            datasubstatakhir = "";
            cout<<"Masukkan Nama Child yang Akan Dicari: ";
//            while(datasubstat!="."){
//                cin>>datasubstat;
//                if(datasubstatakhir!=""&&datasubstat!="."){
//                    datasubstatakhir = datasubstatakhir+" "+datasubstat;
//                }
//                if(datasubstatakhir=="" && datasubstat!="."){
//                    datasubstatakhir = datasubstat;
//                }
//            }
            fflush(stdin);
            cin.getline(childCari, 100);
            if(searchChild(LC,childCari)!=NULL){
                cout<<"============================"<<endl;
                cout<<"Child Ditemukan Pada Element Ke "<<indeksChild(LC,childCari)<<endl;
                cout<<"Child Berada Pada Alamat "<<searchChild(LC, childCari)<<endl;
                cout<<"============================"<<endl;
            }else{
                if(LC.first==NULL){
                    cout<<"List Data Child Kosong"<<endl;
                    cout<<"============================"<<endl;
                }else{
                    cout<<"Data Child Tidak Ditemukan Pada List Child"<<endl;
                    cout<<"============================"<<endl;
                }
            }
            datasubstat = "";
            datasubstatakhir = "";
        }else if(pilih == "8"){
            cout<<"Masukkan Child Yang Akan Dicari: ";
            datasubstat = "";
            datasubstatakhir = "";
//            while(datasubstat!="."){
//                cin>>datasubstat;
//                if(datasubstatakhir!=""&&datasubstat!="."){
//                    datasubstatakhir = datasubstatakhir+" "+datasubstat;
//                }
//                if(datasubstatakhir=="" && datasubstat!="."){
//                    datasubstatakhir = datasubstat;
//                }
//            }
            fflush(stdin);
            cin.getline(childCariInduk, 100);
            if(searchChild(LC,childCariInduk)==NULL){
                if(LC.first==NULL){
                    cout<<"List Data Child Kosong"<<endl;
                    cout<<"============================"<<endl;
                }else{
                    cout<<"Data Child Tidak Ada Didalam List Child"<<endl;
                    cout<<"============================"<<endl;
                }
            }else{
                cout<<"Masukkan ID Artefak yang Akan Dicari Childnya: ";
                cin>>idArtefBuatCari;
                if(searchInduk(LI, idArtefBuatCari)==NULL){
                    if(LI.first==NULL){
                        cout<<"List Data Artefak Kosong"<<endl;
                        cout<<"============================"<<endl;
                    }else{
                        cout<<"Data Artefak Dengan ID "<<idArtefBuatCari<<" Tidak Ditemukan"<<endl;
                        cout<<"============================"<<endl;
                    }
                }else{
                    if(findChildInParent(LI,LC,idArtefBuatCari,childCariInduk)){
                        cout<<"Terdapat Child "<<childCariInduk<<" didalam Artefak Dengan ID "<<idArtefBuatCari<<endl;
                    }else{
                        cout<<"Tidak Ada Child "<<childCariInduk<<" didalam Artefak Dengan ID "<<idArtefBuatCari<<endl;
                    }
                }
            }
        }else if(pilih=="9"){
            cout<<"Masukkan Child Yang Akan Dihapus: ";
            datasubstat = "";
            datasubstatakhir = "";
//            while(datasubstat!="."){
//                cin>>datasubstat;
//                if(datasubstatakhir!=""&&datasubstat!="."){
//                    datasubstatakhir = datasubstatakhir+" "+datasubstat;
//                }
//                if(datasubstatakhir=="" && datasubstat!="."){
//                    datasubstatakhir = datasubstat;
//                }
//            }
            fflush(stdin);
            cin.getline(childCariInduk, 100);
            if(searchChild(LC,childCariInduk)==NULL){
                if(LC.first==NULL){
                    cout<<"List Data Child Kosong"<<endl;
                    cout<<"============================"<<endl;
                }else{
                    cout<<"Data Child Tidak Ada Didalam List Child"<<endl;
                    cout<<"============================"<<endl;
                }
            }else{
                cout<<"Masukkan ID Artefak yang Akan Dihapus Child "<<childCariInduk<<" nya: ";
                cin>>idArtefBuatCari;
                if(searchInduk(LI, idArtefBuatCari)==NULL){
                    if(LI.first==NULL){
                        cout<<"List Data Artefak Kosong"<<endl;
                        cout<<"============================"<<endl;
                    }else{
                        cout<<"Data Artefak Dengan ID "<<idArtefBuatCari<<" Tidak Ditemukan"<<endl;
                        cout<<"============================"<<endl;
                    }
                }else{
                    if(findChildInParent(LI,LC,idArtefBuatCari,childCariInduk)){
                        deleteChildDariInduk(LI,LC,idArtefBuatCari,childCariInduk);
                        cout<<"Data Child "<<childCariInduk<<" Pada Artefak dengan ID "<<idArtefBuatCari<<" Berhasil Dihapus"<<endl;
                    }else{
                        cout<<"Gagal Menghapus Child Pada Artefak!"<<endl;
                        cout<<"Tidak Ada Child "<<childCariInduk<<" didalam Artefak Dengan ID "<<idArtefBuatCari<<endl;
                    }
                }
            }
        }else if(pilih=="10"){
            cout<<"Masukkan ID Artefak yang Akan Dihitung Banyak Childnya: ";
                cin>>idArtefBuatCari;
                if(searchInduk(LI, idArtefBuatCari)==NULL){
                    if(LI.first==NULL){
                        cout<<"List Data Artefak Kosong"<<endl;
                        cout<<"============================"<<endl;
                    }else{
                        cout<<"Data Artefak Dengan ID "<<idArtefBuatCari<<" Tidak Ditemukan"<<endl;
                        cout<<"============================"<<endl;
                    }
                }else{
                    cout<<"Banyak Child Pada Artefak Dengan ID "<<idArtefBuatCari<<" adalah "<<banyakDataChild(LI,LC,idArtefBuatCari)<<endl;
                }
        }else if(pilih=="11"){
            showAllChild(LC);
        }else{
            lanjut = "stop";
        }
        if(lanjut!="stop"){
            cout<<"Ketik Apapun Untuk Melanjutkan Program atau Ketik stop Untuk Keluar dari Program"<<endl;
            cin>>lanjut;
        }
        datasubstat = "";
        data.stats.namastat = "";
        datasubstatakhir = "";
        datasubstatakhir2 = "";
        datasubstatakhir3 = "";
        datasubstatakhir4 = "";
        antibreak = true;
        pilih = "999123999";
        data.stats.namastat = "";
        pilihint = 999123999;
    }
}






>>>>>>> c9207e3 (fixed)
