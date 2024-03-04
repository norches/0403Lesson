#include <stdio.h>
#include <stdlib.h>

typedef struct Person {
    char* name;
    int age;
} Person;

typedef struct Link {
    int val;
    struct Link* next;

} Link;

Link* create_link(int val) {
    Link* link = (Link*)malloc(sizeof(Link));
    link->val = val;
    link->next = NULL;
    return link;
}

void insert_link(Link* link, int val) {
    Link* new_link = create_link(val);
    new_link->next = link->next;
    link->next = new_link;
}

void destroy(Link* root) {
    while (root->next != NULL) destroy(root->next);
    free(root);
}

void add_list_item(int* array, int length, int x, int index) {
    for (int i = length - 1; i > index; i--) {
        array[i] = array[i - 1];
    }
    array[index] = x;
}

void print_array(int* array, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d\n", array[i]);
    }
}

void print_linked_array(Link* root) {
    Link* current = root;
    while (current->next != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

int main() {
    /*int length = 11;
    int a_simple[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    add_list_item(a_simple, length, 80, 7);
    print_array(a_simple, length);*/

    Link* a = create_link(1);
    Link* current = a;
    for (int i = 2; i < 12; i++) {
        insert_link(current, i);
        current = current->next;
    }
    printf("Состояние ДО\n");
    print_linked_array(a);

    printf("Состояние После\n");
    insert_link(a, 80);
    print_linked_array(a);

    // destroy(a);

    /*Person* uvays = (Person*)malloc(sizeof(Person));
    uvays->name = (char*)malloc(50 * sizeof(char));

    uvays->age = 24;

    uvays->name = "Uvays";

    printf("Зовут: %s, Лет: %d\n", uvays->name, uvays->age);*/
    return 0;
};
