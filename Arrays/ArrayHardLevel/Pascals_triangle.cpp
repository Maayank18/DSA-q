//               1                        THIS IS GENERAL REPRESENTATION OF PASCALS TRIANGLE
//            1     1                     POSSIBLE QUESTION ASKED :-
//        1      2      1                 1) find element at given row and column 
//    1      3       3       1            2) print the nth row of pascals triangle 
//1      4       6       4       1        3) given n -> print entire pascals triangle 



// trying to solve part one of qustion that is finding element at particular
// row and column -> one of the common way is using nCr that is combination 
// approach and returning the the answer wher n -> row and r -> column

// this particular part can be optimsed a little if carefully observed at the formula
// number of column is where till my rows will be multiplied that is : 
// eg. 7C3 -> 7!/3!*(7-3)! = 7*6*5/3*2*1  SOMETHING TO NOTICE 

// #include<iostream>
// using namespace std;

// int f( int number){
//     if( number  == 0) return 1;
//     else return number*f(number-1);
// }

// int finding( int rows, int columns ){
//     int result = f(rows)/(f(columns)*f(rows-columns));
//     return result;
// }

// int main(){
//     int r;
//     cout<<" enter the rows of pascals triangle : ";
//     cin>>r;

//     int c;
//     cout<<" enter the column of pascals triangle : ";
//     cin>>c;

//     int ans_element = finding(r,c);

//     cout<<" the element present is : "<<ans_element<<endl;
//     return 0;
// }


// FOR SECOND TYPE QUESTION SOLUTION WE CAN SEE THATB THE ROW EHICH IS NEED TO 
// BE PRINETD WILL HAV ETAHT MANY ELEMENTS ONLY 
// this part is dircetly / indirectly connected to first part
// take a look at TIME COMPLXITY AND THE OPTIMISED SOLUTION

// #include<iostream>
// using namespace std;

// int f( int number){
//     if( number  == 0) return 1;
//     else return number*f(number-1);
// }

// int f( int n, int c){
//     int answer = f(n)/(f(c)*f(n-c));
//     return answer;
// }

// int finding( int n){
//     for(int c = 0; c<=n; c++){
//        int values = f(n,c);
//         cout<<values<<" ";
//     }
// }


// int main(){
//     int n;
//     cout<<" enter the row which is needed to be printed : ";
//     cin>>n;

//     int row_elements = finding(n);

//     cout<<" the elements are : "<<row_elements<<endl;
//     return 0;
// }


// Third variety deals with printing the whole pascal triangle with a given value 

#include<iostream>
using namespace std;

int fact( int number ){
    if( number  == 0 || number == 1) return 1;
    return number*fact(number-1);
}

int f( int row, int column){
    return fact(row)/(fact(column) * fact(row-column));
}

void finding( int n){
    for(int i = 0; i<n; i++){
        for(int c = 0; c<=i; c++){
            cout<<f(i,c)<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cout<<" enter the number of rows to be printed : ";
    cin>>n;

    cout<<" the elements are : "<<endl;

    finding(n);

    return 0;
}