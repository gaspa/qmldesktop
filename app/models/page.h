#ifndef PAGE_H
#define PAGE_H

#include <QDate>
#include <QObject>

class Page : public QObject {
    Q_OBJECT

public:
    explicit Page(int pagenumber, QObject* parent = nullptr);

    Q_PROPERTY(int pagenumber READ pagenumber)
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString body READ title WRITE setBody NOTIFY bodyChanged)
    Q_PROPERTY(QDate date READ date NOTIFY dateChanged)

    int pagenumber();
    QString title();
    void setTitle(QString title);
    QString body();
    void setBody(QString body);
    QDate date();
    void setDate(QDate date);

signals:
    void titleChanged();
    void bodyChanged();
    void dateChanged();

private:
    int _pagenumber;
    QString _title;
    QString _body;
    QDate _date;
};

#endif // PAGE_H
