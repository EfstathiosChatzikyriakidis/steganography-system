#ifndef _ALGORITHM_ACTION_FACTORY_H
#define _ALGORITHM_ACTION_FACTORY_H

#include <QSharedPointer>

#include <QMap>

#include "IAlgorithmRequest.h"
#include "IAlgorithmAction.h"

class AlgorithmActionFactory
{
    private:
        AlgorithmActionFactory ();

        ~AlgorithmActionFactory ();

        static QMap<QString, QSharedPointer<IAlgorithmAction>> _actions;

    public:
        static QSharedPointer<IAlgorithmAction> getInstance (const QSharedPointer<IAlgorithmRequest> & request);

        static bool registerAction (const QSharedPointer<IAlgorithmRequest> & request, const QSharedPointer<IAlgorithmAction> & action);
};

#endif // _ALGORITHM_ACTION_FACTORY_H
