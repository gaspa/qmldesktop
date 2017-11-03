#include "pair.h"

Pair::Pair(Page* left, Page* right, QObject* parent)
    : QObject(parent)
{
    _left = left;
    _right = right;
    connect(_left, SIGNAL(pageChanged()), this, SIGNAL(leftChanged()));
    connect(_right, SIGNAL(pageChanged()), this, SIGNAL(rightChanged()));
}

Page* Pair::left()
{
    return _left;
}
Page* Pair::right()
{
    return _right;
}
