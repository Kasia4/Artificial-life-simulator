#include "Board.h"

Board::Board(const QPoint& size)
{
    setFieldSize(DEFAULT_FIELD_SIZE);
    resize(size);
}

Board::~Board()
{

}


void Board::setFieldSize(float field_size)
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

const MapTable& Board::getFields() const
{
    return fields_;
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
            BoardField* field;
            if(y==3){
                WaterField* temp = new WaterField();
                field = temp;
            }
            else{
                GroundField* temp = new GroundField();
                temp->setOvergrow(x*2);
                field = temp;
            }fields_[x][y] = field;
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
            BoardField* field = fields_[x][y];
            if(!field) return;
            field->setPos(x*field_size_, y*field_size_);
            field->setSize(field_size_);
            field->setVisible(true);
        }
    }
}
