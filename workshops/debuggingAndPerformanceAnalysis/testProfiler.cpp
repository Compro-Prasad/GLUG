/*= compile: g++ -fprofile-arcs -ftest-coverage -std=c++11 -Wall $src -o $exe =*/
/*= run: $exe && gcov $src =*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

inline int random(int start, int end) {
  return (rand() % (end - start)) + start;
}

inline int random(int end) {
  return rand() % end;
}

template <typename Type> ostream &operator<<(ostream &out, vector<Type> v) {
  for (auto val : v)
    out << val << " ";
  return out;
}

template <typename T>
vector<T> insertionSort(const vector<T> &l) {
  vector<T> sortedl = l;
  for (size_t i = 1; i < sortedl.size(); ++i) {
    T x = sortedl[i];
    size_t j = i;
    for (; j > 0 && sortedl[j - 1] > x; --j)
      sortedl[j] = sortedl[j - 1];
    sortedl[j] = x;
  }
  return sortedl;
}

template <typename T>
vector<T> selectionSort(const vector<T> &l) {
  vector<T> sortedl = l;
  for (size_t i = 0; i < sortedl.size() - 1; ++i) {
    T min = sortedl[i];
    size_t pos = i;
    for (size_t j = i + 1; j < sortedl.size(); ++j) {
      if (sortedl[j] < min) {
        min = sortedl[j];
        pos = j;
      }
    }
    swap(sortedl[pos], sortedl[i]);
  }
  return sortedl;
}

template <typename T>
vector<T> bubbleSort(const vector<T> &l) {
  vector<T> sortedl = l;
  bool flag = true;
  for (size_t i = 0; flag == true && i < sortedl.size(); ++i) {
    for (size_t j = 0; j < sortedl.size() - i - 1; ++j) {
      if (sortedl[j] > sortedl[j + 1]) {
        swap(sortedl[j], sortedl[j + 1]);
        flag = true;
      }
    }
  }
  return sortedl;
}

template <typename T>
vector<T> mergeLists(const vector<T> &l1, const vector<T> &l2) {
  vector<T> sortedl(l1.size() + l2.size());
  size_t i = 0, j = 0, k = 0;
  while (i < l1.size() &&
         j < l2.size()) {
    // if (l1[i] < l2[j])
    //   sortedl[k] = l1[i], i++, k++;
    // else
    //   sortedl[k] = l2[j], j++, k++;
    sortedl[k++] = l1[i] < l2[j] ? l1[i++] : l2[j++];
  }
  while (i < l1.size())
    sortedl[k++] = l1[i++];
  while (j < l2.size())
    sortedl[k++] = l2[j++];
  return sortedl;
}

template <typename T>
vector<T> breakList(const vector<T> &l, size_t low, size_t high) {
  if (low < high) {
    size_t mid = low + (high - low) / 2;
    vector<T> l1 = breakList(l, low, mid);
    vector<T> l2 = breakList(l, mid + 1, high);
    return mergeLists(l1, l2);
  } else {
    vector<T> oneElement = {l[low]};
    return oneElement;
  }
}

template <typename T>
vector<T> mergeSort(const vector<T> &l) {
  return breakList(l, 0, l.size() - 1);
}

int main() {
  srand(time(0));
  const size_t s = 10000;
  vector<int> list(s);
  for (auto &i : list) {
    i = random(0, s * 10);
  }
  vector<int> selSort = selectionSort(list);
  vector<int> insSort = insertionSort(list);
  vector<int> bubSort = bubbleSort(list);
  vector<int> merSort = mergeSort(list);

  cout         << "Selection Sort: ";
  for (size_t i = 0; i < 10; ++i) {
    cout << selSort[i] << " ";
  }
  cout << endl << "Insertion Sort: ";
  for (size_t i = 0; i < 10; ++i) {
    cout << insSort[i] << " ";
  }
  cout << endl << "Bubble Sort   : ";
  for (size_t i = 0; i < 10; ++i) {
    cout << bubSort[i] << " ";
  }
  cout << endl << "Merge Sort   : ";
  for (size_t i = 0; i < 10; ++i) {
    cout << merSort[i] << " ";
  }
  cout << endl;
}
