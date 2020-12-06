
# Python program to find the maximum for 
# each and every contiguous subarray of
# size k
 
from collections import deque
 
# A Deque (Double ended queue) based 
# method for printing maximum element 
# of all subarrays of size k 

#my fault:  1. 첫번째 window에서 while로 index를 제거안해줌 
# 2. 같은값을 가지는  원소가 들어오면 삭제를 안해줫음 : deque안에는 항상 제일 큰값, 작은값 2개의 index만 들어이엇야하기때문에 삭제
def printMax(arr, n, k):
     
    """ Create a Double Ended Queue, deq that 
    will store indexes of array elements. 
    The queue will store indexes of useful 
    elements in every window and it will
    maintain decreasing order of values from
    front to rear in deq, i.e., arr[deq.front[]]
    to arr[deq.rear()] are sorted in decreasing
    order"""
    deq = deque()
     
    # Process first k (or first window) 
    # elements of array
    for i in range(k):
       
        # For every element, the previous 
        # smaller elements are useless
        # so remove them from deq
        while deq and arr[i] >= arr[deq[-1]] :
            deq.pop()
         
        # Add new element at rear of queue
        deq.append(i)
         
    # Process rest of the elements, i.e. 
    # from arr[k] to arr[n-1]
    for i in range(k, n):
         
        # The element at the front of the
        # queue is the largest element of
        # previous window, so print it
        print(str(arr[deq[0]]) + " ", end = "")
         
        # Remove the elements which are 
        # out of this window
        while deq and deq[0] <= i-k:
             
            # remove from front of deque
            deq.popleft() 
         
        # Remove all elements smaller than
        # the currently being added element 
        # (Remove useless elements)
        while deq and arr[i] >= arr[deq[-1]] :
            deq.pop()
         
        # Add current element at the rear of deq
        deq.append(i)
     
    # Print the maximum element of last window
    print(str(arr[deq[0]]))
     
# Driver code
if __name__=="__main__":
    arr = [12, 1, 78, 90, 57, 89, 56]
    k = 3
    printMax(arr, len(arr), k)
     
# This code is contributed by Shiv Shankar 