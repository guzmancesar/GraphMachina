#include "stack.h"

/*push and set next broken*/

using namespace std;



//NODE FUNCTIONS 
node::node()
{
	data = 0;
}

node::~node()
{

}


node::node(int a)
{
	//cout << "creating node with value "<< a << endl;
	data = a;
}

void node::print()
{
	cout << "printing node: "<< data << endl; 
}

int node::getdata()
{
	return data;
}

void node::setdata(int newda)
{
	//cout << "setting data node to " << endl;
	data = newda;
}

void node::setnext(node * nextp)
{
	next = nextp;
}

void node::setprev(node * prevp)
{
	prev = prevp;
}

node * node::getnext()
{
	return next;
}

node * node::getprev()
{
	return prev;
}

//END NODE FUNCTIONS 

stack::stack()
{
	size = 0;
	head = NULL;
	tail = NULL;
}

stack::stack(node alf)
{
	//cout << "creating stack" << endl;
	node * p = new node;
	p -> setdata(alf.getdata());
	//p -> print();
	
	head = p;
	tail = p;
	
	size = 1;
}

stack::~stack()
{}

void stack::push(node a)
{
	//case stack is empty
	if (size == 0)
	{
		node * p = new node;
		p->setdata(a.getdata());
		p->setprev(NULL);
		p->setnext(NULL);
		
		head = p;
		tail = p;
		p = NULL;
		delete p;
		size++;
		//node is created and ready here
	}
	else 
	{
		node * p = new node;
		p->setdata(a.getdata());
		p->setprev(tail);
		p->setnext(NULL);
		
		tail->setnext(p);
		tail = p;
		p = NULL;
		delete p;
		size++;
		
	}
}

void stack::print()
{
	cout << "printing stack" << endl;
	node * temp = head;
	
	while(temp != NULL)
	{
		temp -> print();
		temp = temp -> getnext();
	}
}

int stack::pop()
{
	if (size != 0)
	{
		
	//	tail -> print();
	//	cout << "calling pop" << endl;
		node * temp(tail);
		if (size > 1)
		{
			tail = tail -> getprev();
			tail -> setnext(NULL);
			temp -> setprev(NULL);
		}
		else
		{
			head = NULL;
			tail = NULL;
		}
		
		size--;
		int retint = temp -> getdata();
		temp = NULL;
		delete temp;
		return retint;
	}
	else 
	{
		
		return 0;
	}
	
}

int stack::getsize()
{
	return size;
}




