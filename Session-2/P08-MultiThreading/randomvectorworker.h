#ifndef RANDOMVECTORWORKER_H
#define RANDOMVECTORWORKER_H

#include <QObject>

class RandomVectorWorker : public QObject
{
    Q_OBJECT
public:
    explicit RandomVectorWorker(QObject *parent = nullptr);

signals:

public slots:
    void inputHandler(const QString& in);
};

#endif // RANDOMVECTORWORKER_H
