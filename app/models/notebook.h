#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include "page.h"
#include <QObject>

class Notebook : public QObject {
    Q_OBJECT
public:
    explicit Notebook(QObject* parent = nullptr);

    Q_PROPERTY(int x READ x WRITE setX NOTIFY positionChanged)
    Q_PROPERTY(int y READ y WRITE setY NOTIFY positionChanged)
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(int length READ length NOTIFY lengthChanged)
    Q_PROPERTY(QString background READ background NOTIFY backgroundChanged)
    Q_PROPERTY(QList<QObject*> pages READ pages NOTIFY pagesChanged)
    Q_PROPERTY(QList<QObject*> pairs READ pairs NOTIFY pairsChanged)

    int x() const;
    int y() const;
    void setX(int x);
    void setY(int y);
    QString title() const;
    void setTitle(QString title);
    int length() const;
    QString background() const;
    QList<QObject*> pages();
    QList<QObject*> pairs();

    QVariantMap toMap();
    static Notebook* fromMap(QVariantMap map, QObject* parent);

signals:
    void positionChanged();
    void titleChanged();
    void lengthChanged();
    void backgroundChanged();
    void pagesChanged();
    void pairsChanged();

public slots:
    void addPage();
    void addPage(Page* p);

private:
    int _x;
    int _y;
    QString _title;
    QList<Page*> _pages;
    QString _background;
};

#endif // NOTEBOOK_H
