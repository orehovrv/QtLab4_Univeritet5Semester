#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    centralwidget = new QWidget(this);

    gridLayout = new QGridLayout(centralwidget);
    verticalLayoutLeft = new QVBoxLayout(centralwidget);

    horizontalLayoutText = new QHBoxLayout(centralwidget);
    labelText = new QLabel(centralwidget);
    labelText->setMinimumSize(QSize(80, 0));
    labelText->setMaximumSize(QSize(80, 16777215));
    labelText->setText("Текст");
    lineEdit = new QLineEdit(centralwidget);
    horizontalLayoutText->addWidget(labelText);
    horizontalLayoutText->addWidget(lineEdit);
    verticalLayoutLeft->addLayout(horizontalLayoutText);

    horizontalLayoutSquare = new QHBoxLayout(centralwidget);
    labelSquare = new QLabel(centralwidget);
    labelSquare->setMinimumSize(QSize(80, 0));
    labelSquare->setMaximumSize(QSize(80, 16777215));
    labelSquare->setText("Цвет квадрата");
    comboBoxSquare = new QComboBox(centralwidget);
    comboBoxSquare->addItem("Синий кадетский");
    comboBoxSquare->addItem("Темный лосось");
    comboBoxSquare->addItem("Помидор");
    horizontalLayoutSquare->addWidget(labelSquare);
    horizontalLayoutSquare->addWidget(comboBoxSquare);
    verticalLayoutLeft->addLayout(horizontalLayoutSquare);

    horizontalLayoutGod = new QHBoxLayout(centralwidget);
    labelGod = new QLabel(centralwidget);
    labelGod->setMinimumSize(QSize(80, 0));
    labelGod->setMaximumSize(QSize(80, 16777215));
    labelGod->setText("Бог");
    comboBoxGod = new QComboBox(centralwidget);
    comboBoxGod->addItem("Зевс");
    comboBoxGod->addItem("Посейдон");
    comboBoxGod->addItem("Аид");
    horizontalLayoutGod->addWidget(labelGod);
    horizontalLayoutGod->addWidget(comboBoxGod);
    verticalLayoutLeft->addLayout(horizontalLayoutGod);

    horizontalLayoutButton1 = new QHBoxLayout(centralwidget);
    addText = new QPushButton(centralwidget);
    addText->setText("Добавить текст");
    addSquare = new QPushButton(centralwidget);
    addSquare->setText("Добавить квадрат");
    horizontalLayoutButton1->addWidget(addText);
    horizontalLayoutButton1->addWidget(addSquare);
    verticalLayoutLeft->addLayout(horizontalLayoutButton1);

    horizontalLayoutButton2 = new QHBoxLayout(centralwidget);
    addGod = new QPushButton(centralwidget);
    addGod->setText("Добавить бога");
    deleteObject = new QPushButton(centralwidget);
    deleteObject->setText("Удалить объект");
    horizontalLayoutButton2->addWidget(addGod);
    horizontalLayoutButton2->addWidget(deleteObject);
    verticalLayoutLeft->addLayout(horizontalLayoutButton2);

    listWidget = new QListWidget(centralwidget);
    verticalLayoutLeft->addWidget(listWidget);

    scene = new QGraphicsScene(centralwidget);
    scene->setSceneRect(0, 0, 550, 550);
    graphicView = new QGraphicsView(centralwidget);
    graphicView->sceneRect();
    graphicView->setScene(scene);
    graphicView->setRenderHint(QPainter::Antialiasing);
    graphicView->setCacheMode(QGraphicsView::CacheBackground);
    graphicView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    gridLayout->addLayout(verticalLayoutLeft, 1, 0, 1, 1);
    gridLayout->addWidget(graphicView, 1, 1, 1, 1);
    gridLayout->setColumnStretch(0, 2);
    gridLayout->setColumnStretch(1, 5);

    statusbar = new QStatusBar(this);

    this->setMinimumSize(QSize(800, 600));
    this->setMaximumSize(QSize(800, 600));
    this->setCentralWidget(centralwidget);
    this->setStatusBar(statusbar);

    connect(addSquare, SIGNAL(clicked()), this, SLOT(addSquare_clicked()));
    connect(addGod, SIGNAL(clicked()), this, SLOT(addGod_clicked()));
    connect(addText, SIGNAL(clicked()), this, SLOT(addText_clicked()));
    connect(deleteObject, SIGNAL(clicked()), this, SLOT(deleteObject_clicked()));

    connect(listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(listWidget_itemClicked()));

    connect(comboBoxGod, SIGNAL(activated(int)), this, SLOT(comboBoxGod_activated()));
    connect(comboBoxSquare, SIGNAL(activated(int)), this, SLOT(comboBoxSquare_activated()));
    connect(lineEdit, SIGNAL(textEdited(const QString &)), this, SLOT(lineEdit_textEdited()));

    connect(scene, SIGNAL(selectionChanged()), this, SLOT(scene_selectionChanged()));
}

MainWindow::~MainWindow() {
    delete ui;

    for(int i = 0; i < objectList.count(); i++)
        switch(objectList.at(i).type) {
            case 0:
                delete(objectList.at(i).text);
                break;

            case 1:
                delete(objectList.at(i).square);
                break;

            case 2:
                delete(objectList.at(i).god);
                break;
        }
}

void MainWindow::clearWidgetList() {
    listWidget->clear();
}

void MainWindow::viewWidgetList() {
    clearWidgetList();
    listWidget->addItems(stringList);
    if(lastIndex > -1 && lastIndex < stringList.count()) listWidget->setCurrentRow(lastIndex);
}

void MainWindow::addText_clicked() {
    TEXT * temp = new TEXT();

    QString tempStr = lineEdit->text();
    if(tempStr.isEmpty()) return;

    temp->setStr(tempStr);
    scene->addItem(temp);

    NODE node;

    node.type = 0;
    node.text = temp;

    objectList.append(node);
    stringList.append(tempStr);

    lastIndex = -1;
    viewWidgetList();
}

void MainWindow::addSquare_clicked() {
    SQUARE * temp = new SQUARE();

    temp->setColor(comboBoxSquare->currentIndex());
    scene->addItem(temp);

    NODE node;

    node.type = 1;
    node.square = temp;

    objectList.append(node);

    switch(comboBoxSquare->currentIndex()) {
        case 0:
            stringList.append("Cadet blue square");
            break;

        case 1:
            stringList.append("Dark salmon square");
            break;

        case 2:
            stringList.append("Tomato color square");
            break;
    }

    lastIndex = -1;
    viewWidgetList();
}

void MainWindow::addGod_clicked() {
    GOD * temp = new GOD();

    temp->setColor(comboBoxGod->currentIndex());
    scene->addItem(temp);

    NODE node;

    node.type = 2;
    node.god = temp;

    objectList.append(node);

    switch(comboBoxGod->currentIndex()) {
        case 0:
            stringList.append("Zeus");
            break;

        case 1:
            stringList.append("Poseidon");
            break;

        case 2:
            stringList.append("Hades");
            break;
    }

    lastIndex = -1;
    viewWidgetList();
}

void MainWindow::deleteObject_clicked() {
    if(lastIndex < 0 || lastIndex >= listWidget->count()) return;

    NODE temp = objectList.takeAt(lastIndex);
    switch(temp.type) {
        case 0:
            delete(temp.text);
            break;

        case 1:
            delete(temp.square);
            break;

        case 2:
            delete(temp.god);
            break;
    }

    stringList.removeAt(lastIndex);

    lastIndex = -1;
    viewWidgetList();
}

void MainWindow::comboBoxGod_activated() {
    if(lastIndex < 0 || lastIndex >= listWidget->count()) return;

    NODE temp = objectList.at(lastIndex);
    if(temp.type != 2 || temp.god == NULL) return;

    temp.god->setColor(comboBoxGod->currentIndex());

    switch(comboBoxGod->currentIndex()) {
        case 0:
            stringList.replace(lastIndex, "Zeus");
            break;

        case 1:
            stringList.replace(lastIndex, "Poseidon");
            break;

        case 2:
            stringList.replace(lastIndex, "Hades");
            break;
    }

    objectList.replace(lastIndex, temp);

    scene->update();
    viewWidgetList();
}

void MainWindow::comboBoxSquare_activated() {
    if(lastIndex < 0 || lastIndex >= listWidget->count()) return;

    NODE temp = objectList.at(lastIndex);
    if(temp.type != 1 || temp.square == NULL) return;

    temp.square->setColor(comboBoxSquare->currentIndex());

    switch(comboBoxSquare->currentIndex()) {
        case 0:
            stringList.replace(lastIndex, "Cadet blue square");
            break;

        case 1:
            stringList.replace(lastIndex, "Dark salmon square");
            break;

        case 2:
            stringList.replace(lastIndex, "Tomato color square");
            break;
    }

    objectList.replace(lastIndex, temp);

    scene->update();
    viewWidgetList();
}

void MainWindow::lineEdit_textEdited() {
    if(lastIndex < 0 || lastIndex >= listWidget->count()) return;

    NODE temp = objectList.at(lastIndex);
    if(temp.type != 0 || temp.text == NULL) return;

    QString tempStr = lineEdit->text();
    if(tempStr.isEmpty()) return;

    temp.text->setStr(tempStr);
    stringList.replace(lastIndex, tempStr);
    objectList.replace(lastIndex, temp);

    scene->update();
    viewWidgetList();
}

void MainWindow::scene_selectionChanged() {
    QList <QGraphicsItem *> listTemp = scene->selectedItems();
    if(!listTemp.count()) return;

    NODE temp;
    int cur = 0;
    bool flagSel = 0;

    for(cur = 0; cur < objectList.count(); cur++) {
        temp = objectList.at(cur);
        switch(temp.type) {
            case 0:
                if(temp.text->isSelected()) {
                    flagSel = 1;
                    lineEdit->setText(temp.text->getStr());
                }
                break;

            case 1:
                if(temp.square->isSelected()) {
                    flagSel = 1;
                    comboBoxSquare->setCurrentIndex(temp.square->getColor());
                }
                break;

            case 2:
                if(temp.god->isSelected()) {
                    flagSel = 1;
                    comboBoxGod->setCurrentIndex(temp.god->getColor());
                }
                break;
        }

        if(flagSel) break;
    }

    lastIndex = cur;
    listWidget->setCurrentRow(cur);
}

void MainWindow::listWidget_itemClicked() {
    lastIndex = listWidget->currentRow();

    NODE temp = objectList.at(lastIndex);
    int color;
    QString str;

    switch(temp.type) {
        case 0:
            str = temp.text->getStr();
            lineEdit->setText(str);
            break;

        case 1:
            color = temp.square->getColor();
            comboBoxSquare->setCurrentIndex(color);
            break;

        case 2:
            color = temp.god->getColor();
            comboBoxGod->setCurrentIndex(color);
            break;
    }
}
