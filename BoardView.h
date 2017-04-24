#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include <QObject>
#include <QHash>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QPersistentModelIndex>
#include <QAbstractItemView>

#include "SpecimensModel.h"

class BoardView : public QGraphicsView
{
public:
    BoardView();
//    void linkSpecimensModel(const SpecimensModel& model);
//    void linkBoardModel(const Board& model);
//private:
//    QHash<QPersistentModelIndex, BoardViewObject> board_objects;
//    QGraphicsScene scene;


};

#endif // BOARDVIEW_H
