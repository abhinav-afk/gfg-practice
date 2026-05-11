class Solution {
    public boolean palindromePair(String[] arr) {
        int n = arr.length;
        if (n < 2) return false;

        // Map to store strings and their original indices for O(1) lookup
        Map<String, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            map.put(arr[i], i);
        }

        for (int i = 0; i < n; i++) {
            String s = arr[i];
            int len = s.length();

            // Try every possible split point in the string
            for (int j = 0; j <= len; j++) {
                String prefix = s.substring(0, j);
                String suffix = s.substring(j);

                // Case 1: If prefix is a palindrome, look for reverse(suffix)
                if (isPalindrome(prefix)) {
                    String revSuffix = new StringBuilder(suffix).reverse().toString();
                    if (map.containsKey(revSuffix) && map.get(revSuffix) != i) {
                        return true;
                    }
                }

                // Case 2: If suffix is a palindrome, look for reverse(prefix)
                // Note: j < len prevents double-counting the full string vs empty string logic
                if (j < len && isPalindrome(suffix)) {
                    String revPrefix = new StringBuilder(prefix).reverse().toString();
                    if (map.containsKey(revPrefix) && map.get(revPrefix) != i) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    // Standard helper to check if a string reads the same forward and backward
    private boolean isPalindrome(String s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (s.charAt(left++) != s.charAt(right--)) {
                return false;
            }
        }
        return true;
    }
}

