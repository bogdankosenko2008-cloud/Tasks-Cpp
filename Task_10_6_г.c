#include <stdio.h>
typedef struct {
    char city[50];
    char street[50];
    char house[15];
    int apartment;
} Address;

void inputAddress(Address *addr) {
    printf("Enter city: ");
    scanf("%49s", addr->city);

    printf("Enter street: ");
    scanf("%49s", addr->street);

    printf("Enter house number: ");
    scanf("%14s", addr->house);

    printf("Enter apartment number: ");
    scanf("%d", &addr->apartment);
}

void printAddress(Address addr) {
    printf("\nAddress: %s, %s St., bld. %s, apt. %d\n", 
           addr.city, addr.street, addr.house, addr.apartment);
}
int main() {
    Address myAddress;
    inputAddress(&myAddress);
    printAddress(myAddress);

    return 0;
}