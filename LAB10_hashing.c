#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int key;
    char name[30];
} Employee;

Employee hashTable[MAX];
int m;

void initializeHashTable() {
    for (int i = 0; i < m; i++) {
        hashTable[i].key = -1;
    }
}

int hashFunction(int key) {
    return key % m;
}

void insert(int key, char name[]) {
    int hashIndex = hashFunction(key);
    while (hashTable[hashIndex].key != -1) {
        hashIndex = (hashIndex + 1) % m;
    }
    hashTable[hashIndex].key = key;
    snprintf(hashTable[hashIndex].name, sizeof(hashTable[hashIndex].name), "%s", name);
}

int search(int key) {
    int hashIndex = hashFunction(key);
    int startIndex = hashIndex;
    while (hashTable[hashIndex].key != -1) {
        if (hashTable[hashIndex].key == key) {
            return hashIndex;
        }
        hashIndex = (hashIndex + 1) % m;
        if (hashIndex == startIndex) {
            break;
        }
    }
    return -1;
}

void displayHashTable() {
    printf("Hash Table:\n");
    for (int i = 0; i < m; i++) {
        if (hashTable[i].key != -1) {
            printf("Index %d: Key = %d, Name = %s\n", i, hashTable[i].key, hashTable[i].name);
        } else {
            printf("Index %d: Empty\n", i);
        }
    }
}

int main() {
    int n, key;
    char name[30];

    printf("Enter the number of memory locations in the hash table: ");
    scanf("%d", &m);

    initializeHashTable();

    printf("Enter the number of employees: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter key (4-digit) and name for employee %d: ", i + 1);
        scanf("%d %s", &key, name);
        insert(key, name);
    }

    displayHashTable();

    printf("Enter a key to search: ");
    scanf("%d", &key);
    int index = search(key);
    if (index != -1) {
        printf("Key %d found at index %d: Name = %s\n", key, index, hashTable[index].name);
    } else {
        printf("Key %d not found in the hash table.\n", key);
    }

    return 0;
}
