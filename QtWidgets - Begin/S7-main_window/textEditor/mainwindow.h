#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QLabel>
#include <QStatusBar>
#include <QDebug>
#include <QListWidgetItem>
#include <QScopedPointer>
#include "dialog.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void newFile();
    void openFile();
    void saveFile();
    void saveFileAs();
    void selectNone();

    void on_actionToolbar_Top_triggered();

    void on_actionToolbar_Bottom_triggered();

    void on_actionToolbar_Left_triggered();

    void on_actionToolbar_Right_triggered();

    void on_actionToolbar_Floatable_toggled(bool arg1);

    void on_actionToolbar_Moveable_toggled(bool arg1);

    void on_plainTextEdit_textChanged();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_actionAnimals_triggered();

    void on_actionShapes_triggered();

    void on_actionFoods_triggered();

private:
    Ui::MainWindow *ui;

    QString m_filename;
    bool m_saved;

    void setupStatusbar();
    void updateStatus (QString message);
};
#endif // MAINWINDOW_H
