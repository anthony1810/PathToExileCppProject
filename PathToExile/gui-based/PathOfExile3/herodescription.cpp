#include "herodescription.h"

HeroDescription::HeroDescription(QObject *parent, QString des) :
    QGraphicsScene(parent)
{
    this->setParent(parent);
    desArea = new QTextEdit(des);
    this->addWidget(desArea);
}

void HeroDescription::changeDes(QString des){
    desArea->setText(des);
    desArea->update();
}

HeroDescription::~HeroDescription(){
    this->~QGraphicsScene();
    delete desArea;
}


