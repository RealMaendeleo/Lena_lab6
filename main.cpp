#include <iostream>
#include "Window.h"
using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");

    Window w1;
    cin >> w1;

    cout << w1;
    w1.make_invisible();
    cout << w1;
    w1.make_visible();

    w1.move(10000, 10000); // �訡��� ����
    cout << w1;
    w1.move(800, 500);
    cout << w1;

    w1.change_size(10000, 10000);
    cout << w1;
    w1.change_size(-400, -100);
    cout << w1;



    Window w2;
    cin >> w2;
    cout << w2;
    bool result = w1 == w2;

    if (result)
        cout << "���� ==" << endl;
    else
        cout << "���� !=" << endl;

    w1 += 10;
    cout << w1;


    bool vis = !w2;
    // ����� �, �� �� ������ �⮣� ������



    return 0;
}