#include "page.h"

Page::Page(int pagenumber, bool empty, QObject* parent)
    : QObject(parent)
    , _empty(empty)
{
    _pagenumber = pagenumber;
    setDate(QDate::currentDate());
}

Page::operator QString() const
{
    return QString("page: %1 empty: %2").arg(_pagenumber, _empty);
}

bool Page::empty() const
{
    return _empty;
}

QVariantMap Page::toMap() const
{
    QVariantMap map;
    map.insert("pagenumber", _pagenumber);
    map.insert("title", _title);
    map.insert("body", _body);
    map.insert("date", _date);
    return map;
}

Page* Page::fromMap(QVariantMap map, QObject* parent)
{
    Page* p = new Page(map.value("pagenumber").toInt(), parent);
    p->setTitle(map.value("title").toString());
    p->setBody(map.value("body").toString());
    p->setDate(map.value("date").toDate());
    return p;
}

int Page::pagenumber()
{
    return _pagenumber;
}

QString Page::title()
{
    return _title;
}

void Page::setTitle(QString title)
{
    if (title == _title)
        return;
    _title = title;
    emit titleChanged();
}

QString Page::body()
{
    return _body;
}

void Page::setBody(QString body)
{
    if (body == _body)
        return;
    _body = body;
    emit bodyChanged();
}

QDate Page::date()
{
    return _date;
}

void Page::setDate(QDate date)
{
    _date = date;
    emit dateChanged();
}
