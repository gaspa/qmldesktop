#include "desktop.h"

Desktop::Desktop(QObject* parent)
    : QObject(parent)
{
    _notebook = new Notebook(this);
}

QString Desktop::background()
{
    return "qrc:/desktop_bg.jpg";
}

Notebook* Desktop::notebook()
{
    return _notebook;
}
