#include<stdio.h>

/* 
  Try uncommenting pin1 and check size
  Check: https://katecpp.github.io/struct-members-order/
 */

typedef struct _address {
  int pin;
  // int pin1;
  char *street;
  char *city;
} Address;

typedef struct _person {
  Address address;
  char* name;
  int age;
  
} Person;


int main() {
  // instead of using struct _person p;
  Person p;
  
  p.age = 25;
  p.name = "Parikshit";
  p.address.city = "Sangli";
  p.address.pin = 416307;
  // p.address.pin1 = 416307;
  p.address.street = "Shri Siddharaj Maharaj Street";

  printf("Name: %s\nAge: %d\n", p.name, p.age);
  printf("Address:\n\tStreet: %s\n\tCity: %s\n\tPin: %d\n", 
          p.address.street, p.address.city, p.address.pin);

  printf("\nSize of Person: %ld", sizeof(p));
  return 0;
}