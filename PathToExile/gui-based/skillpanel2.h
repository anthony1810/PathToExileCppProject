#ifndef SKILLPANEL2_H
#define SKILLPANEL2_H
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
#include <QPen>
#include <QPainter>
#include <QPoint>

class SkillPanel2 : public QGraphicsScene
{
    Q_OBJECT
    //second skill
    QPixmap imgSrc;
    QGraphicsPixmapItem* img2;
    QGraphicsTextItem* skillNameItem2;
    QGraphicsTextItem* Description2;

    QGraphicsTextItem* skillPointItem;
public:
    SkillPanel2(QObject* parent, QString img,QString name, QString des);
    void buildGui(QString img,QString name, QString des);
    void updateGui();
public slots:
    void changeSecondImg(int img_x, int img_y);
    void changeSecondName(QString secondtName);
    void changeSecondDes(QString des);
    void drawLine(int x1,int y1, int x2, int y2);
};

#endif // SKILLPANEL2_H
