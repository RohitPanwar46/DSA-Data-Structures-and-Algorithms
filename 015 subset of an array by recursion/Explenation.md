# Recursion & Backtracking — Subsets

## LeetCode 78: Subsets

For every element, we have 2 choices:

- Include the element
- Exclude the element

```text
Include
   ↓
Explore
   ↓
Backtrack (pop_back)
   ↓
Exclude
```

### Base Case

```cpp
if(i == arr.size())
```

All elements are processed, so the current `ans` is one complete subset.

### Why `pop_back()`?

`push_back()` includes an element. After exploring that branch, `pop_back()` removes it so that we can explore the exclude branch.

```cpp
ans.push_back(arr[i]); // Include
PS(arr, ans, i+1);

ans.pop_back();        // Backtrack

PS(arr, ans, i+1);     // Exclude
```

### Number of Subsets

Each element has 2 choices:

```text
2 × 2 × ... × 2 = 2^n
```

So an array of `n` elements has `2^n` subsets.

---

## LeetCode 90: Subsets II

This version can contain duplicate elements.

Example:

```text
[1, 2, 3, 3]
```

### Duplicate Handling

First, the array should be sorted so duplicate elements are together.

While going to the **exclude branch**, skip consecutive duplicates:

```cpp
int idx = i + 1;

while(idx < arr.size() && arr[idx-1] == arr[idx]){
    idx++;
}

PS(arr, ans, idx);
```

### Why only skip in Exclude?

- **Include:** We may need both `3`s to create `[3,3]`.
- **Exclude:** Skipping the next duplicate prevents generating the same subset again.

---

## Time Complexity

There can be `2^n` subsets.

Since a subset can contain up to `n` elements, generating/printing all subsets takes:

```text
O(n * 2^n)
```

For Subsets II, duplicates may reduce the actual work, but the **worst-case** complexity is still:

```text
O(n * 2^n)
```

## Space Complexity

Recursion depth + `ans`:

```text
O(n)
```

If all generated subsets are stored, output space can be:

```text
O(n * 2^n)
```

---

## Final Takeaway

```text
Subsets = Include + Exclude

Backtracking = Choose → Explore → Undo

Duplicates = Skip duplicate choices in the Exclude branch

Time  = O(n * 2^n)
Space = O(n) auxiliary
```
