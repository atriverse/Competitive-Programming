/*
Dimash learned that Mansur wrote something very unpleasant about him to a friend, so he decided to find out his password at all costs and discover what exactly he wrote.

Believing in the strength of his password, Mansur stated that his password — is a binary string of length n. He is also ready to answer Dimash's questions of the following type:

Dimash says a binary string t, and Mansur replies whether it is true that t is a substring of his password.

Help Dimash find out the password in no more than 2n operations; otherwise, Mansur will understand the trick and stop communicating with him.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤100). The description of the test cases follows.

Interaction
At the beginning of each test case, first read n (1≤n≤100) — the size of the binary string. Then proceed to guessing it.

To guess each string s, you can make no more than 2n queries of the following type:

"? t", where t is a binary string such that (1≤|t|≤n).
In response to this query, you will receive 1 if t is a substring of s, and 0 otherwise.

Once you receive the answer, output a single string in the following format:

"! s", where s is a binary string of size n.
After that, proceed to solve the next test case.

If you make an incorrect attempt or exceed the limit of 2n attempts, you will receive −1 instead of an answer and get the verdict Wrong answer. In this case, your program should terminate immediately to avoid undefined verdicts.
After outputting the queries, do not forget to output a newline character and flush the output buffer. Otherwise, you will receive the verdict Solution "hung". To flush the buffer, use:

fflush(stdout) or cout.flush() in C++;
System.out.flush() in Java;
flush(output) in Pascal;
stdout.flush() in Python;
refer to the documentation for other languages.
Hacks:

To use hacks, use the following format of tests:

The first line should contain a single integer t (1≤t≤100) — the number of test cases.

The first line of each test case should contain a single number n (1≤n≤100) — the length of the string. The second line should contain a binary string of size n.

Example
Input
4
3

0

0

1

4

4

2
Output


? 00

? 000

? 010

! 010

! 1100

! 0110

! 10
Note
In the first example, the string 010 is given. Therefore, the answers to the queries are as follows:

"? 00" 00 is not a substring of 010, so the answer is 0.

"? 000" 000 is not a substring, so the answer is 0.

"? 010" 010 is a substring, so the answer is 1.

In the second example, the string is 1100, in the third 0110, and in the fourth 10.
*/