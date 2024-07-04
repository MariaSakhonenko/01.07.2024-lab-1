#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void calculateArea(); // Слот для вычисления площади
    void showSettingsDialog(); // Слот для отображения диалогового окна настроек
    void openFile(); // Слот для открытия файла
    void saveFile(); // Слот для сохранения файла
    void showAboutDialog(); // Слот для отображения диалогового окна "О программе"

private:
    Ui::MainWindow *ui;
    qreal calculateSquareArea(qreal side); // Функция вычисления площади квадрата
    qreal calculateRectangleArea(qreal width, qreal height); // Функция вычисления площади прямоугольника
    qreal calculateCircleArea(qreal radius);  // Функция вычисления площади круга
    qreal calculateTriangleArea(qreal base, qreal height); // Функция вычисления площади треугольника
    qreal calculateTrapezoidArea(qreal base1, qreal base2, qreal height); // Функция вычисления площади трапеции
    void displayError(const QString &message); // Функция отображения ошибки
};

#endif // MAINWINDOW_H
