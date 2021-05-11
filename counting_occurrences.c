#include <stdio.h>
int counter[100][1];

int most_common_element(int nums[], size_t length) {
    

    for(int i = 0; i < 100; i ++) {
        counter[i][0] = 0;
    }

    //Add the occurrence of a value to counter at the index of the value,
    // For example, if nums[i] = 1, add 1 to the counter at nums[i]
    for(int i = 0; i < length; i++) {
        counter[nums[i]][0] ++;
        
    }

    int max_occur = 0; 

    for(int i = 0; i < length; i++) {

        //if one element appears more
        if(counter[max_occur][0] < counter[i][0]) {
            max_occur = i;
        }

        // if two elements appear equally
        else if(counter[max_occur][0] == counter[i][0]) {

            //find the smaller one and use that
            if(nums[max_occur] > nums[i]) {
                max_occur = i;
            }
            
        }
    }

    return nums[max_occur];

}

int main(int argc, char *argv[]) {
    int test_array[] = {14, 14, 7, 7, 14};

   printf("%d\n", most_common_element(test_array, 4)); 

}