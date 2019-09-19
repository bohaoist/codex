class BubbleSort {
public:
    int * bubbleSort(int *array,int num)//冒泡,O(n^2)
{
	bool flag;
	for (int i = 0; i < num; i++)
	{
		flag = false;
		for (int j = 1; j < num - i; j++)
		{
			if (array[j - 1]>array[j])
			{
				swap(array[j - 1], array[j]);
				flag = true;
			}
		}
		if (flag == false)
			break;
	}
		
	return array;
}
};

class SelectionSort {
public:
    int* selectionSort(int* array, int num) {
        // write code here
        int min = 0;
	for (int i = 0; i < num - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < num; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		swap(array[i], array[min]);
	}
	return array;
    }
};

class InsertionSort {
public:
    int* insertionSort(int* arr, int length) {
        // write code here
        int index = 0,target;
	for (int i = 0; i < length-1; i++)
	{
		index = i+1;
		target = arr[index];
		while (index>0 && target < arr[index-1])
		{
			arr[index] = arr[index-1];
			index--;
		}
		arr[index] = target;
	}
        return arr;
    }
};

class MergeSort {
public:
void merge(int array[], int low, int mid, int high)//合并，将array[low~mid]和array[mid+1,high]合并到一个临时数组中，然后再写回。
{
	int i = low, j = mid + 1,k = 0;
	int *tmparr = new int[high - low + 1]{0};
	while (i <= mid&&j <= high)
	{
		if (array[i] < array[j])
		{
			tmparr[k++] = array[i++];
		}
		else
		{
			tmparr[k++] = array[j++];
		}
	}
	while (i <= mid)
	{ 
		tmparr[k++] = array[i++];
	}
	while (j <= high)
	{
		tmparr[k++] = array[j++];
	}
	for (k = 0,i = low; i <= high; k++,i++)
	{
		array[i] = tmparr[k];
	}
	delete tmparr;
}

void mergepass(int array[], int gap, int length)//划分为若干个以步长为gap小数组,共有n/gap个有序子表：R[0...gap-1],R[gap...2*gap-1],...R[(n/gap)*gap,n-1]
{
	int i = 0;
	//归并gap长度的相邻两个子表
	for (i = 0; i + 2 * gap - 1 < length; i = i + 2 * gap)
	{
		merge(array, i, i + gap - 1, i + 2 * gap - 1);
	}
	//余下两个子表，后者长度小于gap
	if (i + gap -1 < length)
	{
		merge(array, i, i + gap - 1, length - 1);
	}
}
int* mergeSort(int* array, int n) //归并排序，利用的分治思想,O(N*logN)
{
	for (int gap = 1; gap < n; gap*=2)//步长为1,2,4,8...2^n的指数增长
	{
		mergepass(array, gap, n);
	}
	return array;

}
};

public static void mergeSort(int[] arr) {
    sort(arr, 0, arr.length - 1);
}

public static void sort(int[] arr, int L, int R) {
    if(L == R) {
        return;
    }
    int mid = L + ((R - L) >> 1);
    sort(arr, L, mid);
    sort(arr, mid + 1, R);
    merge(arr, L, mid, R);
}

public static void merge(int[] arr, int L, int mid, int R) {
    int[] temp = new int[R - L + 1];
    int i = 0;
    int p1 = L;
    int p2 = mid + 1;
    // 比较左右两部分的元素，哪个小，把那个元素填入temp中
    while(p1 <= mid && p2 <= R) {
        temp[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
    }
    // 上面的循环退出后，把剩余的元素依次填入到temp中
    // 以下两个while只有一个会执行
    while(p1 <= mid) {
        temp[i++] = arr[p1++];
    }
    while(p2 <= R) {
        temp[i++] = arr[p2++];
    }
    // 把最终的排序的结果复制给原数组
    for(i = 0; i < temp.length; i++) {
        arr[L + i] = temp[i];
    }
}

class QuickSort {
public:
int partition(int *arr, int left, int right)
{
	int pivotKey = arr[left];
	int pivotindex = left;

	while (left < right)
	{
		while (right>left && arr[right] >= pivotKey) //因为在最终两个指针相遇时，需要找到比pivotkey小的那个数的位置，所以是right指针先移动
			right--;
		while (left<right && arr[left] <= pivotKey)
			left++;
		std::swap(arr[left], arr[right]);
	}
	std::swap(arr[pivotindex], arr[left]);//将最后一个比pivotkey小的那个数与pivotkey位置互换
	return left;//返回划分的位置
}

void Quicksort(int *arr, int left, int right)
{
	if (left < right)
	{
		int pivotpos = partition(arr, left, right);
		Quicksort(arr, left, pivotpos - 1);
		Quicksort(arr, pivotpos + 1, right);
	}
	
}

int* quickSort(int* A, int n) //快排入口
{
	if (A == nullptr || n<=0)
	{
		return A;
	}
	Quicksort(A, 0, n - 1);
	return A;
}

};


public class HeapSort {
     public static void heapAdjust(int[] arr, int start, int end) {
        int temp = arr[start];

        for(int i=2*start+1; i<=end; i=i*2+1) {
            //左右孩子的节点分别为2*i+1,2*i+2

            //选择出左右孩子较小的下标
            if(i < end && arr[i] < arr[i+1]) {
                i ++; 
            }
            if(temp >= arr[i]) {
                break; //已经为大顶堆，=保持稳定性。
            }
            arr[start] = arr[i]; //将子节点上移
            start = i; //下一轮筛选
        }

        arr[start] = temp; //插入正确的位置
    }

    public static int[] heapSorts(int[] arr) {
        if(arr == null || arr.length == 0)
            return arr;

        //建立大顶堆
        for(int i=arr.length/2-1; i>=0; i--) {
            heapAdjust(arr, i, arr.length-1);
        }

        for(int i=arr.length-1; i>=0; i--) {
            swap(arr, 0, i);
            heapAdjust(arr, 0, i-1);
        }
        return arr;

    }

    public static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    public int[] heapSort(int[] A, int n) {
        // write code here
       return heapSorts(A);
    }
}

class ShellSort {
public:
    int* shellSort(int* A, int n) {
        // write code here
        return shellSorts(A,n);
    }
    void shellinsert(int *arr, int length, int gap)
{
	for (int i = 0; i + gap <= length - 1; i++)
	{
		if (arr[i] > arr[i + gap])
		{
			std::swap(arr[i], arr[i + gap]);
			for (int j = i; j - gap>= 0; j = j-gap)
			{
				if (arr[j] < arr[j - gap])
				{
					std::swap(arr[j], arr[j - gap]);
				}
			}
		}
	}
}

int* shellSorts(int* arr, int length) {
	if (arr == nullptr || length <= 0)
		return nullptr;
	int gap = length / 2;//希尔排序的增量每次去长度的1/2
	while (gap >= 1)
	{
		shellinsert(arr, length, gap);
		gap /= 2;
	}
	return arr;
}
};