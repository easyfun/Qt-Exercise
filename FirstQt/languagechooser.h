#ifndef LANGUAGECHOOSER_H
#define LANGUAGECHOOSER_H

#include <QDialog>
#include <QMap>
#include <QStringList>

QT_BEGIN_NAMESPACE
class QAbstractButton;
class QCheckBox;
class QDialogButtonBox;
class QGroupBox;
QT_END_NAMESPACE
class MainWindow;


class LanguageChooser : public QDialog
{
    Q_OBJECT
public:
    explicit LanguageChooser(QWidget *parent = 0);

signals:

public slots:
    void checkBoxToggled();
    void showAll();
    void hideAll();

protected:
    bool eventFilter(QObject *object, QEvent *event);
    void closeEvent(QCloseEvent *event);

private:
    QStringList findQmFiles();
    QString languageName(const QString& qmFile);
    QColor colorForLanguage(const QString& language);

private:
    QGroupBox* groupBox;
    QDialogButtonBox *buttonBox;
    QAbstractButton* showAllButton;
    QAbstractButton* hideAllButton;
    QMap<QCheckBox*, QString> qmFileForCheckBoxMap;
    QMap<QCheckBox*, MainWindow*> mainWindowForCheckBoxMap;
};

#endif // LANGUAGECHOOSER_H
