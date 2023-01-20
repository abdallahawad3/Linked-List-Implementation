#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node()
    {
        data = 0;
        next = NULL;
    }
};

class stack
{
    node *top;

public:
    stack()
    {
        top = NULL;
    }
    bool is_empty()
    {
        if (top == NULL)
            return true;
        else
            return false;
    }

    void push(int value)
    {
        if (is_empty())
        {
            node *new_node = new node;
            new_node->data = value;
            new_node->next = NULL;
            top = new_node;
        }
        else
        {
            node *new_node = new node;
            new_node->data = value;
            new_node->next = top;
            top = new_node;
        }
    }

    int pop()
    {
        node *delptr = top;
        if (is_empty())
            cout << "The stack is empty \n";
        else
        {
            top = top->next;
            return top->data;
            delete delptr;
        }
    }

    void display()
    {
        node *temp = top;
        if (is_empty())
            cout << "The stack is empty " << endl;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    int peek()
    {
        return (top->data);
    }
};
int main()
{
    stack list;
    int item, num;
    cout << "How element you want to push: ";
    cin >> item;
    for (int i = 1; i <= item; i++)
    {
        cout << "Enter the element nomber " << i << ": ";
        cin >> num;
        list.push(num);
    }
    cout << "The element befor pop: " << endl;
    list.display();
    cout << "Peek befor the pop: " << list.peek() << endl;
    list.pop(); // dlelte the top element
    cout << "Peek after the pop: " << list.peek() << endl;
    cout << "The list after one pop: " << endl;
    list.display();
    return 0;
}