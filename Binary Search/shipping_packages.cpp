// problem ask the LEAST PACKAGING REQUIRED TO SHIP IT IN D DAYS
// we would be given packages , days withing which they ae needed to be shipped
// find the least packaging
// ships runs once per day and we are given weights in terms of array and find 
// minimum weight it would carry once a day so that all weigts are shipped within d days 

// eg [1,2,3,4,5,6,7,8,9,10]

// something to observe that capacity must(minimum) be equal to max weight of product 
// otherwise some of the leftover wont be able to ship consider example of 
// if capacity is 8 , then we wont be able to ship 9 and 10

// also the range of capacity will be from [ max element to sum of all ]

// return -1 if cant be shipped;

