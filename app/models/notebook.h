#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include <QObject>

class Notebook : public QObject {
    Q_OBJECT
public:
    explicit Notebook(QObject* parent = nullptr);

    Q_PROPERTY(QString title READ title NOTIFY titleChanged)
    Q_PROPERTY(int length READ length NOTIFY lengthChanged)

    QString title();
    int length();
signals:
    void titleChanged();
    void lengthChanged();

public slots:
};

#endif // NOTEBOOK_H
