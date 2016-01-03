#include <array>

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPixmapItem>

#include "CardPixmap.hpp"

using namespace std;

class TarotScene : public QGraphicsScene
{
public:
  TarotScene();
  void mouseMoveEvent( QGraphicsSceneMouseEvent *e );
  void mousePressEvent( QGraphicsSceneMouseEvent *e );

private:
  array< CardPixmap, 78 > cardImages;
};
