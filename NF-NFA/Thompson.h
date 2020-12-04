#pragma once
#ifndef THOMPSON_H
#define THOMPSON_H

using namespace std;
//需要引入的库
#include <iostream>
#include <string>
#include <stack>

//函数
string input_NF();
bool check_legal(const string input_string);
bool check_character_legal(const string input_string);
bool check_parentheses_legal(const string input_string);
bool is_letter(char letter);
string add_connect(const string NF);
#endif  THOMPSON_H
