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

class queue
{
private:
    node *rear;
    node *front;

public:
    queue()
    {
        rear = NULL;
        front = NULL;
    }

    bool is_empty()
    {
        if (rear == NULL && front == NULL)
            return true;
        else
            return false;
    }

    void enqueue(int value)
    {
        if (is_empty())
        {
            node *new_node = new node;
            new_node->data = value;
            front = new_node;
            rear = new_node;
        }
        else
        {
            node *new_node = new node;
            new_node->data = value;
            rear->next = new_node;
            rear = new_node;
        }
    }

    void display()
    {
        node *temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int dequeue()
    {
        node *delptr = front;
        if (is_empty())
        {
            cout << "The queue is empty\n";
        }
        else if (rear == front)
        {
            int x = front->data;
            delete delptr;
            rear = front = NULL;
            return x;
        }

        else
        {
            int x = front->data;
            front = front->next;
            delete delptr;
            return x;
        }
    }
};

int main()
{
    queue li;
    int item, num;
    cout << "How element you want to push: ";
    cin >> item;
    for (int i = 1; i <= item; i++)
    {
        cout << "Enter the element nomber " << i << ": ";
        cin >> num;
        li.enqueue(num);
    }
    cout << "\nThe list befor delete: ";
    li.display();
    cout << "\nThe item was deleted is : " << li.dequeue() << endl;
    cout << "\nThe list after delete is: ";
    li.display();
    return 0;
}