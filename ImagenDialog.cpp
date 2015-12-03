#include "ImagenDialog.h"
#include "ui_ImagenDialog.h"

ImagenDialog::ImagenDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ImagenDialog)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::WindowMinMaxButtonsHint);
    layout()->setMargin(0);
    ui->scrollAreaWidgetContents->layout()->setMargin(0);
}

ImagenDialog::~ImagenDialog()
{
    delete ui;
}
