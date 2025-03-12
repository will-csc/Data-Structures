fn main(){
    let mut arr: [usize;10] = [2,8,1,3,4,5,10,9,6,7];
    arr.sort();
    println!("Your array is: {:?}",arr);
    
    let target = arr[4];
    println!("Your target in array: {}",target);
    
    let idx = binary_src(arr,target,(arr.len()-1) as usize,0 as usize);
    if idx > 0 { print!("Element found at {} index",idx); }
    else { print!("Element not found"); }
}
fn binary_src(arr: [usize;10],target: usize,high: usize, low: usize) -> i32{
    if low > high { return -1 }
    
    let mid = (low + high) / 2;
    if arr[mid as usize] == target { return mid as i32; }
    else if arr[mid] < target { return binary_src(arr,target,(mid-1) as usize,low) }
    else { return binary_src(arr,target,high,(mid+1) as usize) }
}