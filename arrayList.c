#include <stdlib.h>
#include "arrayList.h"

/*
 * Increases the dimension of the Array List.
 * *size is the number of elements in the list.
 * *dimension is the number of elements allocated for the list: it will be doubled
 *  after the function call. In case of 0, it is set to 2.
 * 
 * Returns 0 on success.
 * Returns -1 if memory allocation fails.
 */
int ALIncreaseAndCopy(AList *list, int size, int *dimension)
{
    int allocationError = -1, counter;
    if(*dimension == 0)
        *dimension = 1;
    AList newArrayList = (AList)malloc(2*(*dimension)*sizeof(int));
    if(newArrayList != NULL)
    {
        allocationError = 0;
        for(counter = 0; counter < size; counter++)
            newArrayList[counter] = (*list)[counter];
        free(*list);
        *list = newArrayList;      
        *dimension *= 2;
    }
    return allocationError;
}

/*
 * Inserts the new key at the beginning of the list.
 * *size is the number of elements in the list.
 * *dimension is the number of elements allocated for the list: it could be increased
 *      to store the new element.
 * 
 * Returns 0 on success.
 * Returns -1 if memory allocation fails.
 */
int ALInsertAtBeginning(AList *list, int *size, int *dimension, int key)
{
    int allocationError = -1, counter, returnValue = 0;
    if(*dimension == *size)
        returnValue = ALIncreaseAndCopy(list, *size, dimension);
    if(returnValue == 0)
    {
        allocationError = 0;
        for(counter=*size; counter>0; counter--)
            (*list)[counter] = (*list)[counter-1];
        (*list)[0] = key;
        (*size)++;
    }
    return allocationError;
}

/*
 * Inserts the new key at the end of the list.
 * *size is the number of elements in the list.
 * *dimension is the number of elements allocated for the list: it could be increased
 *      to store the new element.
 * 
 * Returns 0 on success.
 * Returns -1 if memory allocation fails.
 */
int ALInsertAtEnd(AList *list, int *size, int *dimension, int key)
{
    int allocationError = -1, returnValue = 0;
    if(*dimension == *size)
        returnValue = ALIncreaseAndCopy(list, *size, dimension);
    if(returnValue == 0)
    {
        allocationError = 0;
        (*list)[*size] = key;
        (*size)++;
    }
    return allocationError;
}

/*
 * Inserts the new key at the specified positon of the list.
 * Position is zero-based, meaning that the first element is at position 0,
 * analogous to what happens in arrays.
 * *size is the number of elements in the list.
 * *dimension is the number of elements allocated for the list: it could be increased
 *      to store the new element.
 * 
 * Returns 0 on success.
 * Returns -1 if memory allocation fails.
 */
int ALInsertAtPosition(AList *list, int *size, int *dimension, int key, int position)
{
    int allocationError = -1;
    if(position >= 0)
    {
        int counter, returnValue = 0;
        if(*dimension == *size)
            returnValue = ALIncreaseAndCopy(list, *size, dimension);
        if(returnValue == 0 && position < *dimension)
        {
            allocationError = 0;
            for(counter=(*size)-1; counter>=position; counter--)
                (*list)[counter+1] = (*list)[counter];
            (*list)[position] = key;
            (*size)++;
        }
    }
    return allocationError;
}

/*
 * Gives the key at the specified position. * 
 * 
 * Returns 0 on success.
 * Returns -1 if there is no key at the specified position
 */ 
int ALGetKey(AList list, int size, int position, int *key)
{
    int foundKey = -1;
    if(position >= 0 && size > 0 && position < size)
    {
        foundKey = 0;
        *key = list[position];
    }
    return foundKey;
}

/*
 * Gives the position of the first element, starting from startPosition, that
 * has the specified key.
 * 
 * Returns 0 on success.
 * Returns -1 if not found. 
 */ 
int ALFindKey(AList list, int size, int key, int startPosition, int *position)
{
    int counter, foundKey = -1;
    if(startPosition >= 0 && size > 0 && startPosition < size)
    {
        for(counter = startPosition; counter < size && foundKey != 0; counter++)
            if(list[counter] == key)
            {
                foundKey = 0;
                *position = counter;
            }
    }
    return foundKey;
}

/*
 * Removes the first element of the list.
 * *size is the number of elements in the list.
 * The dimension of the list is not reduced.
 * 
 * Returns 0 on success.
 * Returns -1 in case of empty list.
 */
int ALRemoveFirst(AList list, int *size)
{
    int counter, emptyList = -1;
    if(*size > 0)
    {
        emptyList = 0;
        for(counter = 0; counter < (*size)-1; counter++)
            list[counter] = list[counter+1];
        (*size)--;
    }
    return emptyList;
}

/*
 * Remove the last element of the list.
 * *size is the number of elements in the list.
 * The dimension of the list is not reduced.
 * 
 * Returns 0 on success.
 * Returns -1 in case of empty list.
 */
int ALRemoveLast(AList list, int *size)
{
    int emptyList = -1;
    if(*size > 0)
    {
        emptyList = 0;
        (*size)--;
    }
    return emptyList;
}

/*
 * Remove the element at the specified position.
 * Position is zero-based, meaning that the first element is at position 0,
 * analogous to what happens in arrays.
 * 
 * *size is the number of elements in the list.
 * The dimension of the list is not reduced.
 * 
 * Returns 0 on success.
 * Returns -1 in case it does not exist any element at the specified position
 */
int ALRemoveAtPosition(AList list, int *size, int position)
{
    int existingElement = -1;
    if(position >= 0 && *size > 0 && position < *size)
    {
        int counter;
        existingElement = 0;
        for(counter = position; counter < (*size)-1; counter++)
            list[counter] = list[counter+1];
        (*size)--;
    }
    return existingElement;
}

/*
 * Empties the list.
 * 
 * *size is the number of elements in the list: it is set to 0.
 * *dimension is the number of elements allocated for the list: it is set to 0.
 * 
 * Returns 0 on success.
 * Return -1 in case of emtpy list. 
 */
int ALEmptyList(AList *list, int *size, int *dimension)
{
    int emptyList = -1;
    if(*size > 0)
    {
        emptyList = 0;
        *size = 0;
        *dimension = 0;
        free(*list);
    }
    return emptyList;
}


/*
 * Reduces the dimension of the list to its size.
 * 
 * Returns 0 on success.
 * Return -1 if memory allocation fails. 
 */
int ALShrink(AList *list, int *size, int *dimension)
{
    int allocationError = -1;
    if(*size < *dimension)
    {
        int counter;
        AList newArrayList = (AList)malloc((*size)*sizeof(int));
        if(newArrayList != NULL)
        {
            allocationError = 0;
            for(counter = 0; counter < (*size); counter++)
                newArrayList[counter] = (*list)[counter];
            free(*list);
            *list = newArrayList;
            *dimension = *size;
        }
    }
    return allocationError;
}