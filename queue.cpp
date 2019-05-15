#include <iostream>
#include <fstream>
#include "list.h"
#include "queue.h"

using namespace std;

queue::queue() 
{
  end = nullptr;  
}

queue::queue( const queue &q )
{
  node *p1 = end;
  node *p2 = q.end;

  while( p2 != nullptr )
  {
    p1 = new node;
    p1->value = p2->value;
    if( p2->prev != nullptr )
    {
      p1->prev = new node;
      p1 = p1->prev;
      p2 = p2->prev;
    }
  }
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

int queue::pop()
{
  ofstream fp( "queue.txt", ios_base::out );
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

  ptr = end;

  if( ptr == nullptr )
    fp << "Oчepeдь пycтa";
  else
  {
    fp << "Конец очереди" << endl;

    while( ptr != nullptr )
    {
      fp << "-----" << ptr->value << "-----" << endl;
      ptr = ptr->prev;
    }

    fp << "Начало очереди" << endl << endl;
  }

  fp.close();
  show();
  return n;
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

void queue::push( int n )
{
  ofstream fp( "queue.txt", ios_base::out );
  node *ptr = new node;

  ptr->value = n;
  ptr->prev = ( end != nullptr ) ? end : nullptr;
  end = ptr;

  fp << "Конец очереди" << endl;

  while( ptr != nullptr )
  {
    fp << "-----" << ptr->value << "-----" << endl;
    ptr = ptr->prev;
  }

  fp << "Начало очереди" << endl << endl;

  fp.close();
  show();
}
