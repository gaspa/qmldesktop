#ifndef STICKYNOTE_H
#define STICKYNOTE_H

#include <QColor>
#include <QObject>
#include <QVariantMap>

class StickyNote : public QObject {
    Q_OBJECT
public:
    explicit StickyNote(QObject* parent = nullptr);

    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString body READ body WRITE setBody NOTIFY bodyChanged)
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)

    QString title() const;
    QString body() const;
    QColor color() const;
    void setTitle(QString title);
    void setBody(QString body);
    void setColor(QColor color);

    QVariantMap toMap() const;
    static StickyNote* fromMap(QVariantMap map, QObject* parent);

signals:
    void titleChanged();
    void bodyChanged();
    void colorChanged();

public slots:

private:
    QString _title;
    QString _body;
    QColor _color;
};

#endif // STICKYNOTE_H
