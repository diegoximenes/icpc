#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast_io ios::sync_with_stdio(false)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1);
const double EPS = 1e-9;

inline int cmp_double(double x, double y, double tol = EPS) {
    // (x < y): -1, (x == y): 0, (x > y): 1
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);

        unordered_map<int, int> cnt_available_tasks_per_worker;
        set<pair<int, int>> cnt_available_tasks_per_worker_set;

        unordered_map<int, int> worker_to_next_time;

        for (int i = 0; i < m; ++i) {
            int worker_id;
            scanf("%d", &worker_id);
            worker_id--;
            cnt_available_tasks_per_worker[worker_id]++;
        }

        set<pair<int, pair<int, int>>> available_time;
        for (int worker_id = 0; worker_id < n; ++worker_id) {
            available_time.insert(mp(0, mp(-cnt_available_tasks_per_worker[worker_id], worker_id)));
            if (cnt_available_tasks_per_worker[worker_id] > 0) {
                cnt_available_tasks_per_worker_set.insert(mp(-cnt_available_tasks_per_worker[worker_id], worker_id));
            }
            worker_to_next_time[worker_id] = 0;
        }

        int last_time = 0;
        while (!available_time.empty()) {
            pair<int, pair<int, int>> available_time_element = *available_time.begin();
            available_time.erase(available_time.begin());
            int time = available_time_element.fi;
            int cnt_available_tasks = -available_time_element.se.fi;
            int worker_id = available_time_element.se.se;

            last_time = max(time, last_time);

            if (cnt_available_tasks > 0) {
                cnt_available_tasks_per_worker_set.erase(mp(-cnt_available_tasks_per_worker[worker_id], worker_id));

                cnt_available_tasks_per_worker[worker_id]--;
                available_time.insert(mp(time + 1, mp(-cnt_available_tasks_per_worker[worker_id], worker_id)));
                worker_to_next_time[worker_id] = time + 1;

                if (cnt_available_tasks_per_worker[worker_id] > 0) {
                    cnt_available_tasks_per_worker_set.insert(mp(-cnt_available_tasks_per_worker[worker_id], worker_id));
                }
            } else if (!cnt_available_tasks_per_worker_set.empty()) {
                pair<int, int> cnt_available_tasks_per_worker_set_element = *cnt_available_tasks_per_worker_set.begin();
                cnt_available_tasks_per_worker_set.erase(cnt_available_tasks_per_worker_set.begin());

                int worker_id_to_get_task = cnt_available_tasks_per_worker_set_element.se;

                cnt_available_tasks_per_worker[worker_id_to_get_task]--;
                if (cnt_available_tasks_per_worker[worker_id_to_get_task] > 0) {
                    cnt_available_tasks_per_worker_set.insert(mp(-cnt_available_tasks_per_worker[worker_id_to_get_task], worker_id_to_get_task));
                }

                pair<int, pair<int, int>> available_time_worker_to_get_task_element = *available_time.find(mp(worker_to_next_time[worker_id_to_get_task], mp(-cnt_available_tasks_per_worker[worker_id_to_get_task]-1, worker_id_to_get_task)));
                available_time.erase(available_time_worker_to_get_task_element);
                available_time_worker_to_get_task_element.se.fi = -cnt_available_tasks_per_worker[worker_id_to_get_task];
                available_time.insert(available_time_worker_to_get_task_element);

                available_time.insert(mp(time + 2, mp(0, worker_id)));
            }
        }

        printf("%d\n", last_time);
    }

    return 0;
}
