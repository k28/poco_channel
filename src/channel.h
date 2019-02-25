#ifndef CHANNEL_H_INCLUDED_
#define CHANNEL_H_INCLUDED_

#include <Poco/ThreadPool.h>
#include <Poco/NotificationQueue.h>
#include <vector>
#include <memory>

namespace htn {

class Worker;
class Request;

class Channel {
    public:
        Channel(const int num_thread);
        virtual ~Channel();

        /**
         * Put Request
         */
        void PutRequest(Request *request);

    private:
        Poco::ThreadPool pool_;
        Poco::NotificationQueue queue_;
        std::vector<std::shared_ptr<Worker>> worker_list_;

};

}

#endif //CHANNEL_H_INCLUDED_

