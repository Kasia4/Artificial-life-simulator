#include "HoverSpecimenEventFilter.h"

HoverSpecimenEventFilter::HoverSpecimenEventFilter()
{

}

bool HoverSpecimenEventFilter::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type() == QEvent::GraphicsSceneHoverEnter)
    {
        std::cout<<"hehe\n";
    }
    else
    {
        return QObject::eventFilter(watched, event);
    }
}
