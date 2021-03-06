#ifndef DESKTOP_H
#define DESKTOP_H

#include "models/notebook.h"
#include "models/stickynote.h"
#include <QObject>

class Desktop : public QObject {
    Q_OBJECT
public:
    explicit Desktop(QObject* parent = nullptr);

    Q_PROPERTY(QString background READ background NOTIFY backgroundChanged)
    Q_PROPERTY(Notebook* notebook READ notebook NOTIFY notebookChanged)
    Q_PROPERTY(QList<QObject*> stickynotes READ stickynotes NOTIFY stickyChanged)

    QString background() const;
    Notebook* notebook() const;
    QList<QObject*> stickynotes() const;

    QVariantMap toMap() const;
    static Desktop* fromMap(QVariantMap map, QObject* parent);
    static Desktop* load(QObject* parent = nullptr);

public slots:
    void save();
    void addStickyNote();

signals:
    void backgroundChanged();
    void notebookChanged();
    void stickyChanged();

private:
    QString _background;
    Notebook* _notebook;
    QList<StickyNote*> _stickynotes;

    void addNotebook(Notebook* notebook);
    void addStickyNote(StickyNote* note);
};

#endif // DESKTOP_H
