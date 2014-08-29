#include <Window.h>


Window::Window(QWidget *parent)
    : QWidget(parent)
{
    //grid layout for the whole window
    grid = new QGridLayout(this);

    grid->addWidget(new QLabel("HERO INFO"),1,1,1,1,Qt::AlignCenter);
    leftView = new QGraphicsView();
    leftView->resize(1000,1000);
    heroPanel = new HeroPanel(leftView, "img/marauder-large.png", 32,14,14,"");
    leftView->setScene(heroPanel);
    grid->addWidget(leftView,2,0,1,3);

    leftView2 = new QGraphicsView();
    heroDescription = new HeroDescription();
    leftView2->setScene(heroDescription);
    grid->addWidget(new QLabel("TOTAL EFFECTS"), 3,0,1,1, Qt::AlignCenter);
    grid->addWidget(leftView2, 4,0,1,3);

    grid->addWidget(new QLabel("                    "),5,1,1,1);
    grid->addWidget(new QLabel("                    "),5,2,1,1);

    grid->addWidget(new QLabel("INITIAL SKILL"),1,8,1,3, Qt::AlignCenter);
    rightView = new QGraphicsView(this);
    skillPanel = new SkillPanel(this,0,0,"Lord Of The Dead","haha");
    rightView->setScene(skillPanel);
    grid->addWidget(rightView,2,8,1,3);

    grid->addWidget(new QLabel("DESTINATION SKILL"),3,8,1,3,Qt::AlignCenter);
    rightView2 = new QGraphicsView(this);
    skillPanel2 = new SkillPanel2(this,"img/qtm.gif","?","?");
    rightView2->setScene(skillPanel2);
    grid->addWidget(rightView2,4,8,1,3);

    grid->addWidget(new QLabel("                    "),5,8,1,1);
    grid->addWidget(new QLabel("                    "),5,9,1,1);
    grid->addWidget(new QLabel("                    "),5,10,1,1);

     centerView = new QGraphicsView();
     sceneCenter = new QGraphicsScene();
     centerView->setScene(sceneCenter);
     progressBar = new QProgressBar(this);
     grid->addWidget(progressBar,1,3,1,5);
     grid->addWidget(centerView,2,3,3,5);

    centerControl = new CenterControl(this,heroPanel,heroDescription,skillPanel, skillPanel2,sceneCenter, progressBar);
    grid->addWidget(centerControl,5,3,1,1);
    setLayout(grid);
}

Window::~Window(){
    this->~QObject();
    delete grid;
    delete leftView;
    delete leftView2;
    delete rightView;
    delete rightView2;
    delete centerControl;
    delete centerView;

    delete heroPanel;
    delete skillPanel;
    delete skillPanel2;
    delete sceneCenter;
    delete comboHeroClass;
    delete comboSkill;
    delete heroDescription;
    delete progressBar;
}


