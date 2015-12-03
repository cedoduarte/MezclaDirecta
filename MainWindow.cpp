#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "CodigoDialog.h"
#include "ImagenDialog.h"
#include <QStandardItemModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mModelListaOriginal = new QStandardItemModel(this);
    mModelListaOrdenada = new QStandardItemModel(this);
    ui->listaOriginalListView->setModel(mModelListaOriginal);
    ui->listaOrdenadaListView->setModel(mModelListaOrdenada);
    ui->numeroSpinBox->setMinimum(-INT_MAX);
    ui->numeroSpinBox->setMaximum(INT_MAX);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_agregarPushButton_clicked()
{
    mModelListaOrdenada->clear();
    mModelListaOriginal->appendRow(new QStandardItem(QString::number
                                        (ui->numeroSpinBox->value())));
}

void MainWindow::on_ordenarPushButton_clicked()
{
    mModelListaOrdenada->clear();
    const int tamanyo = mModelListaOriginal->rowCount();
    QVector<int> lista(tamanyo);
    for (int ix = 0; ix < tamanyo; ++ix) {
        lista[ix] = mModelListaOriginal->item(ix, 0)->text().toInt();
    }
    mezclaDirecta(lista);
    for (int ix = 0; ix < tamanyo; ++ix) {
        mModelListaOrdenada->setItem(ix, 0, new QStandardItem
                                     (QString::number(lista[ix])));
    }
}

QVector<int> MainWindow::mezclaDirecta(QVector<int> &lista)
{
    int tamanyo = lista.size();
    if (tamanyo <= 1) {
        return lista;
    }
    int numeroElementosDer = tamanyo / 2;
    int numeroElementosIzq = tamanyo - numeroElementosDer;
    QVector<int> listaIzq(numeroElementosIzq);
    QVector<int> listaDer(numeroElementosDer);

    // copiamos los elementos a las sublistas
    int ix = 0;
    int jx = 0;
    int kx = 0;
    for (ix = 0; ix < numeroElementosIzq; ++ix) {
        listaIzq[ix] = lista[ix];
    }
    jx = 0;
    for (ix = numeroElementosIzq; ix < tamanyo; ++ix) {
        listaDer[jx] = lista[ix];
        ++jx;
    }

    // recursividad
    listaIzq = mezclaDirecta(listaIzq);
    listaDer = mezclaDirecta(listaDer);

    // ordenamiento
    ix = 0;
    jx = 0;
    kx = 0;
    while (numeroElementosIzq != jx
            && numeroElementosDer != kx) {
        if (listaIzq[jx] < listaDer[kx]) {
            lista[ix] = listaIzq[jx];
            ++ix;
            ++jx;
        } else {
            lista[ix] = listaDer[kx];
            ++ix;
            ++kx;
        }
    }

    // mezclamos lista final
    while (numeroElementosIzq != jx) {
        lista[ix] = listaIzq[jx];
        ++ix;
        ++jx;
    }
    while (numeroElementosDer != kx) {
        lista[ix] = listaDer[kx];
        ++ix;
        ++kx;
    }
    return lista;
}

void MainWindow::on_verCodigoPushButton_clicked()
{
    CodigoDialog d(this);
    d.exec();
}

void MainWindow::on_quitarAplicacionPushButton_clicked()
{
    close();
}

void MainWindow::on_verImagenPushButton_clicked()
{
    ImagenDialog d(this);
    d.exec();
}

void MainWindow::on_eliminarPushButton_clicked()
{
    const int currentRow = ui->listaOriginalListView->currentIndex().row();
    if (currentRow == -1) {
        return;
    }
    mModelListaOrdenada->clear();
    mModelListaOriginal->removeRow(currentRow);
}

void MainWindow::on_limpiarPushButton_clicked()
{
    mModelListaOrdenada->clear();
    mModelListaOriginal->clear();
}
