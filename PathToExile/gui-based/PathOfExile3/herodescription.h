#ifndef HERODESCRIPTION_H
#define HERODESCRIPTION_H

#include <QGraphicsScene>
#include <QTextEdit>

class HeroDescription : public QGraphicsScene
{
    Q_OBJECT
    QTextEdit* desArea;
public:
    HeroDescription(QObject *parent = 0, QString des=0);
    void changeDes(QString des);
    ~HeroDescription();
signals:

public slots:
    //void release();
};

#endif // HERODESCRIPTION_H
