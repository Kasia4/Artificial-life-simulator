#ifndef BOARD_H
#define BOARD_H

#include <QObject>
#include <QVector>
#include <QPoint>

#include "WaterField.h"
#include "GroundField.h"

class Board : public QObject
{
    Q_OBJECT
public:
    Board(const QPoint& size);
    virtual ~Board();

    void setFieldSize(int field_size);

    int getWidth() const;
    int getHeight() const;
    QPoint getSize() const;
    int getFieldSize() const;
    BoardField& getField(const QPoint& position);


private:
    void resize(const QPoint& size);
    int fieldsIndex(const QPoint& position);

    QPoint size_;
    int field_size_;
    QVector<BoardField*> fields_;
public:
signals:
    void fieldSizeChanged(int new_value);
};

#endif // BOARD_H
