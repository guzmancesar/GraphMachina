#ifndef STACK_H
#define STACK_H 


#include <iostream>
#include <vector>
#include <fstream>
#include <chrono> 

using namespace std;

//struct that holds the data of the stack
/*
struct node
{
	int data;
	node* next;
}
*/

class node
{
	//find what a destructor does again lol
	private:
		bool empty;
		int data;
		node * next;
		node * prev; 
	public:
		node();
		node(int a);
		~node();
		void print();
		int getdata();
		void setdata(int newda);
		void setnext(node * nextp);
		void setprev(node * prevp);
		node * getnext();
		node * getprev();

};

class stack
{
	private:
		int size = 0;
		bool empty;
		node * head;
		node * tail;
	public:
		stack();
		stack(node alf );
		~stack();
		int pop();
		void push(node a);
		void print();
		void printsize();
		int getsize();
		 
};



#endif
