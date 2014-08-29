#include "skillpanel.h"

SkillPanel::SkillPanel(QObject* parent, int img_x, int img_y,QString name, QString des)
{
    this->setParent(parent);
    imgSrc.load("img/imgSrc.jpg");
    buildGui(img_x,img_y, name, des);
}

void SkillPanel::buildGui(int img_x, int img_y,QString name, QString des){
    //add picture
    QPixmap myImage = imgSrc.copy(img_x,img_y,27,27);
    img1 = this->addPixmap(myImage);
    img1->setPos(50,0);

    //font list
    QFont serifFont("Times", 12, QFont::Bold);

    //add name
    skillNameItem1 = this->addText(name);
    skillNameItem1->setPos(0,myImage.height());
    skillNameItem1->setFont(serifFont);



    //add strength
    int strYAt = myImage.height()+20;
    Description1 = this->addText(des);
    Description1->setPos(0, strYAt+20);
}

void SkillPanel::updateGui(){
    img1->update();
    skillNameItem1->update();
    Description1->update();

    this->update();
}

void SkillPanel::changeFirstImg(int img_x, int img_y){
    QPixmap myImage = imgSrc.copy(img_x,img_y,27,27);
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


