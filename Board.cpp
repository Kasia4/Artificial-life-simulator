#include "Board.h"

Board::Board(const QPoint& size)
{
    resize(size);
}

Board::~Board()
{

}


void Board::setFieldSize(int field_size)
{
    field_size_ = field_size;
    emit fieldSizeChanged(field_size);
}

int Board::getWidth() const
{
    return size_.x();
}

int Board::getHeight() const
{
    return size_.y();
}

QPoint Board::getSize() const
{
    return size_;
}

int Board::getFieldSize() const
{
    return field_size_;
}

BoardField &Board::getField(const QPoint& position)
{
    return fields_[fieldsIndex(position)];
}


void Board::resize(const QPoint& size)
{
    fields_.resize(size.x() * size.y());
}

int Board::fieldsIndex(const QPoint& position)
{
    return position.x() + size_.x()*position.y();
}
