#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> scores(n);
    vector<vector<int>> dislikes(n);

    for (int i = 0; i < n; ++i) {
        cin >> scores[i].first >> scores[i].second;
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        dislikes[u].push_back(v);
        dislikes[v].push_back(u);
    }

    vector<long long> total_scores(n, 0);

    for (int i = 0; i < n; ++i) {
        vector<int> valid_pairs;
        for (int j = 0; j < n; ++j) {
            if (i != j && find(dislikes[i].begin(), dislikes[i].end(), j) == dislikes[i].end()) {
                valid_pairs.push_back(min(scores[i].first + scores[j].second, scores[i].second + scores[j].first));
            }
        }
        sort(valid_pairs.begin(), valid_pairs.end());
        for (int k = 0; k < valid_pairs.size(); ++k) {
            total_scores[i] += valid_pairs[k];
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << total_scores[i] << " ";
    }
    cout << endl;

    return 0;
}
