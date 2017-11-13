#include "desktop.h"
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QStandardPaths>
#include <QVariantMap>

Desktop::Desktop(QObject* parent)
    : QObject(parent)
    , _background()
{
    addNotebook(new Notebook(this));

    connect(this, SIGNAL(stickyChanged()),
        this, SLOT(save()));
}

QVariantMap Desktop::toMap() const
{
    QVariantMap map;
    map.insert("background", _background);
    map.insert("notebook", _notebook->toMap());
    QVariantList stickynotes;
    for (auto note : _stickynotes)
        stickynotes.append(note->toMap());
    map.insert("stickynotes", stickynotes);
    return map;
}

Desktop* Desktop::fromMap(QVariantMap map, QObject* parent)
{
    Desktop* d = new Desktop(parent);
    d->_background = map.value("background", "").toString();
    d->addNotebook(Notebook::fromMap(map.value("notebook").toMap(), d));
    auto stickynotes = map.value("stickynotes").toList();
    for (auto variantnote : stickynotes) {
        StickyNote* s = StickyNote::fromMap(variantnote.toMap(), d);
        d->addStickyNote(s);
    }
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
    StickyNote* s = new StickyNote(this);
    connect(s, SIGNAL(titleChanged()),
        this, SIGNAL(stickyChanged()));
    connect(s, SIGNAL(bodyChanged()),
        this, SIGNAL(stickyChanged()));
    connect(s, SIGNAL(colorChanged()),
        this, SIGNAL(stickyChanged()));
    _stickynotes.append(s);
    emit stickyChanged();
}

void Desktop::addStickyNote(StickyNote* note)
{
    connect(note, SIGNAL(titleChanged()),
        this, SIGNAL(stickyChanged()));
    connect(note, SIGNAL(bodyChanged()),
        this, SIGNAL(stickyChanged()));
    connect(note, SIGNAL(colorChanged()),
        this, SIGNAL(stickyChanged()));
    _stickynotes.append(note);
    emit stickyChanged();
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
    return _background.isEmpty() ? "qrc:/desktop_bg.jpg" : _background;
}

Notebook* Desktop::notebook() const
{
    return _notebook;
}

QList<QObject*> Desktop::stickynotes() const
{
    QList<QObject*> list;
    for (auto note : _stickynotes)
        list.append(note);
    return list;
}
