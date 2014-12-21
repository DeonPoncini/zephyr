#ifndef ZEPHYR_QUEUELOOP_H
#define ZEPHYR_QUEUELOOP_H

#include <condition_variable>
#include <deque>
#include <mutex>
#include <utility>

namespace zephyr
{

template <typename T>
class QueueLoop
{
public:
    QueueLoop();
    ~QueueLoop();
    bool shouldExit();
    void terminate();

    bool more() const;
    void write(T&& t);
    T read();

private:
    bool mExit;
    bool mWaitVar;
    std::deque<T> mQueue;
    mutable std::mutex mReadMutex;
    std::mutex mMutex;
    std::condition_variable mCondVar;
};

template <typename T>
QueueLoop<T>::QueueLoop() :
    mExit(false),
    mWaitVar(false)
{
}

template <typename T>
QueueLoop<T>::~QueueLoop()
{
    terminate();
}

template <typename T>
bool QueueLoop<T>::shouldExit()
{
    std::unique_lock<std::mutex> l(mMutex);
    mCondVar.wait(l,[&](){return mWaitVar;});
    mWaitVar = false;
    return mExit;
}

template <typename T>
void QueueLoop<T>::terminate()
{
    mExit = true;
    mWaitVar = true;
    mCondVar.notify_all();
}

template <typename T>
bool QueueLoop<T>::more() const
{
    std::unique_lock<std::mutex> l(mReadMutex);
    return !mQueue.empty();
}

template <typename T>
void QueueLoop<T>::write(T&& t)
{
    std::unique_lock<std::mutex> l(mReadMutex);
    mQueue.emplace_back(std::move(t));
    // notify the waiting thread to continue
    mWaitVar = true;
    mCondVar.notify_all();
}

template <typename T>
T QueueLoop<T>::read()
{
    std::unique_lock<std::mutex> l(mReadMutex);
    auto t = std::move(mQueue.front());
    mQueue.pop_front();
    return t;
}

}

#endif
