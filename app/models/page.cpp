#include "page.h"

Page::Page(int pagenumber, QObject* parent)
    : QObject(parent)
{
    _pagenumber = pagenumber;
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
