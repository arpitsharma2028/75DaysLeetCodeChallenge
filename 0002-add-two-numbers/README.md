<h2><a href="https://leetcode.com/problems/add-two-numbers">2. Add Two Numbers</a></h2><h3>Medium</h3><hr>
<p>You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.</p>

<p><strong>Example 1:</strong></p>
<pre>
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
</pre>

<p><strong>Example 2:</strong></p>
<pre>
Input: l1 = [0], l2 = [0]
Output: [0]
</pre>

<p><strong>Constraints:</strong></p>
<ul>
  <li>The number of nodes in each linked list is in the range <code>[1, 100]</code>.</li>
  <li><code>0 &lt;= Node.val &lt;= 9</code></li>
  <li>The numbers do not contain leading zeros except the number 0 itself.</li>
</ul>

<h3>Approach</h3>
<p>Traverse both lists simultaneously, summing corresponding digits plus a carry. Create new nodes for the result digits (sum % 10) and propagate the carry (sum / 10). Continue while either list has nodes or there is a non-zero carry.</p>

<h3>Complexity</h3>
<ul>
  <li><strong>Time:</strong> O(max(m, n)) — you process each node of the longer list once.</li>
  <li><strong>Space:</strong> O(max(m, n)) — result linked list (excluding input lists).</li>
</ul>

<h3>Solution</h3>
<p>See the implementation in <a href="0002-add-two-numbers/0002-add-two-numbers.cpp">0002-add-two-numbers.cpp</a>.</p>
