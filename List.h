#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <iterator>

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
    List(T *arr);

    ~List();

    List& operator=(const List&);
    T& operator[](const List&);

    void add(int item);
    void remove();

    void display();

    unsigned length() const;
};
#endif //LIST_H