class Solution:
    def isPalindrome(self, s: str) -> bool:
        clean_s = []

        for ch in s:
            if ch.isalnum():
                clean_s.append(ch.lower())

        clean_s = "".join(clean_s)

        left, right = 0, len(clean_s) - 1

        while left < right:
            if clean_s[left] != clean_s[right]:
                return False
            else:
                left += 1
                right -= 1

        return True