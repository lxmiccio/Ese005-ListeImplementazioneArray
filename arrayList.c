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
int ALIncreaseAndCopy(AList *list, int size, int *dimension) {
    int *newList;
    int newDimension;
    int i, result=-1;
    
    if(*dimension == 0)
        newDimension = 2;
    else
        newDimension = 2 * (*dimension);
    
    newList = (int *)malloc(newDimension * sizeof(int));
    if(newList != NULL) {
        for(i=0; i<size; i++) {
            newList[i] = (*list)[i];
        }
        free(*list);
        *list = newList;
        *dimension = newDimension;
        result = 0;
    }
    return result;
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
int ALInsertAtBeginning(AList *list, int *size, int *dimension, int key) {
    int result = -1;
    int ret = 0;
    int i;
    if(*size == *dimension) {
        ret = ALIncreaseAndCopy(list, *size, dimension);
    }
    if(ret == 0) {
        // Moves each element to the following position, starting from the last.
        for(i=(*size)-1; i>=0; i--) {
            (*list)[i+1] = (*list)[i];
        }
        // Sets the new key
        (*list)[0] = key;
        (*size)++;
        result = 0;
    }
    return result;
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
int ALInsertAtEnd(AList *list, int *size, int *dimension, int key) {
    int result = -1;
    int ret = 0;
    if(*size == *dimension) {
        ret = ALIncreaseAndCopy(list, *size, dimension);
    }
    if(ret == 0) {
        (*list)[*size] = key;
        (*size)++;
        result = 0;
    }
    return result;
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
int ALInsertAtPosition(AList *list, int *size, int *dimension, int key, int position) {
    int result = -1;
    int ret = 0;
    int i;
    if(*size == *dimension) {
        ret = ALIncreaseAndCopy(list, *size, dimension);
    }
    if(ret == 0) {
        // Makes room for the new element.
        // Moves the elements from position, starting from the last.
        for(i=(*size)-1; i>=position; i--) {
            (*list)[i+1] = (*list)[i];
        }
        // Sets the new key
        (*list)[position] = key;
        (*size)++;
        result = 0;
    }
    return result;
}

/*
 * Gives the key at the specified position. * 
 * 
 * Returns 0 on success.
 * Returns -1 if there is no key at the specified position
 */ 
int ALGetKey(int *list, int size, int position, int *key) {
    int result = -1;
    if(position < size) {
        *key = list[position];
        result = 0;
    }
    return result;
}

/*
 * Gives the position of the first element, starting from startPosition, that
 * has the specified key.
 * 
 * Returns 0 on success.
 * Returns -1 if not found. 
 */ 
int ALFindKey(int *list, int size, int key, int startPosition, int *position) {
    int result = -1;
    int i;
    int found = 0;
    for(i=startPosition; i<size && !found; i++) {
        if(list[i] == key) {
            found = 1;
            *position = i;
            result = 0;
        }
    }
    return result;
}

/*
 * Removes the first element of the list.
 * *size is the number of elements in the list.
 * The dimension of the list is not reduced.
 * 
 * Returns 0 on success.
 * Returns -1 in case of empty list.
 */
int ALRemoveFirst(int *list, int *size) {
    int result = -1;
    int i;
    if((*size) > 0) {
        for(i=1; i<(*size); i++) {
            list[i-1] = (list)[i];
        }
        (*size)--;
        result = 0;
    }
    return result;
}

/*
 * Remove the last element of the list.
 * *size is the number of elements in the list.
 * The dimension of the list is not reduced.
 * 
 * Returns 0 on success.
 * Returns -1 in case of empty list.
 */
int ALRemoveLast(int *list, int *size) {
    int result = -1;
    if((*size) > 0) {
        (*size)--;
        result = 0;
    }
    return result;
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
int ALRemoveAtPosition(int *list, int *size, int position) {
    int result = -1;
    int i;
    if((*size) > 0) {
        for(i=position+1; i<(*size); i++) {
            list[i-1] = list[i];
        }
        (*size)--;
        result = 0;
    }
    return result;
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
int ALEmptyList(AList *list, int *size, int *dimension) {
    int result = -1;
    if((*size) > 0) {
        free(*list);
        *size = 0;
        *dimension = 0;
        result = 0;
    }
    return result;
}


/*
 * Reduces the dimension of the list to its size.
 * 
 * Returns 0 on success.
 * Return -1 if memory allocation fails. 
 */
int ALShrink(AList *list, int size, int *dimension) {
    int result = -1;
    int i;
    int *newList = NULL;
    if((*dimension) > size) {
        newList = (int *)malloc(size * sizeof(int));
        if(newList != NULL) {
          for(i=0; i<size; i++) {
              newList[i] = (*list)[i];
          }
          free(*list);
          *list = newList;
          *dimension = size;
          result = 0;
        }
    }
    else
        result = 0;
    return result;
}
