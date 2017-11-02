#include "notebook.h"
#include "models/pair.h"
#include <QDate>

Notebook::Notebook(QObject* parent)
    : QObject(parent)
    , _pages()
{
    Page* p = new Page(0, this);
    p->setTitle("Asdasdfasdf");
    p->setDate(QDate::currentDate());
    p->setBody("lkjjljkjlj\nklkjlkj");
    _pages.append(p);
    emit pagesChanged();
    p = new Page(1, this);
    p->setTitle("pagina 2");
    p->setDate(QDate::currentDate());
    p->setBody("testo di pagina 2");
    _pages.append(p);
    emit pagesChanged();
}

QString Notebook::title()
{
    return "Memories";
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

QList<QObject*> Notebook::pairs()
{
    QList<QObject*> list;
    for (int i = 0; i < _pages.length() / 2; i++) {
        Pair* p = new Pair(_pages.at(i * 2), _pages.at(i * 2 + 1), this);
        list.append(p);
    }
    return list;
}

void Notebook::addPage()
{
    _pages.append(new Page(_pages.count(), this));
    emit pagesChanged();
}
