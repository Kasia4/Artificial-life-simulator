/* Board.h
 * author: Karol Checinski
 * The Board class provides grid board for simulator.
 */

#ifndef BOARD_H
#define BOARD_H

#include <QObject>
#include <QVector>
#include <QPoint>

#include "FieldFactory.h"

typedef QVector< BoardField*> MapColumn;
typedef QVector< MapColumn > MapTable;



class Board : public SimulationObject
{
    Q_OBJECT

public:
    Board(const QPoint& size, const QPointF &surface_size);
    virtual ~Board();

    int getWidth() const;
    int getHeight() const;
    QPoint getSize() const;
    int getFieldSize() const;
	BoardField* getField(const QPoint& position);
	QPoint getFieldPositionByPixel(const QPoint& px_position);

    bool onBoard(const QPoint& position);
    FieldType getFieldType(const QPoint& position);

    const MapTable& getFields() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;

    /* Sets field with given type at given position. Creates new field object and destroys old one */
    void replaceField(const QPoint& position, FieldType type);

    QList<BoardField*> getNeighbors(const BoardField* field);
    QList<BoardField*> getNeighbors(const QPoint& position);

    QPointF getSurfaceSize() const;

private:
    void setSurfaceSize(const QPointF &surface_size);
    void resize(const QPoint& size);

    /* Sets properly QGraphicsItem properties for field at given position */
    void placeField(QPoint position);
    /* Calls placeField for every field */
    void placeFields();
    void updateFieldSize();

    QPoint size_;
    QPointF surface_size_;
    qreal field_size_;
    MapTable fields_;

signals:
    void fieldSizeChanged(const QPoint& size);
	void fieldReplaced(BoardField* old_field, BoardField* new_field);
};




#endif // BOARD_H
