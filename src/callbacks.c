#include <stdio.h>

int multiply(int a, int b) { return a * b; }
int addition(int a, int b) { return a + b; }
int difference(int a, int b) { return a - b; }
int division(int a, int b) { return a / b; }

int do_action(int a, int b, int (*action)(int, int)) { return action(a, b); }

int main() {
    int result = do_action(5, 5, multiply);  // 25
    printf("%d\n", result);

    result = do_action(5, 5, addition);  // 10
    printf("%d\n", result);

    result = do_action(5, 5, difference);  // 0
    printf("%d\n", result);

    result = do_action(5, 5, division);  // 1
    printf("%d\n", result);
}
