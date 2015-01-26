#include <stdio.h>
#include <stdlib.h>

#include "arrayList.h"

#define ERRORMESSAGE_MAXLEN 100

void assertSize(int code, int currentSize, int expectedSize);
void assertKey(int code, AList list, int listSize, int position, int expectedKey);
void assertPosition(int code, AList list, int listSize, int key, int startPosition, int expectedPosition);
void assertReturnCode(int assertionCode, int currentReturnCode, int expectedReturnCode);
void assertSuccessfullExecution(int assertionCode, int currentReturnCode);
void printAndExit(int code, char message[]);

/*
 * 
 */
int main(int argc, char** argv) {
    
    AList list = NULL;
    int listSize = 0;
    int listDim = 0;
    int i;
    int key;
    int position;
    int ret; // return value
    
    // TODO shrink e assertdimension 
    
    assertSize(10, listSize, 0);
    
    // Operazioni 20
    ret = ALInsertAtBeginning(&list, &listSize, &listDim, 100);
    assertSuccessfullExecution(2000, ret);
    ret = ALInsertAtBeginning(&list, &listSize, &listDim, 200);
    assertSuccessfullExecution(2001, ret);
    ret = ALInsertAtBeginning(&list, &listSize, &listDim, 300);
    assertSuccessfullExecution(2002, ret);
    
    assertSize(20, listSize, 3);
    assertKey(21, list, listSize, 0, 300);
    assertKey(22, list, listSize, 0, 300);
    assertKey(23, list, listSize, 1, 200);
    assertKey(24, list, listSize, 2, 100);
    assertKey(25, list, listSize, 0, 300);
    
    // Operazioni 30
    ret = ALRemoveFirst(list, &listSize);
    assertSuccessfullExecution(3000, ret);
    
    assertSize(30, listSize, 2);
    assertKey(31, list, listSize, 0, 200);
    assertKey(32, list, listSize, 1, 100);
    
    // Operazioni 40
    ret = ALRemoveLast(list, &listSize);
    assertSuccessfullExecution(4000, ret);
        
    assertSize(40, listSize, 1);
    assertKey(41, list, listSize, 0, 200);
    
    // Operazioni 50
    for(i=0; i<5; i++) {
        ret = ALInsertAtEnd(&list, &listSize, &listDim, i*1000);
        assertSuccessfullExecution(5000+i, ret);
    }
    
    assertSize(50, listSize, 6);
    assertKey(51, list, listSize, 0, 200);
    for(i=0; i<5; i++) {
        assertKey(52, list, listSize, 1+i, i*1000);
    }
    
    // Operazioni 60
    ret = ALRemoveAtPosition(list, &listSize,1);
    assertSuccessfullExecution(6000, ret);
    
    assertSize(60, listSize, 5);
    assertKey(61, list, listSize, 0, 200);
    for(i=1; i<5; i++) {
        assertKey(62, list, listSize, i, i*1000);
    }
    
    // Operazioni 70
    ret = ALInsertAtPosition(&list, &listSize, &listDim, 10000, 3);
    assertSuccessfullExecution(7000, ret);
    
    assertSize(70, listSize, 6);
    assertKey(71, list, listSize, 3, 10000);
    
    // Operazioni 80
    ret = ALInsertAtEnd(&list, &listSize, &listDim, 10000);
    assertSuccessfullExecution(8000, ret);
    assertSize(80, listSize, 7);
    assertKey(81, list, listSize, 3, 10000);
    assertKey(82, list, listSize, 6, 10000);
    assertPosition(83, list, listSize, 10000, 0, 3);
    assertPosition(84, list, listSize, 10000, 4, 6);

    // Operazioni 90
    // Svuoto la lista
    for(i=0; i<listSize; i++) {
        ret = ALRemoveLast(list, &listSize);
        assertSuccessfullExecution(9000+i, ret);
    }
    
    assertSize(90, listSize, 0);
    
    
    // Operazioni 100
    for(i=0; i<10; i++) {
        ret = ALInsertAtEnd(&list, &listSize, &listDim, 10+i);
        assertSuccessfullExecution(10000+i, ret);
    }
    assertSize(100, listSize, 10);
    for(i=0; i<10; i++)
        assertKey(101, list, listSize, i, 10+i);
    
    // Operazioni 110
    ret = ALEmptyList(&list, &listSize, &listDim);   // always free the memory when the list is not
                                // needed anymore
    assertSuccessfullExecution(11000, ret);
    assertSize(110, listSize, 0);
    
    // Operazioni 120
    ret = ALEmptyList(&list, &listSize, &listDim);
    assertReturnCode(12000, ret, -1); // the list is empty
    
    // Operazioni 130
    ret = ALGetKey(list, listSize, 17, &key);
    assertReturnCode(13000, ret, -1); // the list is empty
    
    // Operazioni 140
    ret = ALRemoveFirst(list, &listSize);
    assertReturnCode(14000, ret, -1); // the list is empty
    
    // Operazioni 150
    ret = ALRemoveLast(list, &listSize);
    assertReturnCode(15000, ret, -1); // the list is empty
    
    // Operazioni 160
    ret = ALRemoveAtPosition(list, &listSize, 17);
    assertReturnCode(16000, ret, -1); // the list is empty
    
     // Operazioni 170
    ret = ALFindKey(list, listSize, 17, 0, &position);
    assertReturnCode(16000, ret, -1); // the list is empty
    
    puts("Ottimo lavoro! Sembra proprio che tutto funzioni correttamente.\n");
    return (EXIT_SUCCESS);
}

void assertSize(int code, int currentSize, int expectedSize) {
    char message[ERRORMESSAGE_MAXLEN];
    if(currentSize != expectedSize) {
        sprintf(message, "Dimensione attesa: %d - Dimensione corrente: %d\n", expectedSize, currentSize);
        printAndExit(code, message);
    }
    else
        printf("Asserzione %d verificata\n", code);
    return;
}


void assertKey(int code, AList list, int listSize, int position, int expectedKey) {
    int currentKey;    
    char message[ERRORMESSAGE_MAXLEN];
    ALGetKey(list, listSize, position, &currentKey); // do not care to the return value
    if(expectedKey != currentKey) {
        sprintf(message, "Posizione %d. Valore atteso: %d - Valore corrente: %d\n", position, expectedKey, currentKey);
        printAndExit(code, message);
    }
    else
        printf("Asserzione %d verificata\n", code);
    return;
}

void assertPosition(int code, AList list, int listSize, int key, int startPosition, int expectedPosition) {
    int currentPosition;    
    char message[ERRORMESSAGE_MAXLEN];
    ALFindKey(list, listSize, key, startPosition, &currentPosition); // do not care to the return value
    if(expectedPosition != currentPosition) {
        sprintf(message, "Ricerca valore %d da posizione %d. Posizione attesa: %d - Posizione corrente: %d\n", 
                key, 
                startPosition, 
                expectedPosition, 
                currentPosition);
        printAndExit(code, message);
    }
    else
        printf("Asserzione %d verificata\n", code);
    return;
}

void assertReturnCode(int assertionCode, int currentReturnCode, int expectedReturnCode) {
    char message[ERRORMESSAGE_MAXLEN];
    if(currentReturnCode != expectedReturnCode) {
        sprintf(message, "Valore di ritorno corrente: %d - Valore di ritorno atteso: %d\n", currentReturnCode, expectedReturnCode);
        printAndExit(assertionCode, message);
    }
    else
        printf("Asserzione %d verificata\n", assertionCode);
    return;
}

void assertSuccessfullExecution(int assertionCode, int currentReturnCode) {
    assertReturnCode(assertionCode, currentReturnCode, 0);
    return;
}

void printAndExit(int code, char message[]) {
    fprintf(stderr, "Asserzione %d fallita. %s", code, message);
    exit(code);
}