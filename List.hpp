#pragma once
#include "ListItem.hpp"

class List
{
  private:
    // Longueur de la liste.
    unsigned long count = 0;
    // Premier élément de la liste
    ListItem *first = nullptr;
    // Dernier élément de la liste
    ListItem *last = nullptr;

  public:
    void Add(ListItem *li);
    unsigned long Count();
    ListItem *Get(unsigned long index = 0);
    void Remove(unsigned long index);
    bool IsSorted();
    void Show();
};