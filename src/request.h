#ifndef REQUEST_H_INCLUDED_
#define REQUEST_H_INCLUDED_


#include <Poco/Notification.h>
#include <Poco/AutoPtr.h>

namespace htn {

/**
 * Process the request.
 */
class Request : public Poco::Notification {
    public:
        Request();
        virtual ~Request();

        // Override this method
        virtual void Execute() {};
};

}

#endif //REQUEST_H_INCLUDED_

