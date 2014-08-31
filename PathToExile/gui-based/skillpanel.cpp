#include "skillpanel.h"

SkillPanel::SkillPanel(QObject* parent, QString img,QString name, QString des)
{
    this->setParent(parent);
    imgSrc.load("img/imgSrc.jpg");
    buildGui(img, name, des);
}

void SkillPanel::buildGui(QString img,QString name, QString des){
    //add picture
    QPixmap myImage(img);
    img1 = this->addPixmap(myImage);
    img1->setPos(90,0);

    //font list
    QFont serifFont("Times", 12, QFont::Bold);

    //add name
    skillNameItem1 = this->addText(name);
    skillNameItem1->setPos(80,27);
    skillNameItem1->setFont(serifFont);



    //add strength
    Description1 = this->addText(des);
    Description1->setPos(0, 67);
}

void SkillPanel::updateGui(){
    img1->update();
    skillNameItem1->update();
    Description1->update();

    this->update();
}

void SkillPanel::changeFirstImg(int img_x, int img_y, int imgW, int imgH){
    QPixmap myImage = imgSrc.copy(img_x,img_y,imgW,imgH);
    img1->setPixmap(myImage);
}

void SkillPanel::changeFirstName(QString firstName){
    skillNameItem1->setPlainText(firstName);
}

void SkillPanel::changeFirstDes(QString des){
    Description1->setPlainText(des);
}

SkillPanel::~SkillPanel(){
    this->~QGraphicsScene();
    delete img1;
    delete skillNameItem1;
    delete Description1;

    delete skillPointItem;
}


