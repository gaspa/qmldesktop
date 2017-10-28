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

    QString background();
    Notebook* notebook();

public slots:

signals:
    void backgroundChanged();
    void notebookChanged();

private:
    Notebook* _notebook;
};

#endif // DESKTOP_H
