#include <iostream>
#include "Source.cpp"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    Queue* queue = new Queue();

    for (int i = 0; i < 6; i++)
    {
        char c;
        cout << "Введите символ#" << i+1 << " ";
        cin >> c;
        queue->Push(c);
    }

    cout << endl << "Сейчас наша очередь выглядит вот так:\n" << queue->ToString("\n") << endl;
    cout << "Убираем " << queue->Pop();
    cout << " и " << queue->Pop() << endl;
    cout << "Теперь она выглядит так: \n" << queue->ToString("\n") << endl;

    system("pause");
    return 0;
}
