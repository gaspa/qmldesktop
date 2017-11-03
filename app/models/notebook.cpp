#include "notebook.h"
#include "models/pair.h"
#include <QDate>

Notebook::Notebook(QObject* parent)
    : QObject(parent)
    , _title()
    , _pages()
{
}

QVariantMap Notebook::toMap()
{
    QVariantMap map;
    QVariantList pages;
    map.insert("title", title());
    for (auto page : _pages)
        pages.append(page->toMap());
    map.insert("pages", pages);
    return map;
}

Notebook* Notebook::fromMap(QVariantMap map, QObject* parent)
{
    Notebook* n = new Notebook(parent);
    n->setTitle(map.value("title").toString());
    for (auto page : map.value("pages").toList()) {
        Page* p = Page::fromMap(page.toMap(), n);
        n->addPage(p);
    }

    return n;
}

QString Notebook::title() const
{
    return _title;
}

void Notebook::setTitle(QString title)
{
    if (title != _title) {
        _title = title;
        emit titleChanged();
    }
}

int Notebook::length() const
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
    for (int i = 0; i < (_pages.length() + 1) / 2; i++) {
        // dont-like
        Pair* p = new Pair(_pages.at(i * 2),
            _pages.length() > i * 2 + 1 ? _pages.at(i * 2 + 1) : new Page(-1, true), this);
        list.append(p);
    }
    return list;
}

void Notebook::addPage()
{
    _pages.append(new Page(_pages.count(), false, this));
    emit lengthChanged();
    emit pagesChanged();
    emit pairsChanged();
}

void Notebook::addPage(Page* p)
{
    p->setParent(this);
    _pages.append(p);
    emit lengthChanged();
    emit pagesChanged();
    emit pairsChanged();
}
