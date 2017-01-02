// NOT OPTIMISED FOR DP

public class Solution
{

    public boolean canIWin(int maxChoosableInteger, int desiredTotal)
    {

        if (maxChoosableInteger >= desiredTotal) {
            return true;
        }
        if (maxChoosableInteger <= 0 || desiredTotal <= 0) {
            return false;
        }

        List<Integer> pool = new ArrayList<>();
        for (int i = 1; i <= maxChoosableInteger; i++) {
            pool.add(i);
        }

        return canIWinHelper(pool, desiredTotal);
    }

    private boolean canIWinHelper(List<Integer> pool, int desiredTotal)
    {
        if (pool.get(pool.size() - 1) >= desiredTotal) {
            return true;
        }

        for (int i = 0; i < pool.size(); i++) {
            int removed = pool.remove(i);

            boolean win = !canIWinHelper(pool, desiredTotal - removed);

            pool.add(i, removed);

            if (win) {
                return true;
            }
        }

        return false;
    }
}
