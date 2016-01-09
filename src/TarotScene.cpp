#include "TarotScene.hpp"

TarotScene::TarotScene() : QGraphicsScene()
{
  this->setBackgroundBrush( QImage( "img/bg.png" ) );
  array< QPixmap, 78 > pixmaps;
  matrix.scale(0.5, 0.5);

  for( int i = 0 ; i < 78 ; ++i )
  {
    QString path( "img/cards/" );
    path.append( QString("%1").arg( i+1 ) );
    path.append( ".png" );

    pixmaps[i].load( path );
    cardItems[i].setPixmap( pixmaps[i] );
    
    // matrix.reset();
    // matrix.scale(0.5, 0.5);
    
    // if( i < 26 )
    //   matrix.translate( i*90 - 250, 1200 );
    // else if( i < 52 )
    //   matrix.translate( (i-26)*90 - 250, 1300 );
    // else
    //   matrix.translate( (i-52)*90 - 250, 1400 );

    cardItems[i].setPos( -1000, -1000 );
    cardItems[i].setTransform( matrix );

    this->addItem( &cardItems[i] );
  }
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

void TarotScene::placeCard( const int cardIndex, const int x, const int y )
{
  cardItems[ cardIndex ].setPos( x/2, y/2 );
}
