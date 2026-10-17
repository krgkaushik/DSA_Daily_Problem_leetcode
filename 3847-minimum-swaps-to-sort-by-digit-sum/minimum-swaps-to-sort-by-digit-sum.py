class Solution:
    def minSwaps(self, nums: list[int]) -> int:
        def get_digit_sum(n: int) -> int:
            return sum(int(d) for d in str(n))
        
        n = len(nums)
        
        # Store (digit_sum, num_value, original_index)
        arr = []
        for i, val in enumerate(nums):
            arr.append((get_digit_sum(val), val, i))
        
        # Sort based on custom criteria:
        # Primary: digit_sum (ascending)
        # Secondary: val (ascending)
        arr.sort(key=lambda x: (x[0], x[1]))
        
        # Track visited elements to find permutation cycles
        visited = [False] * n
        swaps = 0
        
        for i in range(n):
            # If element is already visited or in its correct sorted place
            if visited[i] or arr[i][2] == i:
                continue
            
            # Count the size of the cycle
            cycle_size = 0
            curr = i
            
            while not visited[curr]:
                visited[curr] = True
                curr = arr[curr][2]  # Move to the original index of the current target element
                cycle_size += 1
            
            if cycle_size > 1:
                swaps += (cycle_size - 1)
                
        return swaps