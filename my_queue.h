#ifndef MY_QUEUE
#define MY_QUEUE

using namespace std;

template <class type,bool del=false> class my_queue
{
	my_queue *start;
	my_queue *end;
	my_queue *next;
	type data;
public:
	my_queue()
	{
		start = end = next = NULL;
	}
	my_queue(type var)
	{
		start = new my_queue;
		end = start;
		start->data = var;
		next = NULL;
	}
	~my_queue()
	{
		clear();
	}
	void push(type var)
	{
		if (start == NULL)
		{
			start = new my_queue;
			end = start;
			start->data = var;
			next = NULL;
		}
		else
		{
			next = end;
			end = new my_queue;
			next->next = end;
			end->data = var;
			end->next = NULL;
		}
	}
	/*
	void push(type &var)
	{
		if (start == NULL)
		{
			start = new my_queue;
			end = start;
			start->data = var;
			next = NULL;
		}
		else
		{
			next = end;
			end = new my_queue;
			next->next = end;
			end->data = var;
			end->next = NULL;
		}
	}
	*/
	type pop()
	{
		if (start)
		{
			type temp = start->data;
			next = start->next;
			delete start;
			start = next;
			return temp;
		}
		else
		{
			return NULL;
		}
	}
	bool pop(type &var)
	{
		if (start)
		{
			var = start->data;
			next = start->next;
			delete start;
			start = next;
			return true;
		}
		else
		{
			return false;
		}
	}
	void clear()
	{
		while (start != NULL)
		{
			next = start->next;
			delete start;
			start = next;
		}
	}
	bool is_empty()
	{
		if (start == NULL)
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
		if (start)
		{
			while (start != NULL)
			{
				type temp = start->data;
				next = start->next;
				delete start;
				start = next;
				cout << temp << '\n';
			}
		}
		else
		{
			cout<< "NULL\n";
		}
	}
};

template <> class my_queue<char*>
{
	
	char *data;
	char *bufer;
public:
	my_queue *start;
	my_queue *end;
	my_queue *next;


	my_queue()
	{
		start = end = next = NULL;
	}
	my_queue(char *var)
	{
		start = new my_queue;
		end = start;
		start->data = var;
		next = NULL;
	}
	~my_queue()
	{
		clear();
	}
	void push(char *var)
	{
		if (start == NULL)
		{
			start = new my_queue;
			end = start;
			start->data = var;
			next = NULL;
		}
		else
		{
			next = end;
			end = new my_queue;
			next->next = end;
			end->data = var;
			end->next = NULL;
		}
	}
	/*
	void push(type &var)
	{
	if (start == NULL)
	{
	start = new my_queue;
	end = start;
	start->data = var;
	next = NULL;
	}
	else
	{
	next = end;
	end = new my_queue;
	next->next = end;
	end->data = var;
	end->next = NULL;
	}
	}
	*/
	char *pop()
	{
		if (start)
		{
			char *temp = start->data;
			next = start->next;
			delete start;
			start = next;
			bufer = new char[16];
			strcpy_s(bufer, 16, temp);
			//delete[] temp;
			return bufer;
		}
		else
		{
			return NULL;
		}
	}
	bool pop(char *var,int length)
	{
		if (start)
		{
			strcpy_s(var,length,start->data);
			next = start->next;
//			delete[] start->data;
			delete start;
			start = next;
			return true;
		}
		else
		{
			return false;
		}
	}
	void clear()
	{
		while (start != NULL)
		{
			char *temp = start->data;
			delete[] temp;
			next = start->next;
			delete start;
			start = next;
		}
	}
	bool is_empty()
	{
		if (start == NULL)
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
		if (start)
		{
			while (start != NULL)
			{
				char *temp = start->data;
				next = start->next;
				delete start;
				start = next;
				bufer = new char[16];
				strcpy_s(bufer, 16, temp);
				//delete[] temp;
				cout << bufer << '\n';
			}
		}
		else
		{
			cout << "NULL\n";
		}
	}
};

#endif