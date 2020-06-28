#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(size_t n, size_t t, size_t k, size_t d)
{
    size_t time = 0;
    for (size_t c = 0, t1 = t, t2 = d + t; c < n; ) {
        const size_t dt = std::min(t1, t2);

        t1 -= dt;
        if (t1 == 0) {
            c += k;
            t1 = t;
        }

        t2 -= dt;
        if (t2 == 0) {
            c += k;
            t2 = t;
        }

        time += dt;
    }

    const size_t t0 = (n + k - 1) / k * t;
    answer(time < t0);
}

int main()
{
    size_t n, t, k, d;
    std::cin >> n >> t >> k >> d;

    solve(n, t, k, d);

    return 0;
}

