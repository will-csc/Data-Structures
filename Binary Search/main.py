def binary_search(arr: list, target: int, high: int, low: int):
    if low > high:
        return -1
    
    mid = (low + high) // 2
    if target == arr[mid]:
        return mid
    elif arr[mid] < target:
        return binary_search(arr,target,high,mid+1)
    else:
        return binary_search(arr,target,mid-1,low)


size = int(input("Enter a list size: "))

print("Enter values for the list until the size:")
arr = [int(input()) for _ in range(size)]
arr.sort()

target = int(input("Enter a target: "))

result = binary_search(arr, target,len(arr)-1,0)

print("Sorted List:", arr)
if result != -1:
    print(f"Target found at index {result}")
else:
    print("Target not found")
