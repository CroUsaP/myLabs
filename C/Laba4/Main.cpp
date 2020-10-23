#include <iostream>
#include "Source.cpp"


using namespace std;

int main()
{
    Stack* stack = new Stack();

    char string[] = "(([Hello]) {world})";

    for (int i = 0; i < sizeof(string) - 1; i++)
    {
        switch (string[i])
        {
        case '(': case '{': case '[':
            stack->push(string[i]);
            break;

        case ')':
            if ((stack->topitem != 0) ? (stack->pick() == '(') : false)
                stack->pop();
            else
                stack->push('.');
            break;
        case '}':
            if ((stack->topitem != 0) ? (stack->pick() == '{') : false)
                stack->pop();
            else
                stack->push('.');
            break;
        case ']':
            if ((stack->topitem != 0) ? (stack->pick() == '[') : false)
                stack->pop();
            else
                stack->push('.');
            break;
        }
    }
    if (stack->topitem != 0)
        cout << "Ti durak, isprav`" << endl;    // Пишет, когда строка с нормальными скобками
    else
        cout << "Umni4ka" << endl;  // Пишет, когда строка с неправильными скобками

    system("pause");
    return 0;
}