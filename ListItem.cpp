#include "ListItem.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

ListItem *ListItem::Next()
{
  return this->next;
}

void ListItem::SetNext(ListItem *li)
{
  next = li;
}

unsigned long ListItem::Value()
{
  return value;
}
