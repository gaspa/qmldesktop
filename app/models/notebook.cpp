#include "notebook.h"

Notebook::Notebook(QObject* parent)
    : QObject(parent)
    , _pages()
{
}

QString Notebook::title()
{
    return "Antani";
}

int Notebook::length()
{
    return _pages.length();
}

QList<QObject*> Notebook::pages()
{
    QList<QObject*> list;
    for (auto page : _pages) {
        list.append(page);
    }
    return list;
}

void Notebook::addPage()
{
    _pages.append(new Page(_pages.count(), this));
    emit pagesChanged();
}
