#include <iostream>
#include <vector>
using namespace std;

inline void Rotate(vector<int> &vec)
{
    int m = vec.back();
    vec.pop_back();
    vec.insert(vec.begin(), m);
}

inline void input(vector<int> &vec, int N)
{
    for (int i = 0; i < N; i++)
    {
        int d;
        cin >> d;
        vec.push_back(d);
    }
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<int> vec;
        input(vec, N);

        Rotate(vec);

        for (auto val : vec)
            cout << val << " ";

        cout << endl;
    }

    return 0;
}