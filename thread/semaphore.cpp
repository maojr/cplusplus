#include <condition_variable>
#include <thread>
#include <mutex>

class Semaphore
{
private:
    std::condition_variable condition;
    std::mutex mutex;
    int value;

public:
    explicit Semaphore(int init) : value(init) {}

    void wait()
    {
        std::unique_lock<std::mutex> lock(mutex);
        condition.wait(lock, [&]() { return value >= 1; });
        value--;
    }

    bool try_wait()
    {
        std::lock_guard<std::mutex> lock(mutex);
        if (value < 1)
            return false;
        value--;
        return true;
    }

    void post()
    {
        {
            std::lock_guard<std::mutex> lock(mutex);
            value++;
        }
        condition.notify_one();
    }
};

int main(int argc, char const *argv[])
{
    Semaphore s(0);
    s.post();
    s.wait();
    return 0;
}
