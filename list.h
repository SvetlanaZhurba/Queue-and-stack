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

class stack : public list
{
private:
  node *head;

public:
  stack();
  ~stack();
  int pop();
  void show();
  void push( int n );
};

class queue : public list
{
private:
  node *end;

public:
  queue();
  ~queue();
  int pop();
  void show();
  void push( int n );
};
