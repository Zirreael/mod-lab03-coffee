#include <iostream>
#include <string>
#include <Windows.h>
#include "Automata.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    Automata coffee;
    coffee.get_menu();
    coffee.on();
    coffee.coin(100);
    coffee.choice(3);
}
