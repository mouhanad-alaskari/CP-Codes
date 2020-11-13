class Tools {
    
    public static boolean[] seive(int n) {
        boolean [] isPrime = new boolean[n+1];
        Arrays.fill(isPrime, true);
        
        for(int i=2; i*i<=n; i++)
            if(isPrime[i])
                for(int j=i; i*j<=n; j++)
                    isPrime[i*j] = false;
        
        isPrime[1] = false;
        
        return isPrime;
    }
    
    public static boolean next_permutation(int[] p, int len) {
        int a = len - 2;
        while (a >= 0 && p[a] >= p[a + 1]) {
            a--;
        }

        if (a == -1) {
            return false;
        }

        int b = len - 1;
        while (p[b] <= p[a]) {
            b--;
        }

        p[a] += p[b];
        p[b] = p[a] - p[b];
        p[a] -= p[b];

        for (int i = a + 1, j = len - 1; i < j; i++, j--) {
            p[i] += p[j];
            p[j] = p[i] - p[j];
            p[i] -= p[j];
        }

        return true;
    }
    
    public static int lower_bound(Comparable[] arr, Comparable key) {
        int len = arr.length;
        int lo = 0;
        int hi = len-1;
        int mid = (lo + hi)/2;
        while (true) {
            int cmp = arr[mid].compareTo(key);
            if (cmp == 0 || cmp > 0) {
                hi = mid-1;
                if (hi < lo)
                    return mid;
            } else {
                lo = mid+1;
                if (hi < lo)
                    return mid<len-1?mid+1:-1;
            }
            mid = (lo + hi)/2;
        }
    }

    public static int upper_bound(Comparable[] arr, Comparable key) {
        int len = arr.length;
        int lo = 0;
        int hi = len-1;
        int mid = (lo + hi)/2;
        while (true) {
            int cmp = arr[mid].compareTo(key);
            if (cmp == 0 || cmp < 0) {
                lo = mid+1;
                if (hi < lo)
                    return mid<len-1?mid+1:-1;
            } else {
                hi = mid-1;
                if (hi < lo)
                    return mid;
            }
            mid = (lo + hi)/2;
        }
    }

}