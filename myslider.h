#ifndef MYSLIDER_H
#define MYSLIDER_H

#include <QWidget>
#include <QSlider>
#include <QMouseEvent>

namespace Ui {
class MySlider;
}

class MySlider : public QSlider
{
    Q_OBJECT

public:
    explicit MySlider(QWidget *parent = 0);

//    explicit QSlider(QWidget *parent = nullptr);
    explicit MySlider(Qt::Orientation orientation, QWidget *parent = nullptr);
    ~MySlider();

protected:
  void mousePressEvent ( QMouseEvent * event );

private:
    Ui::MySlider *ui;
};

#endif // MYSLIDER_H
