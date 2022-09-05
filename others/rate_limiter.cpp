#include <chrono>
#include <iostream>
#include <algorithm> 
#include <atomic>
using namespace std;


// rate limiter in token buckets
class rate_limiter1 {
    public:
        rate_limiter1(int initial_tokens, int limits, chrono::nanoseconds mInterval);
        bool send(chrono::steady_clock::time_point time);
    private:
        int max_limit;
        int tokens;
        chrono::nanoseconds mInterval;
        chrono::steady_clock::time_point  last_check;
};

rate_limiter1::rate_limiter1(int initial_tokens, int limits, chrono::nanoseconds mInterval)
{
    max_limit = limits;
    tokens = initial_tokens;
    this->mInterval = mInterval;
    last_check = chrono::steady_clock::now();
}

bool rate_limiter1::send(chrono::steady_clock::time_point time)
{
    if (tokens == 0)
    {
        auto time_elapsed = (time - last_check).count();
        tokens = min(max_limit, (int)(tokens + time_elapsed / mInterval.count()));
        last_check = time;
    }
    
    if (tokens > 0)
    {
        tokens--;
        return true;
    }
    else
        return false;
}

// rate limiter in sliding window
using TimePoint = std::chrono::time_point<std::chrono::system_clock, 
        std::chrono::duration<double>>; 
class rate_limiter2 {
    public:
        rate_limiter2(int maxVisitPerInterval, chrono::nanoseconds intervalLength);
        bool send(TimePoint time);
    private:
        int maxVisitPerInterval;
        int index;
        chrono::nanoseconds intervalLength;
        TimePoint* buckets;
};

rate_limiter2::rate_limiter2(int maxVisitPerInterval, chrono::nanoseconds intervalLength)
{
    buckets = new TimePoint[maxVisitPerInterval]{};
    for (int i = 0; i < maxVisitPerInterval; i++)
    {
        TimePoint default_time{};
        buckets[i] = default_time;
    }
    this->maxVisitPerInterval = maxVisitPerInterval;
    this->intervalLength = intervalLength;
    index = 0;
}

bool rate_limiter2::send(TimePoint time)
{
    TimePoint default_time{};
    if (buckets[index] == default_time)
    {
        buckets[index] = time;
        index += (index + 1) % maxVisitPerInterval;
        return true;
    }
    else
    {
        if (chrono::duration_cast<chrono::nanoseconds>(time - buckets[index]) > intervalLength)
        {
            buckets[index] = time;
            index = (index + 1) % maxVisitPerInterval;
            return true;
        }
        else
            return false;
    }

}


int main()
{

    return 0;
}