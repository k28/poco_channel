#include "channel.h"

#include "request.h"
#include "worker.h"

namespace htn {

Channel::Channel(const int num_thread) {
    // Create workers.
    worker_list_.clear();
    for (int i = 0; i < num_thread; i++) {
        std::shared_ptr<Worker> worker(new Worker(queue_));
        worker_list_.push_back(worker);

        pool_.start(*worker);
    }
}

Channel::~Channel() {
    for (std::shared_ptr<Worker> worker : worker_list_) {
        worker->Cancel();
    }

    queue_.wakeUpAll();
    pool_.joinAll();
}

void Channel::PutRequest(Request *request) {
    if (request == nullptr) return;
    queue_.enqueueNotification(request);
}

}
