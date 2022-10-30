#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QComboBox>
#include <QHBoxLayout>
#include <QPushButton>
#include <QList>
#include <QDebug>

#include <QGraphicsView>
#include <QGraphicsScene>

#include "square.h"
#include "god.h"
#include "text.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct NODE {
    int type;
    SQUARE * square;
    GOD * god;
    TEXT * text;
};

class MainWindow : public QMainWindow {
    Q_OBJECT

    QWidget * centralwidget;

    QGridLayout * gridLayout;

    QVBoxLayout * verticalLayoutLeft;

    QHBoxLayout * horizontalLayoutText;
    QLabel * labelText;
    QLineEdit * lineEdit;

    QHBoxLayout * horizontalLayoutSquare;
    QLabel * labelSquare;
    QComboBox * comboBoxSquare;

    QHBoxLayout * horizontalLayoutGod;
    QLabel * labelGod;
    QComboBox * comboBoxGod;

    QHBoxLayout *horizontalLayoutButton1;
    QPushButton *addText;
    QPushButton *addSquare;

    QHBoxLayout *horizontalLayoutButton2;
    QPushButton *addGod;
    QPushButton *deleteObject;

    QListWidget * listWidget;

    QGraphicsScene * scene;
    QGraphicsView * graphicView;

    QStatusBar * statusbar;

public:
    MainWindow(QWidget * parent = nullptr);
    ~MainWindow();

private slots:
    void addSquare_clicked();
    void addGod_clicked();
    void addText_clicked();
    void deleteObject_clicked();

    void comboBoxGod_activated();
    void comboBoxSquare_activated();
    void lineEdit_textEdited();

    void scene_selectionChanged();
    void listWidget_itemClicked();

private:
    QList <NODE> objectList;
    QStringList stringList;

    int lastIndex;

    Ui::MainWindow * ui;

    void clearWidgetList();
    void viewWidgetList();
};

#endif // MAINWINDOW_H
