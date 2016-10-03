# 常见排序算法的实现

## 1. BubbleSort——冒泡排序
  
	代码文件：  
		1. bubble_sort.hpp
			1）冒泡排序（非递归版）
			2）冒泡排序（递归版）
			3）冒泡排序（非递归改进版）
		
## 2. BucketSort——桶排序
  
	代码文件：  
		1. bucket_sort.hpp
			1）桶排序（非递归）
		2. thread_bucket_sort.hpp
			1）桶排序（多线程版）
		
## 3. CountingSort——计数排序

	代码文件：  
		1. counting_sort.hpp
			1）计数排序（非递归）

## 4. HeapSort——堆排序

	代码文件：  
		1. heap_sort.hpp
			1）堆排序（非递归版）
			2）堆排序（递归版）

## 5. InsertSort——插入排序
  
	代码文件：  
		1. insert_sort.hpp
			1）插入排序（非递归版）
			2）插入排序（递归版）
			3）插入排序（非递归迭代器版）
			4）插入排序（用于桶排序）
		
## 6. MergeSort——归并排序
  
	代码文件：  
		1. merge_sort.hpp
			1）归并排序（递归）

## 7. QuickSort——快速排序
  
	代码文件：  
		1. quick_sort.hpp
			1）快速排序（原始版）（递归）
			2）快速排序（随机划分版）（递归）
			3）快速排序（Hoare方法版）（递归）

## 8. SelectionSort——选择排序
  
	代码文件：  
		1. selection_sort.hpp
			1）选择排序（非递归版）
			2）选择排序（递归版）
			
## 9. ShellSort——希尔排序
	代码文件：  
		1. shell_sort.hpp
			1）希尔排序（非递归版）


<br/>
## 算法复杂度分析 
####　　各种排序的算法时间复杂度和空间复杂度比较：

| 排序方法 | 时间复杂度（平均） | 时间复杂度（最好） | 时间复杂度（最差） | 辅助空间复杂度 | 稳定性 |
|:--:|:--:|:--:|:--:|:--:|:--:|
| 冒泡排序 | O(n<sup>2</sup>) | O(n) | O(n<sup>2</sup>) | O(1) | 稳定 |
| 桶排序 | O(n) | O(n) | O(nlog<sub>2</sub>n) | O(n) | 不确定 |
| 计数排序 | O(n+k) | O(n+k) | O(n+k) | O(k) | 稳定 |
| 堆排序 | O(nlog<sub>2</sub>n) | O(nlog<sub>2</sub>n) | O(nlog<sub>2</sub>n) | O(1) | 不稳定 |
| 插入排序 | O(n<sup>2</sup>) | O(n) | O(n<sup>2</sup>) | O(1) | 稳定 |
| 归并排序 | O(nlog<sub>2</sub>n) | O(nlog<sub>2</sub>n) | O(nlog<sub>2</sub>n) | O(n) | 稳定 |
| 快速排序 | O(nlog<sub>2</sub>n) | O(nlog<sub>2</sub>n) | O(n<sup>2</sup>) | O(1) | 不稳定 |
| 选择排序 | O(n<sup>2</sup>) | O(n<sup>2</sup>) | O(n<sup>2</sup>) | O(1) | 不稳定 |
| 希尔排序 | O(n<sup>1.3</sup>) | O(n) | O(n<sup>2</sup>) | O(1) | 不稳定 |

<br/>
## 算法用时测试 
####　　运行环境