//Add an element before a specific element
//Add elelemnt to the end of the list
//add function delete 
#include <iostream>
using namespace std;
class node
{
public:
    node *next;
    int data;
};

class linked_list
{
    node *head;

public:
    linked_list() { head = NULL; }
    bool is_empty()
    {
        return (head == NULL);
    }
    void inert_first(int value)
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
        if (is_empty())
            cout << "The linked list is empty " << endl;
        else
        {
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
    }
    int count()
    {
        int counter = 0;
        node *temp = head;
        if (is_empty())
            cout << "The linked list is empty " << endl;
        else
        {
            while (temp != NULL)
            {
                counter++;
                temp = temp->next;
            }
        }
        return counter;
    }
    void insert_befor(int item, int value)
    {
        if (is_empty())
            inert_first(value);
        else
        {
            node *temp = head;

            while (temp != NULL && temp->next->data != item)
            {
                temp = temp->next;
            }
            node *new_node = new node;
            new_node->data = value;
            new_node->next = temp->next;
            temp->next = new_node;
        }
    }
    void append(int value)
    {
        node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        node *new_node = new node;
        new_node->data = value;
        new_node->next = NULL;
        temp->next = new_node;
    }
    void Delete(int item)
    {
        if (is_empty())
            cout << "The list is empty \n";
        node *delptr = head;
        if (head->data == item)
        {
            head = head->next;
            delete delptr;
        }
        else
        {
            node *delptr = head;
            node *prev = NULL;
            while (delptr->data != item)
            {
                prev = delptr;
                delptr = delptr->next;
            }
            prev->next = delptr->next;
            delete delptr;
        }
    }
};
int main()
{
    linked_list li;
    int number, value;
    li.display();
    // cout << "Enter the number want to first: ";
    // cin >> number;
    /*for (int i = 1; i <= number; i++)
    {
        cout << "Enter the value num: " << i << ": ";
        cin >> value;
        li.inert_first(value);
    }*/
    // li.display();
    // cout << "\nThe number in the list: " << li.count() << endl;
    li.insert_befor(20, 80);
    li.append(90);
    li.display();
    li.Delete(20);
    li.display();
    cout << "\nThe number in the list: " << li.count() << endl;
    return 0;
}
