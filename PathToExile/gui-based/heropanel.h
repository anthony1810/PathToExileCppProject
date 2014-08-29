#ifndef HEROPANEL_H
#define HEROPANEL_H
#include <QComboBox>
#include <QPushButton>
#include <QPixmap>
#include <QFrame>
#include <QSplitter>
#include <QPalette>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <stdio.h>
#include <QDebug>
#include <QImageReader>
#include <QObject>
#include <QLabel>
#include <QTextEdit>

class HeroPanel:public QGraphicsScene
{
    Q_OBJECT
     QGraphicsPixmapItem* avatar;
     QGraphicsTextItem* heroNameItem;
     QGraphicsTextItem* heroStrItem;
     QGraphicsTextItem* heroDexItem;
     QGraphicsTextItem* herointelItem;
     QGraphicsTextItem* description;
     int title_x;
     int title_y;
public:
    HeroPanel(QObject* parent, QString imageSource, int str, int dex, int intel, QString desctiption);
    //~ HeroPanel();
    void buildGui(QString imageSource, int str, int dex, int intel, QString desctiption);
    void updateGui();
    void changeAvatar(QString avatarSrc);
    void changeHeroName(QString heroName);
    void changeStr(int newStr);
    void changeDex(int newDex);
    void changeIntel(int newIntel);
    void changeDescription(QString newDes);
};

#endif // HEROPANEL_H
