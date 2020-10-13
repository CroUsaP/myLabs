#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

#define MAXSIZE 5

#define EMPTY -1

struct  stack //структура стек
{
    char st[MAXSIZE];    // стек

    int top;    // индекс вершины стека
};

int push(struct stack *st, int value)   // функция помещения элемента в стек
{
    if (st->top==MAXSIZE)    // если стек заполнен, то
            return 0;   // вернуть 0

    st->st[st->top]=value;  // поместить новый элемент на вершину стека

    st->top++;  // увеличить индекс вершины

    return 1;   // вернуть 1- признак успешного добавления
}

char pop(struct stack *st) // функция извлечения элемента из стека
{
    if(st->top==0)  // если стек пуст, то
            return EMPTY; // вернуть константу EMPTY

    st->top--;  // уменьшить индекс вершины стека на единицу

    return st->st[st->top]; // вернуть значение элемента
}

char popCheck(struct stack *st)
{
    return st->st[st->top-1];
}

void print(struct stack *st)
{
    for (int i = 0; i < MAXSIZE; i++)
        printf("%d\n", st->st[i]);
}

int main()
{
    struct stack *st = (struct stack*)malloc(sizeof(struct stack)); // выделить память под стек
    st->top = 0;

    char string[] = "(([Hello]) {world})";

    for (int i = 0; i < sizeof(string) - 1; i++)
    {
        switch (string[i])
        {
        case '(': case '{': case '[':
            push(st, string[i]);
            break;
        
        case ')':
            if ((st->top != 0) ? (popCheck(st) == '(') : false)
                pop(st);
            else
                push(st, '.');
            break;
        case '}':
            if ((st->top != 0) ? (popCheck(st) == '{') : false)
                pop(st);
            else
                push(st, '.');
            break;
        case ']':
            if ((st->top != 0) ? (popCheck(st) == '[') : false)
                pop(st);
            else
                push(st, '.');
            break;
        }
    }
    if (st->top != 0)
        printf("Ti durak, isprav`");
    else
        printf("Umni4ka");

    return 0;
}