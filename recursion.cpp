#include <iostream>
#include <string>
using namespace std;
// Returns the product of two positive integers, m and n,
// using only repeated addition.
// Q: what is the base statement?
int mult(unsigned int m, unsigned int n)
{
    if (n == 0){
        return 0;
    }
    return m + mult(m, n-1);
}

// Returns the number of occurrences of digit in the decimal
// representation of num. digit is an int between 0 and 9
// inclusive.
//
// Pseudocode Example:
//    countDigit(18838, 8) => 3
//    countDigit(55555, 3) => 0
//    countDigit(0, 0)     => 0 or 1 (either is fine)
//
int countDigit(int num, int digit)
{
    if ((num / 10) == 0){
        return 0;
    }else{
        if((num % 10) == digit){
            return countDigit(num/10, digit) + 1;
        }else{
            return countDigit(num/10, digit);
        }
    }
}

// Returns a string where the same characters next each other in
// string n are separated by "--". You can use substr in this problem
//
// Pseudocode Example:
//    pairMinus("goodbye") => "go--odbye"
//    pairMinus("yyuu")    => "y--yu--u"
//    pairMinus("aaaa")    => "a--a--a--a"
//
string pairMinus(string n)
{
    string temp_string = "--";
    if (n.length()==0){
        return "";
    }
    string temp = n.substr(0,1);
    if(n[0] == n[1]){
        return temp + temp_string + pairMinus(n.substr(1));
    }else{
        return temp + pairMinus(n.substr(1));
    }
}

// str contains a single pair of parenthesis, return a new string
// made of only the parenthesis and whatever those parensthesis
// contain. You can use substr in this problem.
//
//  Pseudocode Example:
//     findParen("abc(ghj)789") => "(ghj)"
//     findParen("(x)7")        => "(x)"
//     findParen("4agh(y)")     => "(y)"
//
string findParen(string str)
{
    if (str[0] != '('){
        return findParen(str.substr(1));
    }
    if (str[str.length()-1] != ')'){
        return findParen(str.substr(0,str.length()-1));
    }
    return str;
}

// Return true if the sum of any combination of elements in the array
// a equals the value of the target.
//
//  Pseudocode Example:
//     combinationSum([2, 4, 8], 3, 10) => true
//     combinationSum([2, 4, 8], 3, 12) => true
//     combinationSum([2, 4, 8, 6], 4, 11) => false
//     combinationSum([], 0, 0)         => true
//
bool combinationSum(const int a[], int size, int target) {
    //base case
    if (size == 0 && target == 0){
        return true;
    }else if (size == 1 && a[0] == target){
        return true;
    }

    //recursive case
    if (size > 1){
        if (a[size - 2]+a[size - 1] == target) {
            return true;
        }
    }else{
        return false;
    }

    if (combinationSum(a, size-1, target)){
        return true;
    }else{
        return combinationSum(a, size-1, target-a[size-1]);
    }
}


// Return true if there is a path from (sr,sc) to (er,ec)
// through the maze; return false otherwise
bool pathPresent(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec){
    //for checking
//    cout<<"sr: "<<sr<<",sc: "<<sc<<",maze: "<<maze[sc][sr]<<",sr+1: "<<maze[sc][sr+1]<<",sc+1: "<<maze[sc+1][sr]<<endl;
//    for(int i=0;i<10;i++){
//        cout<<maze[i]<<endl;
//    }
    //base case
    if (sr == er && sc == ec){
        return true;
    }
    //recursive case
    maze[sc][sr] = 'v'; // marking
    //checking next element position and go if it is possible
    if (maze[sc][sr+1] != 'X' && maze[sc][sr+1] != '@' && maze[sc][sr+1] != 'v'){
        return pathPresent(maze, nRows, nCols, sr+1, sc, er, ec);
    }else if(maze[sc+1][sr] != 'X' && maze[sc+1][sr] != '@' && maze[sc+1][sr] != 'v'){
        return pathPresent(maze, nRows, nCols, sr, sc+1, er, ec);
    }else if(maze[sc][sr-1] != 'X' && maze[sc][sr-1] != '@' && maze[sc][sr-1] != 'v'){
        return pathPresent(maze, nRows, nCols, sr-1, sc, er, ec);
    }else if(maze[sc-1][sr] != 'X' && maze[sc-1][sr] != '@' && maze[sc-1][sr] != 'v'){
        return pathPresent(maze, nRows, nCols, sr, sc-1, er, ec);
    }else{
        //returning back to the previous position with mark 'X'
        if (maze[sc][sr-1] == 'v'){
            maze[sc][sr] = 'X';
            return pathPresent(maze, nRows, nCols, sr-1, sc, er, ec);
        }else if (maze[sc-1][sr] == 'v'){
            maze[sc][sr] = 'X';
            return pathPresent(maze, nRows, nCols, sr, sc-1, er, ec);
        }else if (maze[sc][sr+1] == 'v'){
            maze[sc][sr] = 'X';
            return pathPresent(maze, nRows, nCols, sr+1, sc, er, ec);
        }else if (maze[sc+1][sr] == 'v'){
            maze[sc][sr] = 'X';
            return pathPresent(maze, nRows, nCols, sr, sc+1, er, ec);
        }else{
            return false;
        }
    }
}

int main() {

    //1
    int test1 = mult(7,7);
    cout<<test1<<endl;

    //2
    int test2 = countDigit(18838,8);
    cout<<test2<<endl;

    //3
    string test3 = pairMinus("yyuu");
    cout<<test3<<endl;

    //4
    string test4 = findParen("abc(ghj)789");
    cout<<test4<<endl;

    //5
    int temp[] = {2, 4, 8, 6};
    bool test5 = combinationSum(temp, 4, 11);
    if (test5 == 1){
        cout<<"test5: true"<<endl;
    }else if (test5 == 0){
        cout<<"test5: false"<<endl;
    }

    //6
    string maze[10] = {
            "XXXXXXXXXX",
            "X.......@X",
            "XX@X@@.XXX",
            "X..X.X...X",
            "X..X...@.X",
            "X....XXX.X",
            "X@X....XXX",
            "X..XX.XX.X",
            "X...X....X",
            "XXXXXXXXXX"
    };
    if (pathPresent(maze, 10, 10, 6, 4, 1, 1))
        cout<<"Solvable!"<<endl;
    else
        cout<<"Out of luck!"<<endl;

}