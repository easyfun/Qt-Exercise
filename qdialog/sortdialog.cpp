#include <QtGui>
#include "sortdialog.h"

SortDialog::SortDialog(QWidget *parent)
    : QDialog(parent)
{
    groupOne = new QGroupBox(tr("Group One"));

    QGridLayout* gridLayout1 = new QGridLayout;
    labelLine1 = new QLabel(tr("line1"));
    textLine1 = new QLineEdit;
    labelLine2 = new QLabel(tr("line2"));
    textLine2 = new QLineEdit;
    gridLayout1->addWidget(labelLine1, 0, 0);
    gridLayout1->addWidget(textLine1, 0, 1);
    gridLayout1->addWidget(labelLine2, 1, 0);
    gridLayout1->addWidget(textLine2, 1, 1);
    groupOne->setLayout(gridLayout1);

    groupTwo = new QGroupBox(tr("Group Two"));

    QGridLayout* gridLayout2 = new QGridLayout;
    label2Line1 = new QLabel(tr("line1"));
    text2Line1 = new QLineEdit;
    label2Line2 = new QLabel(tr("line2"));
    text2Line2 = new QLineEdit;
    gridLayout2->addWidget(label2Line1, 0, 0);
    gridLayout2->addWidget(text2Line1, 0, 1);
    gridLayout2->addWidget(label2Line2, 1, 0);
    gridLayout2->addWidget(text2Line2, 1, 1);
    groupTwo->setLayout(gridLayout2);

    buttonOK = new QPushButton(tr("OK"));
    buttonCancel = new QPushButton(tr("Cancel"));
    buttonMore = new QPushButton(tr("More"));
    QVBoxLayout* vboxBtnLayout = new QVBoxLayout;
    vboxBtnLayout->addWidget(buttonOK);
    vboxBtnLayout->addWidget(buttonCancel);
    vboxBtnLayout->addStretch();
    vboxBtnLayout->addWidget(buttonMore);

    QGridLayout* mainGridLayout = new QGridLayout;
    mainGridLayout->addWidget(groupOne,0,0);
    mainGridLayout->addLayout(vboxBtnLayout,0,1);
    mainGridLayout->addWidget(groupTwo,1,0);
    setLayout(mainGridLayout);

//    groupTwo->hide();
    layout()->setSizeConstraint(QLayout::SetFixedSize);

    connect(buttonMore, SIGNAL(clicked()), this, SLOT(setGroupboxTwoVisible()));
}

SortDialog::~SortDialog()
{

}

void SortDialog::setGroupboxTwoVisible()
{
    if (groupTwo->isVisible())
        groupTwo->hide();
    else
        groupTwo->show();
}
