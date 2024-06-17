Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.

=>
O(log(c) \* sqrt(c)) algo.
Use long long to avoid overflow

```
long long low = 0,high = sqrt(c);
while(low<=high){
    if(low*low+high*high == c)  return true;
    else if(low*low+high*high>c) {
        high--;
    }else {
        low++;
    }
}
return false;
```
