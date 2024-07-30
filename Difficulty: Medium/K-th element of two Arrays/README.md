<h2><a href="https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=k-th-element-of-two-sorted-array">K-th element of two Arrays</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given two sorted arrays <strong>arr1</strong> and <strong>arr2</strong> of sizes <strong>n</strong> and <strong>m</strong> respectively and an element <strong>k</strong>. The task is to find the element that would be at the k<sup>th</sup> position of the combined sorted array.</span><br>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Examples :</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>arr1[] = {2, 3, 6, 7, 9}, arr2[] = {1, 4, 8, 10}, k = 5
<strong>Output: </strong>6
<strong>Explanation: </strong>The final combined sorted array would be -
1, 2, 3, 4, 6, 7, 8, 9, 10
The 5th element of this array is 6.
</span></pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>arr1[] = {100, 112, 256, 349, 770}, arr2[] = {72, 86, 113, 119, 265, 445, 892}, k = 7
<strong>Output: </strong>256
<strong>Explanation: </strong>Combined sorted array is - 72, 86, 100, 112,
113, 119, 256, 265, 349, 445, 770, 892
7th element of this array is 256.</span></pre>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(Log(n) + Log(m))<br><strong>Expected Auxiliary Space:</strong> O(Log (n))</span></p>
<p><br><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 &lt;= arr1.length, arr2.length &lt;= 10<sup>6</sup><br>0 &lt;= arr1<sub>i</sub>, arr2<sub>i</sub> &lt; 10<sup>8</sup><br>1 &lt;= k&lt;=&nbsp;</span><span style="font-size: 18px;">arr1.length+arr2.length</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Flipkart</code>&nbsp;<code>Microsoft</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Divide and Conquer</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;<code>Binary Search</code>&nbsp;