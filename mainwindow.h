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
    MainWindow(QWidget *parent = nullptr); // конструктор
    ~MainWindow(); // деструктор

private slots:
    void calculateArea(); // слот для вычисления площади
    void showSettingsDialog(); // слот для отображения диалога настроек

private:
    Ui::MainWindow *ui; // указатель на пользовательский интерфейс
    qreal calculateSquareArea(qreal side); // метод для расчета площади квадрата
    qreal calculateRectangleArea(qreal width, qreal height); // метод для расчета площади прямоугольника
    qreal calculateCircleArea(qreal radius); // метод для расчета площади круга
    qreal calculateTriangleArea(qreal base, qreal height); // метод для расчета площади треугольника
    qreal calculateTrapezoidArea(qreal base1, qreal base2, qreal height); // метод для расчета площади трапеции
    void displayError(const QString &message); // метод для отображения ошибки
};

#endif // MAINWINDOW_H
