#include "ShopNode.h"

string ShopNode::getDescription()
{
    return description;
}

void ShopNode::setDescription(string phrase)
{
    description = phrase;
}

int ShopNode::getYear()
{
    return year;
}

void ShopNode::setYear(int anno)
{
    year = anno;
}

double ShopNode::getFightChance()
{
    return fightChance;
}

void ShopNode::setFightChance(double chance)
{
    fightChance = chance;
}
