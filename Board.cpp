#include "Board.h"

Board::Board(const QPoint& size)
{
    setFieldSize(DEFAULT_FIELD_SIZE);
    resize(size);
}

Board::~Board()
{

}


void Board::setFieldSize(qreal field_size)
{
    field_size_ = field_size;
    placeFields();
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

BoardField& Board::getField(const QPoint& position)
{
    return *fields_[position.x()][position.y()];
}

bool Board::onBoard(const QPoint &position)
{
    return position.x() >= 0 && position.y() >= 0 && position.x() < size_.x() && position.y() < size_.y();
}

FieldType Board::getFieldType(const QPoint &position)
{
    if(onBoard(position))
        return fields_[position.x()][position.y()]->getFieldType();
    else return FieldType::VOID;
}

const MapTable& Board::getFields() const
{
    return fields_;
}

void Board::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF Board::boundingRect() const
{
    return QRectF(0,0, size_.x()*field_size_, size_.y()*field_size_);
}



void Board::replaceField(const QPoint &position, FieldType type)
{
    BoardField* old_field = &getField(position);
    BoardField* new_field = FieldFactory::getInstance().create(type);
    fields_[position.x()][position.y()] = new_field;
    placeField(position);
    emit fieldReplaced(old_field, new_field);
    delete old_field;
}

void Board::advance(int phase)
{
    if(!phase)return;
    for(MapColumn& column: fields_)
    {
        for(BoardField* field: column)
        {
            //TODO
        }
    }


}


void Board::resize(const QPoint& size)
{
    size_ = size;
    for(QVector<BoardField*> column: fields_)
    {
        for(BoardField* field: column)
        {
            delete field;
        }
    }
    fields_.resize(size_.x());
    for(int x = 0; x < size_.x(); ++x)
    {
        fields_[x].resize(size_.y());
        for(int y = 0; y < size_.y(); ++y){
            GroundField* field = new GroundField();
            fields_[x][y] = field;
            placeField(QPoint(x,y));
        }
    }
    emit fieldSizeChanged(size_);
}

void Board::placeField(QPoint position)
{
    BoardField* field = fields_[position.x()][position.y()];
    if(!field) return;
    field->setPos(position.x()*field_size_, position.y()*field_size_);
    field->setSize(field_size_);
    field->setVisible(true);
}

void Board::placeFields(){
    for(int x = 0; x < size_.x(); ++x)
    {
        for(int y = 0; y < size_.y(); ++y){
            placeField(QPoint(x,y));
        }
    }
}
