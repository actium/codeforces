#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

void answer(size_t v)
{
    std::cout << v << '\n';
}

int main()
{
    using point_t = std::pair<int, int>;

    size_t n;
    std::cin >> n;

    std::unordered_map<int, std::vector<point_t>> groups_by_x;
    std::unordered_map<int, std::vector<point_t>> groups_by_y;
    for (size_t i = 0; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;

        groups_by_x[x].emplace_back(x, y);
        groups_by_y[y].emplace_back(x, y);
    }

    size_t count = 0;
    for (auto& entry : groups_by_x) {
        auto& group_by_x = entry.second;
        if (group_by_x.size() < 3)
            continue;

        std::sort(group_by_x.begin(), group_by_x.end());

        for (size_t i = 1; i < group_by_x.size() - 1; ++i) {
            const point_t& candidate = group_by_x[i];

            const auto& group_by_y = groups_by_y[candidate.second];
            if (group_by_y.size() < 3)
                continue;

            size_t lesser = 0, greater = 0;
            for (const point_t& p : group_by_y) {
                if (p.first < candidate.first)
                    ++lesser;
                if (p.first > candidate.first)
                    ++greater;
                if (lesser > 0 && greater > 0)
                    break;
            }

            count += (lesser > 0 && greater > 0);
        }
    }

    answer(count);

    return 0;
}

