#include <deque>
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

void answer(integer x)
{
    std::cout << x << '\n';
}

template <typename T, typename F>
class MonotonicQueue {
public:
    MonotonicQueue() = default;

    explicit MonotonicQueue(F&& filter)
        : filter_(std::move(filter))
    {}

    void enqueue(T x)
    {
        while (!data_.empty() && filter_(x, data_.back().first))
            data_.pop_back();

        data_.emplace_back(x, enqueue_count_++);
    }

    void dequeue()
    {
        if (!data_.empty() && data_.front().second == dequeue_count_++)
            data_.pop_front();
    }

    T front() const
    {
        return data_.front().first;
    }

private:
    F filter_;

    std::deque<std::pair<T, unsigned>> data_;

    unsigned enqueue_count_ = 0;
    unsigned dequeue_count_ = 0;

}; // class MonotonicQueue<T, F>

integer solve(const std::vector<unsigned>& a, size_t d)
{
    const size_t m = a.size();

    std::vector<integer> dp(m);
    dp[0] = 1;

    MonotonicQueue<integer, std::less<integer>> q;
    q.enqueue(1);
    for (size_t i = 1; i < m; ++i) {
        dp[i] = q.front() + 1 + a[i];
        q.enqueue(dp[i]);
        if (i > d)
            q.dequeue();
    }

    return dp[m-1];
}

void solve(const std::vector<std::vector<unsigned>>& a, size_t k, size_t d)
{
    const size_t n = a.size();

    std::vector<integer> c(n);
    for (size_t i = 0; i < n; ++i)
        c[i] = solve(a[i], d);

    integer s = 0;
    for (size_t i = 0; i < k; ++i)
        s += c[i];

    integer v = s;
    for (size_t i = k; i < n; ++i) {
        s += c[i] - c[i-k];
        v = std::min(v, s);
    }

    answer(v);
}

void test_case()
{
    size_t n, m, k, d;
    std::cin >> n >> m >> k >> d;

    std::vector<std::vector<unsigned>> a(n, std::vector<unsigned>(m));
    std::cin >> a;

    solve(a, k, d);
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
