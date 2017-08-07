#pragma once

#include <QGraphicsPixmapItem>

class CardItem : public QGraphicsPixmapItem
{
public:
  CardItem();
  CardItem( const QPixmap &pixmap );
  
  inline qreal scale() { return _scale; }
  inline void setScale( qreal scale ) { _scale = scale; }

  inline QPointF center() { return _center; }
  void setPos( qreal x, qreal y );
  
private:
  static qreal _zVal;
  QPointF _center; // contient la position du centre du widget
  qreal _scale;
};
