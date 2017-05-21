#include "MainWindow.h"
#include <QApplication>
#include <QGraphicsView>
#include <QDebug>
#include "SimulationEngine.h"
#include "Board.h"
#include "BoardModel.h"
#include "HerbivoreSpecimen.h"
#include "CarnivoreSpecimen.h"
#include "CircleCollider.h"
#include "Genome.h"
#include "Range.h"

void setCustomBoard(Board& board)
{
    for(int i = 0; i<board.getWidth()-1; ++i)
    {
        board.replaceField(QPoint(board.getWidth()-1-i,i), FieldType::WATER);
        board.replaceField(QPoint(board.getWidth()-1-i,i+1), FieldType::WATER);
    }
    for(int i = 0; i<board.getWidth(); ++i){
        for(int j = 0; j<board.getHeight(); ++j){
            BoardField* field = &board.getField(QPoint(i,j));
            if(field->getFieldType()==FieldType::GROUND)
            {
                dynamic_cast<GroundField*>(field)->setOvergrow(i*5);
            }
        }
    }
}

void createSpecimans(SimulationEngine& engine){
    HerbivoreSpecimen* spec1 = new HerbivoreSpecimen;
    CarnivoreSpecimen* spec2 = new CarnivoreSpecimen;
    //CarnivoreSpecimen* spec3 = new CarnivoreSpecimen;
    spec1->setPos(280,40);
    spec1->setSize(20);
    spec1->setVelocity(1);
    spec1->setAngularVelocity(1);
    spec1->setTarget(spec2);
    spec1->setMove(true);
    spec1->setRotation(-350);
    engine.addSpecimen(spec1);
    spec2->setPos(280,350);
    spec2->setSize(20);
    spec2->setRotation(10);
    spec2->setVelocity(0.7);
    spec2->setAngularVelocity(-1);
    spec2->setMove(true);
    engine.addSpecimen(spec2);

    /*
    spec3->setPos(20,240);
    spec3->setSize(40);
    spec3->setVelocity(3);
    spec3->setTarget(spec2);
    engine.addSpecimen(spec3);*/

}

void testGenes(){
    Range range(7, 12);
    std::cout<<range.transform(0)<<"\t"<<range.transform(-1)<<"\t"<<range.transform(0.7)<<"\n";
    Genome genome, genome2;
    genome.addAttributesPair(AttributeType::ENDURANCE, AttributeType::HEARING_RANGE);
    genome.addAttributesPair(AttributeType::SIGHT_ANGLE, AttributeType::SIGHT_RANGE);
    std::cout<<genome.getAttributeValue(AttributeType::ENDURANCE)<<std::endl;
    std::cout<<genome.getAttributeValue(AttributeType::HEARING_RANGE)<<std::endl;
    std::cout<<genome.getAttributeValue(AttributeType::SIGHT_ANGLE)<<std::endl;
    std::cout<<genome.getAttributeValue(AttributeType::SIGHT_RANGE)<<std::endl;
    genome2.addAttributesPair(AttributeType::ENDURANCE, AttributeType::HEARING_RANGE);
    genome2.addAttributesPair(AttributeType::SIGHT_ANGLE, AttributeType::SIGHT_RANGE);
    std::cout<<genome2.getAttributeValue(AttributeType::ENDURANCE)<<std::endl;
    std::cout<<genome2.getAttributeValue(AttributeType::HEARING_RANGE)<<std::endl;

    std::cout<<genome2.getAttributeValue(AttributeType::SIGHT_ANGLE)<<std::endl;
    std::cout<<genome2.getAttributeValue(AttributeType::SIGHT_RANGE)<<std::endl;
    Genome genome3 = Genome::crossing(genome, genome2);
    std::cout<<genome3.getAttributeValue(AttributeType::ENDURANCE)<<std::endl;
    std::cout<<genome3.getAttributeValue(AttributeType::HEARING_RANGE)<<std::endl;

    std::cout<<genome3.getAttributeValue(AttributeType::SIGHT_ANGLE)<<std::endl;
    std::cout<<genome3.getAttributeValue(AttributeType::SIGHT_RANGE)<<std::endl;

}

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow main_window;

//    /* board properties setting */
//    Board board(QPoint(15,15));
//    board.setFieldSize(40);

//    /* simulation engine creating */
//    SimulationEngine engine(board);

//    /* example tests demonstrating implemented features */
//    setCustomBoard(board);
//    createSpecimans(engine);

//    engine.startWork();

//    main_window.setBoardView(&(engine.getScene()));
//    main_window.show();

    testGenes();
//    return a.exec();
}

