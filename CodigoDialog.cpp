#include "CodigoDialog.h"
#include "ui_CodigoDialog.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

CodigoDialog::CodigoDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CodigoDialog)
{
    ui->setupUi(this);
    ui->pointSizeSpinBox->setMinimum(1);
    ui->pointSizeSpinBox->setMaximum(72);
    ui->pointSizeSpinBox->setValue(14);
    ui->textEdit->setReadOnly(true);
    setWindowFlags(windowFlags() | Qt::WindowMinMaxButtonsHint);
    muestraCodigo();
}

CodigoDialog::~CodigoDialog()
{
    delete ui;
}

void CodigoDialog::on_pointSizeSpinBox_valueChanged(int arg1)
{
    muestraCodigo(arg1);
}

void CodigoDialog::muestraCodigo(int pointSize)
{
    QFile file(":/codigo.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream x(&file);
    auto html = x.readAll();
    html.replace("TRIUNFO", QString::number(pointSize));
    ui->textEdit->setHtml(html);
}
