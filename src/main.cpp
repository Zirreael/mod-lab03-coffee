//Copyright 2023 Zirraeal VisualStudio
#include <iostream>
#include <string>
#include "Automata.h"

int main() {
    setlocale(LC_ALL, "Russian");
    Automata coffee;
    coffee.get_menu();
    coffee.on();
    coffee.coin(100);
    coffee.choice(3);
}
