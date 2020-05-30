#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QPainter>
#include "game.h"

const int MARGIN = 80;
const int W_WIDTH = 1000;
const int W_HEIGHT = 800;
const int GAP = (W_HEIGHT - MARGIN*2) / (BOARD_SIZE - 1);
const int RADIUS = (GAP - 10) / 2;

const QPen whiteChess(Qt::darkGray, 3, Qt::SolidLine);
const QPen blackChess(Qt::darkRed, 3, Qt::SolidLine);

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QPoint curPoint;
    Game *game;
    bool gameRunning;
    bool clicked;
    void drawChess(int x, int y, int type);
    void drawBoard();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // MAINWINDOW_H
