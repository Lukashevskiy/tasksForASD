#include <iostream>

struct Array
{
    int *A;
    int size;
    int length;

    void create(int size)
    {
        A = (int *)malloc(size * sizeof(int));
        length = 0;
    }

    void display()
    {
        for (int i = 0; i < length; i++)
        {
            std::cout << A[i] << " ";
        }
        std::cout << std::endl;
    }

    void append(int value)
    {
        if (length < size)
        {
            A[length++] = value;
        }
    }

    void insert(int index, int value)
    {
        if (index >= 0 && index < length)
        {
            for (int i = length; i > index; i--)
            {
                A[i] = A[i - 1];
            }
            A[index] = value;
            length++;
        }
    }

    int del(int index)
    {
        int x = 0;
        if (index >= 0 && index < length)
        {
            x = A[index];
            for (int i = index; i < length - 1; i++)
            {
                A[i] = A[i + 1];
            }
            length--;
            return x;
        }
        return -1;
    }

    int search(int value)
    {
        for (int i = 0; i < length; i++)
        {
            if (A[i] == value)
            {
                return i;
            }
        }
        return -1;
    }

    int seach_transposition(int value)
    {
        for (int i = 0; i < length; i++)
        {
            if (A[i] == value)
            {
                std::swap(A[i], A[0]);
                return i;
            }
        }
        return -1;
    }

    void sort()
    {
        for (int i = 0; i < length - 1; i++)
        {
            for (int j = 0; j < length - i - 1; j++)
            {
                if (A[j] > A[j + 1])
                {
                    std::swap(A[j], A[j + 1]);
                }
            }
        }
    }

    int bin_search(int value)
    {
        int low, mid, high;
        low = 0;
        high = length - 1;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (value == A[mid])
            {
                return mid;
            }
            else if (value < A[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return -1;
    }

    int bin_search_(int value, int low, int high)
    {
        int mid = 0;

        mid = (low + high) / 2;
        if (value == A[mid])
        {
            return mid;
        }
        else if (value < A[mid])
        {
            bin_search_(value, low, mid - 1);
        }
        else
        {
            bin_search_(value, mid + 1, high);
        }
        return -1;
    }

    int bin_search_recursive(int value)
    {
        return bin_search_(value, 0, length - 1);
    }

    int max()
    {
        int max = A[0];
        for (int i = 1; i < length; i++)
        {
            if (A[i] > max)
            {
                max = A[i];
            }
        }
        return max;
    }

    int sum()
    {
        int sum = 0;
        for (int i = 0; i < length; i++)
        {
            sum += A[i];
        }
        return sum;
    }

    float mean()
    {
        return (float)sum() / length;
    }

    void reverse()
    {
        int *B = (int *)malloc(length * sizeof(int));
        int i, j;
        for (i = length - 1, j = 0; i >= 0; i--, j++)
        {
            B[j] = A[i];
        }
        for (i = 0; i < length; i++) {
            A[i] = B[i];
        }
    }

    void reverse2() {
        int i, j;
        for (i=0, j=length-1; i<j; i++, j--){
            std::swap(A[i], A[j]);
        }
    }

    void reverse(int start, int stop){
        for (; start < stop; start++, stop--){
            std::swap(A[start], A[stop]);
        }
    }

    void roll(int n){
        reverse(0, length - 1);
        reverse(0, n - 1);
        reverse(n, length - 1);
    }

    void insert_sorted(int value) {
        if (length == size) {
            return;
        }
        int i = length-1;
        while (i >= 0 && A[i] > value) {
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = value;
        length++;
    }

    bool is_sorted_ascending() {
        for (int i = 0; i < length -1; i++) {
            if (A[i] > A[i+1]) {
                return false;
            }
        }
        return true;
    }

    Array merge_with(Array other) {
        int i, j, k;
        i = j = k = 0;
        Array merged;
        merged.create(length + other.length);
        while (i < length && j < other.length) {
            if (A[i] < other.A[j]) {
                merged.A[k++] = A[i++];
            }
            else {
                merged.A[k++] = other.A[j++];
            }
        }
        for(; i < length; i++) {
            merged.A[k++] = A[i];
        }
        for(; j < other.length; j++) {
            merged.A[k++] = other.A[j];
        }
        merged.length = length + other.length;
        return merged;
    }

    Array union_op(Array other){
        int i, j, k;
		i = j = k = 0;
		Array result;
		result.create(length + other.length);
		while(i < length && j < other.length){
			if(A[i] < other.A[j]){
				result.A[k++] = A[i++];
			}else if( other.A[j] < A[i]){
				result.A[k++] = other.A[j++];
			}else{
				result.A[k++] = A[i++];
				j++;
			}
		}
		for(; i < length; i++){
			result.A[k++] = A[i];
		}
		for(; j < other.length; j++){
			result.A[k++] = other.A[j];
		}
		result.length = k;
		return result;
    }

};

int main()
{
    int raw_array[10] = {3, 1, 10, 20, -3, 0, 40};
    Array arr = {raw_array, 10, 7};
    arr.display();
    arr.roll(3);
    arr.display();
    return 0;
}
