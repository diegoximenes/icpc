#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast_io ios::sync_with_stdio(false)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL
const double PI = acos(-1);
const double EPS = 1e-9;

inline int cmp_double(double x, double y, double tol = EPS) {
    // (x < y): -1, (x == y): 0, (x > y): 1
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

#define MAX 1005

int min_salary[MAX], offered_salary[MAX], max_job_offers[MAX];
string qual[MAX];
bool company_selected[MAX];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) cin >> min_salary[i];
        for (int i = 0; i < m; ++i)
            cin >> offered_salary[i] >> max_job_offers[i];
        for (int i = 0; i < n; ++i)
            cin >> qual[i];

        memset(company_selected, 0, sizeof(company_selected));
        int cnt_candidates = 0, cnt_companies = 0;
        ll salaries = 0;
        for (int i = 0; i < n; ++i) {
            int company = -1, max_salary = -1;
            for (int j = 0; j < m; ++j) {
                if (qual[i][j] == '1' &&
                    offered_salary[j] > max_salary &&
                    max_job_offers[j] > 0) {

                    company = j;
                    max_salary = offered_salary[j];
                }
            }
            if (max_salary >= min_salary[i]) {
                cnt_candidates++;
                company_selected[company] = 1;
                salaries += max_salary;
                max_job_offers[company]--;
            }
        }

        for (int i = 0; i < m; ++i)
            if (!company_selected[i])
                cnt_companies++;

        cout << cnt_candidates << " " << salaries << " " << cnt_companies <<
            endl;
    }

    return 0;
}
