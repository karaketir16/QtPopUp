#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QtDebug>
#include <QInputDialog>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QMessageBox messageBox;
    messageBox.setText(tr("<b>Devam etmek istiyor musunuz?</b>"));
    QAbstractButton  *onayButonu = messageBox.addButton("Evet", QMessageBox::AcceptRole);
    QAbstractButton  *retButonu = messageBox.addButton("Hayır", QMessageBox::RejectRole);
    messageBox.exec();
    if(messageBox.clickedButton() == onayButonu)
    {
        qDebug()<<"Onaylandı";
    }
    else {
        qDebug()<<"Olumsuz";
    }
}

void Widget::on_pushButton_2_clicked()
{
    int res = QMessageBox::critical(this, "Hata",
                tr("<font color=\"red\">Bir sorun ile karşılaşıldı</font>"),
                QMessageBox::StandardButton::Close | QMessageBox::StandardButton::Discard);
    if(res == QMessageBox::StandardButton::Close)
        close();
}

void Widget::on_pushButton_3_clicked()
{
    bool ok;
    QString isim = QInputDialog::getText(this, "İsim",
                          tr("<font size=\"6\">Lütfen Adınızı Giriniz</font>"),
                          QLineEdit::Normal, "", &ok);

    if (ok)
        qDebug()<<isim;

}
