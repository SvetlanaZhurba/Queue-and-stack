#pragma once
#include "list.h"

class queue : public list
{
private:
  node *end;

public:
  queue();
  queue( const queue & );
  ~queue();
  int pop();
  void show();
  void push( int n );
};
