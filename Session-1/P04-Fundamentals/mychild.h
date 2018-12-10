#ifndef MYCHILD_H
#define MYCHILD_H

#include <QObject>

class MyChild : public QObject
{
    Q_OBJECT
public:
    explicit MyChild(QObject *parent = nullptr);
    ~MyChild();

signals:

public slots:
};

#endif // MYCHILD_H
