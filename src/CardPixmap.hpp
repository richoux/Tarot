#include <QGraphicsPixmapItem>

class CardPixmap : public QGraphicsPixmapItem
{
public:
  CardPixmap();
  CardPixmap( const QPixmap &pixmap );
  
  inline qreal rotationY() { return _rotationY; }
  inline void setRotationY( qreal rotation ) { _rotationY = rotation; }

  inline qreal scale() { return _scale; }
  inline void setScale( qreal scale ) { _scale = scale; }

  inline QPointF center() { return _center; }

private:
  qreal _rotationY; // enregistre la rotation autour de l'axe Y
  QPointF _center; // contient la position du centre du widget
  qreal _scale;
};
