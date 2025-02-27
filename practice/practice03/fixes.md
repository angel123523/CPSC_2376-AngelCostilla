## Bug 1: `sumRange` Function - 
**Issue:** The for-loop in `sumRange` excludes the `end` value. This results in the sum not including the last number in the range. - **Cause:** The loop condition uses `< end`, which means the loop stops at `end - 1`. - 
**Fix:** Change the loop condition to `i <= end`. 
## Bug 2: `containsNegative` Function - 
**Issue 1:** The loop runs one step beyond the size of the vector, leading to an out-of-bounds access. -
 **Issue 2:** The condition checks if a number is greater than `0` instead of less than `0` to detect negative values. - **Cause:** The loop condition is `i <= numbers.size()`, which accesses an invalid index on the last iteration, and the comparison logic is inverted. - **Fix:** Change the loop condition to `i < numbers.size()`, and change the check to `if (numbers[i] < 0)`. 
## Bug 3: `findMax` Function - 
**Issue 1:** If the input vector is empty, the function returns `0`, which might not be expected behavior. -
 **Issue 2:** The loop runs to `i <= numbers.size()`, causing an out-of-bounds access. - 
**Issue 3:** The condition `if (numbers[i] >= maxVal)` incorrectly replaces the `maxVal` with equal values. - **Cause:** The loop condition and the check for `maxVal` are incorrect, and empty vector handling is missing. - **Fix:** Add proper handling for empty vectors (e.g., throw an exception), fix the loop to `i < numbers.size()`, and adjust the logic to not replace `maxVal` with equal values.
