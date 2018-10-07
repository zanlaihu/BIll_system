// Transport card record implementation ... Assignment 1 COMP9024 18s2
#include <stdio.h>
#include "cardRecord.h"

#define LINE_LENGTH 1024
#define NO_NUMBER -999

// scan input line for a positive integer, ignores the rest, returns NO_NUMBER if none
int readInt(void) {
   char line[LINE_LENGTH];
   int  n;

   fgets(line, LINE_LENGTH, stdin);
   if ( (sscanf(line, "%d", &n) != 1) || n <= 0 )
      return NO_NUMBER;
   else
      return n;
}

// scan input for a floating point number, ignores the rest, returns NO_NUMBER if none
float readFloat(void) {
   char  line[LINE_LENGTH];
   float f;

   fgets(line, LINE_LENGTH, stdin);
   if (sscanf(line, "%f", &f) != 1)
      return NO_NUMBER;
   else
      return f;
}

int readValidID(void) {
    
    printf("Enter card ID: ");
    int C_id = readInt();
    
    while (C_id == NO_NUMBER || C_id < 9999999 || C_id >= 100000000) {
        printf("Not valid. Enter a valid value: ");
        C_id = readInt();
    }

   return C_id;  /* needs to be replaced */
}

float readValidAmount(void) {
    
    printf("Enter amount: ");
    float C_balance = readFloat();
    
    while (C_balance == NO_NUMBER || C_balance < -2.35 || C_balance > 250) {
        printf("Not valid. Enter a valid value: ");
        C_balance = readFloat();
    }

   return C_balance;  /* needs to be replaced */
}

void printCardData(cardRecordT card) {
    
    
    printf("Card ID: %d\n", card.cardID);
    if (card.balance < 0) {
        float ba1 = card.balance * -1;
        
        printf("Balance: -$%.2f\n", ba1);
    } else {
        printf("Balance: $%.2f\n", card.balance);
    }
    
    if (card.balance < 5) {
        printf("Low balance\n");
    }
    

    

   return;  /* needs to be replaced */
}
