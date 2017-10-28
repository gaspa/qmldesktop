#include "notebook.h"

Notebook::Notebook(QObject* parent)
    : QObject(parent)
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
