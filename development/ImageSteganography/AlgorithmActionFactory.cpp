#include <typeinfo>

#include "AlgorithmActionFactory.h"

AlgorithmActionFactory::AlgorithmActionFactory ()
{
}

AlgorithmActionFactory::~AlgorithmActionFactory ()
{
}

QMap<QString, QSharedPointer<IAlgorithmAction>> AlgorithmActionFactory::_actions;

QSharedPointer<IAlgorithmAction> AlgorithmActionFactory::getInstance (const QSharedPointer<IAlgorithmRequest> & request)
{
    QString reqName = typeid (*request).name ();

    if (_actions.find (reqName) == _actions.end ())
    {
        return QSharedPointer<IAlgorithmAction> (0);
    }

    return _actions[reqName];
}

bool AlgorithmActionFactory::registerAction (const QSharedPointer<IAlgorithmRequest> & request, const QSharedPointer<IAlgorithmAction> & action)
{
    QString reqName = typeid (*request).name ();

    if (_actions.contains(reqName))
    {
        return false;
    }

    _actions.insert (reqName, action);

    return true;
}
