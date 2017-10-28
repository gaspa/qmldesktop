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
    Q_PROPERTY(QList<Page*> pages READ pages NOTIFY pagesChanged)

    QString title();
    int length();
    QList<Page*> pages();

signals:
    void titleChanged();
    void lengthChanged();
    void pagesChanged();

public slots:
    void addPage();

private:
    QList<Page*> _pages;
};

#endif // NOTEBOOK_H
