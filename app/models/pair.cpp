#include "pair.h"

Pair::Pair(Page* left, Page* right, QObject* parent)
    : QObject(parent)
{
    _left = left;
    _right = right;
}

Page* Pair::left()
{
    return _left;
}
Page* Pair::right()
{
    return _right;
}
