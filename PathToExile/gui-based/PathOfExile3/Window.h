#pragma once

#include <QWidget>
#include <QtCore>
#include <QtGui>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
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
#include <QStringList>
#include <QString>
#include <iostream>
#include <QObject>
#include <heropanel.h>
#include <skillpanel.h>
#include <QPoint>
#include <QPixmap>
#include "herodescription.h"
#include "skillpanel2.h"
#include <QProgressBar>
#include <QTabWidget>
#include <centercontrol.h>

class Window : public QWidget
{
    Q_OBJECT
    QGridLayout *grid;
    QGraphicsView *leftView;
    QGraphicsView *leftView2;
    QGraphicsView *rightView;
    QGraphicsView *rightView2;
    QGraphicsView *centerView;
    CenterControl* centerControl; //this one is a Qtabwidget


    HeroPanel* heroPanel;
    SkillPanel* skillPanel;
    SkillPanel2* skillPanel2;
    QGraphicsScene *sceneCenter;
    QComboBox *comboHeroClass;
    QComboBox *comboSkill;
    HeroDescription* heroDescription;
    QProgressBar* progressBar;
  public:
    Window(QWidget *parent = 0);
    ~Window();
  public slots:
};
