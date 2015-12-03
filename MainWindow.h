#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

namespace Ui
{
class MainWindow;
}

class QStandardItemModel;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_agregarPushButton_clicked();
    void on_ordenarPushButton_clicked();
    void on_verCodigoPushButton_clicked();

    void on_quitarAplicacionPushButton_clicked();

    void on_verImagenPushButton_clicked();

    void on_eliminarPushButton_clicked();

    void on_limpiarPushButton_clicked();

private:
    QVector<int> mezclaDirecta(QVector<int> &lista);

    Ui::MainWindow *ui;
    QStandardItemModel *mModelListaOriginal;
    QStandardItemModel *mModelListaOrdenada;
};

#endif // MAINWINDOW_H
