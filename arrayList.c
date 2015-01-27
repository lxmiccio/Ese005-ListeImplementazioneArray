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
int ALIncreaseAndCopy(AList *list, int size, int *dimension) {
    // TODO Implement code here
    return -1;
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
    // TODO Implement code here
    return -1;
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
    // TODO Implement code here
    return -1;
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
    // TODO Implement code here
    return -1;
}

/*
 * Gives the key at the specified position. * 
 * 
 * Returns 0 on success.
 * Returns -1 if there is no key at the specified position
 */ 
int ALGetKey(AList list, int size, int position, int *key) {
    // TODO Implement code here
    return -1;
}

/*
 * Gives the position of the first element, starting from startPosition, that
 * has the specified key.
 * 
 * Returns 0 on success.
 * Returns -1 if not found. 
 */ 
int ALFindKey(AList list, int size, int key, int startPosition, int *position) {
    // TODO Implement code here
    return -1;
}

/*
 * Removes the first element of the list.
 * *size is the number of elements in the list.
 * The dimension of the list is not reduced.
 * 
 * Returns 0 on success.
 * Returns -1 in case of empty list.
 */
int ALRemoveFirst(AList list, int *size) {
    // TODO Implement code here
    return -1;
}

/*
 * Remove the last element of the list.
 * *size is the number of elements in the list.
 * The dimension of the list is not reduced.
 * 
 * Returns 0 on success.
 * Returns -1 in case of empty list.
 */
int ALRemoveLast(AList list, int *size) {
    // TODO Implement code here
    return -1;
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
int ALRemoveAtPosition(AList list, int *size, int position) {
    // TODO Implement code here
    return -1;
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
    // TODO Implement code here
    return -1;
}


/*
 * Reduces the dimension of the list to its size.
 * 
 * Returns 0 on success.
 * Return -1 if memory allocation fails. 
 */
int ALShrink(AList *list, int *size, int *dimension) {
    // TODO Implement code here
    return -1;
}
