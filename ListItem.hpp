#pragma once

class ListItem
{
  private:
    ListItem *next = nullptr;
    unsigned long value;

  public:
    ListItem *Next();
    void SetNext(ListItem *li);
    unsigned long Value();
    ListItem(unsigned long _value) : value(_value) {};
};