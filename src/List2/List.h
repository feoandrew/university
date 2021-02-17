class ListElem 
{
public:
	int data;
	ListElem* next;
	ListElem* prev;
	ListElem(int data = 0) :data(data) 
	{
		next = nullptr;
		prev = nullptr;
	}
	
};
class List 
{
	ListElem* head;
	ListElem* tail;
public:
	List()//конструктор
	{
		head = nullptr;
		tail = nullptr;
	}
	~List()//деструктор 
	{
		while (head != nullptr) 
		{
			ListElem* curr = head->next;
			delete head;
			head = curr;
		}
	}
	void pushHead(ListElem* elem)//добаление элемента в начало списка  
	{
		if (head != nullptr)
		{
			elem->next = head;
			head->prev = elem;
			head = elem;
		}
		else
		{
			head = elem;
			tail = head;
		}
	}
	void push(ListElem* elem)//добаление элемента в конец списка 
	{
		if (tail != nullptr)
		{
			elem->prev = tail;
			tail->next = elem;
			tail = elem;
		}
		else
		{
			head = elem;
			tail = head;
		}
	}
	void popHead()//удаление первого элемента списка
	{
		if (head != nullptr)
		{
			ListElem* curr = head->next;
			delete head;
			head = curr;
			head->prev = nullptr;
		}
	}
	void pop() //удаление последнего элемента списка
	{
		if (head != nullptr)
		{
			ListElem* temp = tail->prev;
			delete tail;
			tail = temp;
			tail->next = nullptr;
		}
	}
	ListElem* getHead()
	{
		
		return head;
	}
	ListElem* getTail()
	{
		
		return tail;
	}
	int getSize()//получение размера 
	{
		if (head == nullptr)
			return 0;
		int size = 1;
		ListElem* curr = head;
		while (curr != nullptr) 
		{
			curr = curr->next;
			size++;
		}
		return size;
	}
	void remove(int data)//удаленте элементов равных заданному
	{
		if (head != nullptr)
		{
			ListElem* curr = head;
			ListElem* temp = new ListElem;
			while (curr->next != nullptr)
			{
				if (curr->data == data)
				{
					if (curr->prev != nullptr)
					{


						temp = curr->prev;
						temp->next = curr->next;
						temp = curr->next;
						temp->prev = curr->prev;
						delete curr;
						curr = temp->prev;
					}
					else
					{
						
						
							this->popHead();
							curr = head;
						
						
					}
				}
				curr = curr->next;
			}
			if (curr->data == data)
			{
				this->pop();
			}
			
		}
	}
	List(const List& list)//конструктор копирования
	{
		head = nullptr;
		tail = nullptr;
		ListElem* curr = list.head;
		
		while (curr != nullptr) 
		{
			ListElem* copy = new ListElem;
			copy->data = curr->data;
			this->push(copy);
			curr = curr->next;
		}
	}

	List&  operator=(const List& list)//копирующий оператор присваивания
	{
		if (&list == this)
			return *this;
		List lst;
		
		ListElem* curr = list.head;
		while (curr != nullptr) 
		{
			ListElem* copy = new ListElem;
			copy->data = curr->data;
			this->push(copy);
			curr = curr->next;
		}
		return *this;
	}

};