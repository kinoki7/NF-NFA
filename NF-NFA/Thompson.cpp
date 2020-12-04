//引入头文件
#include "Thompson.h"

//输入字符串
string input_NF()
{
	string NF;
	cout << "请输入正规式（字符范围为a-z,A-Z,*,|,(,)）：";
	cin >> NF;
	check_legal(NF);
	return NF;
}

//判断字符串是否合法
bool check_legal(const string input_string)
{
	if (check_character_legal(input_string) && check_parentheses_legal(input_string))
	{
		return true;
	}
	else
		return false;
}
//判断字符是否合法
bool check_character_legal(const string input_string)
{
	int length = input_string.length();
	for (int i = 0; i < length; i++)
	{
		char character = input_string.at(i);
		if (is_letter(character))//为合法字母
		{
			
		}
		else if (character == '*' || character == '|' || character == '(' || character == ')')//为合法字符
		{
			
		}
		else
		{
			cout << "有违法字符!请重新输入!"<<endl;
			return false;
		}
	}
	return true;
}

//判断是否为字母
bool is_letter(char letter)
{
	if ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z'))//为合法字母
		return true;
	return false;
}

//判断括号是否匹配
bool check_parentheses_legal(const string input_string)
{
	int length = input_string.length();
	stack<char> STACK;
	for (int i = 0; i < length; i++)
	{
		char character = input_string.at(i);
		if (character == '(')
		{
			STACK.push(character);
		}
		else if (character == ')')
		{
			if (STACK.empty())
			{
				cout << "有多余右括号,请重新输入!" << endl;
				return false;
			}
			else
				STACK.pop();
		}
	}
	if (!STACK.empty())
	{
		cout << "有多余左括号，请重新输入!" << endl;
		return false;
	}
	return true;
}

//---------------------------------------------------以上函数用于输入正规式和判别正规式是否合法

//为正规式增加连接符号
string add_connect(const string NF)
{
	int length = NF.length();
	int return_stringlen = 0;
	char First, Second;//用来当做要检查的字符
	char* return_string = new char[2 * length+1];//创建要返回新数组来存储新的正规式
	for (int i = 0; i < length - 1; i++)
	{
		First = NF.at(i);
		Second = NF.at(i + 1);
		return_string[return_stringlen++] = First;
		if(is_letter(First) && (Second == '(' || is_letter(Second)))//以下情况对正规式添加连接符'+'
		{
			return_string[return_stringlen++] = '+';
		}
		else if(First == ')' && is_letter(Second))
		{
			return_string[return_stringlen++] = '+';
		}
		else if (First == '*' && is_letter(Second))
		{
			return_string[return_stringlen++] = '+';
		}
	}
	return_string[return_stringlen++] = Second;//要写入最后一个字符
	return_string[return_stringlen] = '\0';
	string NF_UP(return_string);//转为串便于输出
	cout << "修改后的正规式为：" << NF_UP << endl;
	return NF_UP;
}

