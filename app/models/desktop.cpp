#include "desktop.h"

Desktop::Desktop(QObject* parent)
    : QObject(parent)
{
}

QString Desktop::background()
{
    return "qrc:/desktop_bg.jpg";
}
