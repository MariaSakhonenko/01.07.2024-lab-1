#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QCheckBox>

// Конструктор класса MainWindow
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Подключение кнопки вычисления площади
    connect(ui->calculateButton, &QPushButton::clicked, this, &MainWindow::calculateArea);

    // Подключение кнопки настроек
    connect(ui->settingsButton, &QPushButton::clicked, this, &MainWindow::showSettingsDialog);

    // Подключение действий меню
    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::openFile);
    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::saveFile);
    connect(ui->actionExit, &QAction::triggered, this, &MainWindow::close);
    connect(ui->actionAbout, &QAction::triggered, this, &MainWindow::showAboutDialog);
}

// Деструктор класса MainWindow
MainWindow::~MainWindow()
{
    delete ui;
}

// Функция вычисления площади
void MainWindow::calculateArea()
{
    qreal result = 0;
    QString shape = ui->shapeComboBox->currentText();

    if (shape == "Square")
    {
        qreal side = ui->lineEdit1->text().toDouble();
        if (side <= 0)
        {
            displayError("Error! 0");
            return;
        }
        result = calculateSquareArea(side);
    }
    else if (shape == "Rectangle")
    {
        qreal width = ui->lineEdit1->text().toDouble();
        qreal height = ui->lineEdit2->text().toDouble();
        if (width <= 0 || height <= 0)
        {
            displayError("Error! 0");
            return;
        }
        result = calculateRectangleArea(width, height);
    }
    else if (shape == "Circle")
    {
        qreal radius = ui->lineEdit1->text().toDouble();
        if (radius <= 0)
        {
            displayError("Error! 0");
            return;
        }
        result = calculateCircleArea(radius);
    }
    else if (shape == "Triangle")
    {
        qreal base = ui->lineEdit1->text().toDouble();
        qreal height = ui->lineEdit2->text().toDouble();
        if (base <= 0 || height <= 0)
        {
            displayError("Error! 0");
            return;
        }
        result = calculateTriangleArea(base, height);
    }
    else if (shape == "Trapezoid")
    {
        qreal base1 = ui->lineEdit1->text().toDouble();
        qreal base2 = ui->lineEdit2->text().toDouble();
        qreal height = ui->lineEdit3->text().toDouble();
        if (base1 <= 0 || base2 <= 0 || height <= 0)
        {
            displayError("Error! 0");
            return;
        }
        result = calculateTrapezoidArea(base1, base2, height);
    }

    // Отображение результата
    ui->resultLabel->setText(QString::number(result));
}

// Функция отображения диалогового окна настроек
void MainWindow::showSettingsDialog()
{
    // Создание и отображение диалогового окна настроек
    QDialog settingsDialog(this);
    settingsDialog.setWindowTitle("Settings");
    QVBoxLayout *layout = new QVBoxLayout(&settingsDialog);

    QCheckBox *checkBox = new QCheckBox("Save results to file", &settingsDialog);
    layout->addWidget(checkBox);

    QPushButton *okButton = new QPushButton("OK", &settingsDialog);
    layout->addWidget(okButton);

    connect(okButton, &QPushButton::clicked, &settingsDialog, &QDialog::accept);

    if (settingsDialog.exec() == QDialog::Accepted)
    {
        // Обработка настроек
    }
}

// Функция открытия файла
void MainWindow::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open file"), "", tr("Text files (*.txt);;All files (*)"));
    if (fileName.isEmpty())
    {    return;      }

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, tr("Error"), tr("File couldn't be opened: ") + file.errorString());
        return;
    }

    QTextStream in(&file);
    ui->lineEdit1->setText(in.readLine());
    ui->lineEdit2->setText(in.readLine());
    ui->lineEdit3->setText(in.readLine());
}

// Функция сохранения файла
void MainWindow::saveFile()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save file"), "", tr("Text files (*.txt);;All files (*)"));
    if (fileName.isEmpty())
    {    return;     }

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, tr("Error"), tr("File couldn't be saved: ") + file.errorString());
        return;
    }

    QTextStream out(&file);
    out << ui->lineEdit1->text() << "\n";
    out << ui->lineEdit2->text() << "\n";
    out << ui->lineEdit3->text() << "\n";
}

// Функция отображения диалогового окна "About program"
void MainWindow::showAboutDialog()
{
    QMessageBox::about(this, tr("About program"), tr("Area calculator\nVersion 1.0\n(c) 2024"));
}

// Функция вычисления площади квадрата
qreal MainWindow::calculateSquareArea(qreal side)
{
    return side * side;
}

// Функция вычисления площади прямоугольника
qreal MainWindow::calculateRectangleArea(qreal width, qreal height)
{
    return width * height;
}

// Функция вычисления площади круга
qreal MainWindow::calculateCircleArea(qreal radius)
{
    return 3.14159 * radius * radius;
}

// Функция вычисления площади треугольника
qreal MainWindow::calculateTriangleArea(qreal base, qreal height)
{
    return 0.5 * base * height;
}

// Функция вычисления площади трапеции
qreal MainWindow::calculateTrapezoidArea(qreal base1, qreal base2, qreal height)
{
    return 0.5 * (base1 + base2) * height;
}

// Функция отображения ошибки
void MainWindow::displayError(const QString &message)
{
    QMessageBox::critical(this, "Error!", message);
}
