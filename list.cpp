#include <iostream>
#include "list.h"

using namespace std;


list::~list() {}

int list::pop() { return 0; }

void list::show() {}

void list::push( int n ) {}

stack::stack() 
{
  head = nullptr;
}

stack::~stack() 
{
  node *ptr;

  while( (ptr = head) != nullptr )
  {
    ptr = ptr->next;
    delete head;
    head = nullptr;
    head = ptr;
  }
}

queue::queue() 
{
  end = nullptr;  
}

queue::~queue() 
{
  node *ptr;

  while( (ptr = end) != nullptr )
  {
    ptr = ptr->prev;
    delete end;
    end = nullptr;
    end = ptr;
  }
}

int stack::pop()
{
  setlocale( LC_ALL, "rus" );
  int n = -1;
  node *ptr = head;

  if( ptr != nullptr )
  {
    n = ptr->value;
    cout << endl << "Извлечено: " << n << endl;
    ptr = ptr->next;
    delete head;
    head = nullptr;
    head = ptr;
  }

  show();
  return n;
}

int queue::pop()
{
  setlocale( LC_ALL, "rus" );
  int n = -1;
  node *ptr = end;

  while( ptr != nullptr && ptr->prev != nullptr && ptr->prev->prev != nullptr ) // Предпоследний элемент
    ptr = ptr->prev;

  if( ptr->prev == nullptr )
  {
    n = ptr->value;
    cout << endl << "Извлечено: " << n << endl;
    delete end;
    end = nullptr;
  }
  else if( ptr->prev->prev == nullptr )
  {
    n = ptr->prev->value;
    cout << endl << "Извлечено: " << n << endl;
    delete ptr->prev;
    ptr->prev = nullptr;
  }

  show();
  return n;
}

void stack::show()
{
  setlocale( LC_ALL, "rus" );
  node *ptr = head;

  if( ptr == nullptr )
  {
    cout << endl << "Стек пуст";
    getchar();
    return;
  }

  cout << endl << "Начало стека" << endl;

  while( ptr != nullptr )
  {
    cout << "-----" << ptr->value << "-----" << endl;
    ptr = ptr->next;
  }

  cout << "Конец стека" << endl << endl;
  getchar();
}

void queue::show()
{
  setlocale( LC_ALL, "rus" );
  node *ptr = end;

  if( ptr == nullptr )
  {
    cout << endl << "Oчepeдь пycтa";
    getchar();
    return;
  }

  cout << endl << "Конец очереди" << endl;

  while( ptr != nullptr )
  {
    cout << "-----" << ptr->value << "-----" << endl;
    ptr = ptr->prev;
  }

  cout << "Начало очереди" << endl << endl;
  getchar();
}

void stack::push( int n )
{
  node *ptr = new node;
  
  ptr->value = n;
  ptr->next = ( head != nullptr ) ? head : nullptr;
  head = ptr;

  show();
}

void queue::push( int n )
{
  node *ptr = new node;

  ptr->value = n;
  ptr->prev = ( end != nullptr ) ? end : nullptr;
  end = ptr;

  show();
}
