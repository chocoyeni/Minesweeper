#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// ham sinh ban do min
vector<vector<int> > generateMap(int m, int n, int k) {
    vector<vector<int> > map(m, vector<int>(n, 0));
    int count = 0;
    while (count < k) {
        int i = rand() % m;
        int j = rand() % n;
        if (map[i][j] != -1) {
            map[i][j] = -1;
            count++;
            for (int x = max(0, i-1); x < min(m, i+2); x++) {
                for (int y = max(0, j-1); y < min(n, j+2); y++) {
                    if (map[x][y] != -1) {
                        map[x][y]++;
                    }
                }
            }
        }
    }
    return map;
}

// ham in ban do
void printMap(vector<vector<int> > map, bool showAll=false) {
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[0].size(); j++) {
            if (showAll || map[i][j] < 0) {
                cout << "*";
            } else {
                cout << map[i][j];
            }
            cout << " ";
        }
        cout << endl;
    }
}

int main() {
    int m, n, k;
    cout << "Enter map size (m n): ";
    cin >> m >> n;
    cout << "Enter number of mines (K): ";
    cin >> k;

    srand(time(NULL));
    vector<vector<int> > map = generateMap(m, n, k);
    printMap(map, true);

    bool gameOver = false;
    while (!gameOver) {
        int x, y;
        cout << "Enter coordinate (x y): ";
        cin >> x >> y;

        if (map[x][y] == -1) {
            cout << "YOU'RE DEAD!" << endl;
            printMap(map, true);
            gameOver = true;
        } else {
            map[x][y] = -map[x][y];
            printMap(map);
        }
    }

    return 0;
}

