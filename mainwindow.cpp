#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QCheckBox>

// Конструктор
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Подключаем кнопку расчета
    connect(ui->calculateButton, &QPushButton::clicked, this, &MainWindow::calculateArea);

    // Подключаем кнопку настроек
    connect(ui->settingsButton, &QPushButton::clicked, this, &MainWindow::showSettingsDialog);
}

// Деструктор
MainWindow::~MainWindow()
{
    delete ui;
}

// Метод для расчета площади выбранной фигуры
void MainWindow::calculateArea()
{
    qreal result = 0;
    QString shape = ui->shapeComboBox->currentText();

    // Определяем, какая фигура выбрана, и рассчитываем площадь
    if (shape == "Square")
    {
        qreal side = ui->lineEdit1->text().toDouble();
        if (side <= 0)
        {
            displayError("Side length must be greater than 0.");
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
            displayError("Width and height must be greater than 0.");
            return;
        }
        result = calculateRectangleArea(width, height);
    }
    else if (shape == "Circle")
    {
        qreal radius = ui->lineEdit1->text().toDouble();
        if (radius <= 0)
        {
            displayError("Radius must be greater than 0.");
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
            displayError("Base and height must be greater than 0.");
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
            displayError("Bases and height must be greater than 0.");
            return;
        }
        result = calculateTrapezoidArea(base1, base2, height);
    }

    ui->resultLabel->setText(QString::number(result)); // Отображаем результат
}

// Метод для отображения диалога настроек
void MainWindow::showSettingsDialog()
{
    QDialog settingsDialog(this); // Создаем диалог настроек
    settingsDialog.setWindowTitle("Settings");
    QVBoxLayout *layout = new QVBoxLayout(&settingsDialog);

    QCheckBox *checkBox = new QCheckBox("Save results to file", &settingsDialog);
    layout->addWidget(checkBox);

    QPushButton *okButton = new QPushButton("OK", &settingsDialog);
    layout->addWidget(okButton);

    connect(okButton, &QPushButton::clicked, &settingsDialog, &QDialog::accept);

    if (settingsDialog.exec() == QDialog::Accepted)
    {
        // Обрабатываем настройки
    }
}

// Методы для расчета площади фигур
qreal MainWindow::calculateSquareArea(qreal side)
{
    return side * side;
}

qreal MainWindow::calculateRectangleArea(qreal width, qreal height)
{
    return width * height;
}

qreal MainWindow::calculateCircleArea(qreal radius)
{
    return 3.14159 * radius * radius;
}

qreal MainWindow::calculateTriangleArea(qreal base, qreal height)
{
    return 0.5 * base * height;
}

qreal MainWindow::calculateTrapezoidArea(qreal base1, qreal base2, qreal height)
{
    return 0.5 * (base1 + base2) * height;
}

// Метод для отображения ошибки
void MainWindow::displayError(const QString &message)
{
    QMessageBox::critical(this, "Error", message);
}
