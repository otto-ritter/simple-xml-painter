#ifndef MYPAINTER_H
#define MYPAINTER_H

#include <QObject>

class myPainter : public QObject
{
    Q_OBJECT
public:
    explicit myPainter(QObject *parent = 0);

signals:

public slots:

};

#endif // MYPAINTER_H
