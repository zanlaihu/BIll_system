// Linked list of transport card records implementation ... Assignment 1 COMP9024 18s2
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "cardLL.h"
#include "cardRecord.h"

// linked list node type
// DO NOT CHANGE
typedef struct node {
    cardRecordT data;
    struct node *next;
} NodeT;

// linked list type
typedef struct ListRep {
   NodeT *head;
    
    int height;
    //numbers of elements in list
    
    
    float Total_balance;
    //total balance
    

/* Add more fields if you wish */

} ListRep;

/*** Your code for stages 2 & 3 starts here ***/

// Time complexity: O(1)
// Explanation: there is no loop in this function.
List newLL() {
    
    List newL = malloc(sizeof(ListRep));
    
    
    newL->Total_balance = 0;
    newL->head = NULL;
    newL->height = 0;
    // give three pointers to the new list
    

   return newL;  /* needs to be replaced */
}

// Time complexity: O(n)
// Explanation: there is one while loop.
void dropLL(List listp) {
    NodeT * cu = listp->head;
    while (cu != NULL) {
        NodeT *tem = cu->next;
        free(cu);
        cu = tem;
    }
    free(listp);

   return;  /* needs to be replaced */
}

// Time complexity: O(n)
// Explanation: there is a while loop. The if statemnt is not a loop.
void removeLL(List listp, int cardID) {
    NodeT *last = NULL;
    NodeT *current = listp->head;
    // set the head node as the current node, it will change later.
    // the reason to create current is that we do not want to make change to the list when we are finding.
    
    if (cardID == current->data.cardID) {
        listp->Total_balance = listp->Total_balance - current->data.balance;
        listp->head = listp->head->next;
        listp->height = listp->height - 1;
        printf("Card removed.\n");
        return;
    }
    while (current != NULL) {
        // if the node is not NULL and the node is not the node we are trying to find, then go to the next node.
        if (cardID == current->data.cardID){
            // when we find the node
            listp->Total_balance = listp->Total_balance - current->data.balance;
            last ->next = current -> next;
            listp->height = listp->height - 1;
            
            printf("Card removed.\n");
            return;
            
        }
        last = current;
        current = current -> next;
    }
    printf("Card not found.\n");
    

   return;  /* needs to be replaced */
}

// Time complexity: O(n^2)
// Explanation: there is one if loop in another if loop.
void insertLL(List listp, int cardID, float amount) {
    
    NodeT *NewList = malloc(sizeof(NodeT));
    // NewList is actually a node
    assert(NewList != NULL);
    
    NewList->data.cardID = cardID;
    //input card id for the node
    NewList->data.balance = amount;
    //input balance for the node
    
    NodeT *current = listp->head;
    NodeT *last = NULL;
    
    if (current == NULL) {
        listp->head = NewList;
        NewList->next = NULL;
        listp->height = listp->height + 1;
        listp->Total_balance = listp->Total_balance + amount;
        printf("Card added.\n");
        return;
    }
    while (current != NULL) {
        if (cardID == current->data.cardID) {
            listp->Total_balance = listp->Total_balance - current->data.balance;
            current->data.balance = current->data.balance + amount;
            listp->Total_balance = listp->Total_balance + current->data.balance;
            printf("-----------------\n");
            printCardData(current->data);
            printf("-----------------\n");
            // if the card id exists, then update the balance.
            return;
        }else if (cardID < current->data.cardID){
            if (last == NULL) {
                NewList->next = current;
                listp->head = NewList;
                listp->height = listp->height + 1;
                listp->Total_balance = listp->Total_balance + amount;
                printf("Card added.\n");
                return;
            }else{
                NewList->next = current;
                last->next = NewList;
                listp->height = listp->height + 1;
                listp->Total_balance = listp->Total_balance + amount;
                printf("Card added.\n");
                return;
            }
        }else{
            last = current;
            current = current->next;
        }
    }
    NewList->next = current;
    last->next = NewList;
    listp->height = listp->height + 1;
    listp->Total_balance = listp->Total_balance + amount;
    printf("Card added.\n");
    

   return;  /* needs to be replaced */
}

// Time complexity: O(1)
// Explanation: there is no loop.
void getAverageLL(List listp, int *n, float *balance) {
    
    *n = listp->height;
    *balance = listp->Total_balance / listp->height;
    

   return;  /* needs to be replaced */
}

// Time complexity: O(n)
// Explanation: there is one for loop.
void showLL(List listp) {
    NodeT *pri;
    
    for (pri = listp->head; pri != NULL; pri = pri->next) {
        printf("-----------------\n");
        printCardData(pri->data);
        printf("-----------------\n");
    }
    
    

   return;  /* needs to be replaced */
}
