#include "BehaviourManager.h"

BehaviourManager::BehaviourManager()
{

}

BehaviourManager& BehaviourManager::getInstance()
{
    static BehaviourManager instance;
    return instance;
}
