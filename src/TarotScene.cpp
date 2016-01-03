#include "TarotScene.hpp"

TarotScene::TarotScene() : QGraphicsScene()
{
  this->setBackgroundBrush( QImage( "img/bg.png" ) );
  vector<QPixmap cardImage( "figs/21.png" );
  card = new CardPixmap( cardImage );
  card->setPos( 300, 50 );
  QTransform matrix;
  matrix.scale(0.25, 0.25);
  card->setTransform( matrix );
  this->addItem( card );
}

void TarotScene::mouseMoveEvent( QGraphicsSceneMouseEvent *e )
{
  // if(e->buttons() & Qt::LeftButton)
  // {
  //   QPointF delta( e->scenePos() - e->lastScenePos() );
  //   qreal rotation = delta.x();
  //   card->setRotationY( rotation + card->rotationY() );
    
  //   QTransform matrix;
  //   matrix.rotate( card->rotationY(), Qt::YAxis );
  //   matrix.scale(0.25, 0.25);
  //   card->setTransform( matrix );
  // }

  if( card->isUnderMouse() )
  {
    QTransform matrix;
    if( card->scale() == 0.25 )
      card->setScale( 0.3 );
    else
      card->setScale( 0.25 );      
    matrix.scale( card->scale(), card->scale() );
    card->setTransform( matrix );    
  }

}

void TarotScene::mousePressEvent( QGraphicsSceneMouseEvent *e )
{
}
