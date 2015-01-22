//============================================================================
// Name        : PQueueSort.cpp
// Author      : Aman Mishra
// Description : Sorting a priority queue using sort function from the algorithm library
//============================================================================

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main(){
	priority_queue<int> mypq;
	mypq.push(30);
	mypq.push(20);
	mypq.push(10);
	mypq.push(90);
	mypq.push(24);
	mypq.push(18);
	mypq.push(78);
	mypq.push(21);

	//A copy of the priority queue that will be used to demonstrate how we can modify elements and push them back in.
	priority_queue<int> mypq_copy=mypq;

	//This queue will just be used to demonstrate how we can change the priority queue to change from descending order to ascending order simply by changing
	//the comparator function.
	priority_queue<int,std::vector<int>,std::greater<int>> mypq_asc;

	/**Printing out the queue. Notice that the queue is in descending order. This is due to
	 * the fact the priority queue uses the default comparator function std::less when pushing
	 * elements. The underlying container for the priority queue is still a vector, unless otherwise
	 * specified.
	 * Output from a line of a dissassembler showing the syntax of the underlying priority queue..
	 * <std::priority_queue<int, std::vector<int, std::allocator<int> >, std::less<int> >::priority_queue(std::less<int> const&, std::vector<int, std::allocator<int> >&&)>
	 *
	 */
	while(!mypq.empty()){
		int temp=mypq.top();
		cout<<mypq.top()<<' ';
		mypq.pop();
		mypq_asc.push(temp);
	}
	cout<<endl;

	//Printing the priority queue that was sorted in ascending order
	while(!mypq_asc.empty()){
		cout<<mypq_asc.top()<<' ';
		mypq_asc.pop();
	}
	cout<<endl;

	/**This array simulates how we may be doing different amounts of work for different elements in the queue.
	 * In this case, I'm simply filling the array with random values from 1 to 99 and then these values will
	 * be added to a value in the queue and this new value will be pushed back into a different queue.
	 */
	int myarr[8];
	for(auto&x : myarr){
		x=rand()%100+1;
	}
	for(auto x : myarr){
		cout<<x<<' ';
	}
	cout<<endl;

	//The new queue that the modified ints will be pushed into.
	priority_queue<int> modified;
	
	for(auto x: myarr){
		int temp=mypq_copy.top();
		mypq_copy.pop();
		modified.push(temp+x);
	}

	while(!modified.empty()){
		cout<<modified.top()<<' ';
		modified.pop();
	}
	cout<<endl;

	return 0;
}
