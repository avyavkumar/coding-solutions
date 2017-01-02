#include <cstdio>
#include <cstring>

int dp[4010][102];
int a[102];
const int MOD = (1e9) + 7;

int main()
{
	int m, r, s;
	while (scanf("%d%d%d",&m,&r,&s) != EOF)
    {
		for (int i = 0 ; i < m ; ++i)
			scanf("%d", &a[i]);
		if (r == 0 && s == 0)
        {
			printf("0\n");
			continue;
		}
		if ((r + s) % 2 == 1 || r < s)
        {
			printf("0\n");
			continue;
		}

		int maxS = (r + s + 1) / 2;
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for (int i = 0 ; i < m ; ++i)
        {
			for (int sum = maxS ; sum >= 0 ; --sum)
            {
				if (sum + a[i] > maxS) continue;
				for (int cnt = 0 ; cnt <= i ; ++cnt)
                {
					dp[sum+a[i]][cnt+1] += dp[sum][cnt];
					dp[sum+a[i]][cnt+1] %= MOD;
				}
			}
		}
		int total = 0;
		for (int cnt = 0 ; cnt <= m ; ++cnt)
        {
			total += (int)((long long)dp[(r+s)/2][cnt] * dp[(r-s)/2][cnt] % MOD);
			total %= MOD;
		}
		printf("%d\n", total);
	}
	return 0;
}
