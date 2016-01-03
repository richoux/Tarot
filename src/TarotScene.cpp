#include "TarotScene.hpp"
#include <iostream>

TarotScene::TarotScene() : QGraphicsScene()
{
  this->setBackgroundBrush( QImage( "img/bg.png" ) );
  array< QPixmap, 78 > cardPixmaps;
  for( int i = 0 ; i < 78 ; ++i )
  {
    QString path( "img/cards/" );
    path.append( QString("%1").arg( i+1 ) );
    path.append( ".png" );
    std::cout << path.toStdString() << std::endl;
    cardPixmaps[i].load( path );
    cardImages[i].setPixmap( cardPixmaps[i] );
    if( i < 26 )
      cardImages[i].setPos( i*30, 50 );
    else if( i < 52 )
      cardImages[i].setPos( (i-26)*30, 150 );
    else
      cardImages[i].setPos( (i-52)*30, 250 );
      
    this->addItem( &cardImages[i] );
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
