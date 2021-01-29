//Given an array, choose a set of integers and remove all the occurrences of these integers in the array.
//Return the minimum size of the set so that at least half of the integers of the array are removed.
//EX: arr = [3,3,3,3,5,5,5,2,2,7] returns 2, becuase our set can be {3, 7} (or {3, 5}, etc.)
//Removing 3 and 7 leaves us with [5,5,5,2,2] which is less than or equal to half the size of arr
//EX2: arr = [2,2,2,2,2] returns 1, our set is {2}
//EX3: arr = [10,10,2,3] returns 1, our set is {10}
//EX4: arr = [1,2,3,4,5,6] returns 3, our set is {1,2,3} etc.




//Let's work with our first ex, arr = [3,3,3,3,5,5,5,2,2,7]
//A greedy approach would be to remove all the instances of the number which occurs the most, in this case 3.
//If we keep doing this based on order of most occuring, we can find the minimum number of removals.
//(in this case only 2 numbers need to be removed until we are left with an array size <= the original)

//If we sort the array by number of occurences, we can solve the problem, but how?


#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>

int findMinSet(std::vector<int> &arr);

int main(){
    std::vector<int> arr;
    arr.push_back(3); 
    arr.push_back(3); 
    arr.push_back(3); 
    arr.push_back(3); 
    arr.push_back(5); 
    arr.push_back(5); 
    arr.push_back(5);
    arr.push_back(2); 
    arr.push_back(2);
    arr.push_back(7); //Now we have arr = [3,3,3,3,5,5,5,2,2,7];
    
    std::cout << findMinSet(arr) << std::endl;
    return 0;
}

int findMinSet(std::vector<int> &arr){
    //We must have a data structure which stores the value as well as the number of time it occurs in the array
    //Becuase we don't know how many values there are and how many occurences, the easiest solution is to
    //store in a hash where we can retrieve both numbers in O(1) time.

    std::unordered_map<int, int> hashMap; //<value, number of occurences>;

    for(const auto &i : arr){
        if(hashMap.find(i) != hashMap.end()){ //check if it exists in the hash, if so update the second number (num of occurences)
            hashMap.at(i) += 1;
        }
        hashMap.insert({i, 1});
    }

    //Now we have a hash of all the values in arr as well as the number of times they appear in the array
    //We can now easily sort by number of occurence, use C++ priority queue which sorts as values are pushed

    std::priority_queue<int> queue;

    for(const auto &i : hashMap){
        queue.push(i.second); //We are sorting using the second value in the hash, so hashMap.second
        //(if we want to know which numbers we are removing, we can also store hashMap.first in the queue using std::pair<int, int>)
    }

    //queue now has the values sorted by number of occurences, so we can loop through it, removing the number which ocurrs
    //the most until we are left with a queue <= the size of the original arr
    int numRemoved = 0;
    int origSize = arr.size();
    int newSize = origSize;
    while(queue.size() != 0){
        if(newSize <= origSize / 2){
            return numRemoved;
        }
        newSize = newSize - queue.top();
        queue.pop();
        numRemoved++;
    }
    return numRemoved;
}
