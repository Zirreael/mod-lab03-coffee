// Copyright 2023 Zirraeal VisualStudio
#pragma once
#include <iostream>
#include <string>

class Automata {
 public:
  enum State { OFF, WAIT, CHECK, ACCEPT, COOK };

 private:
  int cash;
  int* prices;
  int count_menu;
  State state;
  std::string* menu;

 public:
  Automata();
  void on();
  void off();
  void coin(int);
  void get_menu();
  void choice(int);
  void cancel();
  State get_state();

 private:
  void check(int);
  void cook(int);
  void finish(int);
};
