#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

#include "sockettcpru.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_ButtonProcurar_clicked();

    void on_ButtonSearch_clicked();

    void on_ButtonSalvar_clicked();

    void on_ButtonDeletar_clicked();

    void on_ButtonSalvar_2_clicked();

    void on_radioMovel_clicked();

    void on_radioCartao_clicked();

private:
    Ui::MainWindow *ui;
    SocketTcpRU socket;
    AlunoServer aluno;
};

#endif // MAINWINDOW_H
