#include <iostream>
#include <string>

using std::string;

class Item
{
public:
    Item(char value) { this->data = value; this->next = NULL; }

    Item(char value, Item* item) : Item(value) { this->next = item; }

    char data;
    Item* next;
};


class Stack
{
public:

    int push(char value)
    {
        if (this->topitem == NULL)
        {
            this->topitem = new Item(value);
            return this->topitem != NULL ? 0 : 1;
        }
        else
        {
            Item* newElement = new Item(value, this->topitem);
            this->topitem = newElement;
        }
    }

    char pop()
    {
        if (this->topitem == NULL)
            return '0';
        Item* tempItem = this->topitem;
        char tempData = tempItem->data;
        this->topitem = tempItem->next;
        delete(tempItem);
        return tempData;
    }

    char pick()
    {
        return this->topitem->data;
    }
    Item* topitem = NULL;
};