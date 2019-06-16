#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <windows.h>
#include <QMessageBox>
#include <QPainter>
#include <QDebug>
#include <QPoint>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setMouseTracking(true);
    this->centralWidget()->setMouseTracking(true);
    gameRunning = 1;
    clicked = 0;
    game = new Game();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete game;
}

void MainWindow::drawChess(int x, int y, int type)
{
    QPainter painter(this);
    if (type == 0) return;
    painter.setBrush(Qt::black);
    int centreX = MARGIN + x*GAP - RADIUS;
    int centreY = MARGIN + y*GAP - RADIUS;
    painter.drawEllipse(centreX, centreY, RADIUS*2, RADIUS*2);
    if (type == 1)
    {
        painter.setPen(whiteChess);
        painter.drawEllipse(centreX, centreY, RADIUS*2, RADIUS*2);
    }
    else if (type == 2)
    {
        painter.setPen(blackChess);
        painter.drawEllipse(centreX, centreY, RADIUS*2, RADIUS*2);
    }
}

void MainWindow::drawBoard()
{
    QPainter painter(this);

    painter.setBrush(Qt::black);
    painter.drawRect(0, 0, W_WIDTH, W_HEIGHT);

    QPen line(Qt::darkCyan, 2, Qt::SolidLine);
    painter.setPen(line);

    painter.drawRect(MARGIN - 20, MARGIN - 20, W_HEIGHT - 2*MARGIN + 30, W_HEIGHT - 2*MARGIN + 30);
    for (int i = 0; i < BOARD_SIZE - 1; i++)
        for (int j = 0; j < BOARD_SIZE - 1; j++)
            painter.drawRect(MARGIN + i*GAP, MARGIN + j*GAP, GAP, GAP);

    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            drawChess(i, j, game->bd->getChess(i, j));

}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (!gameRunning) return;
    curPoint = event->pos();
    update();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (!gameRunning) return;
    curPoint = event->pos();
    int x = (curPoint.x() - MARGIN + GAP / 2) / GAP;
    int y = (curPoint.y() - MARGIN + GAP / 2) / GAP;
    if (x < 0 || y < 0 || x >= BOARD_SIZE || y >= BOARD_SIZE) return;
    for (int i = 0; i < 8; i++) qDebug("%d ", game->bd->status[x][y][i]);
    qDebug() << endl;
    qDebug("%d %d\n", game->bd->score[x][y][1], game->bd->score[x][y][0]);
    if (game->bd->getChess(x, y)) return;

    if (gameRunning)
    {
        if (event->buttons() == Qt::LeftButton)
        {
            game->curX = x;
            game->curY = y;
            clicked = 1;
        }
    }
    update();
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    int isWin = game->checkWin();
    if (isWin)
    {
        gameRunning = 0;
        if (isWin == WHITE_CHESS)
        {
            QMessageBox::information(nullptr,
                                     "Victory",
                                     "WHITE WINS!!!",
                                     QMessageBox::Yes,
                                     QMessageBox::Yes);
        }
        else
        {
            QMessageBox::information(nullptr,
                                     "Lose",
                                     "RED WINS!!!",
                                     QMessageBox::Yes,
                                     QMessageBox::Yes);
        }
    }
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    this->resize(QSize(W_WIDTH, W_HEIGHT));
    if (clicked)
    {
        game->nextMove();
        game->nextMove();
        clicked = 0;
    }
    this->drawBoard();


    if (!gameRunning) return;

    int x = (curPoint.x() - MARGIN + GAP / 2) / GAP;
    int y = (curPoint.y() - MARGIN + GAP / 2) / GAP;
    if (x < 0 || y < 0 || x >= BOARD_SIZE || y >= BOARD_SIZE) return;
    if (game->bd->getChess(x, y)) return;

    QPainter painter(this);

    painter.setBrush(Qt::white);
    painter.drawRect(MARGIN + x*GAP - 4, MARGIN + y*GAP - 4, 8, 8);

    update();
}
