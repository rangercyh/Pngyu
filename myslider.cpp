#include "myslider.h"
#include "ui_myslider.h"
#include <QtCore/qmath.h>
#include <QDebug>

MySlider::MySlider(QWidget *parent) :
    QSlider(parent),
    ui(new Ui::MySlider)
{
    ui->setupUi(this);
}

MySlider::MySlider(Qt::Orientation orientation, QWidget *parent) :
    QSlider(orientation, parent),
    ui(new Ui::MySlider)
{
    ui->setupUi(this);
}

MySlider::~MySlider()
{
    delete ui;
}

void MySlider::mousePressEvent ( QMouseEvent * event )
{
  QSlider::mousePressEvent(event);
  if (event->button() == Qt::LeftButton)
  {
      float ff = static_cast<float>(event->x()) / static_cast<float>(width());
      float offset = ff * (maximum() - minimum());
      int i = offset;
      float ll = offset - i;
      if (orientation() == Qt::Vertical)
          setValue(minimum() + (maximum() - minimum()) * (static_cast<float>(event->y()) / static_cast<float>(height())));
      else
          if( ll >= 0.5 )
          {
              setValue(minimum() + qCeil(offset));
          }
          else
          {
              setValue(minimum() + qCeil(offset) - 1);
          }


      QEvent evEvent(static_cast<QEvent::Type>(QEvent::User + 1));
      QCoreApplication::sendEvent(parentWidget(), &evEvent);
//      event->accept();
  }

}
