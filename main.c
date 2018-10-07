/**
     main.c

     Program supplied as a starting point for
     Assignment 1: Transport card manager

     COMP9024 18s2
**/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "cardRecord.h"
#include "cardLL.h"

void printHelp();
void CardLinkedListProcessing();

int main(int argc, char *argv[]) {
   if (argc == 2) {
       
       int number_card = atoi(argv[1]);
       // atoi can transfer string to int. Give the value of arguments to number_card.
       
       cardRecordT * array = malloc(number_card * sizeof(cardRecordT));
       assert(array !=NULL);
       // Create an array named array of the struct 'cardRecordT'. The size of it the number of number_card.
       
       
       int i;
       float Totalbalance = 0;
       
       for (i = 0; i < number_card; i++) {
           array[i].cardID = readValidID();
           array[i].balance = readValidAmount();
           
           Totalbalance = Totalbalance + array[i].balance;
           
       }
       // A loop to input every cardIDs and balances. Put them into cardRecordT struct.
       // Totalbalance will be added everytime a new balance is added. As a result, we get total balance.
       
       
       
       for (i = 0; i < number_card; i++) {
           printf("-----------------\n");
           printCardData(array[i]);
           printf("-----------------\n");
       }
       // A loop to print every cardRecordT struct: print every cardID and balance.
       
       float average_balance;
       average_balance = Totalbalance / number_card;
       //calculate average_balance.
       
       printf("Number of cards on file: %d\n", number_card);
       if (average_balance < 0) {
           float va1 = average_balance * -1;
           
           printf("Average balance: -$%.2f\n", va1);
       } else {
           printf("Average balance: $%.2f\n", average_balance);
       }
       
      /*** Insert your code for stage 1 here ***/
      
   } else {
      CardLinkedListProcessing();
   }
   return 0;
}

/* Code for Stages 2 and 3 starts here */

void CardLinkedListProcessing() {
   int op, ch;

   List list = newLL();   // create a new linked list
    
    int C_id;
    int number_c;
    float C_balance, a_balance;
    
    
   while (1) {
      printf("Enter command (a,g,p,q,r, h for Help)> ");

      do {
	 ch = getchar();
      } while (!isalpha(ch) && ch != '\n');  // isalpha() defined in ctype.h
      op = ch;
      // skip the rest of the line until newline is encountered
      while (ch != '\n') {
	 ch = getchar();
      }

      switch (op) {

         case 'a':
         case 'A':
              C_id = readValidID();
              C_balance = readValidAmount();
              
              insertLL(list, C_id, C_balance);
              
              
            /*** Insert your code for adding a card record ***/

	    break;

         case 'g':
         case 'G':
              getAverageLL(list, &number_c, &a_balance);
              
              
              printf("Number of cards on file: %d\n", number_c);
              if (a_balance < 0) {
                  float ab = a_balance * -1;
                  printf("Average balance: -$%.2f\n", ab);
              } else {
                  printf("Average balance: $%.2f\n", a_balance);
              }
              
            /*** Insert your code for getting average balance ***/

	    break;
	    
         case 'h':
         case 'H':
            printHelp();
	    break;
	    
         case 'p':
         case 'P':
              
              showLL(list);
              
            /*** Insert your code for printing all card records ***/

	    break;

         case 'r':
         case 'R':
              removeLL(list, readValidID());
              
            /*** Insert your code for removing a card record ***/

	    break;

	 case 'q':
         case 'Q':
            dropLL(list);       // destroy linked list before returning
	    printf("Bye.\n");
	    return;
      }
   }
}

void printHelp() {
   printf("\n");
   printf(" a - Add card record\n" );
   printf(" g - Get average balance\n" );
   printf(" h - Help\n");
   printf(" p - Print all records\n" );
   printf(" r - Remove card\n");
   printf(" q - Quit\n");
   printf("\n");
}
