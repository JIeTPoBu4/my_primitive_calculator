#include <iostream>
#include "my_stack.h"
#include "my_queue.h"
#include <cstdio>

using namespace std;

void pars(char *str, my_stack<char*> &stack);
void pars(char *str, my_queue<char*> &queue);
void pole_note(my_queue<char*> &queue, my_stack<char*> stack, my_queue<char*> &result);
bool is_operand(char *buffer);
bool is_func(char *buffer);
bool is_operator(char *buffer);
double calculate(my_queue<char*> &pole);

void main()
{
	char str[100];
	my_queue<char*> res;
	double answer;
	my_stack<char*> obj;
	my_queue<char*> ob;
	cin.get(str, 50);
	//pars(str, obj);
	pars(str, ob);
	//ob.show_all();
	pole_note(ob, obj, res);
	//res.show_all();
	cout << calculate(res);

}

void pars(char *str, my_stack<char*> &stack)
{
	char dot[] = ".";
	char *symb[] = { "(", ")", "+", "-", "/", "*", "=", "" };
	char *dig[] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "" };
	char *func[] = { "tg", "ctg", "sin", "cos", "" };
	bool flag = false;
	char *buf;
	for (int i = 0; str[i] != '\0'; i++)
	{
		for (int j = 0; symb[j][0]; j++)
		{
			if (str[i] == symb[j][0])
			{
				if (flag)
				{
					stack.push(buf);
					flag = false;
				}
				buf = new char[2];
				buf[0] = '\0';
				strcat_s(buf, 2, symb[j]);
				stack.push(buf);
			}
			else
			{
				continue;
			}
		}
		if ((str[i] == '.') || (str[i] == '0') || (str[i] == '1') || (str[i] == '2') || (str[i] == '3') || (str[i] == '4') || (str[i] == '5') || (str[i] == '6') || (str[i] == '7') || (str[i] == '8') || (str[i] == '9'))
		{
			if ((str[i] == '.') && (i != 0))
			{
				if (((str[i - 1] == '0') || (str[i - 1] == '1') || (str[i - 1] == '2') || (str[i - 1] == '3') || (str[i - 1] == '4') || (str[i - 1] == '5') || (str[i - 1] == '6') || (str[i - 1] == '7') || (str[i - 1] == '8') || (str[i - 1] == '9')) && ((str[i + 1] == '0') || (str[i + 1] == '1') || (str[i + 1] == '2') || (str[i + 1] == '3') || (str[i + 1] == '4') || (str[i + 1] == '5') || (str[i + 1] == '6') || (str[i + 1] == '7') || (str[i + 1] == '8') || (str[i + 1] == '9')))
				{
					strcat_s(buf, 16, dot);
				}
			}
			for (int z = 0; dig[z][0]; z++)
			{
				if (str[i] == dig[z][0])
				{
					if (!flag)
					{
						buf = new char[16];
						buf[0] = '\0';
						flag = true;
						strcat_s(buf, 16, dig[z]);
					}
					else
					{
						strcat_s(buf, 16, dig[z]);
					}
				}
				else
				{
					continue;
				}
			}
		}
	}
	if (flag)
	{
		stack.push(buf);
	}
}

void pars(char *str, my_queue<char*> &queue)
{
	char dot[] = ".";
	char *symb[] = { "(", ")", "+", "-", "/", "*", "=", "" };
	char *dig[] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "" };
	char *func[] = { "tg", "ctg", "sin", "cos", "" };
	bool flag = false;
	char *buf;
	for (int i = 0; str[i] != '\0'; i++)
	{
		for (int j = 0; symb[j][0]; j++)
		{
			if (str[i] == symb[j][0])
			{
				if (flag)
				{
					queue.push(buf);
					flag = false;
				}
				if (i != 0)
				{
					if ((str[i] == '-') && (str[i - 1] == '('))
					{
						buf = new char[16];
						buf[0] = '\0';
						flag = true;
						strcat_s(buf, 16, symb[j]);
						continue;
					}
				}
				if ((str[i] == '-') && (i == 0))
				{
					buf = new char[16];
					buf[0] = '\0';
					flag = true;
					strcat_s(buf, 16, symb[j]);
				}
				else
				{
					buf = new char[2];
					buf[0] = '\0';
					strcat_s(buf, 2, symb[j]);
					queue.push(buf);
				}
			}
			else
			{
				continue;
			}
		}
		if ((str[i] == '.') || (str[i] == '0') || (str[i] == '1') || (str[i] == '2') || (str[i] == '3') || (str[i] == '4') || (str[i] == '5') || (str[i] == '6') || (str[i] == '7') || (str[i] == '8') || (str[i] == '9'))
		{
			if ((str[i] == '.') && (i != 0))
			{
				if (((str[i - 1] == '0') || (str[i - 1] == '1') || (str[i - 1] == '2') || (str[i - 1] == '3') || (str[i - 1] == '4') || (str[i - 1] == '5') || (str[i - 1] == '6') || (str[i - 1] == '7') || (str[i - 1] == '8') || (str[i - 1] == '9')) && ((str[i + 1] == '0') || (str[i + 1] == '1') || (str[i + 1] == '2') || (str[i + 1] == '3') || (str[i + 1] == '4') || (str[i + 1] == '5') || (str[i + 1] == '6') || (str[i + 1] == '7') || (str[i + 1] == '8') || (str[i + 1] == '9')))
				{
					strcat_s(buf, 16, dot);
				}
			}
			for (int z = 0; dig[z][0]; z++)
			{
				if (str[i] == dig[z][0])
				{
					if (!flag)
					{
						buf = new char[16];
						buf[0] = '\0';
						flag = true;
						strcat_s(buf, 16, dig[z]);
					}
					else
					{
						strcat_s(buf, 16, dig[z]);
					}
				}
				else
				{
					continue;
				}
			}
		}
		//œ¿–—»Õ√ ‘”Õ ÷»…
		for (int f = 0; func[f][0]; f++)
		{
			if (str[i] == func[f][0])
			{
				int q = i;
				int x = 0;
				while (func[f][x] == str[q])
				{
					q++;
					x++;
				}
				if (!func[f][x])
				{
					buf = new char[strlen(func[f]) + 1];
					buf[0] = '\0';
					strcat_s(buf, 16, func[f]);
					queue.push(buf);
					i += strlen(func[f]) - 1;
					break;
				}
				else
				{
					continue;
				}
			}
			else
			{
				continue;
			}
		}
	}
	if (flag)
	{
		queue.push(buf);
	}
}

bool is_operand(char *buffer)
{
	if (!strcmp(buffer, "+") || !strcmp(buffer, "-") || !strcmp(buffer, "*") || !strcmp(buffer, "/") || !strcmp(buffer, "sin") || !strcmp(buffer, "cos") || !strcmp(buffer, "tg") || !strcmp(buffer, "ctg") || !strcmp(buffer, "(") || !strcmp(buffer, ")"))
	{
		return false;
	}
	else
		return true;
}

bool is_func(char *buffer)
{
	if (!strcmp(buffer, "sin") || !strcmp(buffer, "cos") || !strcmp(buffer, "tg") || !strcmp(buffer, "ctg"))
		return true;
	else
		return false;
}
bool is_operator(char *buffer)
{
	if (!strcmp(buffer, "+") || !strcmp(buffer, "-") || !strcmp(buffer, "*") || !strcmp(buffer, "/"))
		return true;
	else
		return false;
}
void pole_note(my_queue<char*> &queue, my_stack<char*> stack, my_queue<char*> &result)
{
	char *buffer;
	buffer = new char[16];
	buffer[0] = '\0';
	while (queue.pop(buffer, 16))
	{
		if (is_operand(buffer))
		{
			result.push(buffer);
			buffer = new char[16];
			buffer[0] = '\0';
		}
		else if (is_func(buffer))
		{
			stack.push(buffer);
			buffer = new char[16];
			buffer[0] = '\0';
		}
		else if (is_operator(buffer))
		{
			if ((!strcmp(buffer, "+") || !strcmp(buffer, "-")) && (!strcmp((stack.show_last()), "+") || !strcmp((stack.show_last()), "-") || !strcmp((stack.show_last()), "*") || !strcmp((stack.show_last()), "/")))
			{
				while (((!strcmp(buffer, "+") || !strcmp(buffer, "-")) && ((!strcmp((stack.show_last()), "+") || !strcmp((stack.show_last()), "-") || !strcmp((stack.show_last()), "*") || !strcmp((stack.show_last()), "/")))) && (strcmp((stack.show_last()), "(")) && !stack.is_empty())
				{
					result.push(stack.pop());
				}
				stack.push(buffer);
				buffer = new char[16];
				buffer[0] = '\0';
			}
			else if ((!strcmp(buffer, "*") || !strcmp(buffer, "/")) /*&& (!strcmp((stack.show_last()), "*") || !strcmp((stack.show_last()), "/"))*/)
			{
				while ((!strcmp(buffer, "*") || !strcmp(buffer, "/")) && (!strcmp((stack.show_last()), "*") || !strcmp((stack.show_last()), "/")) && (strcmp((stack.show_last()), "(")) && !stack.is_empty())
				{
					result.push(stack.pop());
				}
				stack.push(buffer);
				buffer = new char[16];
				buffer[0] = '\0';
			}
			else
			{
				stack.push(buffer);
				buffer = new char[16];
				buffer[0] = '\0';
			}
		}
		else if (!strcmp(buffer, "("))
		{
			stack.push(buffer);
			buffer = new char[16];
			buffer[0] = '\0';
		}
		else if (!strcmp(buffer, ")"))
		{
			while (strcmp((stack.show_last()), "("))
			{
				result.push(stack.pop());
			}
			stack.pop();
			if (!stack.is_empty())
			{
				if (is_func(stack.show_last()))
				{
					result.push(stack.pop());
				}
			}
		}
	}
	delete[] buffer;
	while (!stack.is_empty())
	{

		result.push(stack.pop());
	}
}

double calculate(my_queue<char*> &pole)
{
  //my_queue<double> buf;
  my_stack<double> buf;
  char *pointer;
  double buffer;
  double second, first,result;
  while (pole.start != NULL)
  {
	  pointer = pole.pop();
	  if (is_operand(pointer))
	  {
		  buffer = atof(pointer);
		  buf.push(buffer);
	  }
	  else if (is_func(pointer))
	  {
		  if (!strcmp(pointer, "sin"))
		  {
			  first = buf.pop();
			  result = sin(first);
			  buf.push(result);
		  }
		  if (!strcmp(pointer, "cos"))
		  {
			  first = buf.pop();
			  result = cos(first);
			  buf.push(result);
		  }
		  if (!strcmp(pointer, "tg"))
		  {
			  first = buf.pop();
			  result = tan(first);
			  buf.push(result);
		  }
		  if (!strcmp(pointer, "ctg"))
		  {
			  first = buf.pop();
			  result = cos(first)/sin(first);
			  buf.push(result);
		  }
	  }
	  else if (is_operator(pointer))
	  {
		  if (!strcmp(pointer, "+"))
		  {
			  second = buf.pop();
			  first = buf.pop();
			  result = first + second;
			  buf.push(result);
		  }
		  if (!strcmp(pointer, "-"))
		  {
			  second = buf.pop();
			  first = buf.pop();
			  result = first - second;
			  buf.push(result);
		  }
		  if (!strcmp(pointer, "*"))
		  {
			  second = buf.pop();
			  first = buf.pop();
			  result = second * first;
			  buf.push(result);
		  }
		  if (!strcmp(pointer, "/"))
		  {
			  second = buf.pop();
			  first = buf.pop();
			  result = first / second;
			  buf.push(result);
		  }
	  }
  }

  return buf.pop();
}

