#include <deque>
#include <functional>
#include <iostream>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

template <typename T, typename F = std::function<bool(T, T)>>
class MonotonicQueue {
public:
    explicit MonotonicQueue(F&& filter)
        : filter_(filter)
    {}

    void enqueue(T item)
    {
        while (!data_.empty() && filter_(data_.back().first, item))
            data_.pop_back();

        data_.emplace_back(item, enqueue_count_++);
    }

    void dequeue()
    {
        if (!data_.empty() && data_.front().second == dequeue_count_++)
            data_.pop_front();
    }

    bool is_empty() const noexcept
    {
        return data_.empty();
    }

    T front() const noexcept
    {
        return data_.front().first;
    }

private:
    const F filter_;

    std::deque<std::pair<T, unsigned>> data_;

    unsigned enqueue_count_ = 0;
    unsigned dequeue_count_ = 0;

}; // class MonotonicQueue<T, F>

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    const auto check = [&](integer x) {
        MonotonicQueue<integer> q([](integer last, integer next) { return next <= last; });
        q.enqueue(0);

        integer s = 0;
        for (size_t i = 0, j = 0; i < n; ++i) {
            q.enqueue(q.front() + a[i]);

            s += a[i];
            while (s > x) {
                q.dequeue();
                s -= a[j++];
            }
        }

        return q.front() <= x;
    };

    integer lb = 0, ub = 1e15;
    while (lb + 1 < ub) {
        const integer mid = (lb + ub) / 2;
        (check(mid) ? ub : lb) = mid;
    }

    answer(ub);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
