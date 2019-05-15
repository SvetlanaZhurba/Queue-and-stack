#include <iostream>
#include <fstream>
#include "list.h"
#include "stack.h"

using namespace std;

stack::stack() 
{
  head = nullptr;
}

stack::stack( const stack &s )
{
  node *p1 = head;
  node *p2 = s.head;

  while( p2 != nullptr )
  {
    p1 = new node;
    p1->value = p2->value;
    if( p2->next != nullptr )
    {
      p1->next = new node;
      p1 = p1->next;
      p2 = p2->next;
    }
  }
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

int stack::pop()
{
  ofstream fp( "stack.txt", ios_base::out );
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

  if( ptr == nullptr )
    fp << "Стек пуст";
  else
  {
    fp << "Начало стека" << endl;

    while( ptr != nullptr )
    {
      fp << "-----" << ptr->value << "-----" << endl;
      ptr = ptr->next;
    }

    fp << "Конец стека" << endl << endl;
  }

  fp.close();
  show();
  return n;
}

void stack::push( int n )
{
  ofstream fp( "stack.txt", ios_base::out );
  node *ptr = new node;
  
  ptr->value = n;
  ptr->next = ( head != nullptr ) ? head : nullptr;
  head = ptr;

  fp << "Начало стека" << endl;

  while( ptr != nullptr )
  {
    fp << "-----" << ptr->value << "-----" << endl;
    ptr = ptr->next;
  }

  fp << "Конец стека" << endl << endl;

  fp.close();
  show();
}
