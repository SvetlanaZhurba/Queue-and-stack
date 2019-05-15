#pragma once
#include "list.h"

class stack : public list
{
private:
  node *head;

public:
  stack();
  stack( const stack &s );
  ~stack();
  int pop();
  void show();
  void push( int n );
};
