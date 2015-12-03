#ifndef IMAGENDIALOG_H
#define IMAGENDIALOG_H

#include <QDialog>

namespace Ui
{
class ImagenDialog;
}

class ImagenDialog : public QDialog
{
    Q_OBJECT
public:
    explicit ImagenDialog(QWidget *parent = nullptr);
    ~ImagenDialog();
private:
    Ui::ImagenDialog *ui;
};

#endif // IMAGENDIALOG_H
