#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 1000

// Hash Node Structure
typedef struct HashNode {
    int key;
    int value;
    struct HashNode* next;
} HashNode;

// Hash Table Structure
typedef struct {
    HashNode* table[TABLE_SIZE];
} HashTable;

// Hash Function
int hash(int key) {
    return abs(key) % TABLE_SIZE;
}

// Insert into Hash Table
void insert(HashTable* ht, int key, int value) {
    int index = hash(key);
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->value = value;
    newNode->next = ht->table[index];
    ht->table[index] = newNode;
}

// Search in Hash Table
int search(HashTable* ht, int key, int* found) {
    int index = hash(key);
    HashNode* curr = ht->table[index];
    while (curr) {
        if (curr->key == key) {
            *found = 1;
            return curr->value;
        }
        curr = curr->next;
    }
    *found = 0;
    return -1;
}

// Free the Hash Table
void freeTable(HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        HashNode* curr = ht->table[i];
        while (curr) {
            HashNode* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
}

// Two Sum Function
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    HashTable ht = {0};  // Initialize hash table
    *returnSize = 2;     // Expecting two elements
    int* return_arr = malloc(*returnSize * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int found;
        int index = search(&ht, complement, &found);
        if (found) {
            return_arr[0] = index;
            return_arr[1] = i;
            return return_arr;
        }
        insert(&ht, nums[i], i);  // Insert current number and index
    }
    freeTable(&ht);  // Clean up memory
    return NULL;      // Return NULL if no solution found (though problem guarantees a solution)
}

// Driver Code
int main() {
    int nums[] = {2, 7, 11, 15};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 9;
    int returnSize;

    int* result = twoSum(nums, numsSize, target, &returnSize);

    if (result) {
        printf("Indices: [%d, %d]\n", result[0], result[1]);
        free(result);  // Free result array
    } else {
        printf("No solution found.\n");
    }

    return 0;
}

