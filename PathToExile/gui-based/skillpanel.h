#ifndef SKILLPANEL_H
#define SKILLPANEL_H
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

class SkillPanel : public QGraphicsScene
{
    Q_OBJECT
    //first skill
    QPixmap imgSrc;
    QGraphicsPixmapItem* img1;
    QGraphicsTextItem* skillNameItem1;
    QGraphicsTextItem* Description1;

    QGraphicsTextItem* skillPointItem;
public:
    SkillPanel(QObject* parent, int img_x, int img_y,QString name, QString des);
    void buildGui(int img_x, int img_y,QString name, QString des);
    void updateGui();
public slots:
    void changeFirstImg(int img_x, int img_y);
    void changeFirstName(QString firstName);
    void changeFirstDes(QString des);
};

#endif // SKILLPANEL_H
