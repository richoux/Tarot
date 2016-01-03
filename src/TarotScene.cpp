#include "TarotScene.hpp"

TarotScene::TarotScene() : QGraphicsScene()
{
  this->setBackgroundBrush( QImage( "img/bg.png" ) );
  array< QPixmap, 78 > cardPixmaps;
  for( int i = 0 ; i < 78 ; ++i )
  {
    QString path = "img/cards/" + (i+1) + ".png";
    cardPixmaps[i].load( path );
    card.setPixmap( cardPixmaps[i] );
    cardImages[i]->setPos( 300, 0 + i*10 );
    this->addItem( cardImages[i] );
  }
  
  // QTransform matrix;
  // matrix.scale(0.25, 0.25);
  // card->setTransform( matrix );
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

  // if( card->isUnderMouse() )
  // {
  //   QTransform matrix;
  //   if( card->scale() == 0.25 )
  //     card->setScale( 0.3 );
  //   else
  //     card->setScale( 0.25 );      
  //   matrix.scale( card->scale(), card->scale() );
  //   card->setTransform( matrix );    
  // }

}

void TarotScene::mousePressEvent( QGraphicsSceneMouseEvent *e )
{
}
