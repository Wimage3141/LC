#include <iostream>
using namespace std;

struct P {
  int x, y;
  bool operator<(const P& p) {
    if(x != p.x) return x < p.x;
    else return y < p.y;
  }
};

int main() {
    struct P testp1;
    testp1.x = 5;
    testp1.y = 2;
    
    struct P testp2;
    testp2.x = 3;
    testp2.y = 10;
    
    if(testp1 < testp2) {
        cout << "p1 is smaller" << endl;
    } else {
        cout << "p2 is smaller" << endl;
    }

    return 0;
}
