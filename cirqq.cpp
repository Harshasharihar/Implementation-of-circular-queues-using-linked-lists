#include<iostream>
using namespace std;
#define null 0

class cirq
{
	private : struct node
		{
			int data;
			struct node *next;
		}*front ,*rear;
	public	: cirq();
		  void write(int);
		  int read();
		  ~cirq();
		  
};
cirq :: cirq()
{
	front = null;
	rear = null;
	cout<<"Inside constructor\n";
}

void cirq :: write(int num)
{
	struct node *temp,*k;
	if(front == null)
	{
		temp = new struct node;
		if(temp == null)
		{
			cout<<"Node creation failed ..Sorry try again\n";
			exit(0);
		}
		
		front = temp;
		front -> data = num;
		front ->next = temp;
		rear = front;	
	}
	else
	{
		temp = front;
		while(temp != rear)
		{
			temp= temp->next;
		}
			k = new struct node;
			if(k == null)
			{
				cout<<"node creation failed..Sry try again\n";
				exit(0);
			}
			k->data = num;
			k->next = front;
			temp ->next = k;
			rear = k;
	}
}

int cirq::read()
{
	struct node *temp;
	temp = front;
	if(temp == null)
	{
		cout<<"No existance ofcircular Queue \n";
		return null;
	}
	else
	{
	int x = temp->data;
	if(front == rear)
	{
		front = null;
		rear == null;
	}
	else
	{
		front = front-> next;
		rear->next = front;
	}
	delete temp;
	return x;
}
}

cirq::~cirq()
{
	struct node *temp;
	while(front!=rear)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
	if(front == rear)
	{
		temp = front;
		delete temp;
		front = null;
		rear = null;
	}
}

int main()
{
	cirq q;
	int num = 0,choice = 0;
		while(1)
	{
		cout<<"Enter the choice\n";
		cout<<"1 to add to Queue\n";
		cout<<"2 to delete element from the Queue\n";
		cout<<"3 to Exit \n";
		cin>>choice;
		
		switch(choice)
		{
			case 1 : cout<<"Enter the number\n";
			cin>>num;
			q.write(num);
			break;
			
			case 2 : num = q.read();
			cout<<"The read value from q is "<<num<<endl;
			break;
			
			case 3 : cout<<"Exiting...\n";
			exit(0);
			
			default :cout<<"Invalid input...Try again..!\n";
			break;
		}
	}
	
}
