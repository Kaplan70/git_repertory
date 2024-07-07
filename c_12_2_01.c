#include <stdio.h>

char stock[512];
int top = 0;

void push(char x)
{
    stock[top++] = x;
}

char pop(void)
{
    return stock[--top];
}

int is_empt(void)
{
    return top == 0;
}

int main(void)
{
    push('a');
    push('b');
    push('c');
    while (!(is_empt())) {
        printf("%c\n", pop());
    }

    return 0;
}
