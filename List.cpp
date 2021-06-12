#include "List.hpp"
#include "ListItem.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

/**
 * 
 */

void List::Add(ListItem *li)
{
  if (this->first == nullptr)
  {
    this->first = li;
    this->last = li;
  }
  else
  {
    this->last->SetNext(li);
    this->last = li;
  }

  ++count;
}

/**
 * 
 */
unsigned long List::Count()
{
  return count;
}

/**
 * 
 */
ListItem *List::Get(unsigned long index)
{
  if (index >= this->count)
  {
    throw invalid_argument("Valeur hors de la liste");
  }

  ListItem *li;

  for (unsigned long i = 0; i <= index; ++i)
  {
    if (i == 0)
    {
      li = this->first;
    }
    else
    {
      li = li->Next();
    }
  }

  return li;
}

/**
 * 
 */
void List::Remove(unsigned long index)
{
  if (index >= this->count)
  {
    throw invalid_argument("Valeur hors de la liste");
  }

  if (this->count == 1)
  {
    this->first = nullptr;
    this->last = nullptr;
  }
  else if (index == 0)
  {
    this->first = this->first->Next();
  }
  else
  {
    ListItem *li = this->Get(index - 1);
    li->SetNext(li->Next()->Next());
  }

  --this->count;
}

/**
 * 
 */
bool List::IsSorted()
{
  if (count < 2)
  {
    return true;
  }

  bool sorted = true;

  ListItem *li = this->first;
  ListItem *next = this->first->Next();

  while (next != nullptr)
  {
    if (li->Value() > next->Value())
    {
      sorted = false;
      break;
    }
    li = next;
    next = li->Next();
  }

  return sorted;
}

/**
 * 
 */
void List::Show()
{
  if (count == 0)
  {
    return;
  }

  ListItem *li = first;

  cout << li->Value();

  while (li->Next() != nullptr)
  {
    li = li->Next();
    cout << " < " << li->Value();
  }

  cout << endl;
}