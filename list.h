#pragma once

#include "node.h"

class list
{
public:
  virtual ~list();
  virtual int pop();
  virtual void show();
  virtual void push( int n );
};
