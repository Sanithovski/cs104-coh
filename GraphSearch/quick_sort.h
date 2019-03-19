#ifndef Q_SORT_H
#define Q_SORT_H

#include <vector>
#include <algorithm>


/**
 * Implementing the quick_sort algorithm
 * @param v The vector to be sorted. By reference.
 */
void quick_sort(std::vector<int>& v);

/**
 * Chooses a pivot from the given index range. 
 * This function implement the index selection process with
 * random selection, which is not the best choice.
 * @param start The start of the index. Included in selection.
 * @param end The end of the index. Included in selection.
 * @return The selected pivot index. If start is bigger
 * or equal to n return start;
 */
unsigned int select_pivot(unsigned int start, unsigned int end);

#endif