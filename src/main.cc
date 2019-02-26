
#include "request.h"
#include "channel.h"

#include <iostream>
#include <Poco/Thread.h>

using namespace htn;

class PrintRequest : public Request {
    public:
    PrintRequest(int index) :index_(index) {
    };
    ~PrintRequest() {};

    virtual void Execute() {
        int val = Poco::Thread::currentTid();
        {
            std::cout << "Execute [" << std::to_string(val) << "]" << std::to_string(index_) << std::endl;
        }
        Poco::Thread::sleep(100);
    };

    int index_;
};

int main(int argc, char const* argv[])
{
    std::cout << "hello world" << std::endl;

    {
        Channel channel(3);
        for (int i = 0; i < 100; i++) {
            channel.PutRequest(new PrintRequest(i));
        }

        Poco::Thread::sleep(10 * 1000);
    }

    return 0;
}


