#ifndef CENTERCONTROL_H
#define CENTERCONTROL_H

#include <QTabWidget>
#include <QComboBox>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QWidget>
#include <heropanel.h>
#include <skillpanel.h>
#include <QPoint>
#include <QPixmap>
#include "herodescription.h"
#include "skillpanel2.h"
#include <QProgressBar>
#include <QGraphicsScene>
#include <QLineEdit>
#include <QMessageBox>
#include "modal/DataPopulater.h"
#include "modal/Charater.h"
#include "modal/Class.h"
#include "modal/Shortest.h"

class CenterControl : public QTabWidget
{
    Q_OBJECT
    HeroPanel* heroPanel;
    HeroDescription* desPanel;
    SkillPanel* skillPanel1;
    SkillPanel2* skillPanel2;
    QGraphicsScene* sceneCenter;

    QComboBox *comboHeroClass;
    QComboBox *comboSkill;
    QProgressBar* progressBar;
    QPushButton* shortestButton;
    QWidget* shortestPathTab;
    QLabel *heroTitle;
    QLabel *desTitle;
     QLineEdit* refundPointTxt;

    //Custom Shortest Path
    QWidget* customShortestTab;
    QGridLayout* cusGrid;
    QPushButton* cusShortestButton;
    QLabel* initialNodeLabel;
    QComboBox* initialNode;
std::vector<Node> skillList;
std::vector<string> user_stas;
std::vector<int> user_tree;
Shortest s;
std::vector<Character> characterList;
typedef std::map<int,int>  MAP;
typedef std::pair<int,int> PAIR;
int heroIndex;

    QWidget* writeTab;
    QGridLayout* grid2;
    QLineEdit* desUrl;
    QLineEdit* fileName;
    QPushButton* writeButton;
    QLabel* urlLabel;
    QLabel* fileLabel;
public:
    CenterControl(QWidget *parent = 0, HeroPanel* heroPanel=0, HeroDescription* desPanel=0, SkillPanel* skillPanel1=0, SkillPanel2* skillPanel2=0, QGraphicsScene* sceneCenter=0,QProgressBar* progressBar=0);
    ~CenterControl();
    void buildGui();
    int get_new_pos(int desNode,int& max_node);
signals:

public slots:
    void handleHeroChange(int);
    void handleSkillChange(int);
    void handleGoButton();
    void handleWriteButton();
};

#endif // CENTERCONTROL_H
