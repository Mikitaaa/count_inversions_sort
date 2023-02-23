#include <iostream>

void Merge(size_t *A,size_t *mas, size_t start_of_left, size_t end_of_right,size_t &count) {
    
    size_t middle, left_iter, right_iter, null_left_iter = 0;
    
    
  middle = (start_of_left + end_of_right) / 2;  //вычисление среднего элемента
  left_iter = start_of_left;                //начало левой части
  right_iter = middle + 1;           //начало правой части
    
    for (long j = start_of_left; j <= end_of_right; j++){
        if ((left_iter <= middle) && ((right_iter > end_of_right) || (A[left_iter] <= A[right_iter]))) {
            mas[j] = A[left_iter];
            left_iter++;
            null_left_iter++;
        } else {
            if((A[left_iter] > A[right_iter]))count+=(middle + 1-start_of_left)-null_left_iter;
            mas[j] = A[right_iter];
            right_iter++;
        }
        
    }

    for (size_t i = start_of_left; i <= end_of_right; i++) A[i] = mas[i];
    
  //delete[] mas;
};

void MergeSort(size_t *A, size_t *mas, size_t start_of_left, size_t end_of_right,size_t &count) {
  if (start_of_left < end_of_right) {
      size_t mid = (start_of_left + end_of_right) / 2;
    MergeSort(A,mas, start_of_left, mid,count);  //сортировка левой части
    MergeSort(A,mas, mid + 1, end_of_right, count);  //сортировка правой части
    Merge(A,mas, start_of_left, end_of_right,count);  //слияние двух частей
  }
}

int main(){
    size_t N;
    std::cin>>N;
    size_t *input_arr = new size_t [N];
    size_t *helper_mas = new size_t [N];
    
    for(size_t i = 0; i<N; ++i){
        std::cin>>input_arr[i];
    }
    size_t count = 0;
    MergeSort(input_arr,helper_mas, 0, N - 1,count);
    std::cout<<count;
    return 0;
}
