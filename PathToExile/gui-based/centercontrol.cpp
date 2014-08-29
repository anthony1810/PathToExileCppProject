#include "centercontrol.h"

CenterControl::CenterControl(QWidget *parent,HeroPanel* heroPanel, HeroDescription* desPanel, SkillPanel* skillPanel1,
                             SkillPanel2* skillPanel2,QGraphicsScene *sceneCenter, QProgressBar* progressBar) :
    QTabWidget(parent)
{
    this->setParent(parent);
    this->heroPanel = heroPanel;
    this->desPanel = desPanel;
    this->skillPanel1 = skillPanel1;
    this->skillPanel2 = skillPanel2;
    this->progressBar = progressBar;
    this->sceneCenter = sceneCenter;
    buildGui();
}

void CenterControl::buildGui(){

    //shortest path tab
    shortestPathTab = new QWidget();
    QGridLayout* grid = new QGridLayout();
    shortestPathTab->setLayout(grid);

    heroTitle = new QLabel("Heroes Class", this);
    grid->addWidget(heroTitle, 0, 1, 1, 1);

    comboHeroClass = new QComboBox();
    comboHeroClass->addItem("Maurander");
    comboHeroClass->addItem("Witcher");
    comboHeroClass->setCurrentIndex(0);
    grid->addWidget(comboHeroClass, 0,2,1,1);
    QObject::connect(comboHeroClass, SIGNAL(currentIndexChanged(int)),this, SLOT(handleHeroChange(int)));


    desTitle = new QLabel("Destionation Skill", this);
    grid->addWidget(desTitle, 0, 3, 1, 1);


    comboSkill = new QComboBox();
    comboSkill->addItem("Lord of the dead");
    comboSkill->addItem("Dance Of Dead");
    grid->addWidget(comboSkill, 0,4,1,1);
    QObject::connect(comboSkill, SIGNAL(currentIndexChanged(int)),this, SLOT(handleSkillChange(int)));


    shortestButton = new QPushButton("Go");
    grid->addWidget(shortestButton, 0,5,1,1);
    QObject::connect(shortestButton, SIGNAL(clicked()), this, SLOT(handleGoButton()));

    this->addTab(shortestPathTab, "Shortest Path");


    //Custome Shortestpath Tab
//    customShortestTab = new QWidget();
//    cusGrid = new QGridLayout();
//    customShortestTab->setLayout(cusGrid);
//    initialNodeLabel = new QLabel("Initial Node");
//    initialNode = new QComboBox();

//    cusGrid->addWidget(initialNodeLabel, 0, 1, 1, 1);
//    cusGrid->addWidget(initialNode, 0,2,1,1);
//    cusGrid->addWidget(desTitle, 0, 3, 1, 1);
//    cusGrid->addWidget(comboSkill, 0,4,1,1);
//    cusShortestButton = new QPushButton("Go");
//    cusGrid->addWidget(cusShortestButton, 0,5,1,1);
//    this->addTab(customShortestTab,"Custom Shortest");


    //Write to file tab
    writeTab = new QWidget();
    grid2 = new QGridLayout();
    writeTab->setLayout(grid2);

    urlLabel = new QLabel("Website",this);
    grid2->addWidget(urlLabel, 0,0,1,1);

    desUrl = new QLineEdit("www.pathofexile/passiveskilltree");
    desUrl->setEnabled(false);
    grid2->addWidget(desUrl, 0,1,1,1);

    fileLabel = new QLabel("Text File",this);
    grid2->addWidget(fileLabel,0,2,1,1);

    fileName = new QLineEdit(this);
    grid2->addWidget(fileName,0,3,1,1);

    writeButton = new QPushButton("Extract");
    grid2->addWidget(writeButton,0,4,1,1);
    this->addTab(writeTab,"Connect Handler");
    connect(writeButton,SIGNAL(clicked()),this, SLOT(handleWriteButton()));

}

void CenterControl::handleHeroChange(int index){
    progressBar->reset();
    sceneCenter->clear();
    if(index == 1){
        heroPanel->changeAvatar("img/Witch_avatar.png");
        heroPanel->changeStr(14);
        heroPanel->changeDex(14);
        heroPanel->changeIntel(32);
        heroPanel->changeHeroName("Witch");
        heroPanel->updateGui();

        skillPanel1->changeFirstImg(25,0);
        skillPanel1->changeFirstName("Dance of Death");
        skillPanel1->changeFirstDes("-This is the dance\n of death. It's deadly.");
        skillPanel1->updateGui();
    }else if(index == 0){
        heroPanel->changeAvatar("img/marauder-large.png");
        heroPanel->changeStr(32);
        heroPanel->changeDex(14);
        heroPanel->changeIntel(14);
        heroPanel->changeHeroName("Marauder");
        heroPanel->updateGui();

        skillPanel1->changeFirstImg(0,0);
        skillPanel1->changeFirstName("Lord Of The Death");
        skillPanel1->changeFirstDes("-haha");
        skillPanel1->updateGui();
    }

}

void CenterControl::handleSkillChange(int index){
    progressBar->reset();
    sceneCenter->clear();
    if(index == 1){
        skillPanel2->changeSecondImg(25,0);
        skillPanel2->changeSecondName("Dance of Death");
        skillPanel2->changeSecondDes("-This is the dance\n of death. It's deadly.");
        skillPanel2->updateGui();
    }else if(index == 0){
        skillPanel2->changeSecondImg(0,0);
        skillPanel2->changeSecondName("Lord Of The Death");
        skillPanel2->changeSecondDes("-haha");
        skillPanel2->updateGui();
    }
}

void CenterControl::handleGoButton(){
    QBrush redBrush(Qt::NoBrush);
    QPen blackpen(Qt::yellow);
    blackpen.setWidth(7);
  //  int yCor = 100;
    QPixmap myImage("img/imgSrc.jpg");
    int img_x = 0;
    int img_y = 0;

    int xCor = 0;
    int yCor = 0;
    progressBar->setMaximum(21);
    progressBar->setMinimum(0);
    for(int i = 0 ; i<22; i++){
        QPixmap skillPix = myImage.copy(img_x, img_y, 27,27);
        QGraphicsPixmapItem* skillItem = sceneCenter->addPixmap(skillPix);
        skillItem->setPos(xCor, yCor);
        QGraphicsEllipseItem *ellipse;
        ellipse = sceneCenter->addEllipse(xCor-4,yCor-4,35,35,blackpen,redBrush);
        QGraphicsTextItem* skillId;
        skillId = sceneCenter->addText(QString::number(xCor));
        skillId->setPos(xCor-4, yCor+skillPix.height());
        xCor = xCor + 70;
        if(i == 7 || i == 15 || i== 22){
            xCor = 0;
            yCor +=70;
        }
        img_x+=27;
        img_y+=27;
        progressBar->setValue(i);
    }
}

void CenterControl::handleWriteButton(){
        QMessageBox msgBox(this);
        QString msg(fileName->text());
        if(msg.size()>0){
            QString fullMsg("File has been write to ");
            fullMsg.append(msg);
            msgBox.setText(fullMsg);
        }else{
            QString fullMsg("Please Enter the text file name!");
            msgBox.setText(fullMsg);
        }
        msgBox.exec();
}

CenterControl::~CenterControl(){
    this->~QTabWidget();
    delete heroPanel;
    delete desPanel;
    delete skillPanel1;
    delete skillPanel2;
    delete sceneCenter;


    delete shortestPathTab;
    delete shortestButton;
    delete comboHeroClass;
    delete comboSkill;
    delete progressBar;
    delete heroTitle;
    delete desTitle;

//    delete writeTab;
//    delete grid2;
//    delete desUrl;
//    delete fileName;
//    delete urlLabel;
//    delete fileLabel;

    delete customShortestTab;
    delete cusGrid;
    delete cusShortestButton;
    delete initialNodeLabel;
    delete initialNode;
}



