#ifndef _ALGORITHM_REQUEST_FACTORY_H
#define _ALGORITHM_REQUEST_FACTORY_H

#include <QSharedPointer>

#include <QMap>

#include "IAlgorithmRequest.h"

class AlgorithmRequestFactory
{
    private:
        AlgorithmRequestFactory ();

        ~AlgorithmRequestFactory ();

        static QMap<QString, QSharedPointer<IAlgorithmRequest>> _requests;

    public:
        static QSharedPointer<IAlgorithmRequest> getInstance (const QString & algorithm);

        static bool registerRequest (const QString & algorithm, const QSharedPointer<IAlgorithmRequest> & request);
};

#endif // _ALGORITHM_REQUEST_FACTORY_H
