#include<stdio.h>
#include<conio.h>
#include<iostream.h>

using namespace std;

typedef int E;
class Node 
{
    public:
      E element;            
      Node *next;           
      Node(const E& elemval, Node* nextval =NULL)
	  {
        element = elemval;  next = nextval;
      }
      Node(Node* nextval = NULL) 
	  { 
	  	next = nextval; 
	  }
};

class Queue : private LinkedList{

    public:
        Queue( int size =0);
        ~Queue(){};
        bool empty();
        E & front() ;
        E & back() ;
        int size() ;
        void insert( const E & thisElement);
        E remove();
        void display();
        void clearAll();

};

void Queue::insert(int t)
{
	n = new Node(t);
}
int Queue::remove()
{
	
}
int main()
{
   Queue q;
   q.insert(2);
   q.insert(3);
   q.insert(4);
   q.insert(21);
   q.insert(34);
   q.insert(9);
   q.display();

   cout<<" Element " << q.remove() <<" is removed"<<endl;
   cout<<" Element " << q.remove() <<" is removed"<<endl;
   q.display();
   
   return 0;
}

