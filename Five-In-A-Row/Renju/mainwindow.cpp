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
            drawChess(i, j, game->getChess(i, j));
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
    //for (int s = 0; s < 8; s++)
    //    qDebug() << game->rate(x, y, s, 1) << game->rate(x, y, s, 0);
    //    qDebug() << game->status[x][y][s][1] << game->status[x][y][s][0];
    qDebug() << endl;
    qDebug() << game->score[x][y][1] << game->score[x][y][0];
    qDebug() << endl;
    if (game->getChess(x, y)) return;
    if (game->curType == 1)
    {
        if (event->buttons() == Qt::LeftButton)
        {
            game->curX = x;
            game->curY = y;
            game->placeChess();
            //game->AIdecide();
        }
    }
    update();
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    int isWin = game->validateWin();
    if (isWin)
    {
        gameRunning = 0;
        if (isWin == 1) QMessageBox::information(nullptr, "Title", "WHITE WINS!!!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        else QMessageBox::information(nullptr, "Title", "RED WINS!!!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    if (!gameRunning) return;
    Q_UNUSED(event);
    this->resize(QSize(W_WIDTH, W_HEIGHT));
    this->drawBoard();

    if (game->curType == 0)
    {
        game->AIdecide();
    }

    int x = (curPoint.x() - MARGIN + GAP / 2) / GAP;
    int y = (curPoint.y() - MARGIN + GAP / 2) / GAP;
    if (x < 0 || y < 0 || x >= BOARD_SIZE || y >= BOARD_SIZE) return;
    if (game->getChess(x, y)) return;

    QPainter painter(this);

    painter.setBrush(Qt::white);
    painter.drawRect(MARGIN + x*GAP - 4, MARGIN + y*GAP - 4, 8, 8);

    update();
}
