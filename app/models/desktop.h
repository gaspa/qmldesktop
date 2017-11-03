#ifndef DESKTOP_H
#define DESKTOP_H

#include "models/notebook.h"
#include <QObject>

class Desktop : public QObject {
    Q_OBJECT
public:
    explicit Desktop(QObject* parent = nullptr);

    Q_PROPERTY(QString background READ background NOTIFY backgroundChanged)
    Q_PROPERTY(Notebook* notebook READ notebook NOTIFY notebookChanged)

    QString background() const;
    Notebook* notebook() const;

    QVariantMap toMap() const;
    static Desktop* fromMap(QVariantMap map, QObject* parent);
    static Desktop* load(QObject* parent = nullptr);

public slots:
    void save();

signals:
    void backgroundChanged();
    void notebookChanged();

private:
    Notebook* _notebook;

    void addNotebook(Notebook* notebook);
};

#endif // DESKTOP_H
