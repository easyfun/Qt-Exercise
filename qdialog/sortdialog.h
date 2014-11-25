#ifndef SORTDIALOG_H
#define SORTDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
class QGroupBox;
class QLabel;
class QLineEdit;
class QPushButton;
QT_END_NAMESPACE

class SortDialog : public QDialog
{
    Q_OBJECT

public:
    SortDialog(QWidget *parent = 0);
    ~SortDialog();

private slots:
    void setGroupboxTwoVisible();

private:
    QGroupBox* groupOne;
    QLabel* labelLine1;
    QLabel* labelLine2;
    QLineEdit* textLine1;
    QLineEdit* textLine2;

    QGroupBox* groupTwo;
    QLabel* label2Line1;
    QLabel* label2Line2;
    QLineEdit* text2Line1;
    QLineEdit* text2Line2;

    QPushButton* buttonOK;
    QPushButton* buttonCancel;
    QPushButton* buttonMore;

};

#endif // SORTDIALOG_H
