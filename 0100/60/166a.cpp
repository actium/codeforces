#include <algorithm>
#include <iostream>
#include <vector>

struct TeamResult {
    size_t solution_count;
    size_t penalty;

    bool operator <(const TeamResult& r) const noexcept
    {
        return solution_count > r.solution_count || solution_count == r.solution_count && penalty < r.penalty;
    }
    bool operator ==(const TeamResult& r) const noexcept
    {
        return solution_count == r.solution_count && penalty == r.penalty;
    }
};

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(std::vector<TeamResult>& r, size_t k)
{
    std::sort(r.begin(), r.end());

    answer(std::count(r.cbegin(), r.cend(), r[k-1]));
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<TeamResult> r(n);
    for (TeamResult& x : r)
        std::cin >> x.solution_count >> x.penalty;

    solve(r, k);

    return 0;
}

