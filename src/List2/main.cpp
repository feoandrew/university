#include<iostream>
#include"List.h"


int main()
{
	List List1;
	List List2;

	
	for (int i = 0; i < 10; i++)
	{
		ListElem* Elem = new ListElem;
		Elem->data = i;
		List1.push(Elem);
	}
	ListElem* Elem = new ListElem;
	Elem->data = 9;
	List1.push(Elem);

	
	List2 = List1;

	std::cout << List2.getTail()->data << std::endl;
	List2.popHead();
		std::cout << List1.getHead()->data << std::endl;
		std::cout << List2.getHead()->data << std::endl;
		
		

}