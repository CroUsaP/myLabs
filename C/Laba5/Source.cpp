#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;


class Item
{
public:
    char data;
    Item* next;

    Item(char value) { this->data = value; this->next = NULL; }

    Item(char value, Item* item) : Item(value) { this->next = item; }

    Item* Add(Item* itemToAttach) { this->Last()->next = itemToAttach; return itemToAttach; }
    Item* Add(char value){ return this->Add(new Item(value)); }

    string ToString(string arg = "")
    {
        string str = "";
        for (Item* i = this; i != NULL; i = i->next)
        {
            str = str + string(1, i->data) + (i->next != NULL ? arg : "");
        }
        return str;
    }

    int Length()
    {
        int c = 0;
        for (Item* i = this; i != NULL; i = i->next, c++);
        return c;
    }


    Item* Last()
    {
        Item* i;
        for (i = this; i->next != NULL; i = i->next);
        return i;
    }

};

class Queue
{
public:
    Queue()
    {
        this->head = NULL;
        this->tail = NULL;
    }
    Queue(Item* itemToStartWith) : Queue() { this->head = itemToStartWith; }
    Queue(char value) : Queue() { this->head = new Item(value); }

    Item* Head() { return this->head; }
    Item* Tail() { return this->tail; }

    int Length() { return this->tail->Length(); }

    int Push(char value)
    {
        if (this->head == NULL) {
            this->head = new Item(value);
            return 1;
        }
        this->tail = this->head->Add(value);
        return 0;
    }

    string ToString(string arg)
    {
        return this->head->ToString(arg);
    }

    char Pick()
    {
        return this->head->data;
    }

    char Pop()
    {
        if (this->tail == NULL && this->head != NULL)
        {
            char tmpChar = this->head->data;
            Item* tmpItem = this->head;
            this->head = NULL;
            delete(tmpItem);
            return tmpChar;
        }
        Item* tmpItem = this->head;
        char tmpChar = this->head->data;
        this->head = this->head->next;
        delete(tmpItem);
        return tmpChar;
    }

private:
    Item* head;
    Item* tail;
};