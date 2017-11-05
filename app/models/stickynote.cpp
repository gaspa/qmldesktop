#include "stickynote.h"

StickyNote::StickyNote(QObject* parent)
    : QObject(parent)
{
}

QVariantMap StickyNote::toMap() const
{
    QVariantMap map;
    map.insert("title", _title);
    map.insert("body", _body);
    map.insert("color", _color.name());
    return map;
}

StickyNote* StickyNote::fromMap(QVariantMap map, QObject* parent)
{
    StickyNote* s = new StickyNote(parent);
    s->setTitle(map.value("title").toString());
    s->setBody(map.value("body").toString());
    s->setColor(QColor(map.value("color").toString()));
    return s;
}

QString StickyNote::title() const
{
    return _title;
}

QString StickyNote::body() const
{
    return _body;
}

QColor StickyNote::color() const
{
    return _color;
}

void StickyNote::setTitle(QString title)
{
    if (_title != title) {
        _title = title;
        emit titleChanged();
    }
}

void StickyNote::setBody(QString body)
{
    if (_body != body) {
        _body = body;
        emit bodyChanged();
    }
}

void StickyNote::setColor(QColor color)
{
    if (_color != color) {
        _color = color;
        emit colorChanged();
    }
}
