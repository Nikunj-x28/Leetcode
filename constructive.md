# Finding intersection area of two Rectangles given bottom left corner and top right corner
```
long long intersect(vector<int> &rectangle_one_bottom,vector<int>& rectangle_one_top,
                    vector<int> &rectangle_two_bottom,vector<int>& rectangle_two_top){
            
            // just replace
            x coordinate -> 0
            y coordinate -> 1


            int y1=max(rectangle_one_bottom[y],rectangle_two_bottom[y]);
            int y2=min(rectangle_one_top[y],rectangle_two_top[y]);
            if(y1>=y2) return 0;


            int x1=max(rectangle_one_bottom[x],rectangle_two_bottom[x]);
            int x2=min(rectangle_one_top[x],rectangle_two_top[x]);
            if(x1>=x2) return 0;

            return 1ll * (x2-x1) * (y2-y1);
}
```
# SMALLEST PRIME FACTOR ALGORITHM
```
#define MAXN 100001
int spf[MAXN];
void sieve()
{
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)
        spf[i] = i;
    for (int i = 2; i * i < MAXN; i++) {
        // checking if i is prime
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i)
            // if not marked by any smaller prime mark it
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}
```