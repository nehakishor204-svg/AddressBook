/*FILE: contact.c
  Author : Neha Kishor
  Description : Implement ADDRESSBOOK including search,edit,delete,list,save menu*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h" 

void listContacts(AddressBook *addressBook) 
{
    //Function for listing contacts.
    Contact temp;
    for(int i=0;i<addressBook->contactCount-1;i++){//used sorting method to store names in alphabetical order.
        for(int j=i+1;j<addressBook->contactCount;j++){
            if(strcmp(addressBook->contacts[i].name,addressBook->contacts[j].name)>0){
                temp = addressBook->contacts[i];
                addressBook->contacts[i] = addressBook->contacts[j];
                addressBook->contacts[j] = temp;
            }
        }
    }
    printf("-------------------ADDRESS BOOK------------------------\n");
    printf("%-20s %-15s %-30s\n", "Name", "Phone", "Email");//used for correct spacing.
    for( int i = 0;i < addressBook -> contactCount;i++){
        printf("%-20s %-15s %-30s\n",
           addressBook->contacts[i].name,
           addressBook->contacts[i].phone,
           addressBook->contacts[i].email);
    }
    printf("\n--------------------------------------------------------\n");
    // Sort contacts based on the chosen criteria
    
}

void initialize(AddressBook *addressBook) {
    //populateAddressBook(addressBook); dummy contacts are stored.
    loadContactsFromFile(addressBook);//loaded newly created contacts from file contact.txt
    printf("Total Contacts currently = %d\n", addressBook->contactCount);//displays the no of contacts before printing the menu.
    
  }

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook);//saves recently created contacts to contact.txt file
  

}


void createContact(AddressBook *addressBook)
{
    //Function for creating contact
    printf("Enter the name :\n");
    scanf(" %[^\n]",addressBook -> contacts[addressBook->contactCount].name);
    int validphone=0;
    while(validphone>=0){
    printf("Enter the phone no(10 digits) :\n");
    scanf(" %[^\n]",addressBook -> contacts[addressBook->contactCount].phone);
   
    int len = strlen(addressBook->contacts[addressBook->contactCount].phone);//checking the length of phone number input
    if(len==10){
        break;//check if number is valid or not.
    }
    else{
        printf("Please Enter valid phone number(10 digits)\n");

    }
}
    
    
    
    printf("Enter the mail id :\n");
    while(1){
        int atfound = 0;
    scanf(" %[^\n]",addressBook -> contacts[addressBook->contactCount].email);
   
    
    for(int i=0;addressBook->contacts[addressBook->contactCount].email[i]!='\0';i++){
        if(addressBook->contacts[addressBook->contactCount].email[i] == '@'){
            atfound = 1;//checking the email input is valid or not
            break;
        }
        
    }
        if(atfound==1){
            break;
        }
        else{
            printf("Enter valid email(should contain special characters eg:'@')\n");
        }

    }
    addressBook -> contactCount++;//increamenting count of contacts.
	/* Define the logic to create a Contacts */
    
}

void searchContact(AddressBook *addressBook) 
{
    //Function for search a contact from the given list.
    int ch;
    char str[100];
    
    printf("1.Name\n");
    printf("2.Phone\n");
    printf("3.Email\n");
    printf("Enter the choice :");
    scanf("%d",&ch);
    int found = 0;
    
    switch(ch){//cases for searching by name,phone or email.
        case 1:
        
        printf("Enter name :");
        scanf(" %[^\n]",str);
        for(int i=0;i<addressBook->contactCount;i++){
            if(strcmp(str,addressBook->contacts[i].name) == 0){//printing the name  phone  email which is found.
            printf("%s\t%s\t%s\n",
                           addressBook->contacts[i].name,
                           addressBook->contacts[i].phone,
                           addressBook->contacts[i].email);

            found = 1;
            break;
            }
        }
        if(found==0){
            printf("Contact not found!");//if searched contact is not found displays this message.
        }

        
        break;
        
        case 2:
       
        printf("Enter phone no :");//search by phone number.
        scanf(" %[^\n]",str);
        for(int i=0;i<addressBook->contactCount;i++){
            if(strcmp(str,addressBook->contacts[i].phone) == 0){
            printf("%s\t%s\t%s\n",
                           addressBook->contacts[i].name,
                           addressBook->contacts[i].phone,
                           addressBook->contacts[i].email);

            found = 1;
            break;
            }
        }
        if(found==0){
            printf("Contact not found!");
        }

        
        break;
        case 3:
       
        printf("Enter email :");//search by email.
        scanf(" %[^\n]",str);
        for(int i=0;i<addressBook->contactCount;i++){
            if(strcmp(str,addressBook->contacts[i].email) == 0){
            printf("%s\t%s\t%s\n",
                           addressBook->contacts[i].name,
                           addressBook->contacts[i].phone,
                           addressBook->contacts[i].email);

            found = 1;
            break;
            }
        }
        if(found==0){
            printf("\nContact not found!\n");
        }

        
        break;
        default:
        printf("Invalid choice!\n");//if user inputs no <=0 or no > 3,displays this message,only 3 cases is given.

    }
    

    
    /* Define the logic for search */

}

void editContact(AddressBook *addressBook)
{
    //function to edit the contact.
    //Initially we have to search contact 
    int ch;
    char str[100];
    
    printf("1.Search by Name\n");
    printf("2.Search by Phone\n");
    printf("3.Search by Email\n");
    printf("Enter the choice :");
    scanf("%d",&ch);
    int found = 0;
    int edit;
    switch(ch){    //switch cases for searching.
        case 1:
        
        printf("Enter name :"); //search by name
        scanf(" %[^\n]",str);
        for(int i=0;i<addressBook->contactCount;i++){
            if(strcmp(str,addressBook->contacts[i].name) == 0){
            printf("%s\t",addressBook->contacts[i].name);
            printf("%s\t",addressBook->contacts[i].phone);
            printf("%s\t",addressBook->contacts[i].email);
            printf("\n1.Edit name\n");/*options for edit*/
            printf("2.Edit phone\n");
            printf("3.Edit email\n");
            printf("Enter your option to edit:");
            scanf("%d",&edit);
            switch(edit){
                case 1:
                printf("Enter new name :");  // input new name
                scanf(" %[^\n]",addressBook->contacts[i].name);
                break;
                case 2:
                int validphone=0; // checking if valid phone number
                while(1){
                printf("Enter new phone no(must countain 10 numbers) :");
                scanf(" %[^\n]",addressBook->contacts[i].phone);
                int len = strlen(addressBook->contacts[i].phone);
                if(len==10){
                    break;
                }
                else{
                    printf("Please enter a valid phone number :"); // if not valid  user have to re-enter.
                }
            }
                break;
                case 3:
                int atfound = 0;
                printf("Enter new email(must add special characters eg:'@') :");
                while(1){
                   atfound = 0; // checking valid email or not
                   scanf(" %[^\n]",addressBook->contacts[i].email);
                for(int k=0; addressBook->contacts[i].email[k] != '\0'; k++){
                   if(addressBook->contacts[i].email[k] == '@'){
                   atfound = 1;
                   break;
                   }
                }
                   if(atfound==1){
                   break;
                   }
                   else{
                   printf("Please enter a valid mail id.");
                   }
                }
                break;
                default:
                printf("Invalid choice!"); // invalid choice if user ennters lest or beyond cases.
            }
            
           

        found = 1;
        break;
        }
        }
        if(found==0){
            printf("Contact not found!");
        }
    

        
    break;
    
    case 2:
        
        printf("Enter phone no :"); // search by phone number
        scanf(" %[^\n]",str);
        for(int i=0;i<addressBook->contactCount;i++){
            if(strcmp(str,addressBook->contacts[i].phone) == 0){
            printf("%s\t",addressBook->contacts[i].name);
            printf("%s\t",addressBook->contacts[i].phone);
            printf("%s\t",addressBook->contacts[i].email);
            printf("1.\nEdit name\n");
            printf("2.Edit phone\n");
            printf("3.Edit email\n");
            printf("Enter your option to edit:");
            scanf("%d",&edit);
            switch(edit){
                case 1:
                printf("Enter new name :");
                scanf(" %[^\n]",addressBook->contacts[i].name);
                break;
                case 2:
                int validphone=0;
                while(validphone>=0){
                printf("Enter new phone no :");
                scanf(" %[^\n]",addressBook->contacts[i].phone);
                int len = strlen(addressBook->contacts[i].phone);
                if(len==10){  // checking if no is valid or not
                    break;
                }
                else{
                    printf("Please enter a valid phone number:");
                }
            }
                break;
                case 3: 
                int atfound = 0;
                printf("Enter new email(must add special characters eg:'@') :");
                while(1){
                   atfound = 0;
                   scanf(" %[^\n]",addressBook->contacts[i].email);
                for(int k=0; addressBook->contacts[i].email[k] != '\0'; k++){
                   if(addressBook->contacts[i].email[k] == '@'){
                   atfound = 1;   // checking if mail id is  valid or not.
                   break;
                   }
                }
                   if(atfound==1){
                   break;
                   }
                   else{
                   printf("Please enter a valid mail id.");
                   }
                }
                break;
                default:
                printf("Invalid choice!");
            }
            
           

        found = 1;
        break;
        }
        }
        if(found==0){
            printf("Contact not found!");
        }
    

        
    break;
        case 3:
        
        printf("Enter email :"); // searching by email
        scanf(" %[^\n]",str);
        for(int i=0;i<addressBook->contactCount;i++){
            if(strcmp(str,addressBook->contacts[i].email) == 0){
            printf("%s\t",addressBook->contacts[i].name);
            printf("%s\t",addressBook->contacts[i].phone);
            printf("%s\t",addressBook->contacts[i].email);
            printf("1.Edit name\n");
            printf("2.Edit phone\n");
            printf("3.Edit email\n");
            printf("Enter your option to edit:");
            scanf("%d",&edit);
            switch(edit){
                case 1:
                printf("Enter new name :");
                scanf(" %[^\n]",addressBook->contacts[i].name);
                break;
                case 2:
                int validphone=0;
                while(validphone>=0){ // checkinng the phone no is valid or not
                printf("Enter new phone no :");
                scanf(" %[^\n]",addressBook->contacts[i].phone);
                int len = strlen(addressBook->contacts[i].phone);
                if(len==10){
                    break;
                }
                else{
                    printf("Please enter a valid phone number:");
                }
            }
                break;
                case 3:
                int atfound = 0;
                printf("Enter new email(must add special characters eg:'@') :");
                while(1){ // checks the mail id is valid or not.
                   atfound = 0;
                   scanf(" %[^\n]",addressBook->contacts[i].email);
                for(int k=0; addressBook->contacts[i].email[k] != '\0'; k++){
                   if(addressBook->contacts[i].email[k] == '@'){
                   atfound = 1;
                   break;
                   }
                }
                   if(atfound==1){
                   break;
                   }
                   else{
                   printf("Please enter a valid mail id.");
                   }
                }
                break;
                default:
                printf("Invalid choice!");
            }
            
           

        found = 1;
        break;
        }
        }
        if(found==0){
            printf("Contact not found!");
        }
    

        
    break;


	/* Define the logic for Editcontact */
    
}
}

void deleteContact(AddressBook *addressBook)
{
    //Function for deleting contact
    // Initially we have to search for contact
     int ch;
    char str[100];
    
    printf("1.Search by Name\n");
    printf("2.Search by Phone\n");
    printf("3.Search by Email\n");
    printf("Enter the choice :");
    scanf("%d",&ch);
    int found = 0;
    
    switch(ch){ // searching cases
        case 1: 
        
        printf("Enter name :");
        scanf(" %[^\n]",str);
        for(int i=0;i<addressBook->contactCount;i++){
            if(strcmp(str,addressBook->contacts[i].name) == 0){
            printf("%s\t",addressBook->contacts[i].name);
            printf("%s\t",addressBook->contacts[i].phone);
            printf("%s\t",addressBook->contacts[i].email);
            found = 1;
            for(int j=i;j<addressBook->contactCount-1;j++){
                addressBook->contacts[j] = addressBook->contacts[j+1];//shifting next contact to left after deleting previous one
            }
            addressBook->contactCount--; // decreamenting contact count
            printf("\nContact deleted Successfully\n"); // display this  message after deleting
            break;
            }
        }
        if(found==0){
            printf("Contact not found!");
        }

        
        break;
        case 2:
        
        printf("Enter phone no :"); // search by phone no
        scanf(" %[^\n]",str);
        for(int i=0;i<addressBook->contactCount;i++){
            if(strcmp(str,addressBook->contacts[i].phone) == 0){
            printf("%s\t",addressBook->contacts[i].name);
            printf("%s\t",addressBook->contacts[i].phone);
            printf("%s\t",addressBook->contacts[i].email);
            found = 1;
            for(int j=i;j<addressBook->contactCount-1;j++){
                addressBook->contacts[j] = addressBook->contacts[j+1]; // shifting left
            }
            addressBook->contactCount--; // decreamenting count
            printf("Contact deleted Successfully");
            break;
            }
        }
        if(found==0){
            printf("Contact not found!");
        }

        
        break;
        case 3:
        
        printf("Enter email :"); // search by e mail
        scanf(" %[^\n]",str);
        for(int i=0;i<addressBook->contactCount;i++){
            if(strcmp(str,addressBook->contacts[i].email) == 0){
            printf("%s\t",addressBook->contacts[i].name);
            printf("%s\t",addressBook->contacts[i].phone);
            printf("%s\t",addressBook->contacts[i].email);
            found = 1;
            for(int j=i;j<addressBook->contactCount-1;j++){
                addressBook->contacts[j] = addressBook->contacts[j+1]; // shifting left
            }
            addressBook->contactCount--;
            printf("Contact deleted Successfully");
            break;
            }
        }
        if(found==0){
            printf("Contact not found!"); // if searched contact is not found display this message.
        }

        
        break;
	/* Define the logic for deletecontact */
   
}
}
