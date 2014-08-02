#include <iostream>
#include <cstdint>

using namespace std;

int8_t grid[100][100];
int dx[] = {-0, +1, +0, -1};
int dy[] = {-1, +0, +1, -0};


bool isCavity(int a, int b, int n)
{
  if (a == 0 || b == 0 || a == n - 1 || b == n - 1)
    return false;

  int depth = grid[a][b];

  for (int i = 0; i<4; i++) {
    if (depth<grid[i][j]) {
      return false;
    }
  }

  return true;
}

int main()
{
  int n, i, j;
  cin >> n;

  for (i = 0; i<n; i++) {
    for (j = 0; j<n; j++) {
      cin >> grid[i][j];
    }
  }

  for (i = 0; i<n; i++) {
    for (j = 0; j<n; j++) {
      if (isCavity(i, j, n))
        cout << 'X';
      else cout << grid[i][j];
    }
    cout << endl;
  }
}