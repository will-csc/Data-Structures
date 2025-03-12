import java.util.Scanner;
import java.util.Arrays;

public class Main{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        
        System.out.println("Enter a target: ");
        int target = in.nextInt();
        
        System.out.println("Enter a size for array: ");
        int size = in.nextInt();
        
        System.out.println("Enter the values for array: ");
        int arr[] = new int[size];
        for(int i = 0; i < size; i++){
            arr[i] = in.nextInt();
        }
        Arrays.sort(arr);
        
        int result = binary_search(arr,target,size-1,0);
        if(result == -1){
            System.out.println("Element not found");
        }else{
            System.out.printf("Binary search found the element '%d' in: %d",
                            target,
                            result);
        }
    }
    public static int binary_search(int arr[], int target, int high, int low){
        if(low > high){
            return -1;
        }
        int mid = (low + high) / 2;
        
        if(arr[mid] == target){
            return mid;
        }else if(target < arr[mid]){
            return binary_search(arr,target,mid-1,low);
        }else{
            return binary_search(arr,target,high,mid+1);
        }
    }
}