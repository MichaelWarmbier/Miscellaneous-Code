/* Imperfect Hashmap Example */

/////* External References */////

#include <iostream>
using namespace std;


/////* Class Definition */////

class bucketItem {
  public:
    int key;
    bool inUse = false;
};

class HashMap {
  public:
    // Constructor
    HashMap() { 
      bucketSize = 0;
      bucket = new bucketItem[0];
    }

    // Destructor
    ~HashMap() {
      delete [] bucket;
    }

    // Function to hash the given value
    int Hash(int key) {
      /* This can be written in any way as long as it works as a hash */
      return key;
    }

    // Function to add a new hash to the bucket
    void add(int key) {
      int hashIndex = Hash(key);
      if (bucketSize < hashIndex) {
        bucketSize = hashIndex + 1;
        bucketItem * temp = new bucketItem[hashIndex + 1];
        copy(bucket, bucket + bucketSize - 1, temp);
        delete[] bucket;
        bucket = temp;
        bucket[bucketSize - 1].key = key;
        bucket[bucketSize - 1].inUse = true;
      }
      else
        bucket[hashIndex].key = key;
        bucket[hashIndex].inUse = true;
    }

    // Function to remove a hash from the bucket
    void remove(int key) {
      int hashIndex = Hash(key);
      if (bucket[hashIndex].inUse) {
        bucket[hashIndex].inUse = false;
        bucket[hashIndex].key = 0;
      }
    }

    // Function to return whether or not hash exists in bucket
    bool contains(int key) {
      int hashIndex = Hash(key);
      return bucket[hashIndex].inUse;
    }

    // Function to get the current size of the bucket
    int size() { return bucketSize; }

  private:
    bucketItem * bucket;
    int bucketSize;
};



/////* Data */////

int main() {
  HashMap test;
  cout << "Current size of the bucket: " << test.size() << endl;
  cout << "Value '127' exists in bucket: " << boolalpha << test.contains(127) << endl;
  test.add(127); cout << "New value 127 added!" << endl;
  cout << "Current size of the bucket: " << test.size() << endl;
  cout << "Value '127' exists in bucket: " << boolalpha << test.contains(127) << endl;
  cout << "Value '4' exists in bucket: " << boolalpha << test.contains(4) << endl;
  cout << "Value '600' exists in bucket: " << boolalpha << test.contains(600) << endl;
  test.remove(127); cout << "Value 127 removed!" << endl;
  cout << "Value '127' exists in bucket: " << boolalpha << test.contains(127) << endl;
  cout << "Current size of the bucket: " << test.size() << endl;
  
  return 0;
}

