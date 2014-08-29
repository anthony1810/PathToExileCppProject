#include "heropanel.h"

HeroPanel::HeroPanel(QObject* parent, QString imageSource, int str, int dex, int intel, QString desctiption)
{
   this->setParent(parent);
   buildGui(imageSource,str,dex,intel,desctiption);

}

void HeroPanel::buildGui(QString imageSource, int str, int dex, int intel, QString desctiption){
    //add picture
    QPixmap myImage;
    myImage.load(imageSource);
    title_x = myImage.width();
    title_y = myImage.height();
    qDebug() << myImage.isNull();
    avatar = this->addPixmap(myImage);
    avatar->setPos(0,0);

    //font list
    QFont serifFont("Times", 15, QFont::Bold);

    //add name
    heroNameItem = this->addText(QString("Marauder"));
    heroNameItem->setPos(10,myImage.height());
    heroNameItem->setFont(serifFont);


    //add strength
    QBrush redBrush(Qt::red);
    QPen blackpen(Qt::NoPen);
    blackpen.setWidth(6);
    int strYAt = myImage.height()+40;
    int strXAt = 20;

    ellipseStr = this->addEllipse(strXAt,strYAt-10,40,40,blackpen,redBrush);
    heroStrItem = this->addText(QString::number(str));
    heroStrItem->setPos(strXAt+10,strYAt);
    ellipseStr->update();


    //add dex
    QBrush greenBrush(Qt::green);
    blackpen.setWidth(6);
    int dexAtX = strXAt+40;
    int dexAtY = strYAt;
    ellipseDex = this->addEllipse(dexAtX,dexAtY,40,40,blackpen,greenBrush);
    heroDexItem = this->addText(QString::number(dex));
    heroDexItem->setPos(dexAtX+10, dexAtY+10);
    ellipseDex->update();

    //add Inteligence
    QBrush blueBrush(Qt::blue);
    blackpen.setWidth(6);
    int intelxAtX = (strXAt+dexAtX)/2-10;
    int intelAtY = strYAt+25;
    ellipseIntel = this->addEllipse(intelxAtX,intelAtY,40,40,blackpen,blueBrush);
    herointelItem = this->addText(QString::number(intel));
    herointelItem->setPos(intelxAtX+10, intelAtY+10);
    ellipseIntel->update();

}

void HeroPanel::updateGui(){
        avatar->update();
        herointelItem->update();
        heroStrItem->update();
        heroDexItem->update();
        herointelItem->update();
        this->update();
}

void HeroPanel::changeAvatar(QString avatarSrc){
    QPixmap myImage;
    myImage.load(avatarSrc);
    //qDebug() << myImage.toImage().size();
    avatar->setPixmap(myImage);
}

void HeroPanel::changeHeroName(QString heroName){
    heroNameItem->setPlainText(heroName);
    heroNameItem->setPos(12,title_y);
}

void HeroPanel::changeStr(int newStr){
    heroStrItem->setPlainText(QString::number(newStr));
}

void HeroPanel::changeDex(int newDex){
    heroDexItem->setPlainText(QString::number(newDex));

}

void HeroPanel::changeIntel(int newIntel){
    herointelItem->setPlainText(QString::number(newIntel));
}

void HeroPanel::changeDescription(QString newDes){
    description->setPlainText(newDes);
}

HeroPanel::~HeroPanel(){
    this->~QGraphicsScene();
    delete avatar;
    delete heroNameItem;
    delete heroStrItem;
    delete heroDexItem;
   delete herointelItem;
    delete description;

    delete ellipseStr;
    delete ellipseDex;
   delete ellipseIntel;
}


