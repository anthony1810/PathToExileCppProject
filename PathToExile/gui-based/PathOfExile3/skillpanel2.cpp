#include "skillpanel2.h"

SkillPanel2::SkillPanel2(QObject* parent, QString img,QString name, QString des)
{
    this->setParent(parent);
    imgSrc.load("img/imgSrc.jpg");
    buildGui(img, name, des);
}

void SkillPanel2::buildGui(QString img,QString name, QString des){
    int secondSkillY = 0;
     QFont serifFont("Times", 12, QFont::Bold);
    //add image
    QPixmap myImage2(img);
    img2 = this->addPixmap(myImage2);
    img2->setPos(50,secondSkillY);
    skillNameItem2=this->addText(name);
    skillNameItem2->setPos(0,secondSkillY+27);
    skillNameItem2->setFont(serifFont);

    Description2=this->addText(des);
    Description2->setPos(0, secondSkillY+67);
}

void SkillPanel2::updateGui(){
    img2->update();
    skillNameItem2->update();
    Description2->update();
    this->update();
}

void SkillPanel2::changeSecondImg(int img_x, int img_y){
    QPixmap myImage = imgSrc.copy(img_x,img_y,27,27);
    img2->setPixmap(myImage);
}

void SkillPanel2::changeSecondName(QString secondName){
    skillNameItem2->setPlainText(secondName);
}

void SkillPanel2::changeSecondDes(QString des){
    Description2->setPlainText(des);
}

void SkillPanel2::drawLine(int x1,int y1, int x2, int y2){
    QPen paintpen(Qt::blue, 2, Qt::SolidLine);
    paintpen.setWidth(10);\
    this->addLine(x1, y1, x2, y2, paintpen);
}

SkillPanel2::~SkillPanel2(){
    this->~QGraphicsScene();
    delete img2;
    delete skillNameItem2;
    delete Description2;

}

