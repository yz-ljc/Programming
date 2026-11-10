#include <iostream>
#include <iomanip>
using namespace std;

typedef char SElemType;

const int MAXSIZE = 100;

typedef struct {
    SElemType data[MAXSIZE];
    int top;
} SqStack;

void DisplayElem(SElemType e);
bool matching(char exp[]);

bool InitStack_Sq(SqStack &s);
bool Push_Sq(SqStack &s, SElemType e);
bool Pop_Sq(SqStack &s, SElemType &e);
bool GetTop_Sq(SqStack s, SElemType &e);
bool StackEmpty_Sq(SqStack s);
void StackTraverse_Sq(SqStack s, void (*visit)(SElemType));
void StackTraverseReverse_Sq(SqStack s, void (*visit)(SElemType));
bool DestroyStack_Sq(SqStack &s);

void DisplayElem(SElemType e) {
    cout << e << "  ";
}

bool InitStack_Sq(SqStack &s) {
    s.top = -1;
    return true;
}

bool Push_Sq(SqStack &s, SElemType e) {
    if (s.top == MAXSIZE - 1)
        return false;

    s.data[++s.top] = e;
    return true;
}

bool Pop_Sq(SqStack &s, SElemType &e) {
    if (s.top == -1)
        return false;

    e = s.data[s.top--];
    return true;
}

bool GetTop_Sq(SqStack s, SElemType &e) {
    if (s.top == -1)
        return false;

    e = s.data[s.top];
    return true;
}

bool StackEmpty_Sq(SqStack s) {
    return s.top == -1;
}

void StackTraverse_Sq(SqStack s, void (*visit)(SElemType)) {
    for (int i = s.top; i >= 0; i--)
        visit(s.data[i]);
}

void StackTraverseReverse_Sq(SqStack s, void (*visit)(SElemType)) {
    for (int i = 0; i <= s.top; i++)
        visit(s.data[i]);
}

bool DestroyStack_Sq(SqStack &s) {
    s.top = -1;
    return true;
}

bool matching(char exp[]) {
    SqStack s;
    InitStack_Sq(s);

    for (int i = 0; exp[i] != '\0' && exp[i] != '#'; i++) {
        if (exp[i] == '(' || exp[i] == '[') {
            Push_Sq(s, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == ']') {
            if (StackEmpty_Sq(s))
                return false;

            SElemType e;
            Pop_Sq(s, e);

            if (exp[i] == ')' && e != '(')
                return false;

            if (exp[i] == ']' && e != '[')
                return false;
        }
    }

    return StackEmpty_Sq(s);
}

int main()
{
    SqStack s1;
	SElemType e;
	if(InitStack_Sq(s1))
		cout << "初始化字符顺序栈成功" << endl;
	else
	{
		cout << "初始化字符顺序栈失败" << endl;
		return 1;
	}
	cout << "输入5个字符：" << endl;
	for (int i = 0; i <5; i++) {
		cin >> e;
		Push_Sq(s1, e);
	}
	if(GetTop_Sq(s1, e))
		cout << "取顺序栈栈顶元素是：" << e << endl;
	if(StackEmpty_Sq(s1))
		cout << "顺序栈空栈！" << endl;
	else 
		cout << "顺序栈非空栈！" << endl;
	cout << "自栈顶到栈底输出：" << endl;
	StackTraverse_Sq(s1, DisplayElem);
	cout << endl;
	cout << "自栈底到栈顶输出：" << endl;
	StackTraverseReverse_Sq(s1, DisplayElem);
	cout << endl;
	Pop_Sq(s1, e);
	cout << "弹出栈顶元素是：" << e << endl;
	if(!StackEmpty_Sq(s1)) {
        cout << "弹出栈顶元素后的栈：" << endl;
		StackTraverse_Sq(s1, DisplayElem);
		cout << endl;
	}
	if (DestroyStack_Sq(s1))
		cout<<"顺序栈已销毁！" << endl;
	char s[40];
	cout << "输入带括号表达式：" << endl;
	cin >> s;
	if(matching(s))
		cout<<"表达式括号匹配！" << endl;
	else
		cout<<"表达式括号不匹配！" << endl;
	return 0;
}