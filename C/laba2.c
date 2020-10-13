#include <stdio.h>
#include <malloc.h>
#include <conio.h>


struct item
{
    int data;
    struct item *next;
};

// Создать новый элемент
struct item *newOne(int newData)
{
    struct item *newElement;

    newElement = (struct item*)malloc(sizeof(struct item));
    if (newElement == NULL)
        return NULL;
    
    newElement->next = NULL;
    newElement->data = newData;

    return newElement;
}

// Добавить элемент в список
struct item *addItem(struct item *element, int newData)
{
    if (element == NULL)
        element = newOne(newData);
    else
    {
        struct item *i;
        for(i=element; i->next!=NULL; i=i->next);
        i->next = newOne(newData);
    }
    return element;
}

// Удалить список
void freeList(struct item *list)
{
   struct item *i,*del;
   i=list;

   while(i != NULL)
   {
      del=i;
      i=i->next;
      free(del);
   }
}

// Вывести список
void printList(struct item *list)
{   
    for(struct item *i=list; i!=NULL; i=i->next)
        printf("%d ",i->data);
}

// Проверяем есть ли число в списке
int inList(int num, struct item *list)
{
    for(struct item *i=list; i!=NULL; i=i->next)
        if (i->data == num)
            return 1;
    return 0;
}

// Создание списка из массива
struct item *createNew(int len, int arr[])
{
    struct item *newList = NULL;
    for (int i = 0; i < len; i++)
        newList = addItem(newList, arr[i]);
    
    return newList;
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8}; // Сделал 2 одинаковых списка но заменил пару цифр 10-ками для наглядности 
    struct item *list1 = createNew(8, arr1);
    int arr2[] = {1, 10, 3, 4, 10, 6, 10, 8};
    struct item *list2 = createNew(8, arr2);

    printf("Elements of list#1:\n");
    printList(list1);
    printf("\nElements of list#2:\n");
    printList(list2);

    int summ = 0, count = 0;
    printf("\nThis elements not included in second list: \n");
    for (struct item *i=list1; i!=NULL; i=i->next)
    {
        if (inList(i->data, list2) == 0) // Если числа нету в другом списке, то прибавляем это число к переменной sum и прибавляем 1 к счетчику
        {
            printf("%d ", i->data);
            summ += i->data;
            count++;
        }
    }
    printf("\nCount of elements: %d\n", count);
    printf("Arithmetic mean: %d", summ / count);

    freeList(list1);
    freeList(list2);

    return 0;
}