#ifndef BOARD_H
#define BOARD_H

#include <QObject>
#include <QVector>
#include <QPoint>
#include <iostream>

#include "WaterField.h"
#include "GroundField.h"

typedef QVector< BoardField*> MapColumn;
typedef QVector< MapColumn > MapTable;



class Board : public QObject
{
    Q_OBJECT


public:
    static constexpr float DEFAULT_FIELD_SIZE = 30.0;
    Board(const QPoint& size);
    virtual ~Board();

    void setFieldSize(float field_size);

    int getWidth() const;
    int getHeight() const;
    QPoint getSize() const;
    int getFieldSize() const;
    BoardField& getField(const QPoint& position);
    const MapTable& getFields() const;
    void replaceField(const QPoint& position, BoardField* field);


private:
    void resize(const QPoint& size);
    int fieldIndex(const QPoint& position);
    void placeField(QPoint position);
    void placeFields();

    QPoint size_;
    float field_size_;
    MapTable fields_;

signals:
    void fieldSizeChanged(const QPoint& size);
    void fieldReplaced(BoardField* old_field, BoardField* new_field);
};


#endif // BOARD_H
