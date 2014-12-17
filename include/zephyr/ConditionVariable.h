#ifndef ZEPHYR_CONDITIONVARIABLE_H
#define ZEPHYR_CONDITIONVARIABLE_H

#include <condition_variable>
#include <mutex>

namespace zephyr
{

template <typename T>
class ConditionVariable
{
public:
    ConditionVariable() :
        mWaitVar(false) {}

    T wait()
    {
        std::unique_lock<std::mutex> l(mMutex);
        mCondVar.wait(l,[&]{return mWaitVar;});
        mWaitVar = false;
        return mData;
    }

    void notify(T data)
    {
        mData = std::move(data);
        mWaitVar = true;
        mCondVar.notify_all();
    }

private:
    std::mutex mMutex;
    std::condition_variable mCondVar;
    bool mWaitVar;
    T mData;
};

}

#endif
