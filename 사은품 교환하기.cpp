#include <iostream>
#include<algorithm>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int T;
   cin >> T;

   while(T--) {
      long long n, m;
      cin >> n >> m;

      long long a, b, result;

      a = n / 5;   // 시즌 한정 음료 쿠폰으로 가능한 최대의 상품 수
      b = (n + m) / 12;   // 전체 쿠폰으로 가능한 최대의 상품 수

      result = min(a, b);

      cout << result << "\n";
   }
   
   return 0;
}
