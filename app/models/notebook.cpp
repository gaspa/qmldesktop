#include "notebook.h"
#include "models/pair.h"
#include <QDate>
#include <QDebug>

Notebook::Notebook(QObject* parent)
    : QObject(parent)
    , _x(0)
    , _y(0)
    , _title()
    , _pages()
    , _background()
{
}

QVariantMap Notebook::toMap()
{
    QVariantMap map;
    QVariantList pages;
    map.insert("x", _x);
    map.insert("y", _y);
    map.insert("title", title());
    for (auto page : _pages)
        if (!page->empty())
            pages.append(page->toMap());
    map.insert("pages", pages);
    map.insert("background", _background);
    return map;
}

Notebook* Notebook::fromMap(QVariantMap map, QObject* parent)
{
    Notebook* n = new Notebook(parent);
    n->_x = map.value("x", 0).toInt();
    n->_y = map.value("y", 0).toInt();
    n->setTitle(map.value("title").toString());
    n->_background = map.value("background").toString();
    for (auto page : map.value("pages").toList()) {
        Page* p = Page::fromMap(page.toMap(), n);
        n->addPage(p);
    }

    return n;
}

int Notebook::x() const
{
    return _x;
}

void Notebook::setX(int x)
{
    if (_x != x) {
        _x = x;
        emit positionChanged();
    }
}

int Notebook::y() const
{
    return _y;
}

void Notebook::setY(int y)
{
    if (_y != y) {
        _y = y;
        emit positionChanged();
    }
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

QString Notebook::background() const
{
    return _background;
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
        qDebug() << _pages;
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
    connect(p, SIGNAL(bodyChanged()), this, SIGNAL(pagesChanged()));
    connect(p, SIGNAL(titleChanged()), this, SIGNAL(pagesChanged()));
    _pages.append(p);
    emit lengthChanged();
    emit pagesChanged();
    emit pairsChanged();
}
