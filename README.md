# poco_channel
Poco worker thread

Using Poco NortificationQueue and make WorkerThread pattern.

| Class     | Description                    |
| --------- | ------------------------------ |
| Channel   | Take request and set Queue.    |
| Worker    | Take Request and execute.      |
| Request   | Request. Make this sub-class.  |

