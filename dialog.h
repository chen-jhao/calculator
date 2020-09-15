#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QString>
#include <QMap>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT


public:
   // void setFrontNoZero(QString& strDis);
   // bool isPSMD(QString str);
   // QString yunsuan(const QString& temp1,const QString& temp2,QString& opt);
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();



private slots:


    void on_btn_clear_clicked();

    void on_btn_0_clicked();

    void on_btn_1_clicked();

    void on_btn_2_clicked();

    void on_btn_3_clicked();

    void on_btn_4_clicked();

    void on_btn_5_clicked();

    void on_btn_6_clicked();

    void on_btn_7_clicked();

    void on_btn_8_clicked();

    void on_btn_9_clicked();

    void on_btn_plus_clicked();

    void on_btn_sub_clicked();

    void on_btn_multi_clicked();

    void on_btn_div_clicked();

    void on_btn_equal_clicked();

    void on_btn_left_clicked();

    void on_btn_right_clicked();

    void on_btn_xiaoshudian_clicked();



private:
    Ui::Dialog *ui;
    QString strDis;
    const QMap<QString,int> map;
};

#endif // DIALOG_H
