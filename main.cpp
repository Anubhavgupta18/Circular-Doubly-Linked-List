#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;
class circular_doubly_linked_list
{
private:
    struct node
    {
        node *prev;
        int item;
        node *next;
    };
    node *start;
public:
    circular_doubly_linked_list();
    ~circular_doubly_linked_list();
    void insert_first(int);
    void insert_last(int);
    void insert_AfterElement(int,int);
    void delete_first();
    void delete_last();
    void delete_element(int);
    void viewListItems();
};
circular_doubly_linked_list::circular_doubly_linked_list()
{
    start=NULL;
}
circular_doubly_linked_list::~circular_doubly_linked_list()
{
    while(start)
    {
        delete_first();
    }
}
void circular_doubly_linked_list::insert_first(int data)
{
    node *n=new node;
    n->item=data;
    if(start==NULL)
    {
        start=n;
        n->prev=start;
        n->next=start;
    }
    else
    {
        n->next=start;
        n->prev=start->prev;
        start->prev->next=n;
        start->prev=n;
        start=n;
    }
}
void circular_doubly_linked_list::insert_last(int data)
{
    node *n=new node;
    n->item=data;
    if(start==NULL)
    {
        start=n;
        n->next=start;
        n->prev=start;
    }
    else
    {
        start->prev->next=n;
        n->next=start;
        n->prev=start->prev;
        start->prev=n;
    }
}
void circular_doubly_linked_list::viewListItems()
{
    node *temp=start;
    do
    {
        cout<<temp->item<<" ";
        temp=temp->next;
    }
    while(temp!=start);
}
void circular_doubly_linked_list::delete_first()
{
    if(start==NULL)
    {
        cout<<"OPERATION FAILED:UNDERFLOW!"<<endl;
    }
    else
    {
        if(start->next==start)
        {
            delete start;
            start=NULL;
        }
        else
        {
            node *temp=start;
            start->next->prev=start->prev;
            start->prev->next=start->next;
            start=start->next;
            delete temp;
        }
    }
}
void circular_doubly_linked_list::delete_last()
{
    if(start==NULL)
    {
        cout<<"OPERATION FAILED:UNDERFLOW!"<<endl;
    }
    else
    {
        if(start->next==start)
        {
            delete start;
            start=NULL;
        }
        else
        {
            node *temp=start->prev;
            start->prev->prev->next=start;
            start->prev=start->prev->prev;
            delete temp;
        }
    }
}
void circular_doubly_linked_list::insert_AfterElement(int element,int data)
{
    if(start==NULL)
    {
        cout<<"OPERATION FAILED:UNDERFLOW!"<<endl;
    }
    else
    {
        node *temp=start;
        do
        {
            if(temp->item==element)
            {
                break;
            }
            temp=temp->next;
        }
        while(temp!=start);
        if(temp==start)
        {
            if(temp->item==element)
            {
                node *n=new node;
                n->item=data;
                n->next=temp->next;
                n->prev=temp;
                temp->next->prev=n;
                temp->next=n;
            }
            else
            {
                cout<<"OPERATION FAILED:ELEMENT NOT FOUND!"<<endl;
            }
        }
        else
        {
            node *n=new node;
            n->item=data;
            n->next=temp->next;
            n->prev=temp;
            temp->next->prev=n;
            temp->next=n;
        }
    }
}
void circular_doubly_linked_list::delete_element(int element)
{
    if(start==NULL)
    {
        cout<<"OPERATION FAILED:UNDERFLOW!"<<endl;
    }
    else
    {
        node *temp=start;
        do
        {
            if(temp->item==element)
            {
                break;
            }
            temp=temp->next;
        }
        while(temp!=start);
        if(temp==start)
        {
            if(temp->item==element)
            {
                delete_first();
            }
            else
            {
                cout<<"OPERATION FAILED:ELEMENT NOT FOUND!"<<endl;
            }
        }
        else
        {
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                delete temp;
        }
    }
}
