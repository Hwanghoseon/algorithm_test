using namespace std;

long long gcd(int a, int b){
    long long c;
    
    while(b){
        c = a % b;
        a = b;
        b = c;
    }
    
    return a;
}

long long solution(int w,int h) {
    long long W = w;
    long long H = h;
    long long answer = W * H;
        
    long long temp = w + h - gcd(w, h);
    
    answer -= temp;
    
    return answer;
}
