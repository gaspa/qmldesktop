#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include "page.h"
#include <QObject>

class Notebook : public QObject {
    Q_OBJECT
public:
    explicit Notebook(QObject* parent = nullptr);

    Q_PROPERTY(QString title READ title NOTIFY titleChanged)
    Q_PROPERTY(int length READ length NOTIFY lengthChanged)
    Q_PROPERTY(QList<QObject*> pages READ pages NOTIFY pagesChanged)
    Q_PROPERTY(QList<QObject*> pairs READ pairs NOTIFY pairsChanged)

    QString title();
    int length();
    QList<QObject*> pages();
    QList<QObject*> pairs();

signals:
    void titleChanged();
    void lengthChanged();
    void pagesChanged();
    void pairsChanged();

public slots:
    void addPage();

private:
    QList<Page*> _pages;
};

#endif // NOTEBOOK_H
