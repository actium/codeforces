#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

int main()
{
    size_t n;
    std::cin >> n;

    std::pair<unsigned, unsigned> last_visit_time;
    size_t cash_count = 0, max_cash_count = 0;
    for (size_t i = 0; i < n; ++i) {
        std::pair<unsigned, unsigned> visit_time;
        std::cin >> visit_time.first >> visit_time.second;

        if (i == 0 || visit_time != last_visit_time) {
            last_visit_time = visit_time;
            cash_count = 1;
        } else {
            ++cash_count;
        }

        max_cash_count = std::max(max_cash_count, cash_count);
    }

    answer(max_cash_count);

    return 0;
}

