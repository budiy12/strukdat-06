/**
 * Author       : Asep Budiyana Muharam
 * NPM          : 140810180029
 * Deskripsi    : Multi Linked List
 * Tahun        : 2019
**/
#include <iostream>
#include <conio.h>
using namespace std;

struct Contact{
    string nama;
    char phone[12];
    Contact* next;
};

struct Index{
    char index;
    Index* next;
    Contact* first_contact;
};
typedef Index* pointer_index;
typedef Contact* pointer_contact;
typedef pointer_index List;

void createList(List& First){
    First=NULL;
}

void createIndex(pointer_index& p, char baru){
    p = new Index;
    // cout<<"Index: ";cin>>p->index;
    p->index = baru;
    p->first_contact = NULL;
    p->next = NULL;
}

void createContact(pointer_contact& p){
    p = new Contact;
    cout<<"Nama: ";cin>>p->nama;
    cout<<"No  : ";cin>>p->phone;
    p->next = NULL;
}

void linearSearch(List First,char key, int& status, pointer_index& search){
    search=First;
    status=0;
    while(search!=NULL && status==0){
        if (search->index==key)
            status=1;
        else
            search=search->next;
    }
}

void insertFirstIndex(List& First,pointer_index pNew){
    if (First==NULL){
        First=pNew;
    }
    else{
        pNew->next=First;
        First=pNew;
    }
}

void insertFirstContact(List& First, char key, pointer_contact pNew){
    pointer_index index;
    int found;
    linearSearch(First,key,found,index);
    if (found){
        if(index->first_contact==NULL)
            index->first_contact=pNew;
        else{
            pNew->next=index->first_contact;
            index->first_contact=pNew;
        }
    }
    else{
        cout<<"Tidak ditemukan"<<endl;
    }
}

void deleteContact(List& First, char key[],pointer_contact pDelete){
    pointer_index index;
    int found;
    char awal = key[0];
    linearSearch(First,awal,found,index);
    if (found){
        if(index->first_contact==NULL){
            pDelete=NULL;
            cout<<"Tidak Ada yang dihapus\n";
        }
        else if(index->first_contact->next==NULL){
            pDelete=index->first_contact;
            index->first_contact=NULL;
        }
        else{
            pDelete=index->first_contact;
            index->first_contact=index->first_contact->next;
            pDelete->next=NULL;
        }
    }
    else{
        cout<<"Tidak ditemukan\n";
    }
}

void updateContact(List& First,char key[]){
    pointer_index index;
    int found;
    char awal = key[0];
    bool test;
    linearSearch(First,awal,found,index);
    if (found){
            pointer_contact pUpdate = index->first_contact;
            while(pUpdate!=NULL && pUpdate->nama!=key){
                cout<<pUpdate->nama<<endl;
                test= pUpdate->nama==key;
                cout<<test;
                pUpdate = pUpdate->next;
            }
            if (pUpdate == NULL) cout<<"Tidak Ditemukan"<<endl;
            else {
            cout<<"\nUPDATE:\n";
            cout<<"Nama: ";cin>>pUpdate->nama;
            cout<<"No  : ";cin>>pUpdate->phone;
            }
        }
    else{
        cout<<"Tidak ditemukan"<<endl;
    }
}

void transversal(List First){
    pointer_index pIndex;
    pointer_contact pContact;
    cout<<"CONTACT\n";
    pIndex=First;
    while(pIndex!=NULL){
        if(pIndex->first_contact!=NULL) cout<<pIndex->index<<":"<<endl;
        pContact=pIndex->first_contact;
        while(pContact!=NULL){
            cout<<"->"<<pContact->nama<<"/"<<pContact->phone<<endl;
            pContact=pContact->next;
        }
        pIndex=pIndex->next;
    }
}

int main()
{
    char daftar_index = 'Z',awalan;   
    List f;
    pointer_index pI;
    pointer_contact pC,pD;
    char k[10];
    int pil;
    createList(f);

    for (int i=0;i<26;i++){
        createIndex(pI,daftar_index);
        insertFirstIndex(f,pI);
        daftar_index--;
    }

    do{
        system("cls");
        transversal(f);
        cout<<"\n\n1. Insert contact"
        <<"\n2. Delete Contact"
        <<"\n3. Update Contact"
        <<"\n4. Exit\n";
        cout<<"Pilih : ";cin>>pil;
        switch(pil){
            case 1:
            createContact(pC);
            awalan=pC->nama[0];
            insertFirstContact(f,awalan,pC);
            break;
            case 2:
            cout<<"Enter Contact (Kapital First) : ";cin>>k;
            deleteContact(f,k,pD);
            break;
            case 3:
            cout<<"Enter Contact (kapital Firs) : ";cin>>k;
            updateContact(f,k);
            break;
            case 4:
            break;
            default:
            break;
        }
    }while(pil!=4);
}
