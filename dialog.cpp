#include "dialog.h"
#include "ui_dialog.h"
#include <QStack>
#include <QVector>
#include <QDebug>
#include <QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    strDis("0"),
    map{{"+",1},{"-",1},{"*",2},{"/",2},{"(",3},{")",3}}
{
    ui->setupUi(this);
    ui->label_dis->setText(strDis);

    //setWindowFlags(Qt::FramelessWindowHint);
    // setWindowFlags(Qt::WindowTitleHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint| Qt::WindowCloseButtonHint);
    setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_btn_clear_clicked()
{
    strDis="0";
    ui->label_dis->setText(strDis);

}
QString& setFrontNoZero(QString& strDis)
{
    if(strDis.size()>1&&strDis[1]!=".")
    {
        QString temp=strDis;
        if(temp[0]=="0")
            strDis=temp.mid(1);
    }
    return strDis;
}
void Dialog::on_btn_1_clicked()
{
    strDis+=ui->btn_1->text();
    setFrontNoZero(strDis);

    ui->label_dis->setText(strDis);
}

void Dialog::on_btn_2_clicked()
{
    strDis+=ui->btn_2->text();
    setFrontNoZero(strDis);

    ui->label_dis->setText(strDis);
}

void Dialog::on_btn_3_clicked()
{
    strDis+=ui->btn_3->text();
    setFrontNoZero(strDis);

    ui->label_dis->setText(strDis);
}

void Dialog::on_btn_4_clicked()
{
    strDis+=ui->btn_4->text();
    setFrontNoZero(strDis);

    ui->label_dis->setText(strDis);
}

void Dialog::on_btn_5_clicked()
{
    strDis+=ui->btn_5->text();
    setFrontNoZero(strDis);

    ui->label_dis->setText(strDis);
}

void Dialog::on_btn_6_clicked()
{
    strDis+=ui->btn_6->text();
    setFrontNoZero(strDis);

    ui->label_dis->setText(strDis);
}

void Dialog::on_btn_7_clicked()
{
    strDis+=ui->btn_7->text();
    setFrontNoZero(strDis);

    ui->label_dis->setText(strDis);
}

void Dialog::on_btn_8_clicked()
{
    strDis+=ui->btn_8->text();
    setFrontNoZero(strDis);

    ui->label_dis->setText(strDis);
}

void Dialog::on_btn_9_clicked()
{
    strDis+=ui->btn_9->text();
    setFrontNoZero(strDis);

    ui->label_dis->setText(strDis);
}

void Dialog::on_btn_left_clicked()
{
    strDis+=QString(ui->btn_left->text());
    setFrontNoZero(strDis);

    ui->label_dis->setText(strDis);
}

void Dialog::on_btn_right_clicked()
{
    strDis+=QString(ui->btn_right->text());

    ui->label_dis->setText(strDis);
}

void Dialog::on_btn_xiaoshudian_clicked()
{
    strDis+=ui->btn_xiaoshudian->text();

    ui->label_dis->setText(strDis);
}

void Dialog::on_btn_0_clicked()
{
    strDis+=ui->btn_0->text();
    setFrontNoZero(strDis);

    ui->label_dis->setText(strDis);
}


void Dialog::on_btn_plus_clicked()
{
    strDis+=ui->btn_plus->text();

    ui->label_dis->setText(strDis);
}

void Dialog::on_btn_sub_clicked()
{
    strDis+=ui->btn_sub->text();

    ui->label_dis->setText(strDis);
}

void Dialog::on_btn_multi_clicked()
{
    strDis+=ui->btn_multi->text();

    ui->label_dis->setText(strDis);
}

void Dialog::on_btn_div_clicked()
{
    strDis+=ui->btn_div->text();

    ui->label_dis->setText(strDis);
}

bool isPSMD(QString str)
{
    return (str[0]=="("||str[0]==")"||str[0]=="+"||str[0]=="-"||str[0]=="*"||str[0]=="/")?true:false;
}


void Dialog::on_btn_equal_clicked()
{

   QVector<QString> biaodashi;
   QString temp="\0";
  // qDebug()<<strDis.size();
   for(int i=0;i<strDis.size();i++)
   {

       if(isPSMD(QString(strDis[i])))
       {

           if(temp.size()>0)
                biaodashi.push_back(temp);
           temp="\0";
           biaodashi.push_back(QString(strDis[i]));
       }
       else
       {
           temp+=strDis[i];
       }

   }
   if(temp.size())
        biaodashi.push_back(temp);

  // for(auto a:biaodashi)
   //    qDebug()<<a<<"biaodashi";


   QVector<QString> houzhuibiaodashi;
   QStack<QString> stack;
   int flag=0;
   for(auto val:biaodashi)
   {
       if(!isPSMD(val))
       {
           houzhuibiaodashi.push_back(val);
           continue;
       }
       if(val=="(")
       {
           stack.push(val);
           flag++;
           continue;
       }
       if(stack.size()==0)
       {
           stack.push(val);
           continue;
       }

       if(val==")")
       {
           while(stack.top()!="(")
             houzhuibiaodashi.push_back(stack.pop());
           stack.pop();
           flag--;
           continue;
       }
       if(map[val]>map[stack.top()])
       {
           stack.push(val);
       }
       else
       {
           if(flag)
           {
               if(map[val]>map[stack.top()])
                   stack.push(val);
               else
               {
                   while(stack.top()!="(")
                     houzhuibiaodashi.push_back(stack.pop());
                   stack.push(val);
               }
           }
           else
           {
               while(map[val]<=map[stack.top()])
               {
                    houzhuibiaodashi.push_back(stack.pop());
                    if(stack.empty())
                        break;
               }
               stack.push(val);
           }

       }

   }
   // qDebug()<<"*************"<<stack.size();
   while(!stack.empty())
        houzhuibiaodashi.push_back(stack.pop());

  // for(auto a:houzhuibiaodashi)
   //    qDebug()<<a<<"houzhuibiaodashi";


   stack.clear();
   for(auto val:houzhuibiaodashi)
   {
       if(!isPSMD(val))
         stack.push(val);
       else
       {
           QString temp1,temp2,res;
           temp2=stack.pop();
           temp1=stack.pop();
           double val1=temp1.toDouble();
           double val2=temp2.toDouble();

           if(val=="+")
               res= QString::number(val1+val2);
           else if(val=="-")
               res= QString::number(val1-val2);
           else if(val=="*")
               res= QString::number(val1*val2);
           else if(val=="/")
                {
                    if(val2==0)
                    {
                        //qDebug()<<"--------------";
                        QMessageBox msg(this);
                        msg.setWindowTitle("铁憨憨");
                        msg.setText("你是大傻逼啊，除数不能为0！");
                        msg.exec();
                        //break;
                    }
                    else
                        res= QString::number(val1/val2);
                 }
           stack.push(res);
       }
   }
   strDis=strDis+"="+stack.top();
   ui->label_dis->setText(strDis);
    //qDebug()<<stack.top();

}


