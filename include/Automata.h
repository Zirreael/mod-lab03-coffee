#pragma once
#include <iostream>
#include <string.h>
#include <windows.h>

using namespace std;

class Automata {
public:
	enum State {
		OFF,
		WAIT,
		ACCEPT,
		CHECK,
		COOK
	};
private:
	int cash;
	int* prices;
	int count_menu;
	State state;
	string* menu;
public:
	Automata();
	void on();
	void off();
	void coin(int);
	void get_menu();
	State get_state();
	void choice(int);
	void cancel();
private:
	void check(int);
	void cook(int);
	void finish(int);
};
