#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contacts
    {
        char name[50];
        char pno[15];
    };

void Displaycontacts(){
    
    FILE *fptr = fopen("Contactlist.txt","r");

    if (fptr == NULL){
        printf("File not opened\n");
        return;
    }
    else{
        char content[1000];

        while (fgets(content,1000,fptr))
        {
            printf("=====================");
            printf("%s",content);
            printf("=====================");
        }
    
        fclose(fptr);
    }
    
}


void Addcontacts(struct Contacts contact1[],int size){
    FILE *fptr = fopen("Contactlist.txt","a");

    if(fptr == NULL){
        printf("The File is not opened\n");
        return;
    }

    for(int i=0;i<size;i++){

        printf("Enter the name of the contact:");
        fgets(contact1[i].name,sizeof(contact1[i].name),stdin);
        contact1[i].name[strcspn(contact1[i].name, "\n")] = '\0';

        printf("Enter phone number:");
        fgets(contact1[i].pno,sizeof(contact1[i].pno),stdin);
        contact1[i].pno[strcspn(contact1[i].pno, "\n")] = '\0';

        fprintf(fptr,"%s:%s\n",contact1[i].name,contact1[i].pno);
        
    }

    fclose(fptr);

}

int main(){

    while(1){
    int choi;
    
    printf("==========MENU=========\n");
    printf("1.Add contacts\n");
    printf("2.Display contacts\n");
    printf("3.Exit\n");

    printf("Enter your choice:");
    scanf("%d",&choi);
    getchar();

    if(choi == 1){

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
    free(contact1);
    }
    else if(choi == 2){
        Displaycontacts();
        
    }
    else if (choi == 3 ){
        break;
    }
    else{
        printf("Invalid operator\n");
    }
    
    
    }

    return 0;
    
}