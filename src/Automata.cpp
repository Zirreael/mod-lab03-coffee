// Copyright 2023 Zirraeal VisualStudio
#include "Automata.h"
#include<iostream>
#include<string>

Automata::Automata() {
    count_menu = 4;
    menu = new std::string[count_menu]{ "Эспрессо", "Латте", "Какао", "Чай" };
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
        std::cout << i + 1 << " " << menu[i] << "Цена: " << prices[i] << "\n";
    }
}

std::string Automata::get_state() {
    switch (state) {
    case OFF:
        return "OFF";
    case COOK:
        return "COOK";
    case ACCEPT:
        return "ACCEPT";
    case WAIT:
        return "WAIT";
    case CHECK:
        return "CHECK";
    }
}

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
    } else {
        cook(number);
    }
}

void Automata::cancel() {
    if (state == ACCEPT || state == CHECK)
        state = WAIT;
}

void Automata::cook(int number) {
    state = COOK;
    std::cout << "Напиток готовится. Ожидайте...\n";
    finish(cash - prices[number - 1]);
}

void Automata::finish(int sum) {
    std::cout << "Ваш напиток готов!\n";
    if (sum > 0)
        std::cout << "Ваша сдача: " << sum << "\n";
    state = WAIT;
}
