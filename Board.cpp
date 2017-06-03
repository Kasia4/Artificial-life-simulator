#include "Board.h"

Board::Board(const QPoint& size, const QPointF& surface_size)
{
    size_ = size;
    setSurfaceSize(surface_size);
    resize(size);
}

Board::~Board()
{

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

BoardField* Board::getField(const QPoint& position)
{
    if(onBoard(position))
        return fields_[position.x()][position.y()];
    else
        return nullptr;

}

QPoint Board::getFieldPositionByPixel(const QPoint& px_position)
{
	return QPoint(px_position.x()/field_size_, px_position.y()/field_size_);
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
    return QRectF(0,0, surface_size_.x(), surface_size_.y());
}



void Board::replaceField(const QPoint &position, FieldType type)
{
    BoardField* old_field = getField(position);
    BoardField* new_field = FieldFactory::getInstance().create(type, position);
    fields_[position.x()][position.y()] = new_field;
    placeField(position);
    emit fieldReplaced(old_field, new_field);
    delete old_field;
}

QList<BoardField *> Board::getNeighbors(const BoardField *field)
{
    QPoint position = field->getPosition();
    QList<BoardField *> neighbors;
    neighbors.append(getField(QPoint(position.x(), position.y()-1)));
    neighbors.append(getField(QPoint(position.x()+1, position.y())));
    neighbors.append(getField(QPoint(position.x(), position.y()+1)));
    neighbors.append(getField(QPoint(position.x()-1, position.y())));
    neighbors.removeAll(nullptr);
    return neighbors;
}

QList<BoardField *> Board::getNeighbors(const QPoint &position)
{
    QList<BoardField *> neighbors;
    neighbors.append( getField(QPoint(position.x(), position.y()-1)) );
    neighbors.append( getField(QPoint(position.x()+1, position.y())) );
    neighbors.append( getField(QPoint(position.x(), position.y()+1)) );
    neighbors.append( getField(QPoint(position.x()-1, position.y())) );
    neighbors.removeAll(nullptr);
    return neighbors;
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
            field->setPosition(QPoint(x,y));
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

void Board::updateFieldSize()
{
    qreal new_field_size_x = surface_size_.x()/size_.x();
    qreal new_field_size_y = surface_size_.y()/size_.y();
    field_size_ = new_field_size_x < new_field_size_y ?
                    new_field_size_x :
                    new_field_size_y;
}

QPointF Board::getSurfaceSize() const
{
	return surface_size_;
}


void Board::setSurfaceSize(const QPointF &surface_size)
{
    surface_size_ = surface_size;
    updateFieldSize();
}


