#pragma once

#include <array>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPixmapItem>

#include "CardItem.hpp"

using namespace std;

class TarotScene : public QGraphicsScene
{
public:
  TarotScene();

  void mouseMoveEvent( QGraphicsSceneMouseEvent *e );
  void mousePressEvent( QGraphicsSceneMouseEvent *e );
  void placeCard( const int cardIndex, const int x, const int y );

private:
  array< CardItem, 78 > cardItems;
  QTransform matrix;
};
