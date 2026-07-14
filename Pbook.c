#include <stdio.h>
#include <stdlib.h>

struct Contacts
    {
        char name[50];
        char pno[15];
    };

void Displaycontacts(struct Contacts contact1[],int size){
    
    for(int i =0;i <size;i++){
        printf("Name:%s Contact:%s",contact1[i].name,contact1[i].pno);
    }
}


void Addcontacts(struct Contacts contact1[],int size){

    for(int i=0;i<size;i++){

        printf("Enter the name of the contact:");
        fgets(contact1[i].name,sizeof(contact1[i].name),stdin);

        printf("Enter phone number:");
        fgets(contact1[i].pno,sizeof(contact1[i].pno),stdin);
    }

}

int main(){

    
    int n=0;

    printf("Enter no.0f contacts to be entered:\n");
    scanf("%d",&n);
    getchar();
     
    struct Contacts *contact1 = malloc(n *sizeof(struct Contacts));
    if (contact1 == NULL){
        printf("DEBUG:Memory allocation failed\n");
        return 1;
    }
    Addcontacts(contact1,n);
    Displaycontacts(contact1,n);

    free(contact1);


    return 0;
    
}