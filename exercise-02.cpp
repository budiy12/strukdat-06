/**
 * Author       : Asep Budiyana Muharam
 * NPM          : 140810180029
 * Deskripsi    : Double Linked List
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
    }
    else {
       pBaru->next = first;
       first->prev = pBaru;
       first = pBaru;
    }
}


void insertLast(List& first, pointer pBaru){
    if (first==NULL){
        first = pBaru;
    }
    else {
        pointer last = first;
        while(last->next!=NULL){
            last = last->next;
        }
        last->next = pBaru;
        pBaru->prev = last;
        
    }
}

void deleteFirst(List& first, pointer pHapus){
    if (first==NULL){
        pHapus = NULL;
    }
    else if (first->next==NULL){
        pHapus = first;
        first = NULL;
    }
    else {
        pHapus = first;
        first = first->next;
        pHapus->next = NULL;
        first->prev = NULL;
    }
}

void deleteLast(List& first, pointer pHapus){
    if (first==NULL){
        pHapus = NULL;
    }
    else if (first->next==NULL){
        pHapus = first;
        first = NULL;
    }
    else {
        pointer last = first;
        while(last->next!=NULL){
            last = last->next;
        }
        pHapus = last;
        last->prev->next = NULL;
        last->prev = NULL;
    }
}

void traversal(List& first){
    pointer pBantu = first;
    while(pBantu!=NULL){
        if (pBantu!=first) cout<<" <--> ";
        cout<<"'"<<pBantu->info<<"'";
        pBantu = pBantu->next;
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
