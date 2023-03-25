// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"
// тест включения
TEST(Automata, test1) {
  Automata coffee;
  coffee.on();
  EXPECT_EQ(coffee.get_state(), "WAIT");
}
// тест приготовления напитка
TEST(Automata, test2) {
  Automata coffee;
  coffee.on();
  coffee.coin(100);
  coffee.choice(2);
  EXPECT_EQ(coffee.get_state(), "WAIT");
}
// тест отмены
TEST(Automata, test3) {
  Automata coffee;
  coffee.on();
  coffee.coin(100);
  coffee.cancel();
  EXPECT_EQ(coffee.get_state(), "WAIT");
}
// тест выключения
TEST(Automata, test4) {
  Automata coffee;
  coffee.on();
  coffee.coin(100);
  coffee.cancel();
  coffee.off();
  EXPECT_EQ(coffee.get_state(), "OFF");
}
// тест "выбран неверный пункт меню"
TEST(Automata, test5) {
  Automata coffee;
  coffee.on();
  coffee.coin(100);
  coffee.choice(20);
  EXPECT_EQ(coffee.get_state(), "WAIT");
}
// тест "внесено недостаточно денег"
TEST(Automata, test6) {
  Automata coffee;
  coffee.on();
  coffee.coin(10);
  coffee.choice(2);
  EXPECT_EQ(coffee.get_state(), "WAIT");
}
// тест прием денег
TEST(Automata, test7) {
  Automata coffee;
  coffee.on();
  coffee.coin(100);
  EXPECT_EQ(coffee.get_state(), "ACCEPT");
}
