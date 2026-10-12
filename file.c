// for file operation  -> saving and loading.
#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) {
    //Function to save the created  contact newly.
    FILE *fp;
    fp = fopen("contacts.txt","w"); //opening  file for writing
    if(fp==NULL){
        printf("Failed to open File!\n");
        return;
    }
    fprintf(fp,"%d\n",addressBook->contactCount); //printing contact count in contact.txt file
    for(int i=0;i<addressBook->contactCount;i++){
        fprintf(fp, "%s|%s|%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    } // printing data
    fclose(fp); // close the file
    printf("Contact Saved Successfully.\n");

  
}

void loadContactsFromFile(AddressBook *addressBook)
{ // load contact from file for operation
    FILE *fp;

    fp = fopen("contacts.txt", "r"); // opening file for reading

    if(fp == NULL)
    {
        addressBook->contactCount = 0; // setting contact count as zero initially.
        return;
    }

    fscanf(fp, "%d\n", &addressBook->contactCount); //reading contact count in file

    for(int i = 0; i < addressBook->contactCount; i++)
    {
        fscanf(fp, " %[^|]|%[^|]|%[^\n]\n", 
               addressBook->contacts[i].name,
               addressBook->contacts[i].phone,
               addressBook->contacts[i].email); // displaying saved contacts
    }

    fclose(fp);
}