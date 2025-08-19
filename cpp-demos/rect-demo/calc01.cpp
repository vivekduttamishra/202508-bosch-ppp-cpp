#include <iostream>
#include <string>

using namespace std;

class Calculator
{
public:
    void CalculateResult(int value1, string  oper, int value2){

        int result;
        if(oper=="plus")
        {
            result = value1 + value2;
           // cout<<value1<<" "<<oper<<" "<<value2<<" = "<<result<<endl;
        }
        
        if(oper=="multiply"){
            result = value1 * value2;
         //   cout<<value1<<" "<<oper<<" "<<value2<<" = "<<result<<endl;
        }
        else if (oper=="minus")
        {
            result=value1-value2;
       //     cout<<value1<<" "<<oper<<" "<<value2<<" = "<<result<<endl;
        }
        else{
            cout<<"Invalid operator:"<<oper<<endl;
            return;
        }
        cout<<value1<<" "<<oper<<" "<<value2<<" = "<<result<<endl;

    }
};

//4 plus 8 = 12
// plus(4, 8) = 12


int main(){

    Calculator calc;
    int value1=50, value=15;

    calc.CalculateResult(value1, "plus", value);
    calc.CalculateResult(value1, "minus", value);
    calc.CalculateResult(value1, "multiply", value); // Invalid operator


    return 0;
}