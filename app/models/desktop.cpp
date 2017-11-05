#include "desktop.h"
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QStandardPaths>
#include <QVariantMap>

Desktop::Desktop(QObject* parent)
    : QObject(parent)
{
    addNotebook(new Notebook(this));
}

QVariantMap Desktop::toMap() const
{
    QVariantMap map;
    map.insert("notebook", _notebook->toMap());
    return map;
}

Desktop* Desktop::fromMap(QVariantMap map, QObject* parent)
{
    Desktop* d = new Desktop(parent);
    d->addNotebook(Notebook::fromMap(map.value("notebook").toMap(), d));
    return d;
}

void Desktop::addNotebook(Notebook* notebook)
{
    _notebook = notebook;
    connect(_notebook, SIGNAL(pagesChanged()),
        this, SIGNAL(notebookChanged()));

    connect(_notebook, SIGNAL(pagesChanged()),
        this, SLOT(save()));
    connect(_notebook, SIGNAL(titleChanged()),
        this, SLOT(save()));
}

void Desktop::addStickyNote()
{
    _stickynotes.append(new StickyNote(this));
}

void Desktop::save()
{
    qDebug() << "saving";
    QDir base = QDir(QStandardPaths::writableLocation(QStandardPaths::DataLocation));
    if (!base.exists())
        QDir().mkpath(base.path());
    QJsonDocument doc = QJsonDocument::fromVariant(toMap());
    QString savePath = base.absoluteFilePath("desktop.json");
    qDebug() << "SAVEPATH" << savePath;
    qDebug() << "JSON:" << doc.toJson();
    QFile saveFile(savePath);
    if (saveFile.open(QIODevice::WriteOnly | QIODevice::Truncate))
        saveFile.write(doc.toJson());
}

Desktop* Desktop::load(QObject* parent)
{
    QDir base = QDir(QStandardPaths::writableLocation(QStandardPaths::DataLocation));
    QString savePath = base.absoluteFilePath("desktop.json");
    QFile saveFile(savePath);
    if (saveFile.exists() && saveFile.open(QIODevice::ReadOnly)) {
        QJsonDocument doc = QJsonDocument::fromJson(saveFile.readAll());
        return Desktop::fromMap(doc.toVariant().toMap(), parent);
    }
    qDebug() << "cannot open json file " << savePath;
    return new Desktop(parent);
}

QString Desktop::background() const
{
    return "qrc:/desktop_bg.jpg";
}

Notebook* Desktop::notebook() const
{
    return _notebook;
}

QList<StickyNote*> Desktop::stickynotes() const
{
    return _stickynotes;
}
