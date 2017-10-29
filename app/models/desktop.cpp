#include "desktop.h"

Desktop::Desktop(QObject* parent)
    : QObject(parent)
{
    _notebook = new Notebook(this);
    connect(_notebook, SIGNAL(pagesChanged()),
        this, SIGNAL(notebookChanged()));
}

QString Desktop::background()
{
    return "qrc:/desktop_bg.jpg";
}

Notebook* Desktop::notebook()
{
    return _notebook;
}
