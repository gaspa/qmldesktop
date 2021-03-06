#ifndef PAGE_H
#define PAGE_H

#include <QDate>
#include <QObject>
#include <QVariantMap>

class Page : public QObject {
    Q_OBJECT

public:
    explicit Page(int pagenumber, bool empty = false, QObject* parent = nullptr);

    Q_PROPERTY(bool empty READ empty CONSTANT)
    Q_PROPERTY(int pagenumber READ pagenumber CONSTANT)
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString body READ body WRITE setBody NOTIFY bodyChanged)
    Q_PROPERTY(QDate date READ date WRITE setDate NOTIFY dateChanged)

    operator QString() const;

    bool empty() const;
    QVariantMap toMap() const;
    static Page* fromMap(QVariantMap map, QObject* parent);

public slots:
    int pagenumber();
    QString title();
    void setTitle(QString title);
    QString body();
    void setBody(QString body);
    QDate date();
    void setDate(QDate date);

signals:
    void pageChanged();

    void titleChanged();
    void bodyChanged();
    void dateChanged();

private:
    bool _empty;
    int _pagenumber;
    QString _title;
    QString _body;
    QDate _date;
};

#endif // PAGE_H
