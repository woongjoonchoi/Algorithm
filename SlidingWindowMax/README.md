# slidingwindow max

### sliding window를 하면서 각 window의 최댓값을 찾는 것이다.
### 여기서는 O(N)짜리 알고리즘을 소개 하겠다.

## Method
우리는 deque라는 자료구조를 사용할 것이다.     
deque에는 '쓸모있는' 값만 저장할 것이다. 쓸모있는 값들이란 , 1. window의 범위안에 있는  값, 2. 앞으로의 나올 윈도우의 원소들보다 큰 값
결국, deque에는 윈도우 범위 안에 있으면서, 값들이 정렬되어 있을 것이다.

![image](https://user-images.githubusercontent.com/50165842/101272502-3a8d5c00-37d0-11eb-99ed-07670c815368.png)

1. k개를 저장할 수 있는 deque를 만든다.     
2. 처음 k개에 대하여 원소를 deque에 삽입하는데 , 삽입하기전에 deque의 마지막 원소보다 새로 들어오는 원소가 크거나 같다면, deque 마지막 원소가 클때까지  , pop해준다. 그리고 나서, 삽입을해준다.
3. k~ array 끝까지 , 반복해준다.

4. deque의 first를 출력한다.
5. deque의 왼쪽 원소가 window를 벗어낫으면 , window안에 있을때 까지 , pop해준다.
6. deque의 마지막 원소보다 새로 들어오는 원소가 크거나 같다면, deque 마지막 원소가 클때까지  , pop해준다
7.삽입해준다.

8. loop가 끝나면 deque의 왼쪽 원소를 출력해준다.

참조 : https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/#comment-10874
