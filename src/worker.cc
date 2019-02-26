
#include "worker.h"
#include <Poco/AutoPtr.h>
#include <Poco/Notification.h>
#include "request.h"

#include <iostream>

namespace htn {

Worker::Worker(Poco::NotificationQueue& queue) : queue_(queue) {
    cancel_ = false;
}

Worker::~Worker() {
}

void Worker::run() {
    while(cancel_ == false) {
        Poco::AutoPtr<Poco::Notification> p_notification(queue_.waitDequeueNotification());
        if (p_notification) {
            Request *p_request = dynamic_cast<Request *>(p_notification.get());
            if (p_request) {
                p_request->Execute();
            }
        } else {
            // return NULL exit the thread.
            break;
        }
    }
}

}

