#ifndef DESKTOP_H
#define DESKTOP_H

#include <QObject>

class Desktop : public QObject {
    Q_OBJECT
public:
    explicit Desktop(QObject* parent = nullptr);

    Q_PROPERTY(QString background READ background NOTIFY backgroundChanged)

    QString background();

signals:
    void backgroundChanged();

public slots:
};

#endif // DESKTOP_H
