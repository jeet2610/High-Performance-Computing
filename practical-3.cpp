#include <iostream>
#include <vector>
using namespace std;
/**
* Partition the elements of 1st (A), such that first have elements smaller than
* "who", followed by elements larger than "who". Return the last position of an
* element smaller or equal to "who".
*/
int partition(vector<int>& A, int left, int right, int who) {
for (int i=left; i<right; ++i) {
 if (A[i] <= who) {
 swap(A[i], A[left]);
 left ++;
 }
}
return left - 1;
}
/**
* Quick sort vector A, between index "left" and index "right".
*/
void qsort(vector<int>& A, int left, int right) {
if (left >= right) return;
int middle = left + (right - left) / 2; //find out middle element
swap(A[middle], A[left]);
int midpoint = partition(A, left + 1, right, A[left]);
swap(A[left], A[midpoint]);
qsort(A, left, midpoint);
qsort(A, midpoint + 1, right);
}
void printVector(vector<int>& A) {
for (int i=0; i<A.size(); ++i) {
 cout << A[i] << " ";
}
cout << endl;
}
void testPartition() {
int elements[] = {1, 3, 1, 1, 3};
vector<int> A(elements, elements + 5);
int n = partition(A, 0, 5, 1);
cout << n << endl;
printVector(A);
}
void testSort() {
int elements[] = {1, 12,5, 2,7, 6, 20, 25};
vector<int> A(elements, elements + 8);
qsort(A, 0, A.size());
printVector(A);
}
int main ()
{
testPartition();
cout << "---------------" << endl;
testSort();
return 0;
}
