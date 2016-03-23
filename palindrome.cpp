#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void printUsageInfo(const string& inputString){
    
    cout << "Usage: " << inputString << " [-c] string1 string2 ...";
    
    return;
}


bool isPalindrome(const string& inputString, bool caseSense) {
    
    if(caseSense == false){
        
        if (inputString.length() == 0){
            return true;
        }
        else if (inputString.length() == 1){
            return true;
        }
        else if (inputString.length() > 1){
            if(tolower(inputString[0]) == tolower(inputString[inputString.length() -1]) ){
                return true && isPalindrome(inputString.substr(1, inputString.length() - 2), caseSense);
            }
            else{
                return false;
            }
        }
    }
    else if(caseSense == true){
        if (inputString.length() == 0)
        {
            return true;
        }
        
        else if (inputString.length() == 1){
            return true;
        }
        
        else if (inputString.length() > 1){
            if(inputString[0] == inputString[inputString.length() -1] ){
                return true && isPalindrome(inputString.substr(1, inputString.length() - 2), caseSense);
            }
            else{
                return false;
            }
        }
    }
    
    
}



int main(int argc, char* argv[]){
    
    string arg0 = argv[0];
    string arg1 = argv[1];
    
    
    if(argc == 1){
        printUsageInfo(arg0);
    }
    else if(argc == 2){
        
        if(arg1 == "-C" || arg1 == "-c"){
            printUsageInfo(arg0);
        }
        else{
            string input = argv[1];
            bool palindrome = isPalindrome(input, false);
            if(palindrome){
                cout << argv[1] << " is a palindrome." << endl;
            }
            else{
                cout << argv[1] << " is not a palindrome." << endl;
            }
        }
    }
    else if(argc > 2)
    {
        if(arg1 == "-C" || arg1 == "-c")
        {
            for(int j = 2 ; j < argc; ++j)
            {
                string inputJ = argv[j];
                
                
                bool palindromeJ = isPalindrome(inputJ, true);
                
                if(palindromeJ){
                    cout << argv[j] << " is a palindrome." << endl;
                }
                else{
                    cout << argv[j] << " is not a palindrome." << endl;
                }
            }
        }
        else{
            for(int j = 1 ; j < argc; ++j){
                
                string inputEntered = argv[j];
                bool palindromeEnter = isPalindrome(inputEntered, false);
                if(palindromeEnter)
                {
                    cout << argv[j] << " is a palindrome." << endl;
                }
                else
                {
                    cout << argv[j] << " is not a palindrome." << endl;
                }
            }
        }
    }
    return 0;
}
