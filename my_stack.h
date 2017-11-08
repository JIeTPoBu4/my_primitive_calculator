#ifndef MY_STACK
#define MY_STACK

using namespace std;

template <class type> class my_stack
{
	type data;
	my_stack *bottom;
	my_stack *top;
public:
	my_stack()
	{
		data = NULL;
		bottom = NULL;
		top = NULL;
	}
	my_stack(type var)
	{
		top = new my_stack;
		top->data = var;
		top->bottom = NULL;
		bottom = NULL;
	}
	void clear()
	{
		while (top != NULL)
		{
			bottom = top->bottom;
			delete top;
			top = bottom;
		}

	}
	~my_stack()
	{
		clear();
	}
	void push(type var)
	{
		if (top == NULL)
		{
			top = new my_stack;
			top->data = var;
			top->bottom = NULL;
		}
		else
		{
			bottom = top;
			top = new my_stack;
			top->data = var;
			top->bottom = bottom;
		}
	}
	type pop()
	{
		if (top == NULL)
		{
			return NULL;
		}
		else
		{
			type temp = top->data;
			bottom = top->bottom;
			delete top;
			top = bottom;
			return temp;
		}
	}
	bool pop(type &var)
	{
		if (top == NULL)
		{
			return FALSE;
		}
		else
		{
			type temp = top->data;
			bottom = top->bottom;
			delete top;
			top = bottom;
			var = temp;
			return TRUE;
		}
	}
	bool is_empty()
	{
		if (top == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void show_all()
	{
		if (top == NULL)
		{
			cout<<"NULL"<<'\n';
		}
		else
		{
			while (top != NULL)
			{
				type temp = top->data;
				bottom = top->bottom;
				delete top;
				top = bottom;
				cout << temp<<'\n';
			}
		}
	}
};

template <> class my_stack<char*>
{
	char *data;
	my_stack *bottom;
	my_stack *top;
	char *bufer;
public:
	my_stack()
	{
		data = NULL;
		bottom = NULL;
		top = NULL;
	}
	my_stack(char *var)
	{
		top = new my_stack;
		top->data = var;
		top->bottom = NULL;
		bottom = NULL;
	}
	void clear()
	{
		while (top != NULL)
		{
			char *temp = top->data;
			delete[] temp;
			bottom = top->bottom;
			delete top;
			top = bottom;
		}

	}
	~my_stack()
	{
		clear();
	}
	void push(char *var)
	{
		if (top == NULL)
		{
			top = new my_stack;
			top->data = var;
			top->bottom = NULL;
		}
		else
		{
			bottom = top;
			top = new my_stack;
			top->data = var;
			top->bottom = bottom;
		}
	}
	char *pop()
	{
		if (top == NULL)
		{
			return NULL;
		}
		else
		{
			char *temp = top->data;
			bottom = top->bottom;
			delete top;
			top = bottom;
			bufer = new char[16];
			strcpy_s(bufer, 16, temp);
			delete[] temp;
			return bufer;
		}
	}
	bool pop(char *var)
	{
		if (top == NULL)
		{
			return false;
		}
		else
		{
			char *temp = top->data;
			bottom = top->bottom;
			delete top;
			top = bottom;
			var = temp;
			return true;
		}
	}
	bool is_empty()
	{
		if (top == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void show_all()
	{
		if (top == NULL)
		{
			cout << "NULL" << '\n';
		}
		else
		{
			while (top != NULL)
			{
				char *temp = top->data;
				bottom = top->bottom;
				delete top;
				top = bottom;
				strcpy_s(bufer, 16, temp);
				delete[] temp;
				cout<<bufer<<'\n';
			}
		}
	}
	char *show_last()
	{
		if (top != NULL)
		{
			return (top->data);
		}
		else
		{
			return "";
		}
	}
};

#endif
