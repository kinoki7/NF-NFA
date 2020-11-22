//引入头文件
#include "Thompson.h"

//输入字符串
void input_NF()
{
	string NF;
	cout << "请输入正规式（字符范围为a-z,A-Z,*,|,(,)）：";
	cin >> NF;
	check_legal(NF);
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
		if ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z'))//为合法字母
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

//判断括号是否匹配
bool check_parentheses_legal(const string input_string)
{
	int length = input_string.length();
	stack<int> STACK;
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
				cout << "有多余右括号,请重新输入!"<< endl;
				return false;
			}
		}
	}
	if (!STACK.empty())
	{
		cout << "有多余左括号，请重新输入!" << endl;
		return false;
	}
	return true;
}

//为正规式增加连接符号
string add_connect(const string NF)
{

}