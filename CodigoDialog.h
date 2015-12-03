#ifndef CODIGODIALOG_H
#define CODIGODIALOG_H

#include <QDialog>

namespace Ui
{
class CodigoDialog;
}

class CodigoDialog : public QDialog
{
    Q_OBJECT
public:
    explicit CodigoDialog(QWidget *parent = nullptr);
    ~CodigoDialog();
private slots:
    void on_pointSizeSpinBox_valueChanged(int arg1);
private:
    void muestraCodigo(int pointSize = 14);

    Ui::CodigoDialog *ui;
};

#endif // CODIGODIALOG_H
