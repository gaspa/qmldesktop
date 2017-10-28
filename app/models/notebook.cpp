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
    return 0;
}

QList<Page*> Notebook::pages()
{
    return _pages;
}

void Notebook::addPage()
{
    _pages.append(new Page(_pages.count(), this));
    emit pagesChanged();
}
