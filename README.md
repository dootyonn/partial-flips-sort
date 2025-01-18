# Quiz

## Question 1: Sorting Algorithm (partial flips) 

Given an array of integers arr, sort the array by performing a series of partial flips. 

In one partial flip we do the following steps: 

* Choose an integer k where 1 <= k <= length(arr). 

* Reverse the sub-array arr[0...k-1] (0-indexed). 

For example, if arr = [3,2,1,4] and we performed a partial flip choosing k = 3, we reverse the sub-array [3,2,1], so arr = [1,2,3,4] after the partial flip at k = 3. 

The input array must contain all positive integers from 1 to length(arr)-1 once and only one. For example, for an array of length 7, a valid input is [3,6,1,2,4,7,5]. [1,2,4,5,2,3,7] is invalid because it contains the value 2 twice and it doesn’t contain the value 6.  

 

**First**, implement the partial flip function. 

**Second**, implement a sorting algorithm that uses the partial flip function to sort an array from the smaller number to the larger number.  

This sorting function must output, 

* The sorted array 

* The list of k values (the sequence of partial flips) used to sort the array. 

Any valid answer that sorts the array within 10 * length(arr) flips will be judged as correct. 

**Lastly**, do not forget to write some tests. 

  

**For example:**

```
Input: arr = [3,2,4,1] 

List of k values: ks = [4,2,4,3] 

Explanation: 

We perform 4 partial flips, with k values 4, 2, 4, and 3. 

Starting state: arr = [3, 2, 4, 1] 

After 1st flip (k = 4): arr = [1, 4, 2, 3] 

After 2nd flip (k = 2): arr = [4, 1, 2, 3] 

After 3rd flip (k = 4): arr = [3, 2, 1, 4] 

After 4th flip (k = 3): arr = [1, 2, 3, 4], which is sorted. 
```
 

You can use the language of your choice. You can submit your answer by emailing us the code or by sending us a link to a public Git repository. 

## Instructions

### Run with docker

Container must be built before running the sorting executable. Run the following command to build the container:

```
$ docker build -t quizsort .
```

Run the following command to run the sorting executable with the input array [3,2,4,1]:

```
$ docker run quizsort 3 2 4 1
```
It should print the following output:

```
sorted array: [ 1 2 3 4 ]
k values: [ 3 4 2 3 2 ]
```