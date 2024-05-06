#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QDateEdit>
#include <QTextEdit>
#include <QListView>
#include <QStringListModel>
#include <QLineEdit>
#include <QMessageBox>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void scheduleAppointment();
    void viewRecords();
    void sendMessage();

private:
    QPushButton *btnSchedule;
    QPushButton *btnViewRecords;
    QPushButton *btnSendMessage;
    QDateEdit *dateEdit;
    QTextEdit *textRecords;
    QTextEdit *textMessage;
    QLineEdit *editPatientID;
    QStringListModel *model;
};

#endif // MAINWINDOW_H
