#include <iostream>
using namespace std;
//Creat node to use in linked list(linked list it consists of a group of nodes)
class node
{
public:
    int data;
    node *next;
};

class linked_list
{
public:
    node *head;
    linked_list()
    {
        head = NULL;
    }
    bool is_empty()
    {
        return (head == NULL);
    }
    void insert(int value)
    {
        if (is_empty())
        {
            node *new_node = new node;
            new_node->data = value;
            new_node->next = NULL;
            head = new_node;
        }
        else
        {
            node *new_node = new node;
            new_node->data = value;
            new_node->next = head;
            head = new_node;
        }
    }
    void display()
    {
        node *temp = head;
        while (head != NULL)
        {
        	
            cout<< temp->data << " ";
            temp = temp->next;
        }
    }
    int count()
    {
        node *temp = head;
        int counter = 0;
        while (temp != NULL)
        {
            counter++;
            temp = temp->next;
        }
        return counter;
        cout << endl;
    }
};
int main()
{
	int number,value;
    linked_list list;
    cout<<"Enter the numnber you want to insert in the linked list: ";
    cin>>number;
    for(int i=0;i<number;i++)
    {
    	cout<<"Enter the value of the item number "<<i+1<<": ";
    	cin>>value;
    	list.insert(value);
    		
	}
    cout << "The number of elements in the array: " << list.count() << endl;
    cout<<"\n The items already on The linked list: ";
    list.display();

    return 0;
}
