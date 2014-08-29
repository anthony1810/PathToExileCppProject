#include <Window.h>


Window::Window(QWidget *parent)
    : QWidget(parent)
{
    //grid layout for the whole window
    QGridLayout *grid = new QGridLayout(this);

    grid->addWidget(new QLabel("Hero Info"),1,1,1,1,Qt::AlignCenter);
    QGraphicsView *leftView = new QGraphicsView();
    leftView->resize(1000,1000);
    heroPanel = new HeroPanel(leftView, "img/marauder-large.png", 32,14,14,"");
    leftView->setScene(heroPanel);
    grid->addWidget(leftView,2,0,1,3);

    QGraphicsView *leftView2 = new QGraphicsView();
    heroDescription = new HeroDescription();
    leftView2->setScene(heroDescription);
    grid->addWidget(new QLabel("Total Effects"), 3,0,1,1, Qt::AlignCenter);
    grid->addWidget(leftView2, 4,0,1,3);

    grid->addWidget(new QLabel("                    "),5,1,1,1);
    grid->addWidget(new QLabel("                    "),5,2,1,1);

    grid->addWidget(new QLabel("Initial Skill"),1,8,1,2, Qt::AlignCenter);
    QGraphicsView *rightView = new QGraphicsView(this);
    skillPanel = new SkillPanel(this,0,0,"Lord Of The Dead","haha");
    rightView->setScene(skillPanel);
    grid->addWidget(rightView,2,8,1,3);

    grid->addWidget(new QLabel("Destionation Skill"),3,8,1,3,Qt::AlignCenter);
    QGraphicsView *rightView2 = new QGraphicsView(this);
    skillPanel2 = new SkillPanel2(this,"img/qtm.gif","?","?");
    rightView2->setScene(skillPanel2);
    grid->addWidget(rightView2,4,8,1,3);

    grid->addWidget(new QLabel("                    "),5,8,1,1);
    grid->addWidget(new QLabel("                    "),5,9,1,1);
    QLabel *heroTitle = new QLabel("Heroes Class", this);
    grid->addWidget(heroTitle, 5, 3, 1, 1);

    comboHeroClass = new QComboBox();
    comboHeroClass->addItem("Maurander");
    comboHeroClass->addItem("Witcher");
    comboHeroClass->setCurrentIndex(0);
    grid->addWidget(comboHeroClass, 5,4,1,1);
    QObject::connect(comboHeroClass, SIGNAL(currentIndexChanged(int)),this, SLOT(handleHeroChange(int)));


    QLabel *desTitle = new QLabel("Destionation Skill", this);
    grid->addWidget(desTitle, 5, 5, 1, 1);


    comboSkill = new QComboBox();
    comboSkill->addItem("Lord of the dead");
    comboSkill->addItem("Dance Of Dead");
    grid->addWidget(comboSkill, 5,6,1,1);
    QObject::connect(comboSkill, SIGNAL(currentIndexChanged(int)),this, SLOT(handleSkillChange(int)));


    QPushButton *goButton = new QPushButton("Go");
    grid->addWidget(goButton, 5,7,1,1);
    QObject::connect(goButton, SIGNAL(clicked()), this, SLOT(handleGoButton()));


    QGraphicsView *centerView = new QGraphicsView();
    QGraphicsScene *sceneCenter = new QGraphicsScene();

    centerView->setScene(sceneCenter);
    grid->addWidget(centerView,1,3,4,5);
    QBrush redBrush(Qt::NoBrush);
    QPen blackpen(Qt::yellow);
    blackpen.setWidth(5);
  //  int yCor = 100;
    QPixmap myImage("img/imgSrc.jpg");
    int img_x = 0;
    int img_y = 0;

    for(int j = 0; j<500; j++){
       QGraphicsTextItem *text = sceneCenter->addText("  ");
       text->setPos(-10, j);
    }
    int xCor = 0;
    for(int i = 0 ; i<10; i++){
        QPixmap skillPix = myImage.copy(img_x, img_y, 27,27);
        QGraphicsPixmapItem* skillItem = sceneCenter->addPixmap(skillPix);
        skillItem->setPos(xCor, 0);
        QGraphicsEllipseItem *ellipse;
        ellipse = sceneCenter->addEllipse(xCor-2,0-2,30,30,blackpen,redBrush);
        xCor = xCor + 50;
        img_x+=27;
        img_y+=27
                ;

    }
    setLayout(grid);

}

void Window::handleHeroChange(int index){
    if(index == 1){
        heroPanel->changeAvatar("img/Witch_avatar.png");
        heroPanel->changeStr(14);
        heroPanel->changeDex(14);
        heroPanel->changeIntel(32);
        heroPanel->changeHeroName("Witch");
        heroPanel->updateGui();

        skillPanel->changeFirstImg(25,0);
        skillPanel->changeFirstName("Dance of Death");
        skillPanel->changeFirstDes("-This is the dance\n of death. It's deadly.");
        skillPanel->updateGui();
    }else if(index == 0){
        heroPanel->changeAvatar("img/marauder-large.png");
        heroPanel->changeStr(32);
        heroPanel->changeDex(14);
        heroPanel->changeIntel(14);
        heroPanel->changeHeroName("Marauder");
        heroPanel->updateGui();

        skillPanel->changeFirstImg(0,0);
        skillPanel->changeFirstName("Lord Of The Death");
        skillPanel->changeFirstDes("-haha");
        skillPanel->updateGui();
    }

}

void Window::handleSkillChange(int index){
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

void Window::handleGoButton(){
        skillPanel2->drawLine(50,70,50,150);
        skillPanel2->updateGui();
}

