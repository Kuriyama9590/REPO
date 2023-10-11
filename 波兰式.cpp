#include<iostream> 
#include<string> 
#include<stack>
#include<sstream> 

using namespace std;

class Solution
{
private:
	stack<string> nums;		// 存储操作数, 实际上会存储操作符的
	stack<char> op;			// 存储操作符

	// 逆向遍历时判断操作符优先级
	bool opcmpRight(char op1, char op2)
	{
		// + - 的时候，只需要判断栈顶是否同级，逆序，同级新的优先级更高
		if (op1 == '+' || op1 == '-')
		{
			return op2 == '+' || op2 == '-';
		}
		// * / 直接入栈
		return true;
	}

	// 正向遍历时判断操作符优先级
	bool opcmpLeft(char op1, char op2)
	{
		// 正向的时候，同级新的优先级会低
		if (op1 == '*' || op1 == '/')
		{
			return op2 != '*' && op2 != '/';
		}
		return false;
	}
public:
	// 求解波兰式
	string poland(string s)
	{
		int len = s.length();
		// 逆序遍历字符串
		for (int i = len - 1; i >= 0; --i)
		{
			// 数字存栈
			if (s[i] >= '0' && s[i] <= '9')
			{
				// 字符串拼接
				string num = "";
				num += s[i];
				// 判断前置是否是数字
				while (i - 1 >= 0 && s[i - 1] >= '0' && s[i - 1] <= '9')
				{
					num = s[--i] + num;
				}
				// 将数字入栈
				nums.push(num);
			}
			// 操作符
			// 判断栈是否空，或者有右括号
			else if (op.empty() || s[i] == ')' || op.top() == ')')
			{
				op.push(s[i]);
			}
			// 识别到左括号，此时需要将括号内的操作符输出
			else if (s[i] == '(')
			{
				// 操作数栈存储括号内的操作符
				while (!op.empty() && op.top() != ')')
				{
					string ops = "";
					ops += op.top();
					nums.push(ops);
					op.pop();
				}
				// 右括号出栈
				op.pop();
			}
			// 优先级高于栈顶，无脑入栈
			else if (opcmpRight(s[i], op.top()))
			{
				op.push(s[i]);
			}
			// 优先级低于栈顶
			else
			{
				// 操作符出栈并存入操作数栈
				while (!op.empty() && !opcmpRight(s[i], op.top()))
				{
					string ops = "";
					ops += op.top();
					nums.push(ops);
					op.pop();
				}
				// 压栈
				op.push(s[i]);
			}
		}
		// 将最终操作符栈压入操作数栈中
		while (!op.empty())
		{
			string ops = "";
			ops += op.top();
			nums.push(ops);
			op.pop();
		}
		// 得出答案
		string ans = "";
		while (!nums.empty())
		{
			ans += nums.top() + (nums.size() > 1 ? " " : "");
			nums.pop();
		}
		return ans;
	}

	// 求解逆波兰式
	string antiPoland(string s)
	{
		int len = s.size();
		string ans = "";
		// 正向遍历
		for (int i = 0; i < len; ++i)
		{
			// 数字直接加入答案
			if (s[i] >= '0' && s[i] <= '9')
			{
				ans += s[i];
				while (i + 1 < len && s[i + 1] >= '0' && s[i + 1] <= '9')
				{
					ans += s[++i];
				}
				ans += " ";
			}
			// 操作符的情况则需要和波兰式类似存栈
			// 栈空，左括号
			else if (op.empty() || s[i] == '(' || op.top() == '(')
			{
				op.push(s[i]);
			}
			// 右括号则需要输出括号内的操作符
			else if (s[i] == ')')
			{
				while (!op.empty() && op.top() != '(')
				{
					ans += op.top();
					ans += " ";
					op.pop();
				}
				op.pop();
			}
			// 判断优先级
			else if (opcmpLeft(s[i], op.top()))
			{
				op.push(s[i]);
			}
			else
			{
				while (!op.empty() && !opcmpLeft(s[i], op.top()))
				{
					ans += op.top();
					ans += " ";
					op.pop();
				}
				op.push(s[i]);
			}
		}
		// 将栈中输出到答案中
		while (!op.empty())
		{
			ans += op.top();
			ans += op.size() > 1 ? " " : "";
			op.pop();
		}
		return ans;
	}
};

int main(int argc, char** argv)
{
	int t;
	cin >> t;
	while (t--)
	{
		Solution sol;
		string s;
		cin >> s;
		cout << sol.poland(s) << endl;
		cout << sol.antiPoland(s) << endl << endl;
	}

	return 0;
}