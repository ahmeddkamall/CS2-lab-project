#include "mainwindow.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    btnSchedule = new QPushButton("Schedule Appointment", this);
    btnViewRecords = new QPushButton("View Medical Records", this);
    btnSendMessage = new QPushButton("Send Message", this);
    dateEdit = new QDateEdit(this);
    textRecords = new QTextEdit(this);
    textMessage = new QTextEdit(this);
    editPatientID = new QLineEdit(this);
    editPatientID->setPlaceholderText("Enter Patient ID");

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    layout->addWidget(editPatientID);
    layout->addWidget(dateEdit);
    layout->addWidget(btnSchedule);
    layout->addWidget(btnViewRecords);
    layout->addWidget(textRecords);
    layout->addWidget(textMessage);
    layout->addWidget(btnSendMessage);

    connect(btnSchedule, &QPushButton::clicked, this, &MainWindow::scheduleAppointment);
    connect(btnViewRecords, &QPushButton::clicked, this, &MainWindow::viewRecords);
    connect(btnSendMessage, &QPushButton::clicked, this, &MainWindow::sendMessage);
}

MainWindow::~MainWindow()
{
}

void MainWindow::scheduleAppointment()
{
    QMessageBox::information(this, "Appointment Scheduled", "Your appointment has been scheduled for: " + dateEdit->date().toString());
}

void MainWindow::viewRecords()
{
    // Simulate fetching records for a specific patient ID
    QString patientID = editPatientID->text();
    if (patientID.isEmpty()) {
        QMessageBox::warning(this, "No Patient ID", "Please enter a valid Patient ID.");
        return;
    }
    // Example data - replace with actual data retrieval logic
    textRecords->setText("Medical Record for Patient ID: " + patientID + "\n\nTreatment History: XYZ");
}

void MainWindow::sendMessage()
{
    // Example message sending
    QMessageBox::information(this, "Message Sent", "Your message has been sent: " + textMessage->toPlainText());
}
