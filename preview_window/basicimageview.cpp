#include "basicimageview.h"
#include <QGraphicsScene>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QScrollBar>

#include <QDebug>

#include <cmath>

BasicImageView::BasicImageView(QWidget *parent) :
  QGraphicsView(parent)
{
  setScene( new QGraphicsScene(this) );
  setMouseTracking(true);

  setInteractive( true );
}

void BasicImageView::setImage( const QImage &image )
{
  m_pixmap = QPixmap::fromImage( image );
  setSceneRect( QRectF(image.rect()) );
  viewport()->repaint();
}

void BasicImageView::setPixmap( const QPixmap &pixmap )
{
  m_pixmap = pixmap;
  setSceneRect( QRectF(pixmap.rect()) );
  viewport()->repaint();
}

void BasicImageView::mouseMoveEvent(QMouseEvent *event)
{
  const QPointF pos = event->pos();

  if( event->buttons() == Qt::MidButton )
  {
    const QPointF delta = pos - m_lastMovePoint;

    QScrollBar* h_bar = horizontalScrollBar();
    QScrollBar* v_bar = verticalScrollBar();

    h_bar->setValue( h_bar->value() - delta.x() );
    v_bar->setValue( v_bar->value() - delta.y() );
  }
  m_lastMovePoint = pos;
  QGraphicsView::mouseMoveEvent(event);
}

void BasicImageView::drawBackground(QPainter *painter, const QRectF &rect)
{
  const QRectF rectf = rect.intersected( sceneRect() );

  painter->fillRect( rectf, backgroundBrush() );

  const QMatrix m = matrix();

  painter->fillRect( rectf, QBrush( m_pixmap ) );
  //QGraphicsView::drawBackground( painter, rect.intersect( sceneRect() ) );
}

void BasicImageView::wheelEvent(QWheelEvent *event)
{
  const int delta = event->delta();
  const double SCALING_STEP = 1.2;
  if( 0 < delta )
  {
    scale( SCALING_STEP, SCALING_STEP );
  }
  else if( 0 > delta )
  {
    scale( 1.0 / SCALING_STEP, 1.0 / SCALING_STEP );
  }
}
