#include "List.h"

template<class T>
List<T>::List()
{
  head = NULL;
  tail = NULL;
  _length = 0;
}

template<class T>
List<T>::List(T *arr)
{
  unsigned i = 0;
  head = NULL;
  tail = NULL;
  _length = 0;

  while((arr + i) != NULL)
  {
    List<T>::add(arr[i]);
    i++;
  }
}

template<class T>
List<T>::~List<T>()
{
  while(_length != 0)
    List<T>::remove();
}

template<class T>
List<T>& List<T>::operator=(const List<T> &someList)
{
  struct node *curr = someList.head;
  if(this == &someList)
    return *this;

  while(_length != 0)
    List<T>::remove();

  while(curr)
  {
    List<T>::add(curr->data);
    curr = curr->next;
  }

  return *this;
}

template<class T>
T& List<T>::operator[](unsigned pos)
{
    struct node *curr = head;
    unsigned i = 0;
    if(pos >= 0 && pos < _length)
    {
        while(curr != NULL && i < pos)
        {
            curr = curr->next;
            i++;
        }
    }
    return curr->data;
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