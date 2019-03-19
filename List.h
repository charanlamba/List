#ifndef LIST_H
#define LIST_H

#include <iostream>

using namespace std;

template <class T>
class List
{
  private:
    struct node
    {
      T data;
      node *prev;
      node *next;
    };
    node *head;
    node *tail;
    unsigned _length;

  public:
    List();

    List& operator=(const List&);

    void add(int item);
    void remove();

    void display();

    unsigned length() const;
};
#endif //LIST_H

template<class T>
List<T>::List()
{
  head = NULL;
  tail = NULL;
  _length = 0;
}

template<class T>
List<T>& List<T>::operator=(const List &someList)
{
  struct node *curr = someList.head;
  struct node *thisHead = head;
  if(this == &someList)
    return *this;

  while(thisHead != NULL)
  {
    remove();
    thisHead = thisHead->next;
  }

  while(curr)
  {
    add(curr->data);
    curr = curr->next;
  }

  return *this;
}

template<class T>
void List<T>::add(int item)
{
  struct node *newNode = new node;
  newNode->data = item;
  newNode->next = NULL;
  if(!head)
  {
    newNode->prev = NULL;
    tail = newNode;
    head = newNode;
  }
  else
  {
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
  }
  _length++;
}

template<class T>
void List<T>::remove()
{
  struct node *temp;
  if(tail)
  {
    temp = tail;
    tail = tail->prev;
    delete tail;
    if(!tail)
      head = NULL;
    _length--;
  }
}

template<class T>
void List<T>::display()
{
  struct node *curr = head;
  while(curr)
  {
    cout << curr->data << " ";
    curr = curr->next;
  }
  cout << endl;
}

template<class T>
unsigned List<T>::length() const
{
  return _length;
}
