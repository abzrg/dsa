# Quick sort (`qsort`) algorithm

Quicksort is a widely used and efficient sorting algorithm that follows the divide-and-conquer paradigm. It was developed by Tony Hoare in 1960 and is known for its average-case time complexity of O(n log n), making it one of the fastest sorting algorithms in practice. Quicksort works by selecting a pivot element, partitioning the array into two sub-arrays (elements less than the pivot and elements greater than the pivot), and then recursively sorting the sub-arrays.


## Algorithm ([wikipedia](https://en.wikipedia.org/wiki/Quicksort#Algorithm))

1. If the range has fewer than two elements, return immediately as there is nothing to do. Possibly for other very short lengths a special-purpose sorting method is applied and the remainder of these steps skipped.

2. Otherwise pick a value, called a pivot, that occurs in the range (the precise manner of choosing depends on the partition routine, and can involve randomness).

3. Partition the range: reorder its elements, while determining a point of division, so that all elements with values less than the pivot come before the division, while all elements with values greater than the pivot come after it; elements that are equal to the pivot can go either way. Since at least one instance of the pivot is present, most partition routines ensure that the value that ends up at the point of division is equal to the pivot, and is now in its final position (but termination of quicksort does not depend on this, as long as sub-ranges strictly smaller than the original are produced).

4. Recursively apply the quicksort to the sub-range up to the point of division and to the sub-range after it, possibly excluding from both ranges the element equal to the pivot at the point of division. (If the partition produces a possibly larger sub-range near the boundary where all elements are known to be equal to the pivot, these can be excluded as well.)


## When to use

Quicksort has several advantages:

- It's highly efficient for large datasets due to its average-case time complexity of O(n log n).
- It's an in-place sorting algorithm, meaning it doesn't require additional memory for sorting, except for the recursive call stack.
- It performs well in practice, and its constant factors are relatively small, making it faster than some other sorting algorithms like Merge Sort.

However, there are certain scenarios where Quicksort might not be the best choice:

1. **Worst-Case Performance**: In the worst-case scenario, when the pivot selection is poor, Quicksort can degrade to O(n^2) time complexity, which is inefficient. This can happen when the pivot is consistently chosen as the smallest or largest element.
2. **Random Data**: Quicksort might not perform as well on datasets with a lot of duplicate elements or already partially sorted data.
3. **Stable Sorting**: Quicksort is not stable by default, meaning the order of equal elements might change after sorting.
4. **Small Datasets**: For very small datasets, the overhead of the recursive calls and partitioning might not be worthwhile, and simpler sorting algorithms like Insertion Sort might perform better.

In summary, Quicksort is a highly efficient sorting algorithm that works well for a wide range of datasets. It's a great choice for sorting large datasets and general-purpose sorting tasks. However, in situations where you need guaranteed performance or stable sorting, or when dealing with small datasets, you might want to consider other sorting algorithms that better fit those requirements.
