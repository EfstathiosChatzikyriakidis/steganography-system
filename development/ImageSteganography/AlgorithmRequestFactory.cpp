#include "AlgorithmRequestFactory.h"

AlgorithmRequestFactory::AlgorithmRequestFactory ()
{
}

AlgorithmRequestFactory::~AlgorithmRequestFactory ()
{
}

QMap<QString, QSharedPointer<IAlgorithmRequest>> AlgorithmRequestFactory::_requests;

QSharedPointer<IAlgorithmRequest> AlgorithmRequestFactory::getInstance (const QString & algorithm)
{
    if (_requests.contains (algorithm))
    {
        return _requests[algorithm];
    }

    return QSharedPointer<IAlgorithmRequest> (0);
}

bool AlgorithmRequestFactory::registerRequest (const QString & algorithm, const QSharedPointer<IAlgorithmRequest> & request)
{
    if (_requests.contains (algorithm))
    {
        return false;
    }

    _requests.insert (algorithm, request);

    return true;
}
