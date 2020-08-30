#include <iostream>
#include <queue>
#include <fstream>
using namespace std;

void addNumbers(int number, priority_queue <int, vector<int>, greater<int> > &minimum, priority_queue<int> &maximum){
	if(minimum.empty() || number > minimum.top()){
		minimum.push(number);
	}
	else{
		maximum.push(number);
	}
}

void rebalance(priority_queue <int, vector<int>, greater<int> > &minimum, priority_queue<int> &maximum){
	int minSize = minimum.size();
	int maxSize = maximum.size();
	if(minSize-maxSize > 1){
		maximum.push(minimum.top());
		minimum.pop();
	}
	else if(maxSize-minSize  > 1){
		minimum.push(maximum.top());
		maximum.pop();
	}
}

int getMedian(priority_queue <int, vector<int>, greater<int> > &maximum, priority_queue<int> &minimum){
	int minSize = minimum.size();
	int maxSize = maximum.size();
	int result;
	if (minSize==maxSize){
		result = minimum.top();
	}
	else{
		if(minSize > maxSize){
			result = minimum.top();
		}
		else{
			result = maximum.top();
		}
	}
	return result;
}

int main()
{	
	int currNumber;
	long long unsigned int total = 0;
	fstream numberFile;
	numberFile.open("numbers.txt");

	priority_queue <int, vector<int>, greater<int> > minHeap;

	priority_queue <int, vector<int>, less<int> > maxHeap;

	if(numberFile.is_open()){
		while(numberFile >> currNumber){
			
			addNumbers(currNumber, minHeap, maxHeap);

			rebalance(minHeap, maxHeap);

			int median = getMedian(minHeap, maxHeap);

			total = total+median;
		}
	}

	cout <<"min heap in toplam eleman sayisi: "<< minHeap.size() <<" en dusuk elemani : "<< minHeap.top()<<"\n";
	cout <<"max heap in toplam eleman sayisi: "<< maxHeap.size() <<" en yuksek elemani : "<< maxHeap.top()<<"\n";

	total = total % 10000;
	cout << "result : "<<total<<endl;
}



