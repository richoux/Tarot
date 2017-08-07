#include "CardItem.hpp"

qreal CardItem::_zVal = 0;

CardItem::CardItem() : QGraphicsPixmapItem() { }
CardItem::CardItem( const QPixmap &pixmap ) : QGraphicsPixmapItem( pixmap ) { }

void CardItem::setPos( qreal x, qreal y )
{
  QGraphicsItem::setPos( x, y );
  setZValue( ++_zVal );
}
