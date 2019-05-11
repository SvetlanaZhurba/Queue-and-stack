#include <iostream>
#include "list.h"

using namespace std;

int main()
{
  setlocale( LC_ALL, "rus" );

  int c1, c2, elem;

  list *s = new stack;
  list *q = new queue;

  do
  {
    system( "cls" );
    cout << "1. Стек\n2. Очередь\n0. Выход\nВаш выбор: ";
    cin >> c1;
    cin.ignore( 1, '\n' );

    if( c1 == 0 )
      break;

    system( "cls" );
    cout << "1. Добавить элемент\n2. Извлечь элемент\n3. Вывести на экран\n0. Выход\nВаш выбор: ";
    cin >> c2;
    cin.ignore( 1, '\n' );

    if( c2 == 1 )
    {
      cout << endl << "Введите значение: ";
      cin >> elem;
      cin.ignore( 1, '\n' );

      ( c1 == 1 ) ? s->push( elem ) : q->push( elem );
    }
    else if( c2 == 2 )
      ( c1 == 1 ) ? s->pop() : q->pop();
    else if( c2 == 3 )
      ( c1 == 1 ) ? s->show() : q->show();

  } while ( c2 != 0 );

  return 0;
}
