#ifndef PAIR_H
#define PAIR_H

#include <QObject>

#include "models/page.h"

class Pair : public QObject {
    Q_OBJECT
public:
    explicit Pair(Page* left, Page* right, QObject* parent = nullptr);

    Q_PROPERTY(Page* left READ left NOTIFY leftChanged)
    Q_PROPERTY(Page* right READ right NOTIFY rightChanged)

    Page* left();
    Page* right();

signals:
    void leftChanged();
    void rightChanged();

private:
    Page* _left;
    Page* _right;
};

#endif // PAIR_H
