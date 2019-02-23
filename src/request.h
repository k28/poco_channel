
#include <Poco/Notification.h>

/**
 * リクエストを処理するクラス
 */
class Request : public Poco::Norification {
    public:
        Request();
        virtual ~Request();

        // この処理が実行される
        virtual void Execute();
};


