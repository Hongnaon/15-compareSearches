# compare Searches { Result Image }
![](./15-compareSearches결과.png)

!A, B, C에 대해서 퀵 정렬후의 이진탐색에서 순차탐색보다 적게 비교하는 이유

순차 탐색은 배열의 첫 번째부터 마지막까지 순차적으로 검색을 수행
최악의 경우에는 배열의 끝까지 탐색해야 하므로, 최악의 시간 복잡도는 O(N)

이진 탐색은 정렬된 배열에서만 사용 가능하며, 배열의 중간값을 기준으로 탐색 범위를 절반으로 좁혀가며 찾음
이진 탐색은 매번 비교를 통해 배열을 절반으로 나누어가므로 시간복잡도는 O(log N)

퀵 정렬은 배열을 정렬하는 알고리즘이고 시간 복잡도는 O(N log N)
퀵 정렬을 사용하여 배열을 정렬하면, 이진 탐색을 활용하여 탐색 가능

순차 탐색은 배열의 크기에 비례하여 비교 횟수가 O(N)으로 증가, 이진 탐색은 O(log N)으로 비교 횟수가 상대적으로 적음.

따라서 퀵 정렬 후 이진 탐색을 사용하면 순차 탐색보다 비교 횟수가 평균적으로 적게 나옴.
