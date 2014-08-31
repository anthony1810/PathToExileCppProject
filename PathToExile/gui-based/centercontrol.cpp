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

    QLabel* refundPoint = new QLabel("Refund Point",this);
    grid->addWidget(refundPoint, 0,0,1,1);

    refundPointTxt = new QLineEdit(this);
    refundPointTxt->setAlignment(Qt::AlignCenter);
    refundPointTxt->setText("120");
    refundPointTxt->setFixedWidth(50);
    grid->addWidget(refundPointTxt,0,1,1,1);


    heroTitle = new QLabel("Heroes Class", this);
    grid->addWidget(heroTitle, 0, 2, 1, 1);

    comboHeroClass = new QComboBox();
    grid->addWidget(comboHeroClass, 0,3,1,1);
    QObject::connect(comboHeroClass, SIGNAL(currentIndexChanged(int)),this, SLOT(handleHeroChange(int)));

    //populate comboheroclass
    std::vector<Character> characterList;
    DataPopulater data;
    data.populateCharacters("modal/Skilltree.txt", characterList);
    for(Character c:characterList){
        QString heroName = QString::fromStdString(c.get_classType());
        comboHeroClass->addItem(heroName);
    }
    comboHeroClass->setCurrentIndex(1);
    heroIndex = 1;
    desTitle = new QLabel("Destionation Skill", this);
    grid->addWidget(desTitle, 0, 5, 1, 1);


    comboSkill = new QComboBox();

    std::vector<Image> all_image;
    data.populateImage("modal/Skilltree.txt",all_image);
    data.populateSkills("modal/Skilltree.txt", skillList,s,all_image);
    for(Node skill:skillList){
        QString readId = QString::number(skill.get_real_id());
        //QString readId2 = QString::fromStdString(skill.get_image().get_image_name());
        comboSkill->addItem(readId);
    }
    grid->addWidget(comboSkill, 0,4,1,1);
    QObject::connect(comboSkill, SIGNAL(currentIndexChanged(int)),this, SLOT(handleSkillChange(int)));


    shortestButton = new QPushButton("Go");
    grid->addWidget(shortestButton, 0,5,1,1);
    QObject::connect(shortestButton, SIGNAL(clicked()), this, SLOT(handleGoButton()));

    this->addTab(shortestPathTab, "Shortest Path");


   // Custome Shortestpath Tab
//    customShortestTab = new QWidget(this);
//    cusGrid = new QGridLayout(this);
//    customShortestTab->setLayout(cusGrid);
//    initialNodeLabel = new QLabel("Initial Node",this);
//    initialNode = new QComboBox(this);

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

    //populate comboheroclass
    DataPopulater data;
    data.populateCharacters("modal/Skilltree.txt", characterList);


    if(index == 1){
        Character character = characterList.at(1);
        heroPanel->changeAvatar("img/Witch_avatar.png");
        heroPanel->changeStr(character.getStr());
        heroPanel->changeDex(character.getDex());
        heroPanel->changeIntel(character.getInt());
        QString heroName = QString::fromStdString(character.get_classType());
        heroPanel->changeHeroName(heroName);
        heroPanel->updateGui();
    }else if(index == 0){
        Character character = characterList.at(0);
        heroPanel->changeAvatar("img/marauder-large.png");
        heroPanel->changeStr(character.getStr());
        heroPanel->changeDex(character.getDex());
        heroPanel->changeIntel(character.getInt());
        QString heroName = QString::fromStdString(character.get_classType());
        heroPanel->changeHeroName(heroName);
        heroPanel->updateGui();
    }else if(index == 2){
        Character character = characterList.at(2);
        heroPanel->changeAvatar("img/scion-large.png");
        heroPanel->changeStr(character.getStr());
        heroPanel->changeDex(character.getDex());
        heroPanel->changeIntel(character.getInt());
        QString heroName = QString::fromStdString(character.get_classType());
        heroPanel->changeHeroName(heroName);
        heroPanel->updateGui();
    }else if(index == 3){
        Character character = characterList.at(3);
        heroPanel->changeAvatar("img/Ranger_avatar.png");
        heroPanel->changeStr(character.getStr());
        heroPanel->changeDex(character.getDex());
        heroPanel->changeIntel(character.getInt());
        QString heroName = QString::fromStdString(character.get_classType());
        heroPanel->changeHeroName(heroName);
        heroPanel->updateGui();
    }else if(index == 4){
        Character character = characterList.at(4);
        heroPanel->changeAvatar("img/duelist-large.png");
        heroPanel->changeStr(character.getStr());
        heroPanel->changeDex(character.getDex());
        heroPanel->changeIntel(character.getInt());
        QString heroName = QString::fromStdString(character.get_classType());
        heroPanel->changeHeroName(heroName);
        heroPanel->updateGui();
    }else if(index == 5){
        Character character = characterList.at(5);
        heroPanel->changeAvatar("img/Shadow_avatar.png");
        heroPanel->changeStr(character.getStr());
        heroPanel->changeDex(character.getDex());
        heroPanel->changeIntel(character.getInt());
        QString heroName = QString::fromStdString(character.get_classType());
        heroPanel->changeHeroName(heroName);
        heroPanel->updateGui();
    }else if(index == 6){
        Character character = characterList.at(6);
        heroPanel->changeAvatar("img/templar-large.png");
        heroPanel->changeStr(character.getStr());
        heroPanel->changeDex(character.getDex());
        heroPanel->changeIntel(character.getInt());
        QString heroName = QString::fromStdString(character.get_classType());
        heroPanel->changeHeroName(heroName);
        heroPanel->updateGui();
    }
    heroIndex = index;
}

void CenterControl::handleSkillChange(int index){
    progressBar->reset();
    sceneCenter->clear();
\
    Node Skill = skillList.at(index);
    skillPanel2->changeSecondImg(Skill.get_image().get_width(),Skill.get_image().get_height());
    QString skillId = QString::number(Skill.get_real_id());
    skillPanel2->changeSecondName(skillId);
    QString skillDes = QString::fromStdString(Skill.get_description());
    skillPanel2->changeSecondDes(skillDes);
    skillPanel2->updateGui();

}

void CenterControl::handleGoButton(){

    //reset state
    progressBar->reset();
    sceneCenter->clear();

    //tool for drawing
    QBrush redBrush(Qt::NoBrush);
    QPen blackpen(Qt::yellow);
    blackpen.setWidth(7);

    QPixmap myImage("img/imgSrc.jpg");
        int xCor = 0;
        int yCor = 0;
    //add first node skill to user Skill list
     int class_input = atoi(characterList.at(heroIndex).get_charID().c_str());
     int initialNode = characterList.at(heroIndex).get_starting_pos();
     user_tree.push_back(initialNode);

     //start shortest path
     Node desNode = skillList.at(comboSkill->currentIndex());
     int desNodeID = desNode.get_real_id();

     //get point to go
     int max = refundPointTxt->text().toInt();
     //checking refund point
     QMessageBox msgBox(this);
     if(max< 0||max ==0){
        msgBox.setText("You're out of refund point. Go kill some beasts to get more!");
        msgBox.exec();
        return;
     }
     int new_node_start=CenterControl::get_new_pos(desNodeID,max);
     if(new_node_start!=-1){
          s.dijkstra(return_count_id_from_real_id(skillList,new_node_start )) ;
          s.printPath( return_count_id_from_real_id(skillList,desNodeID) , skillList, user_tree);
          qDebug() << user_tree.size();
          progressBar->setMaximum(user_tree.size()-1);
          progressBar->setMinimum(0);

          //change initial skill panel
          std::vector<int>::iterator initialSkillId = user_tree.begin()+1;
          Node initialSKill = Node::nullNode;
          for(Node skill:skillList){
              if(skill.get_real_id() == *initialSkillId){
                  initialSKill = skill;
              }
          }


          //draw the initial node
          int imgW = initialSKill.get_image().get_width();
          int imgH = initialSKill.get_image().get_height();
          int imgX = initialSKill.get_image().get_x();
          int imgY = initialSKill.get_image().get_y();
          skillPanel1->changeFirstImg(imgX, imgY, imgW, imgH);
          QString skillId = QString::number(initialSKill.get_real_id());
          skillPanel1->changeFirstName(skillId);
          QString skillDes = QString::fromStdString(initialSKill.get_description());
          skillPanel1->changeFirstDes(skillDes);
          skillPanel1->updateGui();


          int counter = 0;
          for (std::vector<int>::iterator i = user_tree.begin(); i != user_tree.end(); ++i)
          {
              counter++;
              max--;
              refundPointTxt->setText(QString::number(max));
              refundPointTxt->update();
              progressBar->setValue(counter);
              Node target = Node::nullNode;
              for(Node skill:skillList){
                  if(skill.get_real_id() == *i){
                      target = skill;
                  }
              }
              //draw the node above
              int imgW = target.get_image().get_width();
              int imgH = target.get_image().get_height();
              int imgX = target.get_image().get_x();
              int imgY = target.get_image().get_y();
              QPixmap skillPix = myImage.copy(imgX,imgY ,imgW ,imgH);
              QGraphicsPixmapItem* skillItem = sceneCenter->addPixmap(skillPix);
              skillItem->setPos(xCor, yCor);
              QGraphicsEllipseItem *ellipse;
              ellipse = sceneCenter->addEllipse(xCor-4,yCor-4,imgW+7,imgH+7,blackpen,redBrush);
              QGraphicsTextItem *skillId;
              skillId = sceneCenter->addText(QString::number(target.get_real_id()));
              skillId->setPos(xCor-4, yCor+skillPix.height());
              xCor = xCor + 70;
              if(counter == 7 || counter%7==0){
                 xCor = 0;
                 yCor +=70;
               }
          }


          //get total effect of all skill
          QString totalEffect;
          user_node_description(user_stas,skillList,user_tree);
          for (std::vector<string>::iterator i = user_stas.begin()+1; i != user_stas.end(); ++i)
          {
              QString temp = QString::fromStdString(*i);
              temp.append('\n');
              totalEffect.append(temp);
          }
          desPanel->changeDes(totalEffect);

              cout<<"\n";
              cout<<max<<" node remain   \n";
          }else{
              cout<<"More than allow"<<max<<" node remain\n";
          }
}


//this method used to check all the path from all selected node to new destination node
int CenterControl::get_new_pos(int desNode,int& max_node){
    MAP squares_map;
    for (std::vector<int>::iterator i = user_tree.begin(); i != user_tree.end(); ++i)
    {	int total_dis=0;
        s.dijkstra(return_count_id_from_real_id(skillList,(*i) ) );
        s.printPath( return_count_id_from_real_id(skillList,desNode) , skillList,total_dis);
        squares_map.insert( PAIR(total_dis, (*i)) );
    }
    if (!squares_map.empty())
    {
        MAP::iterator it_min = squares_map.begin();

        MAP::iterator it_max = squares_map.end();  // points to just past last element
        --it_max;          // points to last element
        if( max_node - it_min->first <0  ){
            return -1;
        }else{
        max_node-= (it_min->first-1);

            return it_min->second;
        }
    }
    return -1;

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

    delete writeTab;
    delete grid2;
    delete desUrl;
    delete fileName;
    delete urlLabel;
    delete fileLabel;

//    delete customShortestTab;
//    delete cusGrid;
//    delete cusShortestButton;
//    delete initialNodeLabel;
//    delete initialNode;
}



