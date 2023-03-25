#include "Automata.h"
#include<iostream>
#include<string.h>

Automata::Automata() {
    count_menu = 4;
    menu = new string[count_menu]{ "Эспрессо", "Капучино", "Какао", "Чай" };
    prices = new int[count_menu] {50, 60, 55, 40};
    state = OFF;
    cash = 0;
}

void Automata::on() {
    if (state == OFF)
        state = WAIT;
}

void Automata::off() {
    if (state == WAIT)
        state = OFF;
}

void Automata::coin(int sum) {
    if (state == WAIT || state == ACCEPT) {
        state = ACCEPT;
        cash += sum;
    }
}

void Automata::get_menu() {
    for (int i = 0; i < count_menu; i++) {
        std::cout << i + 1 << " " << menu[i] << " -- Цена: " << prices[i] << " руб.\n";
    }
}

Automata::State Automata::get_state() { return state; }

void Automata::choice(int number) {
    if (state == ACCEPT) {
        if (number < 1 || number > count_menu) {
            std::cout << "Введен неверный номер напитка\n";
        } else {
            state = CHECK;
            check(number);
        }
    }
}

void Automata::check(int number) {
    state = CHECK;
    if (cash < prices[number - 1]) {
        std::cout << "Недостаточно денег!\n";
        state = WAIT;
    } else
        cook(number);
}

void Automata::cancel() {
    if (state == ACCEPT || state == CHECK)
        state = WAIT;
}

void Automata::cook(int number) {
    state = COOK;
    std::cout << "Напиток готовится. Ожидайте...\n";
    switch (number) {
    case 1:
        Sleep(8000);
    case 2:
        Sleep(10000);
    case 3:
        Sleep(9000);
    case 4:
        Sleep(5000);
    }
    finish(cash - prices[number - 1]);
}

void Automata::finish(int sum) {
    cout << "Ваш напиток готов!\n";
    if (sum > 0)
        std::cout << "Ваша сдача: " << sum << "\n";
    state = WAIT;
}
