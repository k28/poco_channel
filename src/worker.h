#ifndef WORKER_H_INCLUDED_
#define WORKER_H_INCLUDED_

#include <Poco/Runnable.h>
#include <Poco/NotificationQueue.h>

namespace htn {

class Worker : public Poco::Runnable {

private:
    Poco::NotificationQueue &queue_;

    bool cancel_;

public:
    Worker(Poco::NotificationQueue& queue);
    ~Worker();

    virtual void run();
    void Cancel(){cancel_ = true;};;

};

}

#endif //WORKER_H_INCLUDED_

