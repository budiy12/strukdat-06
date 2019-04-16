/**
 * Author       : Asep Budiyana Muharam
 * NPM          : 140810180029
 * Deskripsi    : Circular Double Linked List
 * Tahun        : 2019
**/
#include <iostream>
#include <conio.h>
using namespace std;

struct PhoneBook{
    char info;
    PhoneBook* next;
    PhoneBook* prev;
};
typedef PhoneBook* pointer;
typedef pointer List;

void createElement(pointer& p){
    p = new PhoneBook;
    cout<<"input info: ";
    cin>>p->info;
    p->next=NULL;
    p->prev=NULL;
}

void insertFirst(List& first,pointer pBaru){
    if (first==NULL){
        first = pBaru;
        pBaru->next = first;
        pBaru->prev = first;
    }
    else {
       pBaru->next = first;
       pBaru->prev = first->prev;
       first->prev->next = pBaru;
       first->prev = pBaru;
       first = pBaru;
    }
}


void insertLast(List& first, pointer pBaru){
    if (first==NULL){
        first = pBaru;
        pBaru->next=first;
        pBaru->prev=first;
    }
    else {
        pointer last = first;
        while(last->next->next!=first->next){
            last = last->next;
        }
        pBaru->prev = last;
        pBaru->next = first;
        last->next = pBaru;
        first->prev = pBaru;
    }
}

void deleteFirst(List& first, pointer pHapus){
    if (first==NULL){
        pHapus = NULL;
    }
    else if (first->next==first){
        pHapus = first;
        first = NULL;
    }
    else {
        pHapus = first;
        first = first->next;
        pHapus->prev->next = first;
        first->prev = pHapus->prev;
        pHapus->next = NULL;
        pHapus->prev = NULL;
    }
}

void deleteLast(List& first, pointer pHapus){
    if (first==NULL){
        pHapus = NULL;
    }
    else if (first->next==first){
        pHapus = first;
        first = NULL;
    }
    else {
        pointer last = first;
        while(last->next->next!=first->next){
            last = last->next;
        }
        pHapus = last;
        last->prev->next = first;
        first->prev = last->prev;
        last->next = NULL;
        last->prev = NULL;
    }
}

void traversal(List& first){
    pointer pBantu = first;
    if (first==NULL) cout<<"*LIST KOSONG*\n";
    else{
        while(pBantu->next->prev!=first->prev){
        if (pBantu!=first) cout<<" -> ";
        cout<<"'"<<pBantu->info<<"'";
        pBantu = pBantu->next;
        }
        cout<<" -> ";
        cout<<pBantu->info;
    }
    
}

int main(){
    pointer p,h;
    List f;
    int pil;
    f=NULL;
    do{
        system("cls");
        traversal(f);
        cout<<endl
        <<"\n1. Insert First"
        <<"\n2. Insert Last"
        <<"\n3. Delete First"
        <<"\n4. Delete Last"
        <<"\n5. Exit"
        <<endl;
        cout<<"Pilih : ";cin>>pil;
        switch(pil){
            case 1:
            createElement(p);
            insertFirst(f,p);
            break;
            case 2:
            createElement(p);
            insertLast(f,p);
            break;
            case 3:
            deleteFirst(f,h);
            break;
            case 4:
            deleteLast(f,h);
            break;
            case 5:
            break;
            default:
            break;
        }
    }while(pil!=5);

}
