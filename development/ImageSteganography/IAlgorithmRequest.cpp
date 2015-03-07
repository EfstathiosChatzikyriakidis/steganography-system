#include "IAlgorithmRequest.h"

IAlgorithmRequest::IAlgorithmRequest ()
{
}

IAlgorithmRequest::~IAlgorithmRequest ()
{
}

void IAlgorithmRequest::setName (const QString & name)
{
    _name = name;
}

QString IAlgorithmRequest::getName ()
{
    return _name;
}
