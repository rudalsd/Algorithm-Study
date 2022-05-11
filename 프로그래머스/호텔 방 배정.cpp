#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<long long, long long> map;

long long Find(long long N)
{
    if (map[N] == 0) return N;
    return map[N] = Find(map[N]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    for (long long i = 0; i < room_number.size(); i++) {
        long long num = room_number[i];
        if (map[num] == 0) {
            map[num] = Find(num + 1);
            answer.push_back(num);
        }
        else {
            long long next = Find(num + 1);
            answer.push_back(next);
            map[next] = Find(next + 1);
        }
    }
    return answer;
}