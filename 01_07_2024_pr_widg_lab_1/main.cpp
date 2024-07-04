#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); // создание объекта приложения
    MainWindow w; // создание главного окна
    w.show(); // показываем главное окно
    return a.exec(); // запуск главного цикла обработки событий приложения
}
