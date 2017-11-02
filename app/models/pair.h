#ifndef PAIR_H
#define PAIR_H

#include <QObject>

#include "models/page.h"

class Pair : public QObject {
    Q_OBJECT
public:
    explicit Pair(Page* left, Page* right, QObject* parent = nullptr);

    Q_PROPERTY(Page* left READ left)
    Q_PROPERTY(Page* right READ right)

    Page* left();
    Page* right();

private:
    Page* _left;
    Page* _right;
};

#endif // PAIR_H
