#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(std::string q, size_t t)
{
    const size_t n = q.length();

    for (size_t i = 0; i < t; ++i) {
        std::string next_q = q;
        for (size_t j = 0; j < n - 1; ++j) {
            if (q[j] == 'B' && q[j+1] == 'G') {
                next_q[j] = 'G';
                next_q[j+1] = 'B';
            }
        }
        q.swap(next_q);
    }

    answer(q);
}

int main()
{
    size_t n, t;
    std::cin >> n >> t;

    std::string q;
    std::cin >> q;

    solve(q, t);

    return 0;
}

